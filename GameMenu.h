//
//  GameMenu.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/03/30.
//
//

#ifndef __ColorfulTouch_X__GameMenu__
#define __ColorfulTouch_X__GameMenu__

#include <iostream>
#include "cocos2d.h"

class GameMenu : public cocos2d::CCLayer
{
public:
    // ----
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameMenu);
    // ----
    
    /* Back to the Game */
    void backToGame(CCObject* pSender);
    
};

#endif /* defined(__ColorfulTouch_X__GameMenu__) */
