//
//  ConfirmLayer.cpp
//  GMFramework
//
//  Created by langtujava on 4/21/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "ConfirmLayer.h"
#include "gmg.h"

#include "utils/WidgetUtils.h"
#include "AppMacros.h"


bool ConfirmLayer::init()
{
    if ( !InfoLayer::init() )
    {
        return false;
    }
    
    
    onShow([&](const std::string content, const std::function<void()>& ok,const std::function<void()>& cancle){
        InfoLayer::emitShow(content);
        
        if(ok){
            buttonOK->onPushed(ok);
            buttonOK->onPushed([&](){
                this->emitClose();
            });
        }
        if(cancle){
            buttonClose->onPushed(cancle);
        }
            buttonClose->onPushed([&](){
                 this->emitClose();
            });
        
    });
    buttonClose->removeFromParentAndCleanup(true);
    
    buttonClose = WidgetUtils::createTTFButton("  Thôi  ",Size(90,0),nullptr);
    buttonOK = WidgetUtils::createTTFButton("Đồng ý",Size(90,0),nullptr);
    
    buttonClose->setPosition(Point(background->getContentSize().width/2+buttonClose->getContentSize().width/2,0));
    buttonOK->setPosition(Point(background->getContentSize().width/2-buttonOK->getContentSize().width/2,0));
    background->addChild(buttonClose);
    background->addChild(buttonOK);
    return true;
}
