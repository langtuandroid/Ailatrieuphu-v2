//
//  BaseLayer.cpp
//  GMFramework
//
//  Created by langtujava on 4/29/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "BaseModalLayer.h"
#include "utils/WidgetUtils.h"


BaseModalLayer * BaseModalLayer::create(const string  & bgSprite, float left, float right, float top, float bottom ){
    
    auto baseLayer = new BaseModalLayer();
    if(baseLayer&&baseLayer->init(bgSprite,left,right,top,bottom)){
        baseLayer->autorelease();
        return baseLayer;
    }else{
        delete baseLayer;
        baseLayer=null;
        return null;
    }
}

bool BaseModalLayer::init(const string  & bgSprite, float left, float right, float top, float bottom ){
    if(!ModalLayer::init()){
        
        return false;
    }
    
    background = Scale9Sprite::createWithSpriteFrameName(bgSprite);
    
    background->setInsetLeft(left);
    background->setInsetRight(right);
    background->setInsetTop(top);
    background->setInsetBottom(bottom);
    
    float with =VisibleRect::getVisibleRect().size.width<400?VisibleRect::getVisibleRect().size.width-20:400;
    background->setContentSize(Size(with,background->getContentSize().height));
    this->addChild(background);
    background->setPosition(VisibleRect::center());
    onClose([&](){
        this->close();
        background->runAction(
                              Sequence::create(
                                               FadeTo::create(.09, 0x00),
                                               CallFunc::create([this]() {
                                  this->removeFromParentAndCleanup(true);
                                  
                                 
                              }),
                                               null
                                               )
                              );
    });
    
    onShow([&](){
        this->show();
        background-> setScale(.5);
        this->setVisible(true);
        background->setOpacity(0);
        background->runAction(FadeIn::create(0.2));
        background->runAction(EaseElasticOut::create(ScaleTo::create(.6, 1),.7));
        
    });
    
    buttonClose = WidgetUtils::createTTFButton(" Đóng ", [=](){
        this->emitClose();
    });
    
    buttonClose->setPosition(Point(background->getContentSize().width/2,0));
    background->addChild(buttonClose);
    return true;
    
}


