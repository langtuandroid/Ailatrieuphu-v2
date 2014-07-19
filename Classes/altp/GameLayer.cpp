//
//  GameLayer.cpp
//  GMFramework
//
//  Created by langtujava on 4/19/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "GameLayer.h"
#include "GameScene.h"
class AnswersSprite : public ToggleButton {

  CC_SYNTHESIZE(Label *, content, Content);
   CC_SYNTHESIZE(string , leter, Leter);
    CC_SYNTHESIZE(string , leterLower, LeterLower);

public:
  virtual ~AnswersSprite() {}

  CREATE_FUNC(AnswersSprite);
  virtual void btDetouchedInside() override;
  
  virtual bool init();

  static AnswersSprite *create(int index,const string & leter,const string &leterLower);
  void setClickListerner(ClickListerner *click);
  int caseIndex;

private:
    ClickListerner *clickListerner;
    Vector<SpriteFrame*> list;
};

void AnswersSprite::btDetouchedInside() {
  ToggleButton::btDetouchedInside();
  if (clickListerner)
    clickListerner->onClick(this);
  // call sound;
}

void AnswersSprite::setClickListerner(ClickListerner *click) {
  this->clickListerner = click;
}

AnswersSprite *AnswersSprite::create(int index, const string & leter,const string & leterLower) {
  auto a = AnswersSprite::create();
    if(a&&a->init()){
  a->caseIndex = index+1;
  auto spriteLeter = Sprite::createWithSpriteFrame(
      ImageUtils::split("item_ten_cot_do_thi.png", 1, 4).at(index));
  spriteLeter->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
  // spriteLeter->setContentSize(Size(50,50));
  spriteLeter->setPosition(Point(-a->getContentSize().width / 2, 0));
  a->addChild(spriteLeter);
        a->leter=leter;
        a->leterLower=leterLower;
      
        
    }else{
        CC_SAFE_DELETE(a);
    }
  return a;
}

bool AnswersSprite::init() {
  ToggleButton::init();

  // setAnchorPoint(Point::ANCHOR_MIDDLE);

  list = ImageUtils::split("box_tra_loi.png", 3, 1);
  for (auto a : list) {
    auto aa = Scale9Sprite::createWithSpriteFrame(a);
    aa->setInsetRight(40);
    aa->setInsetLeft(40);
    aa->setContentSize(Size(gmg::LayoutUtils::visibleSize().width - 50,
                            aa->getContentSize().height));
    setContentSize(Size(gmg::LayoutUtils::visibleSize().width - 50,
                        aa->getContentSize().height));
    addItemWithSprite(aa);
  }

  auto label = Label::createWithTTF("", "fonts/arial.ttf", TEXT_FONT_SIZE);
  // label->setAnchorPoint(Point::ANCHOR_MIDDLE);
  label->setWidth(getContentSize().width - 20);
  label->setVerticalAlignment(TextVAlignment::CENTER);
  label->setHorizontalAlignment(TextHAlignment::LEFT);
  label->setPosition(Point(40, 0));
  addChild(label);
  setContent(label);

    return true;
}

class TimeCountSprite : public Node {
public:
  CC_SYNTHESIZE(Label *, content, Content);

  virtual ~TimeCountSprite() {}

  CREATE_FUNC(TimeCountSprite);

  virtual bool init();

  void updateTime(int time);
};

bool TimeCountSprite::init() {
  // supper init head
  auto background = Sprite::createWithSpriteFrameName("box_dem_thoi_gian.png");
  this->addChild(background);
  this->setContentSize(background->getContentSize());
  auto label =
      Label::createWithTTF("0", "fonts/Marker Felt.ttf", TIME_FONT_SIZE);
  // label->setAnchorPoint(Point::ANCHOR_MIDDLE);
  label->setVerticalAlignment(TextVAlignment::CENTER);
  label->setHorizontalAlignment(TextHAlignment::CENTER);
  label->setPosition(Point(0, 0));
  addChild(label);
  setContent(label);
  return true;
}

void TimeCountSprite::updateTime(int time) {
  if (time < 0) {
    return;
  }
  content->setString(StringUtils::format("%i", time));
  content->setPosition(Point(0, 0));
}

