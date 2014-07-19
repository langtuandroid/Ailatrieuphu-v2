//
//  GameManager.h
//  GMFramework
//
//  Created by langtujava on 4/14/14.
//
//

#ifndef __GMFramework__GameManager__
#define __GMFramework__GameManager__

#include "gmg.h"

#include "cocos2d.h"
#include "AppMacros.h"
#include "QuestionEntity.h"
#include <stack>
USING_NS_CC;

namespace gmg {
    

    
	
	class GameManager {
		
		DEFINE_EVENT_EMITTER(Close);
		DEFINE_EVENT_EMITTER(SelectBack);
        
        DEFINE_EVENT_EMITTER_WITH_ARG(ShowScene,Scene *);
        DEFINE_EVENT_EMITTER(ShowMenuScene);
        DEFINE_EVENT_EMITTER(ShowLoadingScene);
		
	private:
		
	
		GameManager() {
		}
		~GameManager() {
		}
        
     
		
	public:
        CREATE_STATIC_GET_INSTANCE(GameManager);
				
		void setup();
     	
		void initDisplay();
		
		void startGame();
        
        int effectMusicPercen;
        
        int backgroundMusicPercen;
        
        string username;
       
     		
	};
	
}

#endif /* defined(__GMFramework__GameManager__) */
