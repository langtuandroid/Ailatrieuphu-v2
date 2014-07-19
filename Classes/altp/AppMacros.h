#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"
#include <gmg.h>

USING_NS_CC;
/* For demonstrating using one design resolution to match different resources,
   or one resource to match different design resolutions.

   [Situation 1] Using one design resolution to match different resources.
     Please look into Appdelegate::applicationDidFinishLaunching.
     We check current device frame size to decide which resource need to be selected.
     So if you want to test this situation which said in title '[Situation 1]',
     you should change ios simulator to different device(e.g. iphone, iphone-retina3.5, iphone-retina4.0, ipad, ipad-retina),
     or change the window size in "proj.XXX/main.cpp" by "CCEGLView::setFrameSize" if you are using win32 or linux plaform
     and modify "proj.mac/AppController.mm" by changing the window rectangle.

   [Situation 2] Using one resource to match different design resolutions.
     The coordinates in your codes is based on your current design resolution rather than resource size.
     Therefore, your design resolution could be very large and your resource size could be small.
     To test this, just define the marco 'TARGET_DESIGN_RESOLUTION_SIZE' to 'DESIGN_RESOLUTION_2048X1536'
     and open iphone simulator or create a window of 480x320 size.
 
 chuyen nho y ma;
 

   [Note] Normally, developer just need to define one design resolution(e.g. 960x640) with one or more resources.
 */


#define ORIENTATION_LANDSCAPE		0
#define ORIENTATION_PORTRAIT		1


#define ORIENTATION		ORIENTATION_PORTRAIT

#if (ORIENTATION == ORIENTATION_LANDSCAPE)
#define DESIGN_RESOLUTION_480X320    0
#define DESIGN_RESOLUTION_1024X768   1
#define DESIGN_RESOLUTION_2048X1536  2

/* If you want to switch design resolution, change next line */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_480X320

typedef struct tagResource
{
    cocos2d::Size size;
    char directory[100];
}Resource;

static Resource smallResource  =  { cocos2d::Size(480, 320),   "images/SD" };
static Resource mediumResource =  { cocos2d::Size(1024, 768),  "images/HD"   };
static Resource largeResource  =  { cocos2d::Size(2048, 1536), "images/HDR" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_480X320)
static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1024X768)
static cocos2d::Size designResolutionSize = cocos2d::Size(1024, 768);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_2048X1536)
static cocos2d::Size designResolutionSize = cocos2d::Size(2048, 1536);
#else
#error unknown target design resolution!
#endif

#else	// ORIENTATION_PORTRAIT

#define DESIGN_RESOLUTION_320X480    0
#define DESIGN_RESOLUTION_768X1024   1
#define DESIGN_RESOLUTION_1536X2048  2

/* If you want to switch design resolution, change next line */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_480X320

typedef struct tagResource
{
    cocos2d::Size size;
    char directory[100];
}Resource;

static Resource smallResource  =  { cocos2d::Size(320, 480),   "images/SD" };
static Resource mediumResource =  { cocos2d::Size(768, 1024),  "images/HD"   };
static Resource largeResource  =  { cocos2d::Size(1536, 2048), "images/HDR" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_320X480)
static cocos2d::Size designResolutionSize = cocos2d::Size(320, 480);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_768X1024)
static cocos2d::Size designResolutionSize = cocos2d::Size(768, 1024);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1536X2048)
static cocos2d::Size designResolutionSize = cocos2d::Size(1536, 2048);
#else
#error unknown target design resolution!
#endif

#endif	// ORIENTATION

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TEXT_FONT_SIZE  (Director::getInstance()->getOpenGLView()->getDesignResolutionSize().width/ smallResource.size.width * 14)
#define TITLE_FONT_SIZE  (Director::getInstance()->getOpenGLView()->getDesignResolutionSize().width/ smallResource.size.width * 16)
#define BUTTON_FONT_SIZE  (Director::getInstance()->getOpenGLView()->getDesignResolutionSize().width/ smallResource.size.width * 18)

#define TIME_FONT_SIZE  (Director::getInstance()->getOpenGLView()->getDesignResolutionSize().width/ smallResource.size.width * 30)

// admod

/** @warning
 * The file UCGameSDK.jar conflicts with weiboSDK.jar
 * if you want test the login/logout of UC,
 * modify the android project config: remove the weiboSDK.jar, and add UCGameSDK.jar
*/
#define TEST_UC             0


/**
 @brief Developer information of flurry
 */
#define FLURRY_KEY_IOS          "KMGG7CD9WPK2TW4X9VR8"
#define FLURRY_KEY_ANDROID      "SPKFH8KMPGHMMBWRBT5W"

/**
 @brief Developer information of Umeng
 */
#define UMENG_KEY_IOS           "50d2b18c5270152187000097"
#define UMENG_KEY_ANDROID       ""          // umeng key for android is setted in AndroidManifest.xml

/**
 @brief Developer information of Admob
 */
#define ADMOB_ID_IOS            "ca-app-pub-1913679474421040/7986769617"
#define ADMOB_ID_ANDROID        "ca-app-pub-1913679474421040/2079836814"

/**
 @brief Developer information of Nd91
 */
#define ND91_APPID              "100010"
#define ND91_APPKEY             "C28454605B9312157C2F76F27A9BCA2349434E546A6E9C75";
#define ND91_ORIENTATION        "landscape"

/**
 @brief Developer information of QH360
 */
#define QH360_EXCHANGE_RATE     "1"

/**
 @brief Developer information of UC
 */
#define UC_CPID                 "20087"
#define UC_GAME_ID              "119474"
#define UC_SERVER_ID            "1333"




#endif /* __APPMACROS_H__ */