class BoxAndLabelSprite : public Node {
  CC_SYNTHESIZE(Label *, content, Content);

public:
  virtual ~BoxAndLabelSprite() {}

  CREATE_FUNC(BoxAndLabelSprite);

  virtual bool init();
};

bool BoxAndLabelSprite::init() {
  auto aa = Scale9Sprite::createWithSpriteFrameName("box_so_cau_hoi.png");
  aa->setInsetRight(20);
  aa->setInsetLeft(20);
  aa->setContentSize(Size(90, aa->getContentSize().height));
  setContentSize(aa->getContentSize());
  addChild(aa);

  auto label = Label::createWithTTF("", "fonts/arial.ttf", TEXT_FONT_SIZE);
  label->setWidth(getContentSize().width - 20);
  label->setVerticalAlignment(TextVAlignment::CENTER);
  label->setHorizontalAlignment(TextHAlignment::LEFT);
  label->setPosition(Point(0, 0));
  addChild(label);
  setContent(label);
  return true;
}

class QuestionSprite : public Node {
  CC_SYNTHESIZE(Label *, content, Content);

public:
  virtual ~QuestionSprite() {}

  CREATE_FUNC(QuestionSprite);

  virtual bool init();
};

bool QuestionSprite::init() {

  // them cai label vao;

  auto question = Scale9Sprite::createWithSpriteFrameName("btn_cau_hoi.png");
  question->setInsetRight(40);
  question->setInsetLeft(40);
  question->setContentSize(Size(gmg::LayoutUtils::visibleSize().width - 10,
                                question->getContentSize().height));
  addChild(question);

  auto label = Label::createWithTTF("", "fonts/arial.ttf", TEXT_FONT_SIZE);
  label->setAnchorPoint(Point::ANCHOR_MIDDLE);
  label->setMaxLineWidth(question->getContentSize().width - 20);
  label->setPosition(Point(question->getContentSize().width / 2,
                           question->getContentSize().height / 2));
  question->addChild(label);
  setContent(label);

  return true;
}

void GameLayer::setControllHelp(bool b) {
  for (auto bb : helpButtons) {
    bb->setVisible(b);
    bb->setEnabled(b);
    if (bb && b) {
      bb->setScale(0);
      bb->runAction(EaseElasticOut::create(ScaleTo::create(1, 1), .5));
    }
  }
  questionNumberSprite->setVisible(b);
  moneySprite->setVisible(b);
}

void GameLayer::setEnable(bool b) {
  for (auto a : lists) {
    a->setEnabled(b);
  }
}

void GameLayer::onClick(AnswersSprite *ref) {
  for (auto a : lists) {
    if (a != ref) {
      a->setCurrentIndex(0);
    }
  }
  isSelected = true;
    currentSelect=ref;
    
    gameScene->play("ans_"+ref->getLeterLower()+".mp3");
    
    gameScene->showConfirmDialog("Phương án "+ref->getLeter()+" là phương án cuối cùng của bạn", [this](){
        // pause
        isScheduleOn=false;
        isCountdownBegin=false;
        
        for(auto t:lists)
        {
            t->setEnabled(false);
           // t->stopAllActions();
        }
        for(auto tt:helpButtons){
            tt->setEnabled(false);
        }
        gameScene->play(random(100)>50?"ans_now1.mp3":"ans_now2.mp3");
        
        this->scheduleOnce(schedule_selector(GameLayer::result), 2);
        
    },[this](){
        currentSelect->setCurrentIndex(0);
    });
}

void GameLayer::reset() {
  for (auto a : lists) {
    a->setCurrentIndex(0);
  }
  isSelected = false;
}

