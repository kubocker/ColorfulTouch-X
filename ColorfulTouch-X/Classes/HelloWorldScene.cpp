#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MultiSceneLayer.h"
#include "MultiSceneLayer02.h"
#include "BackParticle.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /* Label */
    CCLabelTTF* pLabel = CCLabelTTF::create("Colorful Touch-x", "Hevetica-BoldOblique", 100);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pLabel->setPosition( ccp(size.width / 2, size.height/2+100) );
    this->addChild(pLabel, 1);
    
    /* Image */
    CCSprite* pSprite = CCSprite::create("space_bg8.jpg");
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    this->addChild(pSprite, 0);
    
    /* Play the Game */
    CCMenuItemFont::setFontName("Hevetica-BoldOblique");
    CCMenuItemFont::setFontSize(50);
    CCMenuItemFont* item = CCMenuItemFont::create("play the game", this, menu_selector(HelloWorld::PlayTheGame));
    CCMenu *menu = CCMenu::menuWithItem(item);
    menu->setPosition(CCPointMake(size.width/2, size.height/2-150));
    CCFadeTo* fadeIn = CCFadeTo::actionWithDuration(1.0f, 127);
    CCFadeTo* fadeOut = CCFadeTo::actionWithDuration(1.0f, 255);
    CCSequence *pulseSequence = CCSequence::actionOneTwo(fadeIn, fadeOut);
    CCRepeatForever *repeat = CCRepeatForever::actionWithAction(pulseSequence);
    menu->runAction(repeat);
    this->addChild(menu,1);
    
    /* Back Particle */
    BackParticle *backParticle = (BackParticle *)BackParticle::create();
    this->addChild(backParticle);

    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::PlayTheGame(CCObject* pSender)
{
    CCScene* pScene = MultiSceneLayer02::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
    
}