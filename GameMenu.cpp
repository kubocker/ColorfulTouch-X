//
//  GameMenu.cpp
//  ColorfulTouch-X
//
//  Created by t.k on 13/03/30.
//
//

#include "GameMenu.h"
#include "HelloWorldScene.h"


using namespace cocos2d;

CCScene* GameMenu::scene()
{
    CCScene *scene = CCScene::create();
    GameMenu *layer = GameMenu::create();
    scene->addChild(layer);
    return scene;
}

bool GameMenu::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    /* Device Size */
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /* Background */
    CCSprite *bg = CCSprite::create("space_bg8.jpg");
    bg->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(bg);
    
    /* Shadow */
    CCLayerColor *shadow = CCLayerColor::create (ccc4(140, 140, 140, 180));

    /* Label */
    CCLabelTTF *label = CCLabelTTF::create("Game Menu", "Helvetica", 64);
    label->setPosition(ccp(winSize.width/2, winSize.height/2+100));
    
    /* Label */
    CCLabelTTF *label02 = CCLabelTTF::create("~ thank you for playing game ~", "Helvetica", 50);
    label02->setPosition(ccp(winSize.width/2, winSize.height/2+50));
    
    /* Display Score */
 
    /* back to the game */
    CCMenuItemFont::setFontName("Hevetica-BoldOblique");
    CCMenuItemFont::setFontSize(50);
    CCMenuItemFont* item = CCMenuItemFont::create("back", this, menu_selector(GameMenu::backToGame));
    CCMenu *menu = CCMenu::menuWithItem(item);
    menu->setPosition(CCPointMake(winSize.width/2, winSize.height-420));
    CCFadeTo* fadeIn = CCFadeTo::actionWithDuration(1.0f, 127);
    CCFadeTo* fadeOut = CCFadeTo::actionWithDuration(1.0f, 255);
    CCSequence *pulseSequence = CCSequence::actionOneTwo(fadeIn, fadeOut);
    CCRepeatForever *repeat = CCRepeatForever::actionWithAction(pulseSequence);
    menu->runAction(repeat);
    
    /* Add */
    this->addChild(shadow,20);
    this->addChild(label,20);
    this->addChild(label02,20);
    this->addChild(menu,20);
    
    return true;
};

void GameMenu::backToGame(CCObject* pSender)
{
    CCScene* pScene = HelloWorld::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}
