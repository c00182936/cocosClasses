#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
	auto drawNode = DrawNode::create();
	if (!Layer::init())
	{
		return false;
	}
	//void drawPolygon(Vec2 *verts, int count, const cocos2d::Color4F &fillColor, float borderWidth, const Color4F &borderColor);
	Vec2 vertics[4] = { Vec2(0,0), Vec2(200,0), Vec2(200,200), Vec2(0,200) };
	drawNode->drawPolygon(vertics,4, cocos2d::Color4F::GREEN, 10, cocos2d::Color4F::WHITE);
	auto menuTitle =
		MenuItemImage::create("MainMenuScreen/Game_Title.png",
			"MainMenuScreen/Game_Title.png");
	auto playItem =
		MenuItemImage::create("MainMenuScreen/Play_Button.png",
			"MainMenuScreen/Play_Button(Click).png",
			CC_CALLBACK_1(MainMenu::activateGameScene, this));
	auto menu = Menu::create(menuTitle, playItem, NULL);

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);
	this->addChild(drawNode);
	return true;
}
void MainMenu::activateGameScene(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MainMenu::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
