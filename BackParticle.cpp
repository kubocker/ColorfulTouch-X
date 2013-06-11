//
//  BackParticle.cpp
//  ColorfulTouch-X
//
//  Created by t.k on 13/03/30.
//
//

#include "BackParticle.h"

using namespace cocos2d;

bool BackParticle::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Particle */
    backParticle = CCParticleExplosion::create();
    backParticle->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
    backParticle->setPosition(ccp(winSize.width/2, winSize.height/2));
    backParticle->setLife(10);
    backParticle->setStartSpin(180);
    backParticle->setDuration(-1);
    
    this->addChild(backParticle);
    
    
    return true;
}