bool GameLayer::init() {
  if (!Layer::init()) {
    return false;
  }

  lists.push_back(AnswersSprite::create(3,"D","d"));
  lists.push_back(AnswersSprite::create(2,"C","c"));
  lists.push_back(AnswersSprite::create(1,"B","b"));
  lists.push_back(AnswersSprite::create(0,"A","a"));

  int x = 0;

  for (auto a : lists) {
    a->setPosition(
        Point(VisibleRect::center().x, 90 + x * (a->getContentSize().height)));
    addChild(a);
    x++;
    a->setScaleY(0);
    a->setEnabled(false);
    a->setClickListerner(this);
  }

  // HELP BUTTON:

  auto help5050 =
      WidgetUtils::createToggleButton("btn_tro_giup_5050.png", [this]() {
        auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(0));

        btn->setCurrentIndex(0);

        gameScene->showConfirmDialog(
            "Bạn đã chắc chắn lựa chọn chức năng trợ giúp bỏ đi 2 câu trả lời sai? .",
            [&]() {
              auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(0));
              btn->setEnabled(false);
              btn->setCurrentIndex(1);
                this->scheduleOnce(schedule_selector(GameLayer::help5050),2);
                gameScene->play("sound5050.mp3");
            },
            [&]() {
              auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(0));
              btn->setEnabled(true);
            });
      });
  addChild(help5050);

  help5050->setAnchorPoint(Point::ANCHOR_MIDDLE);
  help5050->setPosition(VisibleRect::leftTop() +
                        Point(help5050->getContentSize().width, 0));

  auto helpExpress =
      WidgetUtils::createToggleButton("btn_tro_giup_chuyen_gia.png", [this]() {
        auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(1));

        btn->setCurrentIndex(0);

        gameScene->showConfirmDialog(
            "Bạn đã chắc chắn lựa chọn chức năng trợ giúp đổi câu hỏi ? .",
            [&]() {
              if (currentQuestion)
                this->emitStart(atoi(currentQuestion->getLevel().c_str()));
              else
                this->emitStart(1);
              auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(1));
              btn->setEnabled(false);
              btn->setCurrentIndex(1);
              gameScene->play("khan_gia.mp3");

            },
            [&]() {
              auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(1));
              btn->setEnabled(true);
            });
      });
  helpExpress->setAnchorPoint(Point::ANCHOR_MIDDLE);
  addChild(helpExpress);

  helpExpress->setPosition(help5050->getPosition() +
                           Point(help5050->getContentSize().width, 0));
  auto helpVisitor =
      WidgetUtils::createToggleButton("btn_tro_giup_khan_gia.png", [this]() {
        auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(2));

        btn->setCurrentIndex(0);
        gameScene->showConfirmDialog("Bạn đã chắc chắn lựa chọn chức năng trợ "
                                     "giúp thống kê khán giả ? .",
                                     [&]() {
                                         auto helpAudience = HelpAudience::create();
                                         helpAudience->setTrueCase(atoi(currentQuestion->getTrueCase().c_str()));
                                         this->addChild(helpAudience,INT16_MAX);
                                         helpAudience->emitShow();

                                         
                                       auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(2));
                                       btn->setEnabled(false);
                                       btn->setCurrentIndex(1);
                                         gameScene->play("khan_gia.mp3");
                                     },
                                     [&]() {
                                        auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(2));
                                         btn->setEnabled(true);
                                     });
      });

  helpVisitor->setAnchorPoint(Point::ANCHOR_MIDDLE);
  addChild(helpVisitor);

  helpVisitor->setPosition(VisibleRect::rightTop());

  auto helpCall =
      WidgetUtils::createToggleButton("btn_tro_goi_dien.png", [this]() {
        auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(3));
        btn->setCurrentIndex(0);
        gameScene->showConfirmDialog(
            "Bạn đã chắc chắn lựa chọn chức năng trợ giúp gọi điện ? .",
            [&]() {
              auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(3));
              btn->setCurrentIndex(1);
              btn->setEnabled(false);
                
               auto help =  HelpTelelphone::create();
                help->setTrueCase(atoi(currentQuestion->getTrueCase().c_str()));
                this->addChild(help,INT16_MAX);
                help->emitShow();
                gameScene->play("call.mp3");
            },
            [&]() {
              auto btn = dynamic_cast<ToggleButton *>(helpButtons.at(3));
              btn->setEnabled(true);
            });

        ;
      });
  helpCall->setAnchorPoint(Point::ANCHOR_MIDDLE);
  addChild(helpCall);
  helpCall->setPosition(helpVisitor->getPosition() - Point(helpCall->getContentSize().width, 0));

  helpButtons.push_back(help5050);
  helpButtons.push_back(helpExpress);
  helpButtons.push_back(helpVisitor);
  helpButtons.push_back(helpCall);

  // money info;
  questionNumberSprite = BoxAndLabelSprite::create();

  moneySprite = BoxAndLabelSprite::create();
  //

  // time count;
  timeCountSprite = TimeCountSprite::create();

  addChild(timeCountSprite);

  PositionerRelativeUtils::alignTopEdgesAndCenter(
      this, timeCountSprite, 0, -timeCountSprite->getContentSize().height / 2);

  timeCountSprite->setVisible(false);

  // Question

  questionSprite = QuestionSprite::create();
  questionSprite->setPosition(
      Point(VisibleRect::center().x, VisibleRect::center().y + 80));
  addChild(questionSprite);

  questionNumberSprite->setPosition(Point(
      VisibleRect::center().x - 70, questionSprite->getPosition().y + 70));

  moneySprite->setPosition(Point(VisibleRect::center().x + 70,
                                 questionNumberSprite->getPosition().y));

  addChild(questionNumberSprite);
  addChild(moneySprite);

  questionSprite->setScaleY(0);

  setControllHelp(false);
    
    // sec;
    
    onGameOver([&](){
        gameScene->play("out_of_time.mp3");
        isCountdownBegin = false;
        isScheduleOn = false;
        isGameOver = true;
        timeCountSprite->setVisible(false);
        setControllHelp(false);
        questionSprite->setVisible(false);
        
        for(auto t:lists)
        {
            t->setVisible(false);
            t->setEnabled(false);
        }
        this->unscheduleAllSelectors();
        this->unscheduleUpdate();
        
        // reset logo;
       ( dynamic_cast<GameScene*>(gameScene))->logo->runAction(MoveBy::create(.2, Point(0,-50- ( dynamic_cast<GameScene*>(gameScene))->logo->getContentSize().height/2)));
 
        
        if(questionLevel-1>0){
        
        sec = Sprite::createWithSpriteFrameName("sec.png");
        sec->setPosition(VisibleRect::center());
        auto label = Label::createWithTTF("", "fonts/arial.ttf", TITLE_FONT_SIZE);

        label->setVerticalAlignment(TextVAlignment::CENTER);
        label->setHorizontalAlignment(TextHAlignment::LEFT);
        label->setPosition(Point(sec->getContentSize().width/2, sec->getContentSize().height/2));
        label->setString(GameManager::getInstance()->username);
            sec->addChild(label);
            label->setColor(Color3B::BLACK);
        
        label = Label::createWithTTF("", "fonts/arial.ttf", TITLE_FONT_SIZE);
        
        label->setVerticalAlignment(TextVAlignment::CENTER);
        label->setHorizontalAlignment(TextHAlignment::LEFT);
        label->setPosition(Point(sec->getContentSize().width/2, sec->getContentSize().height/2-40));
        label->setColor(Color3B::BLACK);
        sec->addChild(label);
            
        label->setString(Configuration::getInstance()->getValue(itstr(questionLevel)).asString());
        this->addChild(sec);
            
            sec->setScale(0);
            sec->runAction(ScaleTo::create(2, 1));
            sec->runAction(Sequence::create(RotateBy::create(1, 360),CallFunc::create([this](){
               this->scheduleOnce(schedule_selector(GameLayer::gotoMainMenu),10);
            }),null));
  
           
        }
        else{
            this->emitQuit();
            GameManager::getInstance()->emitShowMenuScene();
        }
        
    });

  onStart([&](int level) {
      if(level>15){
          gameScene->showInfoDialog("Chúc mừng bạn đã vượt qua được 15 câu hỏi của chương trình ");
          gameScene->play("win.mp3");
          return;
      }
      
    auto questionManager = VKBaseManager<QuestionEntity>::create();
    currentQuestion =
        questionManager->queryWithOrder(" where level =" + itstr(level) +
                                       " order by random() limit 1")->at(0);
      //questionManager->queryWithOrder(" where id = 10 limit 1")->at(0);
    currentQuestion->retain();
    questionSprite->getContent()->setString(currentQuestion->getQuestion());
    questionSprite->runAction(EaseElasticOut::create(ScaleToY::create(1, 1)));
      
   

    if (currentQuestion) {
      lists.at(3)->getContent()->setString(currentQuestion->getCaseA());
      lists.at(2)->getContent()->setString(currentQuestion->getCaseB());
      lists.at(1)->getContent()->setString(currentQuestion->getCaseC());
      lists.at(0)->getContent()->setString(currentQuestion->getCaseD());
    }
      const string filename =StringUtils::format("ques%d.mp3",level);
      gameScene->play(filename);
  
    
    questionNumberSprite->getContent()->setString("Câu : " + itstr(level));
    moneySprite->getContent()->setString(Configuration::getInstance()->getValue(itstr(level)).asString());
  
    for (auto btn : lists) {
      btn->stopAllActions();
      btn->runAction(ScaleToY::create(.3, 1));
      btn->setEnabled(true);
      btn->setVisible(true);
    }

    setControllHelp(true);
    isCountdownBegin = true;
    isScheduleOn = true;
    isGameOver = false;
    countdownNumber = maxCountDown;
    timeCountSprite->updateTime(countdownNumber);
    timeCountSprite->setVisible(true);
     this->unscheduleUpdate();
     
      this->unscheduleAllSelectors();
    this->scheduleUpdate();

    reset();
  });

  onQuit([&]() {
  
    isCountdownBegin = false;
    isScheduleOn = false;
    isGameOver = true;
    timeCountSprite->setVisible(false);
    setControllHelp(false);
    this->unscheduleAllSelectors();
    this->unscheduleUpdate();
    this->removeFromParentAndCleanup(true);
     
  });
 
  return true;
}

