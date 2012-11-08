#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleController.h"

#define RESOLUTION 10

using namespace ci;
using namespace ci::app;
using namespace std;

class matrixP : public AppBasic {
  public:
	void prepareSettings(Settings *settings);
	void setup();
	void update();
	void draw();
	void keyDown(KeyEvent event);
	
	ParticleController mParticleController;
	
	bool mRenderParticles;
	bool mRenderColor;
	bool mRenderMarked;
	bool mRenderOrdered;
};

void matrixP::prepareSettings(Settings *settings){
    settings->setWindowSize(640, 761);
    settings->setFrameRate(60.0f);
}

void matrixP::setup() {
	mParticleController = ParticleController(RESOLUTION);
	mRenderParticles = TRUE;
	mRenderColor = FALSE;
	mRenderMarked = FALSE;
	mRenderOrdered = FALSE;
}

void matrixP::update() {
	mParticleController.update(mRenderColor, mRenderMarked, mRenderOrdered);
}

void matrixP::draw() {
	gl::clear();
	if(mRenderParticles) mParticleController.draw();
}

void matrixP::keyDown(KeyEvent event) {
	if(event.getChar() == '1') mRenderParticles = !mRenderParticles;
	if(event.getChar() == '2') mRenderColor = !mRenderColor;
	if(event.getChar() == '3') mRenderMarked = !mRenderMarked;
	if(event.getChar() == '4') mRenderOrdered = !mRenderOrdered;
}

CINDER_APP_BASIC(matrixP, RendererGl)
