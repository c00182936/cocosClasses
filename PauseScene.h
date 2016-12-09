#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__
#include "GameScene.h"
#include "MainMenuScene.h"
#include "cocos2d.h"

class PauseMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	// Called when resume is selected.
	void resume(Ref *pSender);
	// Called when main menu is selected.
	void activateMainMenuScene(Ref *pSender);
	// Called when retry is selected.
	void retry(Ref *pSender);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PauseMenu);
};

#endif // __HELLOWORLD_SCENE_H__
