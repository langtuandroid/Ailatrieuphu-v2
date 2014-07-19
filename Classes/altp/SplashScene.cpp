//
//  SplashScene.cpp
//  GMFramework
//
//  Created by langtujava on 4/13/14.
//
//

#include "SplashScene.h"
#include "GameManager.h"
#include "utils/WidgetUtils.h"
#include "gmg.h"

USING_NS_CC;
using namespace gmg;


void SplashScene::onEnter(){
    Layer::onEnter();
	// add background to current scene
	auto logo = Sprite::create("logo.png");
	Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Point origin = Director::getInstance()->getVisibleOrigin();
	logo->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
	this->addChild(logo);
    logo->setScale(30);
    logo->setOpacity(0);
    logo->runAction(ScaleTo::create(0.5,0.5, 0.5));
    logo->runAction(Sequence::create(FadeIn::create(.5),DelayTime::create(1),
                                     FadeOut::create(.5),
                      CallFuncN::create(CC_CALLBACK_1(SplashScene::loadingCallBack,this)), NULL));
  
}

void SplashScene::loadingCallBack(Node *texture){
    // load sound;
   
   GameManager::getInstance()->emitShowLoadingScene();
}
