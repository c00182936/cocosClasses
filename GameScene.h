#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "PauseScene.h"
#include "GameOverScene.h"
#include "cocos2d.h"

class GameScreen : public cocos2d::Layer
{
private:
	cocos2d::Sprite * paddleSprite;
	bool leftPressed = false;//for continious input
	bool rightPressed = false;
	cocos2d::Vec2 position;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void update(float deltaTime);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen);
};

#endif // __HELLOWORLD_SCENE_H__
