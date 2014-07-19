//
//  BaseLayer.h
//  GMFramework
//
//  Created by langtujava on 4/29/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__BaseLayer__
#define __GMFramework__BaseLayer__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
using namespace gmg;

class BaseModalLayer : public ModalLayer
{
    CC_SYNTHESIZE(Scale9Sprite*, background, Background);
    CC_SYNTHESIZE(Button*, buttonClose, ButtonClose);
    
public:
    
    virtual ~BaseModalLayer() {

    }
    
    DEFINE_EVENT_EMITTER(Close);
    DEFINE_EVENT_EMITTER(Show);


    static BaseModalLayer * create(const string  & background, float left=32, float right=32, float top=32, float bottom =32);
    
    virtual bool init(const string  & bgSprite, float left=32, float right=32, float top=32, float bottom =32);


};

#endif 

/* defined(__GMFramework__BaseLayer__) */

