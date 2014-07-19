//
//  BaseScene.cpp
//  GMFramework
//
//  Created by langtujava on 4/13/14.
//
//

#include "BaseScene.h"

#include "GameManager.h"
#include "PluginManager.h"


void MyAdsListener::onAdsResult(AdsResultCode code, const char* msg)
{
	log("OnAdsResult, code : %d, msg : %s", code, msg);
}

void MyAdsListener::onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, int points)
{
	log("Player get points : %d", points);
    
	// @warning should add code to give game-money to player here
    
	// spend the points of player
	if (pAdsPlugin != NULL) {
		pAdsPlugin->spendPoints(points);
	}
}

void BaseScene::play(const string & filename){
    SoundManager::getInstance()->stopAll();
    SoundManager::getInstance()->play(filename.c_str());

}

void BaseScene::showConfirmDialog(const std::string & content, const std::function<void()> & cb){
    auto confirmLayer = ConfirmLayer::create();
    this->addChild(confirmLayer,INT32_MAX);
    confirmLayer->emitShow(content,cb,nullptr);
}

void BaseScene::showConfirmDialog(const std::string & content, const std::function<void()> & cb,const std::function<void()> & cb2){
    auto confirmLayer = ConfirmLayer::create();
    this->addChild(confirmLayer,INT32_MAX);
    confirmLayer->emitShow(content,cb,cb2);
}

bool BaseScene::buildComponent()
{
    return true;
}

void BaseScene::showInfoDialog(const std::string &content){
    auto infoLayer= InfoLayer::create();
    this->addChild(infoLayer, INT32_MAX);
    infoLayer->emitShow(content);
}



void BaseScene::showAdmob(cocos2d::plugin::ProtocolAds::AdsPos pos )
{
	if (ads)
	{
		ads->showAds(adInfo, pos);
	}
}

void BaseScene::hideAdmob()
{
	if (ads)
	{
		ads->hideAds(adInfo);
	}
}

bool BaseScene::init(){

    if ( !Layer::init() )
    {
        return false;
    }
    // admod
    ads = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("AdsAdmob"));


    auto bg =Sprite::create("mainmenu_bg.jpg");
    bg->cocos2d::Node::setPosition(VisibleRect::center());
    bg->cocos2d::Node::setScale(Director::getInstance()->getContentScaleFactor()/1.3);
    // add background
    this->addChild(bg);

    auto listerner = EventListenerKeyboard::create();
    listerner->onKeyReleased=CC_CALLBACK_2(BaseScene::onKeyReleased,this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listerner, this);
   
    
    TAdsDeveloperInfo devInfo;
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    devInfo["AdmobID"] = ADMOB_ID_IOS;
   // devInfo["FlurryAppKey"] = FLURRY_KEY_IOS;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    devInfo["AdmobID"] = ADMOB_ID_ANDROID;
    //devInfo["FlurryAppKey"] = FLURRY_KEY_ANDROID;
#endif
    
    ads->configDeveloperInfo(devInfo);
    ads->setAdsListener(new MyAdsListener());
    ads->setDebugMode(true);
    
    // init the AdsInfo
    
    adInfo["AdmobType"] = "1";
    adInfo["AdmobSizeEnum"] = "1";
    
    
  //  adInfo["FlurryAdsID"] = "BANNER_MAIN_VC";
   // adInfo["FlurryAdsSize"] = "2";
    
    this->buildComponent();
    
    return true;
    
}

