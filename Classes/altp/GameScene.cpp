//
//  GameScene.cpp
//  GMFramework
//
//  Created by langtujava on 4/13/14.
//
//

#include "GameScene.h"


#include "cocos-ext.h"
#include "ConfigLayer.h"
USING_NS_CC_EXT;
USING_NS_CC;




// on "init" you need to initialize your instance
bool GameScene::buildComponent() {
    this->keyBackClicked();
    // LOGO
    
    logo = Sprite::createWithSpriteFrameName("logo_center.png");
    addChild(logo);
    PositionerRelativeUtils::alignTopEdgesAndCenter( this, logo, 0, -logo->getContentSize().height / 2);
    auto logo2 = Sprite::createWithSpriteFrameName("center_toy.png");
    logo2->setAnchorPoint(Point::ANCHOR_MIDDLE);
    logo2->cocos2d::Node::setPosition(Point(logo->getContentSize().width/2,logo->getContentSize().height/2));
    logo->addChild(logo2);
    logo2->runAction(RepeatForever::create(RotateBy::create(6, 360)));
    logo->runAction(SlideIn::top(1));
    
    auto logo3=Sprite::createWithSpriteFrameName("logo.png");
    logo3->setAnchorPoint(Point::ANCHOR_MIDDLE);
    logo3->cocos2d::Node::setPosition(logo2->getPosition());
    logo->addChild(logo3);
 
    // CLOSE
    /*
    auto closeItem = Button::createWithSpriteFrameName(
                                                       "CloseNormal.png", "CloseSelected.png",
                                                       [this]() {
                                                           this->onBackAction();
                                                           
                                                       });
    closeItem->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
    closeItem->setPosition(VisibleRect::rightBottom()+Point(closeItem->getContentSize().width/2,closeItem->getContentSize().height/2));
    this->addChild(closeItem);
    
     */
   
    
    // answet;
    

    
    onMenuState([&](){
        setState(State::MENU_STATE);
        if(gameLayer)
            gameLayer->emitQuit();
        SoundManager::getInstance()->resumeBgm();
        PositionerRelativeUtils::alignTopEdgesAndCenter( this, logo, 0, -logo->getContentSize().height / 2);
        logo->runAction(SlideIn::top(.2));
       
         int x =0;
        for(auto btn:buttons){
            btn->setPosition(Point(VisibleRect::center().x, 100 + x* (btn->getContentSize().height+5)));
            x++;
     
            if(x%2==0)
                btn->runAction(SlideIn::left(.3));
            else
                btn->runAction(SlideIn::right(.3));
        }
        
    });
        
    onGameState([this](){
        SoundManager::getInstance()->pauseBgm();
        this->play("ready.mp3");
        setState(State::PLAY_STATE);
        // start Game;
        logo->runAction(MoveBy::create(.2, Point(0,logo->getContentSize().height/2 +50)));
  
        
        
        int x =0;
         for(auto btn:buttons){
            if(x%2==0)
                btn->runAction(SlideOut::left(.3));
            else
                btn->runAction(SlideOut::right(.3));
            x++;
        }
        
        gameLayer=GameLayer::create();
        gameLayer->setGameScene(this);
        addChild(gameLayer);
  
        
          this->gameLayer->emitStart(1);
        
        //auto moneyTable =  MoneyTableLayer::create();
        //moneyTable->gameLayer=gameLayer;
        //this->addChild(moneyTable);
        
 
    });
    
    
    
    Size size(200,0);
    
    auto button = WidgetUtils::createTTFButton("Bắt đầu", BUTTON_FONT_SIZE,size,[&]() {
        this->showConfirmDialog("Bạn đã hiểu luật chơi và sẵn sàng trở thành triệu phú ?.", [&](){
            this->emitGameState();
        });
        
    });
    
   
    buttons.pushBack(button);
  
    button = WidgetUtils::createTTFButton("Xếp hạng",BUTTON_FONT_SIZE, size,[&]() {
       // auto highScore = HighScoreLayer::create();
        //this->addChild(highScore,INT16_MAX);
        //highScore->emitShow();
        
        // test admod
     
        
        this->showInfoDialog("Chức năng này hiện đang hoàn thiện.");
        
     });
    buttons.pushBack(button);
    
    button = WidgetUtils::createTTFButton("Hướng dẫn",BUTTON_FONT_SIZE,size,[&]() {
       this->play("luatchoi.mp3");

        this->showInfoDialog("Lần lượt trả lời 15 câu hỏi, mỗi câu trong 1 phút để trở thành triệu phú .");
                this->hideAdmob();
    });
    
    buttons.pushBack(button);
  
    button = WidgetUtils::createTTFButton("Cấu hình",BUTTON_FONT_SIZE,size, [&]() {
        auto configLayer = ConfigLayer::create();
        this->addChild(configLayer,INT16_MAX);
        configLayer->emitShow();
    });

    buttons.pushBack(button);
    buttons.reverse();
    
    int x =0;

    for(auto btn:buttons){
       
        btn->setPosition(Point(VisibleRect::center().x, 100 + x* (button->getContentSize().height+5)));
        x++;
        this->addChild(btn);
        
        if(x%2==0)
            btn->runAction(SlideIn::left(.8));
        else
            btn->runAction(SlideIn::right(.8));
    }
    
    
    setState(State::MENU_STATE);
    
    
    if(GameManager::getInstance()->username.empty()){
        auto inputLayer = InputLayer::create();
        addChild(inputLayer);
        inputLayer->emitShow();
    }
    this->showAdmob(ProtocolAds::AdsPos::kPosBottom);
   
  return true;
}

void GameScene::onBackAction(){
    if(getState()==State::PLAY_STATE){
        showConfirmDialog("Bạn chắc chắn muốn dừng  trò chơi ?", [&](){
            emitMenuState();
        });
    }else if(getState()==State::MENU_STATE){
        showConfirmDialog("Bạn chắc chắn muốn thoát khỏi trò chơi ?", [&](){
            GameManager::getInstance()->emitClose();
            this->hideAdmob();

        });
    }

}
void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, Event *event){
      if(keyCode==cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE||keyCode==cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE){
        onBackAction();
      }
}

