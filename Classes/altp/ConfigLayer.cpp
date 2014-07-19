//
//  ConfigLayer.cpp
//  GMFramework
//
//  Created by langtujava on 4/26/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "ConfigLayer.h"

#include "utils/WidgetUtils.h"

using namespace ui;



bool ConfigLayer::init()



{
    if ( !ModalLayer::init() )
    {
        return false;
    }
    
    background = Scale9Sprite::createWithSpriteFrameName("box_ket_qua.png");
    
    onClose([&](){
        background->runAction(
                              Sequence::create(
                                               FadeTo::create(.09, 0x00),
                                               CallFunc::create([this]() {
                                  
                                  this->removeFromParentAndCleanup(true);
                                  
                                          UserDefault::getInstance()->setIntegerForKey(sound::EFFECT_SOUND, GameManager::getInstance()->effectMusicPercen);
                                   UserDefault::getInstance()->setIntegerForKey(sound::BACKGROUND_SOUND, GameManager::getInstance()->backgroundMusicPercen);
                                  
                              }),
                                               null
                                               )
                              );
        

    });
    
    onShow([&](){
        background->setPosition(VisibleRect::center());
        background-> setScale(.5);
        this->setVisible(true);
        background->setOpacity(0);
        background->runAction(FadeIn::create(0.2));
        background->runAction(EaseElasticOut::create(ScaleTo::create(.6, 1),.7));
    });
    
    background->setInsetLeft(32);
    background->setInsetRight(32);
    float with =VisibleRect::getVisibleRect().size.width<400?VisibleRect::getVisibleRect().size.width-20:400;
    background->setContentSize(Size(with,background->getContentSize().height+50));
    
    
    
    auto buttonClose = WidgetUtils::createTTFButton(" Đóng ", [=](){
        this->emitClose();
    });
    
    buttonClose->setPosition(Point(background->getContentSize().width/2,0));
    background->addChild(buttonClose);
 //   string text= Configuration::getInstance()->getValue("game").asString();
 
    TTFConfig ttfConfig("fonts/arial.ttf", TEXT_FONT_SIZE, GlyphCollection::DYNAMIC);

    auto label = Label::createWithTTF(ttfConfig, "Nhạc nền");
    
    label->setWidth(with-64);
    label->setPosition(Point(background->getContentSize().width/2,background->getContentSize().height/2+50));
    label->setAnchorPoint(Point::ANCHOR_MIDDLE);
    
    background->addChild(label);
    
    
    // Create the slider
    ui::Slider* slider = ui::Slider::create();
    slider->loadBarTexture("sliderTrack.png");
    slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    slider->loadProgressBarTexture("sliderProgress.png");
    slider->setPosition(label->getPosition()-Point(0,20));
    
    slider->addEventListenerSlider(this, sliderpercentchangedselector(ConfigLayer::sliderEvent));
    
    background->addChild(slider);
    
   // percen1=UserDefault::getInstance()->getIntegerForKey(sound::BACKGROUND_SOUND);
    slider->setPercent(GameManager::getInstance()->backgroundMusicPercen);
    
    
    
    label = Label::createWithTTF(ttfConfig, "Hiệu ứng");
    
    label->setWidth(with-64);
    label->setPosition(Point(background->getContentSize().width/2,background->getContentSize().height/2-10));
    label->setAnchorPoint(Point::ANCHOR_MIDDLE);
    
    background->addChild(label);
    
    
    // Create the slider
   auto slider2 = ui::Slider::create();
    slider2->loadBarTexture("sliderTrack.png");
    slider2->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    slider2->loadProgressBarTexture("sliderProgress.png");
    slider2->setPosition(label->getPosition()-Point(0,20));
    
    slider2->addEventListenerSlider(this, sliderpercentchangedselector(ConfigLayer::sliderEvent2));
    
    background->addChild(slider2);
    //percen2=UserDefault::getInstance()->getIntegerForKey(sound::EFFECT_SOUND);
    
    slider2->setPercent(GameManager::getInstance()->effectMusicPercen);

    
   
    this->addChild(background);
   
    return true;
};


void ConfigLayer::sliderEvent(Ref * node,ui::SliderEventType type){
    if(type==SLIDER_PERCENTCHANGED){
        ui::Slider* slider = dynamic_cast<ui::Slider*>(node);
        GameManager::getInstance()->backgroundMusicPercen= slider->getPercent();
        SoundManager::getInstance()->setBgmVolume((float)slider->getPercent()/(float)100);
    }

}

void ConfigLayer::sliderEvent2(Ref * node,ui::SliderEventType type){
    if(type==SLIDER_PERCENTCHANGED){
        ui::Slider* slider = dynamic_cast<ui::Slider*>(node);
        GameManager::getInstance()->effectMusicPercen=slider->getPercent();
        SoundManager::getInstance()->setVolume((float)slider->getPercent()/100);
    }
    
}





