//
//  ControlLayer02.cpp
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/13.
//
//

#include "ControlLayer02.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MultiSceneLayer02.h"
#include "GameLayer02.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* ControlLayer02::scene()
{
    CCScene *scene = CCScene::create();
    ControlLayer02 *layer = ControlLayer02::create();
    scene->addChild(layer);
    return scene;
}

bool ControlLayer02::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    /* Touch Enable */
    this->setTouchEnabled(true);
    //this->setTouchMode(kCCTouchesOneByOne);
     CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Motion Streak */
    streak = CCMotionStreak::create(2, 3, 32, ccGREEN, "C6.png");
    streak->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    this->addChild(streak,20);
    
    CCFiniteTimeAction* action = CCSequence::create(CCTintTo::create(0.2f, 255, 0, 0),
                                                    CCTintTo::create(0.2f, 0, 255, 0),
                                                    CCTintTo::create(0.2f, 0, 0, 255),
                                                    CCTintTo::create(0.2f, 0, 255, 255),
                                                    CCTintTo::create(0.2f, 255, 255, 0),
                                                    CCTintTo::create(0.2f, 255, 0, 255),
                                                    CCTintTo::create(0.2f, 255, 255, 255),
                                                    NULL);
    CCActionInterval *colorAction = CCRepeatForever::create((CCActionInterval *)action);
    streak->runAction(colorAction);
    
    return true;
}

/* Remove Touch Dispatcher */
void ControlLayer02::removeTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeAllDelegates();
}

/* Touch Began */
bool ControlLayer02::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    // Log
    CCLOG("touch Began");
    
    /* Game Touch */
    MultiSceneLayer02::sharedLayer()->gameLayer()->doTouch(touch, event);
    
    return true;
}

/* Touch Moved */
void ControlLayer02::ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    // Log
    CCLog("touch Moved");
    
    /* Touch Setting */
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCPoint touchPoint = pDirector->convertToGL(ptouch->getLocationInView());
    
    /* Move Particle from Touch Point */
    streak->setPosition(touchPoint);
    
}

/* Touch Ended */
void ControlLayer02::ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    // Log
    CCLog("touch Ended");
    
}

/* Touch Canceled */
void ControlLayer02::ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    // Log
    CCLog("touch Canceled");
}