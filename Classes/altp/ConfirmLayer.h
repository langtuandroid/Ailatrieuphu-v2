//
//  ConfirmLayer.h
//  GMFramework
//
//  Created by langtujava on 4/21/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__ConfirmLayer__
#define __GMFramework__ConfirmLayer__


#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"

#include "AppMacros.h"
#include "InfoLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace gmg;

class ConfirmLayer : public InfoLayer
{
    

public:
    
    virtual ~ConfirmLayer() {
      
    }

    
    CREATE_FUNC(ConfirmLayer);
    DEFINE_EVENT_EMITTER_WITH_ARGS3(Show,const std::string & , const std::function<void()>&,const std::function<void()>&);
    
private:
    Button * buttonOK;
    virtual bool init();
};

#endif 

/* defined(__GMFramework__ConfirmLayer__) */

