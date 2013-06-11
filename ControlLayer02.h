//
//  ControlLayer02.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/13.
//
//

#ifndef __ColorfulTouch_X__ControlLayer02__
#define __ColorfulTouch_X__ControlLayer02__

#include <iostream>
#include "cocos2d.h"

class ControlLayer02 : public cocos2d::CCLayer
{
private:
    cocos2d::CCMotionStreak *streak;
    cocos2d::CCParticleSystemQuad *particle;
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(ControlLayer02);
    
    /* Touch Setting */
    virtual bool ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    
    /* Remove Touch Dispatcher */
    void removeTouchDispatcher();

    
};

#endif /* defined(__ColorfulTouch_X__ControlLayer02__) */
