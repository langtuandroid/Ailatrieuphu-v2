//
//  WidgetUtils.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/09/18.
//
//

#include "WidgetUtils.h"
#include "gmg.h"
#include "cocos-ext.h"
#include "../GameManager.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace gmg;

namespace gmg {

const string WidgetUtils::defaultFontName = "fonts/arial.ttf";

const Size WidgetUtils::defaultSize = Size(0,0);
    
 Node* WidgetUtils::createRoundedRect(const Size& size)
    {
     
        Scale9Sprite* sprite = Scale9Sprite::createWithSpriteFrameName("btn_background.png");
        sprite->setInsetLeft(30);
        sprite->setInsetRight(30);
        
        sprite->setContentSize(Size(size.width,sprite->getContentSize().height));
        
        
        return sprite;
    }

Node* WidgetUtils::createTTFSprite(const Size & size, const string text,
                                   const string fontName, int textSize)
{
    const float margin = 6;

    auto labelTTF =  Label::createWithTTF(text,fontName,textSize);
    labelTTF->setTag(1);
    Size labelSize = labelTTF->getContentSize();
    labelSize.width += margin * 4;
    labelSize.height += margin * 2;

     Node* sprite = createRoundedRect(size.width==0?labelSize:size);
     sprite->setAnchorPoint(Point::ANCHOR_MIDDLE);
     labelTTF->setPosition(Point(sprite->getContentSize().width/2,sprite->getContentSize().height/2));

     sprite->addChild(labelTTF);
    
    return sprite;
}

Button* WidgetUtils::createTTFButton(const string text, const string fontName,
                                     int textSize,const Size &size,
                                     const std::function<void()>& callback)
{
    //const string lightColor = String::createWithFormat("%s_light", color)->getCString();
    Node* normalSprite = createTTFSprite(size, text, fontName, textSize);
    Node* touchingSprite = createTTFSprite(size, text, fontName, textSize);
   // touchingSprite->setAnchorPoint(Point::ANCHOR_MIDDLE);
    touchingSprite->setScale(normalSprite->getScale()*0.95);

    Button* button = Button::createWithSprite(normalSprite, touchingSprite);
   
    
    if (callback) {
        button->onPushed(callback);
    }
    return button;
}

Button* WidgetUtils::createGlowButton(const string sprite,
                                      const std::function<void()>& callback)
{

    auto buttonSprite = GlowButtonSprite::createWithSpriteFrameName(sprite);
    Button* button = Button::create(buttonSprite);
    if (callback) {
        button->offAllPushed();
        button->onPushed(callback);
    }
    return button;
}
    
    Button* WidgetUtils::createToggleButton(Vector<SpriteFrame*> sprites, const std::function<void()>& callback){
      auto btn= ToggleButton::create();
        auto btns=ImageUtils::createButtonSprite(sprites);
        btn->addItem(btns);
        btn->setContentSize(btns.at(0)->getContentSize());
        //btn->setAnchorPoint(Point::ANCHOR_MIDDLE);

        if(callback){
            btn->offAllChanged();
            btn->onChanged(callback);
        }
        return btn;
    }
    
    
    Button* WidgetUtils::createToggleButton(const std::string & sprites, const std::function<void()>& callback){
        return createToggleButton(ImageUtils::split(sprites,1,2),callback);
    }
    
}
