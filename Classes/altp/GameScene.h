//
//  MenuScene.h
//  GMFramework
//
//  Created by langtujava on 4/13/14.
//
//

#ifndef __GMFramework__MenuScene__
#define __GMFramework__MenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "gmg.h"

#include "AppMacros.h"
#include "BaseScene.h"

#include "utils/WidgetUtils.h"

#include "GameManager.h"
#include "InfoLayer.h"
#include "GameLayer.h"



USING_NS_CC;
USING_NS_CC_EXT;
USING_NS_GMG;


class GameScene : public BaseScene
{
   
    
public:
    
    CREATE_SCENE_FUNC(GameScene);
    
    DEFINE_EVENT_EMITTER(GameState);
    DEFINE_EVENT_EMITTER(MenuState);


    
    virtual  bool buildComponent();
    virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    
    void onBackAction();

     Sprite * logo;
    
private:

    
    Vector<Button*> buttons;
    GameLayer * gameLayer;
   
    
};

#endif /* defined(__GMFramework__SplashScene__) *///#endif /* defined(__GMFramework__MenuScene__) */
