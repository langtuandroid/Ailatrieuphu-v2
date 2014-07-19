//
//  LoginScene.h
//  GMFramework
//
//  Created by langtujava on 5/3/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__LoginScene__
#define __GMFramework__LoginScene__
#include "cocos2d.h"
#include "cocos-ext.h"

#include  "gmg.h"
#include "utils/WidgetUtils.h"

#include "BaseModalLayer.h"

#include "ui/CocosGUI.h"
#include "utils/WidgetUtils.h"
#include "GameManager.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class InputLayer:  public BaseModalLayer,public TextFieldDelegate
{
public:
    
    virtual ~InputLayer() {
     
    }
   
    CREATE_FUNC(InputLayer);

    virtual bool init();
   
    
private:
    ui::TextField * textField;
};

#endif 

/* defined(__GMFramework__LoginScene__) */

