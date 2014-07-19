//
//  LoginScene.cpp
//  GMFramework
//
//  Created by langtujava on 5/3/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "InputLayer.h"

bool InputLayer::init() {

  if (!BaseModalLayer::init("box_ket_qua.png")) {
    return false;
  }

  TTFConfig ttfConfig("fonts/arial.ttf", TEXT_FONT_SIZE,
                      GlyphCollection::DYNAMIC);

  auto label = Label::createWithTTF(ttfConfig, "Nhập tên");
  label->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
  label->setPosition(Point(20, background->getContentSize().height / 2 + 20));
  getBackground()->addChild(label);

  // ve o nhap ten vao day
  textField =
      cocos2d::ui::TextField::create(" <input > ", "fonts/arial.ttf", TEXT_FONT_SIZE+2);
  textField->setAnchorPoint(Point::ANCHOR_MIDDLE);
  textField->setPosition(
      Point(background->getContentSize().width/2, background->getContentSize().height / 2 - 5));
  getBackground()->addChild(textField);

  getBackground()->setPosition(getBackground()->getPosition() + Point(0, 60));

  onClose([&]() {
      string value = textField->getStringValue();
      GameManager::getInstance()->username=value;
      UserDefault::getInstance()->setStringForKey("USERNAME", value);
      
    background->runAction(Sequence::create(
        FadeTo::create(.09, 0x00),
        CallFunc::create([this]() {
         this->removeFromParentAndCleanup(true);
        }),
        null));
      
     
  });

  // supper init head
  return true;
}
