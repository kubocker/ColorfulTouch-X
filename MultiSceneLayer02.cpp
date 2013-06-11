//
//  MultiSceneLayer02.cpp
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/13.
//
//

#include "MultiSceneLayer02.h"

using namespace cocos2d;

static MultiSceneLayer02 *multiSceneLayerInstance;

MultiSceneLayer02* MultiSceneLayer02::sharedLayer()
{
    return multiSceneLayerInstance;
}

GameLayer02* MultiSceneLayer02::gameLayer()
{
    cocos2d::CCNode* layer = this->getChildByTag(GameLayerTag02);
    return (GameLayer02 *) layer;
}

ControlLayer02* MultiSceneLayer02::controlLayer()
{
    cocos2d::CCNode* layer = MultiSceneLayer02::sharedLayer()->getChildByTag(ControlLayerTag02);
    return (ControlLayer02 *) layer;
}

CCScene* MultiSceneLayer02::scene()
{
    CCScene *scene = CCScene::create();
    MultiSceneLayer02 *layer = MultiSceneLayer02::create();
    scene->addChild(layer);
    return scene;
}

bool MultiSceneLayer02::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    multiSceneLayerInstance = this;
    
    GameLayer02 *gameLayer = GameLayer02::create();
    this->addChild(gameLayer, 0, GameLayerTag02);
    
    ControlLayer02 *controlLayer = ControlLayer02::create();
    this->addChild(controlLayer, 1, ControlLayerTag02);
    
    return true;
}
