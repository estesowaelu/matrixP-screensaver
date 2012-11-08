//
//  Particle.h
//  matrixP
//
//  Created by Tim Honeywell on 12/11/04.
//
//

#pragma once

#include "cinder/Vector.h"
#include "cinder/Color.h"
#include <vector>

class Particle {
public:
	Particle();
	Particle(ci::Vec2f);

	void update(bool colored, bool marked, bool ordered);
	void draw();
	void boundFloat(float& i, bool colored);
	
	ci::Vec2f	mLoc;
	
	float		mRadius;
	float		cMod;
	float		rMod;
	float		gMod;
	float		bMod;

	ci::Color	mColor;

};
