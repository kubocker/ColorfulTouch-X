//
//  GameLayer02.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/13.
//
//

#ifndef __ColorfulTouch_X__GameLayer02__
#define __ColorfulTouch_X__GameLayer02__

#include <iostream>
#include "cocos2d.h"

/* Shape */
typedef enum {
    Circle02,
    Star02,
    Triangle02,
    Square02,
    Snow02
} Shape02;

/* Particle */
typedef enum {
    Flower02,
    Sun02,
    Fire02,
    Galaxy02,
    Explotion02
} Particle02;


class GameLayer02 : public cocos2d::CCLayer
{
private:
    cocos2d::CCParticleSystemQuad *snow;
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLayer02);
    
    /* Shape */
    //cocos2d::CCArray *shapeArray = cocos2d::CCArray::create();
    cocos2d::CCArray *shapeArray = new cocos2d::CCArray;
    //cocos2d::CCArray *shapeArray;
    cocos2d::CCSprite *shapeSprite;
    float shapeAppearDuration;
    
    /* Shake */
    cocos2d::CCNode action;
    cocos2d::CCNode reset;
    
    /* Particle */
    cocos2d::CCParticleSystemQuad *gameParticle;
    cocos2d::CCArray *particleArray;
    
    /* Label & Score */
    cocos2d::CCTime *totalTime;
    int continous;
    int score = 0;
    cocos2d::CCLabelTTF *labelofScore;
    cocos2d::CCLabelTTF *labelofTime;
    cocos2d::CCLabelTTF *scoreLabel;
    cocos2d::CCLabelTTF *timeLabel;
    cocos2d::CCInteger count = 120;
    int test_count = 120;
    
    /* Method */
    // Shape
    void setNewShape(CCNode* pSender);
    void TouchShape(cocos2d::CCTouch* touchspace, cocos2d::CCEvent* event);
    void doTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    // Particle
    void GameParticle(cocos2d::CCTouch* touch);
    // Add Score
    void addScore();
    // Shake
    void shake();
    // Game Setting
    bool containsTouchSprite(cocos2d::CCSprite* sprite, cocos2d::CCTouch* touch);
    void CountDownSchedule(cocos2d::CCTime delta);
    void makeTransition();
    void removeAndupObject(cocos2d::CCNode* pSender);
};



#endif /* defined(__ColorfulTouch_X__GameLayer02__) */
