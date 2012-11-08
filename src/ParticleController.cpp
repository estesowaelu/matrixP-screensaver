//
//  ParticleController.cpp
//  matrixP
//
//  Created by Tim Honeywell on 12/11/04.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "ParticleController.h"

using namespace ci;
using std::list;

ParticleController::ParticleController() {
}

ParticleController::ParticleController(int res) {
	mXRes = app::getWindowWidth()/res;
	mYRes = app::getWindowHeight()/res;
	
	for(int y=0; y<mYRes; y++){
		for(int x=0; x<mXRes; x++){
			addParticle(x, y, res);
		}
	}
}

void ParticleController::update(bool colored, bool marked, bool ordered) {
	for(list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p) {
		p->update(colored, marked, ordered);
	}
}

void ParticleController::draw() {
	for(list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p) {
		p->draw();
	}
}

void ParticleController::addParticle(int xi, int yi, int res) {
    float x = (xi + 0.5f) * (float)res;
    float y = (yi + 0.5f) * (float)res;
    mParticles.push_back(Particle(Vec2f(x, y)));
}
