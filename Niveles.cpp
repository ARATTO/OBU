#include "Niveles.h"
#include "IntroGeneral.h"
#include "cocos2d.h"


USING_NS_CC;

Scene* Niveles::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Niveles::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Niveles::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	double alto = visibleSize.height;
	double ancho = visibleSize.width;

	Size TM = Director::getInstance()->getWinSize();

	float AN = TM.width;
	float AL = TM.height;

	/////////////////////////////LOGO

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Motto.plist");

	auto fondo = Sprite::createWithSpriteFrameName("fondo.png");
	//fondo->setAnchorPoint(Vec2::ZERO);
	fondo->setPosition(Vec2(AN / 2, AL / 2));
	fondo->setScaleY(AL / fondo->getContentSize().height);
	fondo->setScaleX(AN / fondo->getContentSize().width);
	addChild(fondo);

	/////////////////////////////

	////////////////////////////////////

	//HACER ALGO

	auto titulo = Label::createWithSystemFont("NIVELES", "fonts/Marker Felt.ttf", 20);
	titulo->setPosition(Vec2(38,origin.y + visibleSize.height - titulo->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(titulo, 1);

	///////////////////////////////////
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Niveles::intentRegresar, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void Niveles::intentRegresar(Ref * pSender)
{
	auto scene = IntroGeneral::createScene();
	Director::getInstance()->replaceScene(scene);
}




