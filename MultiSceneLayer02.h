//
//  MultiSceneLayer02.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/13.
//
//

#ifndef __ColorfulTouch_X__MultiSceneLayer02__
#define __ColorfulTouch_X__MultiSceneLayer02__

#include <iostream>
#include "cocos2d.h"
#include "GameLayer02.h"
#include "ControlLayer02.h"


/* Scene Enumration */
typedef enum {
    GameLayerTag02,
    ControlLayerTag02,
} MultiSceneLayerTag02;

/* GameMode Enumration */
typedef enum {
    Game02EasyMode,
    Game02NormalMode,
    Game02HardMode
} Game02Mode;

class MultiSceneLayer02 : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    
    static MultiSceneLayer02* sharedLayer();
    GameLayer02* gameLayer();
    ControlLayer02* controlLayer();

    CREATE_FUNC(MultiSceneLayer02);
};


#endif /* defined(__ColorfulTouch_X__MultiSceneLayer02__) */
