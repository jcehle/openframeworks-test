//
//  Particle.cpp
//  particle_00
//
//  Created by jc@gumbojuice on 1/19/13.
//
//

#include "Particle.h"
Particle::Particle(int id)
{
    reset();
    this->id = id;
}

void Particle::setup()
{
    
}

void Particle::update()
{
    age++;
    if(age > lifespan)
    {
        ofLog() << id << " im dead: " << age << " / " << lifespan;
        isDead = true;
        lifeCount++;
    }
    
    position += velocity;
    velocity *= 0.97;
    noiseOffset += 0.01f;
}

void Particle::draw()
{
    if(isDead) return;
    ofSetColor(0);
    ofCircle(position.x, position.y, 3);
}

void Particle::addLife(int lifespan)
{
    this->lifespan = lifespan;
    age = 0;
    isDead = false;
}

void Particle::addNoiseToPosition()
{
    float noiseAmountX = ofMap(ofNoise(noiseOffset.x), 0, 1, -3, 3);
    float noiseAmountY = ofMap(ofNoise(noiseOffset.y), 0, 1, -3, 3);
    
    position.x += noiseAmountX;
    position.y += noiseAmountY;
}

void Particle::reset()
{
    age = 0;
    lifespan = 100;
    isDead = false;
    position.x = 0;
    position.y = 0;
    velocity.x = 0;
    velocity.y = 0;
    noiseOffset.x = ofRandom(10000);
    noiseOffset.y = ofRandom(10000);
}