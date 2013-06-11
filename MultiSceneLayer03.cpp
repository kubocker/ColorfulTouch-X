//
//  MultiSceneLayer03.cpp
//  ColorfulTouch-X
//
//  Created by t.k on 13/04/15.
//
//

#include "MultiSceneLayer03.h"

using namespace cocos2d;

static MultiSceneLayer03 *multiSceneLayerInstance;

MultiSceneLayer03* MultiSceneLayer03::sharedLayer()
{
    return multiSceneLayerInstance;
}

GameLayer03* MultiSceneLayer03::gameLayer()
{
    cocos2d::CCNode* layer = this->getChildByTag(GameLayerTag03);
    return (GameLayer03 *) layer;
}

ControlLayer03* MultiSceneLayer03::controlLayer()
{
    cocos2d::CCNode* layer = MultiSceneLayer03::sharedLayer()->getChildByTag(ControlLayerTag03);
    return (ControlLayer03 *) layer;
}

CCScene* MultiSceneLayer03::scene()
{
    CCScene *scene = CCScene::create();
    MultiSceneLayer03 *layer = MultiSceneLayer03::create();
    scene->addChild(layer);
    return scene;
}

bool MultiSceneLayer03::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    multiSceneLayerInstance = this;
    
    GameLayer03 *gameLayer = GameLayer03::create();
    this->addChild(gameLayer, 0, GameLayerTag03);
    
    ControlLayer03 *controlLayer = ControlLayer03::create();
    this->addChild(controlLayer, 1, ControlLayerTag03);
    
    return true;
}
