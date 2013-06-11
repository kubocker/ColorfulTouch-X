//
//  GameLayer02.cpp
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/13.
//
//

#include "GameLayer02.h"
#include "MultiSceneLayer02.h"
#include "SimpleAudioEngine.h"
#include "GameMenu.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

CCScene* GameLayer02::scene()
{
    CCScene *scene = CCScene::create();
    GameLayer02 *layer = GameLayer02::create();
    scene->addChild(layer);
    return scene;
};

bool GameLayer02::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
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
    
    /* BGM */
    
    /* Time Label */
    test_count = 10;
    CCString *label = CCString::createWithFormat("%d", test_count);
    labelofTime = CCLabelTTF::create("Time: ","Marker Felt",50);
    timeLabel = CCLabelTTF::create((char*)label, "Marker Felt", 50);
    timeLabel->setString(label->getCString());
    this->schedule(schedule_selector(GameLayer02::CountDownSchedule),1.0f);
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

    
    /* Shape */
    shapeAppearDuration = 0.7f;
   // shapeArray->CCArray::createWithCapacity(0);
    shapeArray->initWithCapacity(0);
    CCDelayTime *delayActionShape = CCDelayTime::create(shapeAppearDuration);
    CCCallFunc *callSelectorActionShape = CCCallFunc::create(this, callfunc_selector(GameLayer02::setNewShape));
    this->runAction(CCSequence::create(delayActionShape, callSelectorActionShape, NULL));
    
   return true;
}

/* CountDownSchedule */
void GameLayer02::CountDownSchedule(cocos2d::CCTime delta)
{
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Time Label Size */
    CCString *time = CCString::createWithFormat("%d",--test_count);
    timeLabel->setString(time->getCString());
    timeLabel->setPosition(ccp(winSize.width/2+80, winSize.height/2+280));
    
    /* CountDown */
    if (test_count <= 3 && test_count > 1) {
        timeLabel->setColor(ccc3(200, 1, 1));
    }else if (test_count == 0){
        this->unscheduleUpdate();
        this->unscheduleAllSelectors();
        this->removeChild(shapeSprite, true);
    //    this->removeAllChildrenWithCleanup(true);
    //    this->removeFromParentAndCleanup(true);
        this->scheduleOnce(schedule_selector(GameLayer02::makeTransition),1.5f);
        
    }
}

/* AddScore */
void GameLayer02::addScore()
{
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Score Setting */
    CCString *score01 = CCString::createWithFormat("%d",++score);
    scoreLabel->setString(score01->getCString());
    scoreLabel->setPosition(ccp(winSize.width/2+420, winSize.height/2+280));
    scoreLabel->setColor(ccc3(255, 255, 0));
    
}

/* makeTransiosn */
void GameLayer02::makeTransition()
{
    /* UnScheduleUpdate */
    this->unscheduleUpdate();
    this->unscheduleAllSelectors();
    
    /* Important Node */
    CCArray* children = this->getChildren();
    CCObject* child;
    CCARRAY_FOREACH(children, child){
        CCSprite *sprite = (CCSprite*)child;
        sprite->stopAllActions();
    }
    /* Page Turn */
    CCScene* menuScene = GameMenu::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.8f, menuScene));
    
}


/* Shape */
void GameLayer02::setNewShape(cocos2d::CCNode* pSender)
{
    int shapeNumber = arc4random()%5;
    
    switch (shapeNumber) {
        case 0:
            shapeSprite = CCSprite::create("C6.png");
            shapeSprite->setTag(Circle02);
            break;
        case 1:
            shapeSprite = CCSprite::create("C2.png");
            shapeSprite->setTag(Star02);
            break;
        case 2:
            shapeSprite = CCSprite::create("C1.png");
            shapeSprite->setTag(Triangle02);
            break;
        case 3:
            shapeSprite = CCSprite::create("C4.png");
            shapeSprite->setTag(Square02);
            break;
        case 4:
            shapeSprite = CCSprite::create("C5.png");
            shapeSprite->setTag(Snow02);
            break;
    }
    shapeArray->create();
    shapeNumber = arc4random()%5;
    shapeSprite->setColor(ccc3(CCRANDOM_0_1()*255, CCRANDOM_0_1()*255, CCRANDOM_0_1()*255));
    shapeSprite->setPosition(ccp(this->getContentSize().width*CCRANDOM_0_1(), this->getContentSize().height*CCRANDOM_0_1()));
    shapeArray->addObject(shapeSprite);
    this->addChild(shapeSprite,20);
    
    /* ScheduleUpdate */
    CCDelayTime *delayAction = CCDelayTime::create(shapeAppearDuration);
    CCCallFunc *callSelectorAction = CCCallFunc::create(this, callfunc_selector(GameLayer02::setNewShape));
    this->runAction(CCSequence::create(delayAction, callSelectorAction, NULL));
    
    
}

