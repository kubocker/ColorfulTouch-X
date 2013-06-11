//
//  GameLayer03.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/15.
//
//

#ifndef __ColorfulTouch_X__GameLayer03__
#define __ColorfulTouch_X__GameLayer03__

#include <iostream>
#include "cocos2d.h"

/* Shape */
typedef enum {
    Circle03,
    Star03,
    Triangle03,
    Square03,
    Snow03
} Shape03;

/* Particle */
typedef enum {
    Flower03,
    Sun03,
    Fire03,
    Galaxy03,
    Explotion03
} Particle03;

class GameLayer03 : public cocos2d::CCLayer
{
private:
    cocos2d::CCParticleSystemQuad *snow;
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLayer03);
    
};

#endif /* defined(__ColorfulTouch_X__GameLayer03__) */
