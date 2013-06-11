//
//  BackParticle.h
//  ColorfulTouch-X
//
//  Created by t.k on 13/03/30.
//
//

#ifndef __ColorfulTouch_X__BackParticle__
#define __ColorfulTouch_X__BackParticle__

#include <iostream>
#include "cocos2d.h"

class BackParticle : public cocos2d::CCLayer
{
private:
    cocos2d::CCParticleSystemQuad *backParticle;
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(BackParticle);
};

#endif /* defined(__ColorfulTouch_X__BackParticle__) */
