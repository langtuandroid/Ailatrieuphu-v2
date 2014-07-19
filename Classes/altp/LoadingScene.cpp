//
//  LoadingScene.cpp
//  GMFramework
//
//  Created by langtujava on 5/2/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "LoadingScene.h"




bool LoadingScene::init()
{
    if(!LayerColor::init()){
        return false;
    }
    setColor(Color3B(1,1,1));
     loadingText = Label::createWithTTF("Loading ...", "fonts/arial.ttf", TITLE_FONT_SIZE);
    addChild(loadingText);
    loadingText->setPosition(VisibleRect::center());
    
    loaders.push_back([](){
         // images
        ImageManager* imageManager = ImageManager::getInstance();
        imageManager->addCommonSpriteFrame("ui.plist");
        imageManager->prepare();
        
    });
    
    
    loaders.push_back([](){
        // sounds
        auto  soundManager = SoundManager::getInstance();
        soundManager->addCommonBgm(sound::BACKGROUND);
        soundManager->addCommonEffect(sound::CLICK);
        soundManager->addCommonEffect(sound::EXPLOSION);
        soundManager->addCommonEffect(sound::WOOD);
        soundManager->prepare();
    });
    
    loaders.push_back([](){
        // sounds
        auto  soundManager = SoundManager::getInstance();
        
        soundManager->addCommonEffect("ans_a.mp3");
        soundManager->addCommonEffect("ans_b.mp3");
        soundManager->addCommonEffect("ans_c.mp3");
        soundManager->addCommonEffect("ans_d.mp3");
        soundManager->addCommonEffect("ans_now1.mp3");
        soundManager->addCommonEffect("ans_now2.mp3");
        soundManager->addCommonEffect("call.mp3");
        soundManager->addCommonEffect("gofind.mp3");
        soundManager->addCommonEffect("khan_gia.mp3");
        soundManager->addCommonEffect("lose.mp3");
        soundManager->addCommonEffect("lose_a.mp3");
        soundManager->addCommonEffect("lose_b.mp3");
        soundManager->addCommonEffect("lose_c.mp3");
        soundManager->addCommonEffect("lose_d.mp3");
        soundManager->addCommonEffect("luatchoi.mp3");
        soundManager->addCommonEffect("moc1.mp3");
        soundManager->addCommonEffect("moc2.mp3");
        soundManager->addCommonEffect("moc3.mp3");
        soundManager->prepare();
    });
    loaders.push_back([](){
        // sounds
        auto  soundManager = SoundManager::getInstance();
        
        
        soundManager->addCommonEffect("out_of_time.mp3");
        soundManager->addCommonEffect("pass14.mp3");
        soundManager->addCommonEffect("ques1.mp3");
        soundManager->addCommonEffect("ques2.mp3");
        soundManager->addCommonEffect("ques3.mp3");
        soundManager->addCommonEffect("ques4.mp3");
        soundManager->addCommonEffect("ques5.mp3");
        soundManager->addCommonEffect("ques6.mp3");
        soundManager->addCommonEffect("ques7.mp3");
        soundManager->addCommonEffect("ques8.mp3");
        soundManager->addCommonEffect("ques9.mp3");
        soundManager->addCommonEffect("ques10.mp3");
        soundManager->addCommonEffect("ques11.mp3");
        soundManager->addCommonEffect("ques12.mp3");
        soundManager->addCommonEffect("ques13.mp3");
        soundManager->addCommonEffect("ques14.mp3");
        soundManager->addCommonEffect("ques15.mp3");
        soundManager->prepare();
    });
    loaders.push_back([](){
        // sounds
        auto  soundManager = SoundManager::getInstance();
        
        soundManager->addCommonEffect("ready.mp3");
        soundManager->addCommonEffect("ringback.mp3");
        soundManager->addCommonEffect("sound5050.mp3");
        soundManager->addCommonEffect("splashrise.mp3");
        soundManager->addCommonEffect("true_a.mp3");
        soundManager->addCommonEffect("true_b.mp3");
        soundManager->addCommonEffect("true_c.mp3");
        soundManager->addCommonEffect("true_c2.mp3");
        soundManager->addCommonEffect("true_d.mp3");
        soundManager->addCommonEffect("true_d2.mp3");
        soundManager->addCommonEffect("true_fast.mp3");
        soundManager->addCommonEffect("win.mp3");
        
        soundManager->prepare();
    });
    
    loaders.push_back([](){
        // sounds
        auto  soundManager = SoundManager::getInstance();

        GameManager::getInstance()->backgroundMusicPercen=UserDefault::getInstance()->getIntegerForKey(sound::BACKGROUND_SOUND);
        GameManager::getInstance()-> effectMusicPercen=UserDefault::getInstance()->getIntegerForKey(sound::EFFECT_SOUND);
        
        if(GameManager::getInstance()->backgroundMusicPercen==0){
            GameManager::getInstance()->backgroundMusicPercen=50;
            UserDefault::getInstance()->setIntegerForKey(sound::BACKGROUND_SOUND, 50);
        }
        
        if(GameManager::getInstance()->effectMusicPercen==0){
            GameManager::getInstance()->effectMusicPercen=50;
            UserDefault::getInstance()->setIntegerForKey(sound::EFFECT_SOUND, 50);
        }
        
        
        soundManager->setVolume((float) GameManager::getInstance()->effectMusicPercen/(float)100);
        soundManager->setBgmVolume((float) GameManager::getInstance()->backgroundMusicPercen/(float)100);
        soundManager->playBgm(sound::BACKGROUND,true);
        
        string username =UserDefault::getInstance()->getStringForKey("USERNAME");
        GameManager::getInstance()->username = username;
        
    });
    
    
    
    loaders.push_back([](){
        SoundManager::getInstance()->playBgm(sound::BACKGROUND,true);
        Configuration::getInstance()->loadConfigFile("client.plist");
    });
    
    loaders.push_back([](){
        GameManager::getInstance()->emitShowMenuScene();
        
    });
   
    
    // supper init head
    return true;
}


void LoadingScene::onEnter(){
    Layer::onEnter();
    scheduleOnce(schedule_selector(LoadingScene::gotoLoading),1);
}


void LoadingScene::gotoLoading(float f){
    countNumber=0;
    for(auto fun:loaders){
        countNumber++;
        log("loading .. %i",countNumber);
       
        //loadingText->setString("Loading..."+itstr(countNumber));
        fun();
    }
    
}
