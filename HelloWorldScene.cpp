#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "IntroGeneral.h"
#include "ui\CocosGUI.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	double alto = visibleSize.height;
	double ancho = visibleSize.width;

    //////////////////////////////
	Vector <MenuItem*> MenuItems;

	auto nuevo = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(HelloWorld::pasarIntro, this));
	nuevo->setPosition(Vec2(origin.x, origin.y - alto*0.2));
	//nuevo->addChild(nuevo, 1);
	MenuItems.pushBack(nuevo);

	auto miMenu = Menu::createWithArray(MenuItems);
	this->addChild(miMenu, 1);


	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/intro1.mp3",true);
	//////////////////////////////
    return true;
}
void HelloWorld::pasarIntro(Ref* pSender)
{

	auto scene = IntroGeneral::createScene();
	Director::getInstance()->replaceScene(scene);

}



