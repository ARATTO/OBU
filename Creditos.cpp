#include "Creditos.h"
#include "cocos2d.h"


USING_NS_CC;

Scene* Creditos::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Creditos::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Creditos::init()
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

	////////////////////////////////////

	//HACER ALGO

	auto titulo = Label::createWithSystemFont("fonts/Marker Felt.ttf", "CREDITOS", 20);
	titulo->setPosition(Vec2(38, origin.y + visibleSize.height - titulo->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(titulo, 1);

	///////////////////////////////////

	return true;
}




