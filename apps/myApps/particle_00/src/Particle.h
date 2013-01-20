
//
//  Particle.h
//  particle_00
//
//  Created by jc@gumbojuice on 1/19/13.
//
//

#ifndef __particle_00__Particle__
#define __particle_00__Particle__

#include <iostream>
#include "ofMain.h"

class Particle
{
public:
    Particle(int id);
    void setup();
    void update();
    void draw();
    void reset();
    void addLife(int lifespan);
    void addNoiseToPosition();

    ofVec2f position;
    ofVec2f velocity;
    ofVec2f noiseOffset;
    
    int age;
    int lifespan;
    bool isDead;
    int id;
    int lifeCount;



};

#endif /* defined(__particle_00__Particle__) */
