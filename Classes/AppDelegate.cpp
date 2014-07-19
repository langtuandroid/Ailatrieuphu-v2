#include "AppDelegate.h"
#include "AppMacros.h"
#include "SplashScene.h"

#include "GameManager.h"
#include "SimpleAudioEngine.h"
#include "gmg.h"

USING_NS_CC;

using namespace gmg;

using namespace CocosDenshion;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

bool AppDelegate::applicationDidFinishLaunching() {
//initialize director
  gmg::GameManager *gameManager = gmg::GameManager::getInstance();
  gameManager->setup();
  gameManager->initDisplay();
  gameManager->startGame();
  return true;
}
// This function  will be called when the app is inactive. When comes a phone
// call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
  Director::getInstance()->stopAnimation();

  // if you use SimpleAudioEngine, it must be pause
   SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
   SimpleAudioEngine::getInstance()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
  Director::getInstance()->startAnimation();
  
  // if you use SimpleAudioEngine, it must resume here
  SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
  SimpleAudioEngine::getInstance()->resumeAllEffects();
}
