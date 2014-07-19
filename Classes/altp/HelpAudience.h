//
//  HelpAudience.h
//  GMFramework
//
//  Created by langtujava on 4/29/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__HelpAudience__
#define __GMFramework__HelpAudience__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"
#include "BaseModalLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class Cols;
class HelpAudience : public BaseModalLayer
{
    CC_SYNTHESIZE(int, trueCase, TrueCase);
public:
    
    virtual ~HelpAudience() {
        CC_SAFE_DELETE(cols);
        
    }
    
    CREATE_FUNC(HelpAudience);
    
    virtual bool init();
    
private:
     std::vector<Cols*> * cols;
     void onResult(float f);
    void close(float f);
};

#endif 

/* defined(__GMFramework__HelpAudience__) */

