//
//  Game.cpp
//  ColorfulGroovy-x
//
//  Created by t.k on 13/03/29.
//
//

#include <sstream>
#include <vector>
#include "SimpleAudioEngine.h"
#include "GameLayer.h"
#include "HelloWorldScene.h"
#include "MultiSceneLayer.h"
#include "GameMenu.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

void test_particle(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

CCScene* GameLayer::scene()
{
    CCScene *scene = CCScene::create();
    GameLayer *layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
};

bool GameLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // -------------------------------------------------
    /* Background */
    CCSprite *bg = CCSprite::create("space_bg8.jpg");
    bg->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(bg);
    
    /* BackParticle */
    snow = CCParticleRain::create();
    snow->setTexture(CCTextureCache::sharedTextureCache()->addImage("space_bg10.jpg"));
    snow->setLife(10);
    snow->setStartSpin(180);
    snow->setDuration(-1);
    this->addChild(snow,20);
    
    /* Shape */
    this->shapeAppearDuration = 1.0f;
 //   shapeArray->CCArray::createWithCapacity(0);
    //shapeArray->initWithCapacity(0);
    CCDelayTime *delayActionShape = CCDelayTime::create(shapeAppearDuration);
    CCCallFunc *callSelectorActionShape = CCCallFunc::create(this, callfunc_selector(GameLayer::setNewShape));
    this->runAction(CCSequence::create(delayActionShape, callSelectorActionShape, NULL));
    
    /* Time Label */
    test_count = 10;
    CCString *label = CCString::createWithFormat("%d", test_count);
    labelofTime = CCLabelTTF::create("Time: ","Marker Felt",50);
    timeLabel = CCLabelTTF::create((char*)label, "Marker Felt", 50);
    timeLabel->setString(label->getCString());
    this->schedule(schedule_selector(GameLayer::CountDownSchedule),1.0f);
    this->unscheduleUpdate();
    
    /* Score Label */
    score = 0;
    CCString *label02 = CCString::createWithFormat("%d", score);
    labelofScore = CCLabelTTF::create("Score: ", "Marker Felt", 50);
    scoreLabel = CCLabelTTF::create((char *)label02, "Marker Felt", 50);
    scoreLabel->setString(label02->getCString());
    scoreLabel->setColor(ccc3(255, 255, 0));
    
    /* Label Setting */
    labelofTime->setPosition(ccp(winSize.width/2, winSize.height/2+280));
    labelofScore->setPosition(ccp(winSize.width/2+350, winSize.height/2+280));
    timeLabel->setPosition(ccp(winSize.width/2+80, winSize.height/2+280));
    scoreLabel->setPosition(ccp(winSize.width/2+420, winSize.height/2+280));
    
    /* Add */
    this->addChild(labelofTime,50);
    this->addChild(labelofScore,50);
    this->addChild(timeLabel,50);
    this->addChild(scoreLabel,50);
    
    
    /* ScheduleUpdate */
    this->scheduleUpdate();


    return true;
}

/**** Game Setting ****/
void GameLayer::CountDownSchedule(cocos2d::CCTime delta)
{
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Time Label Setting */
    CCString *time = CCString::createWithFormat("%d",--test_count);
    timeLabel->setString(time->getCString());
    timeLabel->setPosition(ccp(winSize.width/2+80, winSize.height/2+280));
    
    if (test_count <= 3 && test_count > 1) {
        timeLabel->setColor(ccc3(200, 1, 1));
    }else if (test_count == 0){
        this->unscheduleUpdate();
        this->unscheduleAllSelectors();
       // this->removeChild(shapeSprite, true);
        this->scheduleOnce(schedule_selector(GameLayer::makeTransition),1.5f);

    }
}

void GameLayer::makeTransition()
{
    /* UnScheduleUpdate */
    this->unscheduleUpdate();
    this->unscheduleAllSelectors();
  //  MultiSceneLayer::sharedLayer()->controlLayer()->removeTouchDispatcher();
    
    /* Import Node */
    CCArray* children = this->getChildren();
    CCObject* child;
    CCARRAY_FOREACH(children, child){
        CCSprite *sprite = (CCSprite*)child;
        sprite->stopAllActions();
    }
    
    /* Page Turn */
   // CCScene* menuScene = GameMenu::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.8f, GameMenu::scene()));
    
    
}

/* Remove Object */



