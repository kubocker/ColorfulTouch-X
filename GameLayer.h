//
//  Game.h
//  ColorfulGroovy-x
//
//  Created by t.k on 13/03/03.
//
//

#ifndef __ColorfulGroovy_x__Game__
#define __ColorfulGroovy_x__Game__
#define callfunc_selector(_SELECTOR) (SEL_CallFunc)(&_SELECTOR)

/* Include */
#include "cocos2d.h"
#include <iostream>


/* Define */
#define STARTING_POINT (1000)
#define SPACE (150)

/* Shape */
typedef enum {
    Circle,
    Star,
    Triangle,
    Square,
    Snow
} Shape;

/* Combo */
typedef enum {
    combo1,
    combo2,
    combo3
} Combooo;

/* Particle */
typedef enum {
    Flower,
    Sun,
    Fire,
    Galaxy,
    Explotion
} Particle;


class GameLayer : public cocos2d::CCLayer
{
private:
    cocos2d::CCParticleSystemQuad *snow;
    
public:
    // ----
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLayer);
    // ----
    
    /* Shape */
   // cocos2d::CCArray *shapeArray = cocos2d::CCArray::create();
    //cocos2d::CCArray * shapeArray = new cocos2d::CCArray;
    cocos2d::CCSprite *shapeSprite;
    float shapeAppearDuration;

    /* Shake */
    cocos2d::CCNode action;
    cocos2d::CCNode reset;
    void shake();
    
    /* Particle */
    cocos2d::CCParticleSystemQuad *gameParticle;
   // cocos2d::CCArray *particleArray;
    
    
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
    
    /* Member Method */
    // Shape
    void setNewShape(CCNode* pSender);
    void ToucShape(cocos2d::CCTouch* touchspace, cocos2d::CCEvent* event);
    // Add Score
    void addScore();
    
    void removeAndUpObject(CCObject *pSender);
    
    /**** SEtting ****/
    void CountDownSchedule(cocos2d::CCTime delta);
    void makeTransition();
    
    
    
    
    
};

#endif /* defined(__ColorfulGroovy_x__Game__) */
