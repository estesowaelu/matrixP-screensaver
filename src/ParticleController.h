//
//  ParticleController.h
//  matrixP
//
//  Created by Tim Honeywell on 12/11/04.
//
//

#pragma once

#include "Particle.h"
#include <list>

class ParticleController {
public:
	ParticleController();
	ParticleController(int res);
	void update(bool colored, bool marked, bool ordered);
	void draw();
	void addParticle(int xi, int yi, int res);
	
	std::list<Particle>	mParticles;
	
	int mXRes;
	int mYRes;
};
