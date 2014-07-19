//
//  HelpTelelphone.h
//  GMFramework
//
//  Created by langtujava on 4/29/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__HelpTelelphone__
#define __GMFramework__HelpTelelphone__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"
#include "BaseModalLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class HelpTelelphone : public BaseModalLayer
{
    CC_SYNTHESIZE(int, trueCase, TrueCase);
public:
    
    virtual ~HelpTelelphone() {
        
    }
    
    CREATE_FUNC(HelpTelelphone);
    
    virtual bool init();
    
private:
    Sprite * dienthoai;
    void onResult(float f);
    void close(float f);
};

#endif

/* defined(__GMFramework__HelpTelelphone__) */

