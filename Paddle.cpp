#include "Paddle.h"



Paddle::Paddle()
{

	//paddleSize = temp;
}
void Paddle::init()
{
	paddleSprite= cocos2d::Sprite::create("Ball/paddleSpriteA.png");
	paddlePos = cocos2d::Vec2(20, 50);
	cocos2d::Size temp = paddleSprite->getContentSize();

	auto drawNode = cocos2d::DrawNode::create();
	cocos2d::Vec2 vertics[4] = { cocos2d::Vec2(0,0), cocos2d::Vec2(200,0), cocos2d::Vec2(200,200), cocos2d::Vec2(0,200) };
	drawNode->drawPolygon(vertics, 4, cocos2d::Color4F::GREEN, 10, cocos2d::Color4F::WHITE);
	
}

Paddle::~Paddle()
{
}
