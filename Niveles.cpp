#include "Niveles.h"
#include "IntroGeneral.h"
#include "cocos2d.h"
#include "ObuWorld.h"
#include "SimpleAudioEngine.h"


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

	//TITULO

	auto titulo = Label::createWithSystemFont("NIVELES", "fonts/Marker Felt.ttf", 35);
	titulo->enableShadow();
	titulo->enableOutline(Color4B::BLACK, 2);
	titulo->setPosition(Vec2(AN /2, AL - AL * 0.2));

	// add the label as a child to this layer
	this->addChild(titulo, 1);

	/////////////////////////////
	//CREAR OBU
	obu = Sprite::createWithSpriteFrameName("obu.png");
	obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(AN - AN*0.9, AL - AL *0.3));
	obu->setScale(AL*0.1 / obu->getContentSize().height);

	addChild(obu, 2);

	/////////////////////////////
	//LVL1
	btn_lvl_1 = Sprite::createWithSpriteFrameName("luz.png");
	btn_lvl_1->setPosition(Vec2(AN - AN * 0.6 , AL - AL*0.8));
	btn_lvl_1->setScaleY(AL*0.3 / btn_lvl_1->getContentSize().height);
	btn_lvl_1->setScaleX(AN*0.2 / btn_lvl_1->getContentSize().width);

	this->addChild(btn_lvl_1, 2);

	//LVL2
	btn_lvl_2 = Sprite::createWithSpriteFrameName("fuego.png");
	btn_lvl_2->setPosition(Vec2(AN - AN * 0.4, AL - AL*0.6));
	btn_lvl_2->setScaleY(AL*0.3 / btn_lvl_2->getContentSize().height);
	btn_lvl_2->setScaleX(AN*0.2 / btn_lvl_2->getContentSize().width);

	this->addChild(btn_lvl_2, 2);

	//LVL3
	btn_lvl_3 = Sprite::createWithSpriteFrameName("fuego.png");
	btn_lvl_3->setPosition(Vec2(AN - AN * 0.2, AL - AL*0.4));
	btn_lvl_3->setScaleY(AL*0.3 / btn_lvl_3->getContentSize().height);
	btn_lvl_3->setScaleX(AN*0.2 / btn_lvl_3->getContentSize().width);

	this->addChild(btn_lvl_3, 2);

	//BTN REGRESAR
	btn_regresar = Sprite::createWithSpriteFrameName("boton_review.png");
	btn_regresar->setPosition(Vec2(AN - AN * 0.95, AL - AL*0.85));
	btn_regresar->setScaleY(AL*0.1 / btn_regresar->getContentSize().height);
	btn_regresar->setScaleX(AN*0.07 / btn_regresar->getContentSize().width);

	this->addChild(btn_regresar, 2);
	///////////////////////////////////
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Niveles::intentRegresar, this));

	closeItem->setPosition(Vec2(AN - AN * 0.95, AL - AL*0.85));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	///////////////////////////////////

	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(Niveles::onAcceleration, this));

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void Niveles::intentRegresar(Ref * pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/atras.mp3");

	auto scene = IntroGeneral::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Niveles::intentLvl_1(Ref * pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

	auto scene = ObuWorld::createScene();
	Director::getInstance()->replaceScene(scene);
}
void Niveles::intentLvl_2(Ref * pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

	//Agregar Scena lvl2
}
void Niveles::intentLvl_3(Ref * pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

	//Agregar Scena lvl3
}

void Niveles::onAcceleration(cocos2d::Acceleration * acc, cocos2d::Event * event)
{
	float posX = acc->x;
	float posY = acc->y;

	Size screenSize = Director::getInstance()->getWinSize();

	float w = screenSize.width;
	float h = screenSize.height;

	obu->setVisible(true);

	float X = obu->getPosition().x;
	float Y = obu->getPosition().y;

	X = X + (posX* w *0.03);
	Y = Y + (posY* h *0.03);

	obu->setPosition(X, Y);

	Rect Rregresar = btn_regresar->getBoundingBox();
	Rect Rlvl1 = btn_lvl_1->getBoundingBox();
	Rect Rlvl2 = btn_lvl_2->getBoundingBox();
	Rect Rlvl3 = btn_lvl_3->getBoundingBox();
	
	Rect bbObu = obu->getBoundingBox();


	if (bbObu.intersectsRect(Rregresar)) {
		Niveles::intentRegresar(this);
	}
	else if (bbObu.intersectsRect(Rlvl1)) {
		Niveles::intentLvl_1(this);
	}
	else if (bbObu.intersectsRect(Rlvl2)) {
		Niveles::intentLvl_2(this);
	}
	else if (bbObu.intersectsRect(Rlvl3)) {
		Niveles::intentLvl_3(this);
	}
	
	
}




