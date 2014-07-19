//
//  ConfigLayer.h
//  GMFramework
//
//  Created by langtujava on 4/26/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__ConfigLayer__
#define __GMFramework__ConfigLayer__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class ConfigLayer : public ModalLayer
{
    
public:
    
    DEFINE_EVENT_EMITTER(Close);
    DEFINE_EVENT_EMITTER(Show);

    virtual ~ConfigLayer() {
       
    }
    
    CREATE_FUNC(ConfigLayer);
    
    virtual bool init();
    
    void sliderEvent(Ref * node,ui::SliderEventType type);
    void sliderEvent2(Ref * node,ui::SliderEventType type);
    
private:
     Scale9Sprite * background;
  
};

#endif 

/* defined(__GMFramework__ConfigLayer__) */