void GameLayer::update(float detal) {
  if (isGameOver) {
    this->unscheduleAllSelectors();
      this->emitGameOver();
  }
  if (isScheduleOn) {
    if (isCountdownBegin) {
      this->schedule(schedule_selector(GameLayer::countdown), 1.0, maxCountDown, 1.0);
    }
  }
}

void GameLayer::countdown(float detal) {
  if (countdownNumber < 0) {
    // finish;
    isScheduleOn = false;
    isCountdownBegin = false;
    isGameOver = true;
  }
  if (isScheduleOn && isCountdownBegin) {
    countdownNumber--;
    timeCountSprite->updateTime(countdownNumber);
  }
}

void GameLayer::help5050(float detal){
    int k=0;
    while(true){
        auto i = random(1,4);
        if(i!=atoi(currentQuestion->getTrueCase().c_str())){
            lists.at(4-i)->setVisible(false);
            lists.at(4-i)->setEnabled(false);
            k++;
        }
        if(k>2){
            break;
        }
    }
    
}
void GameLayer::nextLevel(float f){
    questionLevel++;
    emitStart(questionLevel);
}

void GameLayer::quitGame(float f){
    emitGameOver();
}

void GameLayer::gotoMainMenu(float f){
    this->emitQuit();
    GameManager::getInstance()->emitShowMenuScene();
}
void GameLayer::result(float f){
        if((currentSelect->caseIndex)==atoi(currentQuestion->getTrueCase().c_str())){
            currentSelect->setCurrentIndex(1);
            if(random(100)>50)
                 SoundManager::getInstance()->play("true_fast.mp3");
            
             SoundManager::getInstance()->play(("true_"+currentSelect->getLeterLower()+".mp3").c_str());
            
            scheduleOnce(schedule_selector(GameLayer::nextLevel),3);
        }else {
             SoundManager::getInstance()->play("lose.mp3");
             currentSelect->setCurrentIndex(2);
            for(auto a:lists){
                if(a->caseIndex==atoi(currentQuestion->getTrueCase().c_str())){
                  a->setCurrentIndex(1);
                     SoundManager::getInstance()->play(("lose_"+a->getLeterLower()+".mp3").c_str());
                    break;
                }
            }
             scheduleOnce(schedule_selector(GameLayer::quitGame),3);
        }
}
