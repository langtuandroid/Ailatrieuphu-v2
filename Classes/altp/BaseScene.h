//
//  BaseScene.h
//  GMFramework
//
//  Created by langtujava on 4/13/14.
//
//

#ifndef __GMFramework__BaseScene__
#define __GMFramework__BaseScene__

#include "gmg.h"

#include "AppMacros.h"
#include "InfoLayer.h"
#include "ConfirmLayer.h"
#include "ProtocolAds.h"

using namespace cocos2d::plugin;

class MyAdsListener : public cocos2d::plugin::AdsListener
{
public:
	virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);
	virtual void onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, int points);
    
};

USING_NS_CC;
USING_NS_GMG;

enum State{
    PLAY_STATE,
    MENU_STATE,
    PAUSE_STATE,
    GAME_OVER_STATE
};

class BaseScene : public Layer
{
    
     CC_SYNTHESIZE(State, state, State);
 
    
public:
    
    virtual  bool init();
    
    virtual bool buildComponent();

    void showInfoDialog(const std::string & content);
   
    void showConfirmDialog(const std::string & content,const std::function<void()>& callback);
    void showConfirmDialog(const std::string & content,const std::function<void()>& callback,const std::function<void()>& callback2);
    void showAdmob(ProtocolAds::AdsPos pos );
    void hideAdmob();
    
    void play(const string & filename);
  
    
    
private:

	cocos2d::plugin::ProtocolAds* ads;
	cocos2d::plugin::TAdsInfo adInfo;
    
};


#endif /* defined(__GMFramework__SplashScene__) *///#endif /* defined(__GMFramework__MenuScene__) */
