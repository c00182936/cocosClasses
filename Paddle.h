#pragma once
#include "cocos2d.h"
class Paddle
{
	//started making the paddle into an object for stuff and neatness
public:
	Paddle();
	cocos2d::Sprite *paddleSprite;
	cocos2d::Vec2 paddlePos;
	cocos2d::Vec2 paddleSize;
	void init();
	~Paddle();
};

