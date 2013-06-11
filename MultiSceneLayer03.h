//
//  MultiSceneLayer03.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/15.
//
//

#ifndef __ColorfulTouch_X__MultiSceneLayer03__
#define __ColorfulTouch_X__MultiSceneLayer03__

#include <iostream>
#include "cocos-ext.h"
#include "GameLayer03.h"
#include "ControlLayer03.h"

/* Scene Enumration */
typedef enum {
    GameLayerTag03,
    ControlLayerTag03
} MultiSceneLayerTag03;

/* GameMode Enumration */
typedef enum {
    Game03EasyMode,
    Game03NormalMode,
    Game03HardMode
} Game03Mode;

class MultiSceneLayer03 : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(MultiSceneLayer03);

    static MultiSceneLayer03* sharedLayer();
    GameLayer03* gameLayer();
    ControlLayer03* controlLayer();
    
};


#endif /* defined(__ColorfulTouch_X__MultiSceneLayer03__) */
