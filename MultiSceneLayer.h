//
//  MultiSceneLayer.h
//  ColorfulGroovy-x
//
//  Created by t.k on 13/03/29.
//
//

#ifndef __ColorfulGroovy_x__MultiSceneLayer__
#define __ColorfulGroovy_x__MultiSceneLayer__

#include <iostream>
#include "cocos2d.h"
#include "GameLayer.h"
#include "ControlLayer.h"

/* Scene Enumration */
typedef enum {
    GameLayerTag,
    ControlLayerTag
} MultiSceneLayerTag;

/* GameMode Enumration */
typedef enum {
    GameEasyMode,
    GameNormalMode,
    GameHardMode
} GameModeTag;

class MultiSceneLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    static GameModeTag* gameModeTag;
 //   GameModeTag* getGameModeTag();
    void menuCloseCallback(CCObject* pSender);
    
    static MultiSceneLayer* sharedLayer();
    GameLayer* gameLayer();
    ControlLayer* controlLayer();
    
    CREATE_FUNC(MultiSceneLayer);
    
};



#endif /* defined(__ColorfulGroovy_x__MultiSceneLayer__) */