/* Set New Shape */
void GameLayer::setNewShape(cocos2d::CCNode* pSender)
{
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    int shapeNumber = arc4random()%5;
    
    switch (shapeNumber) {
        case 0:
            shapeSprite = CCSprite::create("Ring3.png");
            shapeSprite->setTag(Circle);
            break;
        case 1:
            shapeSprite = CCSprite::create("Ring4.png");
            shapeSprite->setTag(Star);
            break;
        case 2:
            shapeSprite = CCSprite::create("Ring5.png");
            shapeSprite->setTag(Triangle);
            break;
        case 3:
            shapeSprite = CCSprite::create("Ring6.png");
            shapeSprite->setTag(Square);
            break;
        case 4:
            shapeSprite = CCSprite::create("Ring7.png");
            shapeSprite->setTag(Snow);
            break;
    }
    shapeSprite->setColor(ccc3(CCRANDOM_0_1()*255, CCRANDOM_0_1()*255, CCRANDOM_0_1()*255));
    shapeSprite->setPosition(ccp(this->getContentSize().width*CCRANDOM_0_1(), this->getContentSize().height*CCRANDOM_0_1()));

    /* FadeIn & FadeOut */
    CCFadeIn *fadeIn = CCFadeIn::create(0.2f);
    shapeSprite->runAction(fadeIn);
    CCDelayTime *delay = CCDelayTime::create(0.9f);
    CCActionInterval *reverse = fadeIn->reverse();
    shapeSprite->runAction(CCSequence::create(fadeIn, delay, reverse, NULL));
    
    this->addChild(shapeSprite,20);
    
    /* PerformSelector */
    CCDelayTime *delayAction = CCDelayTime::create(shapeAppearDuration);
    CCCallFunc *callSelectorAction = CCCallFunc::create(this, callfunc_selector(GameLayer::setNewShape));
    this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
};

void GameLayer::ToucShape(cocos2d::CCTouch* touchspace , cocos2d::CCEvent* event)
{
    // Log
    CCLog("TouchShape is working");
    
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Touch Setting */
    CCPoint touchPoint = touchspace->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    CCPoint yourtouch = this->convertTouchToNodeSpace(touchspace);
    
    /* shapeSprite */
    shapeSprite->create();
    float w = shapeSprite->getContentSize().width;
    float h = shapeSprite->getContentSize().height;
    float x = shapeSprite->getPosition().x - w/2;
    float y = shapeSprite->getPosition().y - h/2;
    CCRect rect = CCRectMake(x, y, w, h);
    
    /* Touch Check */
    if (CCRect::CCRectContainsPoint(rect, touchPoint)) {
  
        // Log
        CCLOG("you touch the shape");
        
        /* Touch Particle */
        CCParticleSystemQuad *particle_touch = CCParticleExplosion::create();
        particle_touch->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
        particle_touch->setPosition(touchPoint);
        particle_touch->setLife(0.2f);
        particle_touch->setStartSpin(180);
        particle_touch->autorelease();
        this->addChild(particle_touch,1000);
        
        /* Score */
        this->addScore();
        
    }else if (!CCRect::CCRectContainsPoint(rect, touchPoint)) {
        // Log
        CCLOG("you couldnot touch the shape");
        
        /* Touch Particle */
        CCTexture2D* test_texture = CCTextureCache::sharedTextureCache()->addImage("C4.png");
        CCParticleSystemQuad *particle_touch = CCParticleExplosion::create();
        particle_touch->setTexture(test_texture);
        particle_touch->setPosition(touchPoint);
        particle_touch->setLife(0.2f);
        particle_touch->setStartSpin(180);
        particle_touch->autorelease();
        this->addChild(particle_touch,1000);
        
        /* Shake */
       // this->shake();
    }
}

/* Add Score */
void GameLayer::addScore()
{
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Score Setting */
    CCString *score01 = CCString::createWithFormat("%d", ++score);
    scoreLabel->setString(score01->getCString());
    scoreLabel->setPosition(ccp(winSize.width/2+420, winSize.height/2+280));
    scoreLabel->setColor(ccc3(255, 255, 0));
    
}

/* Shake */
void GameLayer::shake()
{
    CCShaky3D* action = CCShaky3D::create(2, true, ccg(20, 30), 0.5f);
    CCFiniteTimeAction* reset = CCSequence::create(CCCallFunc::create(this, callfunc_selector(GameLayer::shake)), NULL);
    this->runAction(CCSequence::create(action, reset, NULL));
}





