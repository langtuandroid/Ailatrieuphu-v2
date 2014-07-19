//
//  SplashScene.h
//  GMFramework
//
//  Created by langtujava on 4/13/14.
//
//

#ifndef __GMFramework__SplashScene__
#define __GMFramework__SplashScene__

#include <iostream>
#include "AppMacros.h"
USING_NS_CC;

class SplashScene : public Layer
{
public:

    
    void onEnter() override;
    
    void load(float dt);

    CREATE_SCENE_FUNC(SplashScene);
    
    
private:
   	/**
     * Called when the texture (exp. atlas.png) is loading finish, will call this function
     * this function finish build all the SpritFrame by using AtlasLoader
     */
	void loadingCallBack(Node *texture);
    
};

#endif /* defined(__GMFramework__SplashScene__) */
