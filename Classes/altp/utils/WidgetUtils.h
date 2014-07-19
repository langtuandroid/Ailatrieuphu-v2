//
//  WidgetUtils.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/09/18.
//


//

/*
 
 /////////////////////////////
 // 3. add your codes below...
 
 const int fontSize = 80;
 
 // デフォルトで入ってるMarker Felt.ttfフォントの設定を作る
 TTFConfig ttfConfig("fonts/Marker Felt.ttf",
 fontSize,
 GlyphCollection::DYNAMIC);
 // 1. 普通にTTFフォントを使って表示
 auto label = Label::createWithTTF(ttfConfig, "hoge hoge");
 label->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
 this->addChild(label);
 
 const int height = label->getContentSize().height * 1.5;
 
 // 2. 文字と文字の間隔を設定（アウトライン）
 TTFConfig ttfConfigOutLine(ttfConfig);
 // 文字の間隔を指定（フォントサイズの幅っぽい）
 ttfConfigOutLine.outlineSize = 4;
 auto labelOutLine = Label::createWithTTF(ttfConfigOutLine, "hoge hoge");
 labelOutLine->setPosition(Point(label->getPosition() - Point(0, height)));
 this->addChild(labelOutLine);
 
 // 3. 文字に影をつける（x=4, y=-4の位置に影を置く）
 auto labelShadow = Label::createWithTTF(ttfConfig, "hoge hoge");
 labelShadow->setPosition(Point(labelOutLine->getPosition() - Point(0, height)));
 labelShadow->setColor(Color3B::RED);
 // 半透明の影を（x = 4, y = -4）の位置へ指定
 labelShadow->enableShadow(Color4B(255,255,255,128), Size(4, -4));
 this->addChild(labelShadow);
 
 // 4. エフェクト表示（アウトラインと併用できないので注意）
 TTFConfig ttfConfigEffect(ttfConfig);
 // エフェクト有効（_useDistanceField = distanceFieldEnabled;されます）
 ttfConfigEffect.distanceFieldEnabled = true;
 auto labelEffect = Label::createWithTTF(ttfConfigEffect, "hoge hoge");
 labelEffect->setPosition(Point(labelShadow->getPosition() - Point(0, height)));
 // エフェクトの色を指定
 labelEffect->enableGlow(Color4B::RED);
 this->addChild(labelEffect);
 
 
 */


#ifndef coconut_sample_WidgetUtils_h
#define coconut_sample_WidgetUtils_h


#include "gmg.h"
#include "AppMacros.h"
USING_NS_CC;

using namespace gmg;
using namespace std;
namespace gmg {

class WidgetUtils {
private:
    WidgetUtils() {};

    static cocos2d::Node* createTTFSprite(const Size &size,
                                          const string text,
                                          const string fontName,
                                          int textSize);

    static ToggleButton* createTTFToggleButton(const string fontName,
                                               int textSize,
                                               const string color,
                                               const std::function<void()>& callback,
                                               const string text, va_list);

public:
    static const string defaultFontName;
  
    static const Size  defaultSize;

    static Button* createGlowButton(const string image, const std::function<void()>& callback);
    
    
    
   
    
    static Button* createToggleButton(cocos2d::Vector<cocos2d::SpriteFrame*> sprites, const std::function<void()>& callback);
    
     static Button* createToggleButton(const std::string & sprites, const std::function<void()>& callback);
    
    static cocos2d::Node* createRoundedRect(const cocos2d::Size& size);

    static gmg::Button* createTTFButton(const string text,
                                        const string fontName,
                                        int textSize,
                                        const Size &size,
                                        const std::function<void()>& callback);
    static Button* createTTFButton(const string text,
                                   int textSize,
                                   const Size &size,
                                   const std::function<void()>& callback)
    {
        return createTTFButton(text, defaultFontName, textSize, size, callback);
    }
    static Button* createTTFButton(const string text,
                                   const Size &size,
                                   const std::function<void()>& callback)
    {
        return createTTFButton(text, defaultFontName, BUTTON_FONT_SIZE, size, callback);
    }
    static Button* createTTFButton(const string text,
                                   int textSize,
                                   const std::function<void()>& callback)
    {
        return createTTFButton(text, defaultFontName, textSize, defaultSize, callback);
    }
    static Button* createTTFButton(const string text,
                                   const std::function<void()>& callback)
    {
        return createTTFButton(text, defaultFontName, BUTTON_FONT_SIZE, defaultSize, callback);
    }

    static Button* createTTFButton(const string text,
                                   const string fontName,
                                   int textSize,
                                   const Size & size)
    {
        return createTTFButton(text, fontName, textSize, size, std::function<void()>());
    }
    static Button* createTTFButton(const string text,
                                   int textSize,
                                   const Size & size)
    {
        return createTTFButton(text, textSize, size, std::function<void()>());
    }
    static Button* createTTFButton(const string text,
                                   const Size & size)
    {
        return createTTFButton(text, size, std::function<void()>());
    }
    static Button* createTTFButton(const string text,
                                   int textSize)
    {
        return createTTFButton(text, textSize, std::function<void()>());
    }
    static Button* createTTFButton(const string text)
    {
        return createTTFButton(text, std::function<void()>());
    }

    static ToggleButton* createTTFToggleButton(const string fontName,
                                               int textSize,
                                               const Size & size,
                                               const std::function<void()>& callback,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(fontName, textSize, size, callback, text, params, NULL);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(int textSize,
                                                const Size & size,
                                               const std::function<void()>& callback,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, size, callback, text, params, NULL);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(const string color,
                                               const std::function<void()>& callback,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, BUTTON_FONT_SIZE, color, callback, text, params);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(int textSize,
                                               const std::function<void()>& callback,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, defaultSize, callback, text, params, NULL);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(const std::function<void()>& callback,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, BUTTON_FONT_SIZE, defaultSize, callback, text, params, NULL);
        va_end(params);
        return btn;
    }

    static ToggleButton* createTTFToggleButton(const string fontName,
                                               int textSize,
                                               const string color,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(fontName, textSize, color, std::function<void()>(), text, params);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(int textSize,
                                               const string color,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, color, std::function<void()>(), text, params);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(const string color,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, BUTTON_FONT_SIZE, color, std::function<void()>(), text, params);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(int textSize,
                                               const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, defaultSize, std::function<void()>(), text, params, NULL);
        va_end(params);
        return btn;
    }
    static ToggleButton* createTTFToggleButton(const string text, ...) CC_REQUIRES_NULL_TERMINATION
    {
        va_list params;
        va_start(params, text);
        ToggleButton* btn = createTTFToggleButton(defaultFontName, BUTTON_FONT_SIZE, defaultSize, std::function<void()>(), text, params, NULL);
        va_end(params);
        return btn;
    }
};
}

#endif