/* Game Particle */
void GameLayer02::GameParticle(cocos2d::CCTouch* touch)
{
    /* Touch Setting */
    CCPoint touchPoint = touch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    
    /* Random */
    int particleNumber = arc4random()%5;
    
    switch (particleNumber) {
        case 0:
            gameParticle = CCParticleFlower::create();
            gameParticle->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
            gameParticle->setPosition(touchPoint);
            gameParticle->setDuration(0.4f);
            gameParticle->setLife(0.2f);
            gameParticle->autorelease();
            this->removeAndupObject(gameParticle);
            gameParticle->setTag(Flower02);
       //     SimpleAudioEngine::sharedEngine()->playEffect(<#const char *pszFilePath#>);
            break;
        case 1:
            gameParticle = CCParticleSun::create();
            gameParticle->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
            gameParticle->setPosition(touchPoint);
            gameParticle->setDuration(0.4f);
            gameParticle->setLife(0.4f);
            gameParticle->autorelease();
            this->removeAndupObject(gameParticle);
            gameParticle->setTag(Sun02);
            
            break;
        case 2:
            gameParticle = CCParticleFire::create();
            gameParticle->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
            gameParticle->setPosition(touchPoint);
            gameParticle->setDuration(0.4f);
            gameParticle->setLife(0.4f);
            gameParticle->autorelease();
            this->removeAndupObject(gameParticle);
            gameParticle->setTag(Fire02);
            
            break;
        case 3:
            gameParticle = CCParticleGalaxy::create();
            gameParticle->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
            gameParticle->setPosition(touchPoint);
            gameParticle->setDuration(0.4f);
            gameParticle->setLife(0.4f);
            gameParticle->autorelease();
            this->removeAndupObject(gameParticle);
            gameParticle->setTag(Galaxy02);
            
            break;
        case 4:
            gameParticle = CCParticleExplosion::create();
            gameParticle->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
            gameParticle->setPosition(touchPoint);
            gameParticle->setDuration(0.4f);
            gameParticle->setLife(0.4f);
            gameParticle->autorelease();
            this->removeAndupObject(gameParticle);
            gameParticle->setTag(Explotion02);
            
            break;
        
    }
    particleNumber = arc4random()%5;
    particleArray = CCArray::create();
    particleArray->addObject(gameParticle);
    this->addChild(gameParticle);
}

/* Tap */
void GameLayer02::doTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    // Log
    CCLOG("doTouch is working");
    
    /* Touch Point */
    CCPoint touchPoint = touch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    
    /* ShapeSprite */
    for (int i = 0; i < shapeArray->count(); i++) {
        
        /* shape Setting */
        CCSprite *shapes = (CCSprite *)shapeArray->objectAtIndex(i);
        
        if (this->containsTouchSprite(shapes, touch)) {
            // Log
            CCLOG("touch Shapes");
            
            /* Particle */
            this->GameParticle(touch);
            
            /* Shake */
         //   this->shake();
            
            /* remove Shapes */
            this->removeAndupObject(shapes);
            
            /* Add Score */
            this->addScore();
            
            /* Delete Shape */
            shapeArray->removeObjectAtIndex(i);
        
            
        } else if (!this->containsTouchSprite(shapes, touch)) {
            
        }
    
    } 
    
}

/* ContainsTouchSprite */
bool GameLayer02::containsTouchSprite(cocos2d::CCSprite* sprite, cocos2d::CCTouch* touch)
{
    /* ShapeSprite */
    float w = sprite->getContentSize().width;
    float h = sprite->getContentSize().height;
    float x = sprite->getPosition().x - w/2;
    float y = sprite->getPosition().y - h/2;
    CCRect rect = CCRectMake(x, y, w, h);
    
    return CCRect::CCRectContainsPoint(rect, this->convertTouchToNodeSpace(touch));
}

/* Shake */
void GameLayer02::shake()
{
    CCShaky3D* action = CCShaky3D::create(2, true, ccg(20, 30), 0.5f);
    CCFiniteTimeAction* reset = CCSequence::create(CCCallFunc::create(this, callfunc_selector(GameLayer02::shake)), NULL);
    this->runAction(CCSequence::create(action, reset, NULL));
}

/* Remove Shapes */
void GameLayer02::removeAndupObject(cocos2d::CCNode* pSender)
{
    pSender->removeFromParentAndCleanup(true);
    return;
}



