//
//  GameManager.cpp
//  GMFramework
//
//  Created by langtujava on 4/14/14.
//
//

#include "GameManager.h"


#include "gmg.h"

#include "SimpleAudioEngine.h"
#include "SplashScene.h"
#include "GameScene.h"
#include "utils/WidgetUtils.h"
#include "LoadingScene.h"

#include <fstream>


USING_NS_CC;
using namespace CocosDenshion;
using namespace gmg;

//template class VKBaseManager<Config>;

namespace gmg {
    
    
    
    
	void GameManager::setup() {
		// close this application
        
		onClose([&]() {
			Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
            MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
            return;
#endif
            
            Director::getInstance()->end();
            
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
#endif
            
		});
        
        
        onShowLoadingScene([&](){
            auto scene = LoadingScene::createScene();
            TransitionScene * transition = TransitionFade::create(.5, scene);
            Director::getInstance()->replaceScene(transition);
        });
        
         
        onShowMenuScene([&](){
            auto scene = GameScene::createScene();
            TransitionScene * transition = TransitionFade::create(.5, scene);
            Director::getInstance()->replaceScene(transition);
        });
    }
    
    
    void GameManager::initDisplay() {
		// initialize director
		auto director = Director::getInstance();
		auto glview = director->getOpenGLView();
        
        
        if(!glview){
            glview = GLView::create("MyGame");
            director->setOpenGLView(glview);
        }
        
        // Set the design resolution
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
        // a bug in DirectX 11 level9-x on the device prevents ResolutionPolicy::NO_BORDER from working correctly
        glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
#else
        glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
#endif
        
        Size frameSize = glview->getFrameSize();
        
        vector<string> searchPath;
        
        searchPath.push_back("images/common");
        searchPath.push_back("fonts");
        searchPath.push_back("sounds");
        searchPath.push_back("sounds/altp");
         searchPath.push_back("sounds/altp/play");
        searchPath.push_back("configs");
        // In this demo, we select resource according to the frame's height.
        // If the resource size is different from design resolution size, you need to set contentScaleFactor.
        // We use the ratio of resource's height to the height of design resolution,
        // this can make sure that the resource's height could fit for the height of design resolution.
        
        // if the frame's height is larger than the height of medium resource size, select large resource.
        if (frameSize.height > mediumResource.size.height)
        {
            searchPath.push_back(largeResource.directory);
            
            director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width))
            ;
                   }
        // if the frame's height is larger than the height of small resource size, select medium resource.
        else if (frameSize.height > smallResource.size.height)
        {
            searchPath.push_back(mediumResource.directory);
            
            director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
            
                  }
        // if the frame's height is smaller than the height of medium resource size, select small resource.
        else
        {
            searchPath.push_back(smallResource.directory);
            
            director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
            
           

        }
        
        // set searching path
        FileUtils::getInstance()->setSearchPaths(searchPath);
      
    
   
        
        // turn on display FPS
		//director->setDisplayStats(true);
		
		// set FPS. the default value is 1.0/60 if you don't call this
		//director->setAnimationInterval(1.0 / 60);

	}
	
	void GameManager::startGame() {
        auto director = Director::getInstance();
        auto splash = SplashScene::createScene();
        director->runWithScene(splash);
        
	}

    
    


}