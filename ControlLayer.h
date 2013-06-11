//
//  ControlLayer.h
//  ColorfulGroovy-x
//
//  Created by t.k on 13/03/29.
//
//

#ifndef __ColorfulGroovy_x__ControlLayer__
#define __ColorfulGroovy_x__ControlLayer__

#include "cocos2d.h"
#include <iostream>


class ControlLayer:public cocos2d::CCLayer
{
private:
    cocos2d::CCMotionStreak *streak;
    cocos2d::CCParticleSystemQuad *particle;
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    /* Remove Touch Dispatcher */
    void removeTouchDispatcher();
    
    /* Touch Setting */
    virtual bool ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    
    CREATE_FUNC(ControlLayer);
};




#endif /* defined(__ColorfulGroovy_x__ControlLayer__) */
