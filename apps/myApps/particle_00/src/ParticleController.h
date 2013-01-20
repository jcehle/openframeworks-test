//
//  ParticleController.h
//  particle_00
//
//  Created by jc@gumbojuice on 1/19/13.
//
//

#ifndef __particle_00__ParticleController__
#define __particle_00__ParticleController__

#include <iostream>
#include "ofMain.h"
#include "Particle.h"

class ParticleController
{
public:
    ParticleController();
    void setup();
    void update();
    void draw();
    
    int totalParticles;
    int poolIndex;
    vector<Particle*> pool;
    vector<Particle*> active;
    vector<Particle*> midLife;
    
private:
    Particle* getParticleFromPool();
    void addToMidLife(Particle* p);
    void putParticleInPool(Particle* p);
    
    ofVec2f mouseVelocity;
    ofVec2f oldMousePos;
    
};


#endif /* defined(__particle_00__ParticleController__) */
