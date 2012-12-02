#include "ParticleController.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"

#define RESOLUTION 15
#define WIDTH 640
#define HEIGHT 761
//#define WIDTH 720
//#define HEIGHT 450
//#define WIDTH 1440
//#define HEIGHT 900
#define CYCLELIMIT 3600

using namespace ci;
using namespace ci::app;

class matrixP : public AppBasic {
  public:
	void prepareSettings(Settings *settings);
	void setup();
	void update();
	void draw();
	void keyDown(KeyEvent event);
	void mouseMove(MouseEvent event);
	void mouseDrag(MouseEvent event);
	
	void printStats();
	
	ParticleController mParticleController;
	
	Vec2i mMouseLoc;
	Vec2f mGhostMouse;
	Vec2f mGhostGoal;
	
	float mStepX;
	float mStepY;
	
	int framecounter;
	int typecounter;
	
	bool mRenderParticles;
	int mRenderColor;
	bool mRenderOrdered;
	bool mRenderAuto;
};

void matrixP::prepareSettings(Settings *settings){
    settings->setWindowSize(WIDTH, HEIGHT);
    settings->setFrameRate(60.0f);
}

void matrixP::setup() {
	mParticleController = ParticleController(RESOLUTION);
	mMouseLoc = Vec2i(getWindowWidth()/2, getWindowHeight()/2);
	mGhostMouse = Vec2i(getWindowWidth()/2, getWindowHeight()/2);
	mRenderParticles = TRUE;
	mRenderColor = 1;
	mRenderOrdered = FALSE;
	mRenderAuto = FALSE;
	framecounter = 0;
	typecounter = 1;
	mGhostGoal.x = Rand::randFloat(0.0f, getWindowWidth() - 1.0f);
	mGhostGoal.y = Rand::randFloat(0.0f, getWindowHeight() - 1.0f);
//	app::setFullScreen();
}

void matrixP::update() {
	if(mRenderAuto) {
		framecounter++;
		if(framecounter==CYCLELIMIT) {
			typecounter++;
			mGhostGoal.x = Rand::randFloat(0.0f, getWindowWidth() - 1.0f);
			mGhostGoal.y = Rand::randFloat(0.0f, getWindowHeight() - 1.0f);
			mStepX = (mGhostGoal.x - mGhostMouse.x)/CYCLELIMIT;
			mStepY = (mGhostGoal.y - mGhostMouse.y)/CYCLELIMIT;
			framecounter = 0;
		}
		if(typecounter==4) {
			mRenderOrdered = !mRenderOrdered;
			typecounter = 1;
		}
		mRenderColor = typecounter;
		
		mGhostMouse.x += mStepX;
		mGhostMouse.y += mStepY;

		mParticleController.update(mRenderColor, mRenderOrdered, mGhostMouse);
	}
	else mParticleController.update(mRenderColor, mRenderOrdered, mMouseLoc);
	printStats();
}

void matrixP::printStats() {
	app::console() << "===========================" << std::endl;
	if(mRenderAuto) {
		app::console() << "AutoRender ON" << std::endl;
		app::console() << "Frame " << framecounter << "/" << CYCLELIMIT << std::endl;
		app::console() << "Type " << typecounter << "/3" << std::endl;
		app::console() << "GhostMouse: " << mGhostMouse << std::endl;
	}
	else if(!mRenderAuto) {
		app::console() << "AutoRender OFF" << std::endl;
		app::console() << "Mouse: " << mMouseLoc << std::endl;
	}
	if(mRenderOrdered)
		app::console() << "MouseFollow ON" << std::endl;
	else if(!mRenderOrdered)
		app::console() << "MouseFollow OFF" << std::endl;
	if(mRenderParticles)
		app::console() << "Particles ON" << std::endl;
	else if(!mRenderParticles)
		app::console() << "Particles OFF" << std::endl;
	switch (mRenderColor) {
		case 1:
			app::console() << "Render GRAYSCALE" << std::endl;
			break;
		case 2:
			app::console() << "Render COLOR" << std::endl;
			break;
		case 3:
			app::console() << "Render GRADIENT" << std::endl;
			break;
		default:
			break;
	}
}

void matrixP::draw() {
	gl::clear();
	if(mRenderParticles) mParticleController.draw();
}

void matrixP::keyDown(KeyEvent event) {
	// greyscale
	if(event.getChar() == '1') {
		mRenderColor = 1;
	}
	// color
	if(event.getChar() == '2') {
		mRenderColor = 2;
	}
	// gradient
	if(event.getChar() == '3') {
		mRenderColor = 3;
	}
	// follow-decay
	if(event.getChar() == '4') {
		mRenderOrdered = !mRenderOrdered;
	}
	// render-auto
	if(event.getChar() == '9') {
		mRenderAuto = !mRenderAuto;
	}
	// show-hide particles
	if(event.getChar() == '0') {
		mRenderParticles = !mRenderParticles;
	}
}

void matrixP::mouseMove(MouseEvent event) {
	mMouseLoc = event.getPos();
}

void matrixP::mouseDrag(MouseEvent event) {
	mouseMove(event);
}

CINDER_APP_BASIC(matrixP, RendererGl)
