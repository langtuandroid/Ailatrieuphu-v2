//
//  LoadingScene.h
//  GMFramework
//
//  Created by langtujava on 5/2/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__LoadingScene__
#define __GMFramework__LoadingScene__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"
#include "AppMacros.h"
#include "GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

USING_NS_GMG;

class LoadingScene : public LayerColor
{
public:
    
    virtual ~LoadingScene() {

    }
    void onEnter() override;
    
    CREATE_SCENE_FUNC(LoadingScene);
    
    virtual bool init();
    
    void gotoLoading(float f);
private:
    vector<function<void()>> loaders;
    int countNumber;
    Label* loadingText;
};

#endif 

/* defined(__GMFramework__LoadingScene__) */

