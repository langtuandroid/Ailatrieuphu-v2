//
//  GroupAnswers.h
//  GMFramework
//
//  Created by langtujava on 4/19/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#ifndef __GMFramework__GroupAnswers__
#define __GMFramework__GroupAnswers__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "AppMacros.h"
#include "QuestionEntity.h"
#include "utils/WidgetUtils.h"
#include "BaseScene.h"
#include "gmg.h"
#include "HelpAudience.h"
#include "HelpTelelphone.h"
#include "GameManager.h"
#include "InputLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class BoxAndLabelSprite;

class AnswersSprite;

class QuestionSprite;

class TimeCountSprite;

class ClickListerner{
public:
    virtual void onClick(AnswersSprite * f){};
};



class GameLayer : public Layer, public ClickListerner
{
    CC_SYNTHESIZE(BaseScene*,gameScene, GameScene);
    
public:
    std::vector<AnswersSprite*> lists;
    
   
    DEFINE_EVENT_EMITTER_WITH_ARG(Start,int);
    DEFINE_EVENT_EMITTER(Pause);
    DEFINE_EVENT_EMITTER(Resume);
    DEFINE_EVENT_EMITTER(GameOver);
    DEFINE_EVENT_EMITTER(Quit);
    
    
    virtual ~GameLayer() {
        
       }
  

    CREATE_FUNC(GameLayer);

private:
    
    void setEnable(bool b);

    virtual bool init();
    void setControllHelp(bool b);

    void reset();
    virtual void onClick(AnswersSprite * ref);
    
private:
    
    bool isSelected;
    AnswersSprite * currentSelect;
    QuestionEntity * currentQuestion;
    
    QuestionSprite * questionSprite;
    
    std::vector<Button *> helpButtons;
    TimeCountSprite * timeCountSprite;
    
    
    BoxAndLabelSprite * questionNumberSprite;
    BoxAndLabelSprite * moneySprite;
    
    Sprite * sec;
    
    int maxCountDown =30;
    int countdownNumber=maxCountDown;
    
    bool isRunning;
    bool isScheduleOn;
    bool isCountdownBegin;
    
    bool isGameOver;
    
    int questionLevel =1;
    
private:
    void countdown(float detal);
     virtual void update(float detal);
    void help5050(float detal);
     void result(float detal);
    void nextLevel(float detal);
    void quitGame(float detal);
    void gotoMainMenu(float detal);
};

#endif 

/* defined(__GMFramework__GroupAnswers__) */

