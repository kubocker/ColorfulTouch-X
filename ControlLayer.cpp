//
//  ControlLayer.cpp
//  ColorfulGroovy-x
//
//  Created by t.k on 13/03/29.
//
//
#include "HelloWorldScene.h"
#include "ControlLayer.h"
#include "SimpleAudioEngine.h"
#include "MultiSceneLayer.h"
#include "GameLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* ControlLayer::scene()
{
    CCScene *scene = CCScene::create();
    ControlLayer *layer = ControlLayer::create();
    scene->addChild(layer);
    return scene;
    
}

bool ControlLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    /* Touch Enable */
    this->setTouchEnabled(true);
    // this->setTouchMode(kCCTouchesOneByOne);
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
};

/* Remove Touch Dispatcher */
void ControlLayer::removeTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeAllDelegates();
}


/* Touch Began */
bool ControlLayer::ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    
    // Log
    CCLog("touch Began");
    
    MultiSceneLayer::sharedLayer()->gameLayer()->ToucShape(ptouch, pEvent);
    
    return true;
}

/* Touch Moved */
void ControlLayer::ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    // Log
    CCLog("touch Moved");
    
   
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCPoint touchPoint = pDirector->convertToGL(ptouch->getLocationInView());
    
    // タップ位置へパーティクルを移動
    streak->setPosition(touchPoint);
    
}

/* Touch Ended */
void ControlLayer::ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    // Log
    CCLog("touch Ended");
    
}

/* Touch Canceled */
void ControlLayer::ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    // Log
    CCLog("touch Canceled");
}

