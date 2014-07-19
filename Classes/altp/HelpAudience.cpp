//
//  HelpAudience.cpp
//  GMFramework
//
//  Created by langtujava on 4/29/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "HelpAudience.h"
#include "utils/WidgetUtils.h"
class Cols: public Node{
    
public:
    virtual ~Cols() {}
    CREATE_FUNC(Cols);
    
    Scale9Sprite * c;
    virtual bool init(){
        c= Scale9Sprite::createWithSpriteFrameName("item_cot_do_thi.png");
        c->setInsetTop(15);
        c->setInsetBottom(15);
        
        c->setContentSize(Size(c->getContentSize().width,0));
        c->setVisible(false);
        c->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
        addChild(c);
        
        return true;
    }
    
public:
   
    static Cols * create(int index){
        Cols * c = Cols::create();
        auto spriteLeter = Sprite::createWithSpriteFrame(
                                                         ImageUtils::split("item_ten_cot_do_thi.png", 1, 4).at(index));
        spriteLeter->setPosition(Point(-c->getContentSize().width / 2, 0));
        c->setContentSize(spriteLeter->getContentSize());
        c->addChild(spriteLeter);
        return c;
    }
 
};


bool HelpAudience::init()
{
    if(!BaseModalLayer::init("box_do_thi.png")){
        
        return false;
    }

    
    background->setContentSize(Size(240,300));
    background->setPosition(VisibleRect::center());
   
    
    // vec cac cot do thi len;
    cols =new vector<Cols*>();
    
    cols->push_back(Cols::create(0));
    cols->push_back(Cols::create(1));
    cols->push_back(Cols::create(2));
    cols->push_back(Cols::create(3));
    
    for(int i=0;i<4;i++){
        auto c = cols->at(i);
        c->setPosition(Point(40 + i*50, 50));
        background->addChild(c);
    }
    
    buttonClose->setPosition(Point(background->getContentSize().width/2,0));
    
    this->scheduleOnce(schedule_selector(HelpAudience::onResult), 2);
                       
    // supper init head
    return true;
}
                       
 void HelpAudience::onResult(float t){
      for(int i=0;i<4;i++){
          auto c = cols->at(i);
          c->c->setVisible(true);
          if(i==getTrueCase()-1){
              c->c->runAction(PreferredSizeTo::create(1, Size(c->c->getContentSize().width,200)));
             // c->c->setContentSize(Size(c->c->getContentSize().width,200));
          }else{
               c->c->runAction(PreferredSizeTo::create(1, Size(c->c->getContentSize().width,random(50, 180))));
             // c->c->setContentSize(Size(c->c->getContentSize().width,random(50, 180)));
          }
      }
     
       this->scheduleOnce(schedule_selector(HelpAudience::close),15);
     
  }



void HelpAudience::close(float f){
    this->emitClose();
    
}
