//
//  ParticleController.h
//  matrixP
//
//  Created by Tim Honeywell on 12/11/04.
//
//

#ifndef __matrixP__ParticleController__
#define __matrixP__ParticleController__

#pragma once
#include "Particle.h"
#include <list>

class ParticleController {
public:
	ParticleController();
	ParticleController(int res);
	void update();
	void draw();
	void addParticles(int amt);
	void addParticle(int xi, int yi, int res);
	void removeParticles(int amt);
	
	std::list<Particle>	mParticles;
	
	int mXRes, mYRes;
};

#endif /* defined(__matrixP__ParticleController__) */
