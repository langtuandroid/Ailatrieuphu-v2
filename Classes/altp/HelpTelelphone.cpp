//
//  HelpTelelphone.cpp
//  GMFramework
//
//  Created by langtujava on 4/29/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "HelpTelelphone.h"

#include "utils/WidgetUtils.h"

bool HelpTelelphone::init()
{
    if(!BaseModalLayer::init("box_ket_qua.png")){
        
        return false;
    }
    
    
    background->setContentSize(Size(200,240));
    background->setPosition(VisibleRect::center());
    
    // them cai telephoen vao giuax;
    
    dienthoai = Sprite::createWithSpriteFrameName("item_dien_thoai.png");
    auto ongnghe = Sprite::createWithSpriteFrameName("item_ong_nghe.png");
    ongnghe->setPosition(Point(dienthoai->getContentSize().width/2,dienthoai->getContentSize().height));
    dienthoai->addChild(ongnghe);
    dienthoai->setPosition(Point(background->getContentSize().width/2,background->getContentSize().height/2));
    
    ongnghe->runAction(Sequence::create(Repeat::create(Sequence::create(RotateTo::create(0.1, 20),RotateTo::create(0.1, -20),RotateTo::create(0.1, 20),RotateTo::create(0.1, 0),DelayTime::create(0.2), NULL), 5),CallFunc::create([this](){
    
        // SHOW KET QUA RA DAY;
        this->onResult(0);
    
    }),NULL));
    
    background->addChild(dienthoai);
    
    buttonClose->setPosition(Point(background->getContentSize().width/2,0));
    
    return true;
}

void HelpTelelphone::onResult(float f){
    dienthoai->removeFromParentAndCleanup(true);
      
    auto spriteLeter = Sprite::createWithSpriteFrame(
                                                     ImageUtils::split("item_dap_an.png", 1, 4).at(getTrueCase()-1));
    spriteLeter->setPosition(Point(background->getContentSize().width / 2, background->getContentSize().height/2));
    background->addChild(spriteLeter);
    
    spriteLeter->setScale(30);
    spriteLeter->setOpacity(0);
    spriteLeter->runAction(ScaleTo::create(0.5,1,1));
    spriteLeter->runAction(Sequence::create(FadeIn::create(.5), NULL));
    
    this->scheduleOnce(schedule_selector(HelpTelelphone::close),5);
}
                       
                       void HelpTelelphone::close(float f){
                           this->emitClose();
                           
                       }
