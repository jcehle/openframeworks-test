//
//  ParticleController.cpp
//  particle_00
//
//  Created by jc@gumbojuice on 1/19/13.
//
//

#include "ParticleController.h"

ParticleController::ParticleController()
{
    totalParticles = 30;
    poolIndex = 0;
    
    for (int i=0; i<totalParticles; i++)
    {
        Particle* p = new Particle(i);
        pool.push_back(p);
    }
    
    mouseVelocity.x = 0;
    mouseVelocity.y = 0;
    oldMousePos.x = 0;
    oldMousePos.y = 0;
}

void ParticleController::setup()
{
}

void ParticleController::update()
{
    Particle* p;
    ofVec2f velOffset, mousePos, dirTowardsMouse;
    mousePos.x = (float)ofGetMouseX();
    mousePos.y = (float)ofGetMouseY();
    mouseVelocity.x = mousePos.x - oldMousePos.x;
    mouseVelocity.y = mousePos.y - oldMousePos.y;
    oldMousePos.x = mousePos.x;
    oldMousePos.y = mousePos.y;
    

    if(ofGetMousePressed())
    {
        p = getParticleFromPool();
        if( p != NULL)
        {
            p->reset();
            p->addLife(ofRandom(30,75));
            p->position.x = mousePos.x + ofRandom(-15, 15);
            p->position.y = ofGetMouseY() + ofRandom(-15, 15);
            velOffset.x  = ofRandom(-1.0f, 1.0f) * ofRandom(1.0f, 3.0f);
            velOffset.y  = ofRandom(-1.0f, 1.0f) *ofRandom(1.0f, 3.0f);
            p->velocity.x = mouseVelocity.x * 0.25f + velOffset.x;
            p->velocity.y = mouseVelocity.y * 0.25f + velOffset.y;
            active.push_back( p );
        }
    }
    
    vector<Particle*>::iterator pi;
    for(pi = active.begin(); pi != active.end(); )
    {
        if((*pi)->isDead)
        {
            p = *pi;
            pi = active.erase(pi);
            addToMidLife( p );
        }else
        {            
            (*pi)->update();
            ++pi;
        }
    }
    
    for(pi = midLife.begin(); pi != midLife.end(); )
    {
        if((*pi)->isDead)
        {
            p = *pi;
            pi = midLife.erase(pi);
            putParticleInPool(p);
        }else
        {
            p = *pi;
            dirTowardsMouse = mousePos - p->position;
            dirTowardsMouse.normalize();
            p->addNoiseToPosition();
            p->velocity += dirTowardsMouse * 0.25;
            p->update();
            ++pi;
        }
    }
}

void ParticleController::draw()
{
    vector<Particle*>::iterator pi;
    for(pi = active.begin(); pi != active.end(); pi++)
    {
        (*pi)->draw();
    }
    
    for(pi = midLife.begin(); pi != midLife.end(); pi++)
    {
        (*pi)->draw();
    }
}

Particle* ParticleController::getParticleFromPool()
{
    if(pool.size() > 0)
    {
        Particle* p = pool.back();
        pool.pop_back();
        return  p;
    }

    return NULL;
}

void ParticleController::putParticleInPool(Particle* p)
{
    pool.push_back( p );
}

void ParticleController::addToMidLife(Particle* p)
{
     p->addLife(ofRandom(350));
    midLife.push_back( p );
}