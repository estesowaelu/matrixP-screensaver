//
//  Particle.h
//  matrixP
//
//  Created by Tim Honeywell on 12/11/04.
//
//

#ifndef __matrixP__Particle__
#define __matrixP__Particle__

#pragma once
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include <vector>

class Particle {
public:
	Particle();
	Particle(ci::Vec2f);

	void update(bool, bool, bool);
	void draw();
	void boundFloat(float, bool);
	
	ci::Vec2f	mLoc;
	
	float		mRadius;
	float		cMod;
	float		rMod;
	float		gMod;
	float		bMod;

	ci::Color	mColor;

};

#endif /* defined(__matrixP__Particle__) */
