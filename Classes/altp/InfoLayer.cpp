//
//  InfoLayer.cpp
//  GMFramework
//
//  Created by langtujava on 4/17/14.
//
//

#include "InfoLayer.h"
#include "gmg.h"
#include "utils/WidgetUtils.h"

#include "AppMacros.h"

USING_NS_CC_EXT;

bool InfoLayer::init()
{
    if ( !BaseModalLayer::init("box_dialog.png",32,32,0,0) )
    {
        return false;
    }
    
    
    onShow([&](const std::string & content){
        BaseModalLayer::emitShow();
        
        getText()->setString(content);

    });
  
   
    float with =VisibleRect::getVisibleRect().size.width<400?VisibleRect::getVisibleRect().size.width-20:400;
    getBackground()->setContentSize(Size(with,background->getContentSize().height));
   
    
    TTFConfig ttfConfig("fonts/arial.ttf", TEXT_FONT_SIZE, GlyphCollection::DYNAMIC);

        auto label = Label::createWithTTF(ttfConfig, "hoge hoge");

    label->setWidth(with-64);
    
    label->setPosition(Point(getBackground()->getContentSize().width/2,getBackground()->getContentSize().height/2));
    label->setAnchorPoint(Point::ANCHOR_MIDDLE);
    label->retain();
    
    getBackground()->addChild(label);
   
    this->setText(label);

    return true;
};