//
//  MultiSceneLayer.cpp
//  ColorfulGroovy-x
//
//  Created by t.k on 13/03/29.
//
//

#include "MultiSceneLayer.h"


using namespace cocos2d;
//using namespace CocosDenshion;

static MultiSceneLayer *multiSceneLayerInstance;
static GameModeTag sGameModeTag;

MultiSceneLayer* MultiSceneLayer::sharedLayer()
{
    return multiSceneLayerInstance;
}

GameLayer* MultiSceneLayer::gameLayer()
{
    cocos2d::CCNode* layer = this->getChildByTag(GameLayerTag);
    return (GameLayer *)layer;
}

ControlLayer* MultiSceneLayer::controlLayer()
{
    cocos2d::CCNode* layer = MultiSceneLayer::sharedLayer()->getChildByTag(ControlLayerTag);
    return (ControlLayer *)layer;
}

CCScene* MultiSceneLayer::scene()
{
    CCScene *scene = CCScene::create();
    MultiSceneLayer *layer = MultiSceneLayer::create();
    scene->addChild(layer);
    return scene;
};

//GameModeTag* gameModeTag()
//{
//   // sGameModeTag = gameModeTag;
//   // CCScene* scene =
//}

bool MultiSceneLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    multiSceneLayerInstance = this;
    
    GameLayer *gameLayer = GameLayer::create();
    this->addChild(gameLayer, 0, GameLayerTag);
    
    ControlLayer *controlLayer = ControlLayer::create();
    this->addChild(controlLayer, 1, ControlLayerTag);
    
    
    return true;
}