#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleController.h"

#define TOTAL_PARTICLES 4800
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
	Boolean mRenderParticles;
};

void matrixP::prepareSettings(Settings *settings){
    settings->setWindowSize(640, 761);
    settings->setFrameRate(60.0f);
}

void matrixP::setup() {
//	mParticleController.addParticles(5000);

	mParticleController = ParticleController(RESOLUTION);
	mRenderParticles = TRUE;
}

void matrixP::update() {
	mParticleController.update();
}

void matrixP::draw() {
//	float gray = sin(getElapsedSeconds()) * 0.5f + 0.3f;
//	gl::clear(Color(gray, gray, gray), true);
//	float x = cos(getElapsedSeconds()) * 100.0f;
//	float y = sin(getElapsedSeconds()) * 100.0f;
//	gl::drawSolidCircle(Vec2f(x, y) + getWindowSize()/2, abs(x));
	gl::clear();
	if(mRenderParticles)
		mParticleController.draw();
}

void matrixP::keyDown(KeyEvent event) {
	if(event.getChar() == '1'){
        mRenderParticles = !mRenderParticles;
    }
}

CINDER_APP_BASIC(matrixP, RendererGl)
