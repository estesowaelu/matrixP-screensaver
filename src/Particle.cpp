//
//  Particle.cpp
//  matrixP
//
//  Created by Tim Honeywell on 12/11/04.
//
//

#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Particle::Particle() {
}

Particle::Particle(Vec2f loc) {
	mLoc	= loc;
	cMod = 0.0f;
	rMod = 0.0f;
	gMod = 0.0f;
	bMod = 0.0f;
	mColor = Color(1.0f, 1.0f, 1.0f);
	mRadius = Rand::randFloat(1.0f, 5.0f);
}

void Particle::update(bool color, bool marked, bool ordered) {
	// update color if needed
	if(color) {
		rMod += Rand::randFloat(-0.1f, 0.1f);
		gMod += Rand::randFloat(-0.1f, 0.1f);
		bMod += Rand::randFloat(-0.1f, 0.1f);
		boundFloat(rMod, true);
		boundFloat(gMod, true);
		boundFloat(bMod, true);
		mColor = Color(rMod, gMod, bMod);
	}
	else {
		cMod += Rand::randFloat(-0.1f, 0.1f);
		boundFloat(cMod, true);
		mColor = Color(cMod, cMod, cMod);
	}
	
	// update order if needed
	if(ordered) {
	}
	else {
		mRadius += Rand::randFloat(-0.5f, 0.5f);
		boundFloat(mRadius, false);
	}

	// update mark if needed
	if(marked) {
		mColor = Color(1.0f, 0.0f, 0.0f);
	}
	else {
	}
}

void Particle::draw() {
	gl::color(mColor);
	gl::drawSolidCircle(mLoc, mRadius);
}

void Particle::boundFloat(float i, bool c) {
	if(i <= 0.0f) i = 0.0f;
	else if(c && i >= 1.0f) i = 1.0f;
	else if(!c && i >= 5.0f) i = 5.0f;
}

/*
 grayscale random
 greyscale random-marked
 greyscale ordered
 greyscale ordered-marked
 color random
 color ordered
 
 - color switch
 - random switch
 - marked switch
*/