//
//  InfoLayer.h
//  GMFramework
//
//  Created by langtujava on 4/17/14.
//
//

#ifndef __GMFramework__InfoLayer__
#define __GMFramework__InfoLayer__


#include "AppMacros.h"

#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"
#include "BaseModalLayer.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace gmg;
using namespace std;


class InfoLayer : public BaseModalLayer
{
    CC_SYNTHESIZE(Label*, _text, Text);
public:
    
    virtual ~InfoLayer() {
       
          }
    
    CREATE_FUNC(InfoLayer);
    DEFINE_EVENT_EMITTER_WITH_ARG(Show,const std::string &);
   virtual bool init();
   
private:
    
};

#endif /* defined(__GMFramework__InfoLayer__) */
