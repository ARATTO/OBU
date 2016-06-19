#include "IntroGeneral.h"
#include "SimpleAudioEngine.h"
//#include "cocos2d.h"

#include "ObuWorld.h"
#include "Niveles.h"
#include "Creditos.h"
#include "ui\CocosGUI.h"
#include "Nivel1.h"
#include "Puntaje.h"
//#include "ui\UIButton.h"



USING_NS_CC;

Scene* IntroGeneral::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = IntroGeneral::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool IntroGeneral::init()
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

	AN = TM.width;
	AL = TM.height;

	////////////////////////////////////
	//Musica
	//CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/mainMarcos.mp3");
	
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("audio/intro1.mp3", true);
	
	/////////////////////////////LOGO
	
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MottoMenu.plist");
	
	auto fondo = Sprite::createWithSpriteFrameName("fondo_menu.png");
	//fondo->setAnchorPoint(Vec2::ZERO);
	fondo->setPosition(Vec2(AN/2,AL/2));
	fondo->setScaleY(AL/ fondo->getContentSize().height);
	fondo->setScaleX(AN/ fondo->getContentSize().width);
	addChild(fondo);

	/////////////////////////////
	//CREATE LOGO
	//ANIMACION OBU
	OBULogo = Sprite::createWithSpriteFrameName("OBU_LOGO.png");
	OBULogo->setPosition(Vec2(AN / 5, AL - AL*0.3));
	OBULogo->setScaleY(AL*0.1 / OBULogo->getContentSize().height);
	OBULogo->setScaleX(AN*0.1 / OBULogo->getContentSize().width);

	this->addChild(OBULogo, 2);

	////Repeticion Infinita !!
	auto scaleToMin = ScaleTo::create(1.0f, 0.1f);
	auto scaleToMax = ScaleTo::create(1.0f, 0.3f);
	auto delay = DelayTime::create(0.1);
	
	auto action = (ActionInterval*)Sequence::create(scaleToMin, delay, scaleToMax, delay, NULL);
	OBULogo->runAction(RepeatForever::create(action));

	/////////////////////////////
	//CREATE BOTONES
	//BTN JUGAR
	btn_jugar = Sprite::createWithSpriteFrameName("BTN_JUGAR.png");
	btn_jugar->setPosition(Vec2(AN - AN *0.2 , AL - AL*0.2));
	btn_jugar->setScaleY(AL*0.1 / btn_jugar->getContentSize().height);
	btn_jugar->setScaleX(AN*0.2 / btn_jugar->getContentSize().width);

	this->addChild(btn_jugar, 2);

	//BTN NIVELES
	btn_niveles = Sprite::createWithSpriteFrameName("BTN_NIVELES.png");
	btn_niveles->setPosition(Vec2(AN - AN *0.2, AL - AL*0.4));
	btn_niveles->setScaleY(AL*0.1 / btn_niveles->getContentSize().height);
	btn_niveles->setScaleX(AN*0.2 / btn_niveles->getContentSize().width);

	this->addChild(btn_niveles, 2);

	//BTN PUNTAJE
	btn_puntaje = Sprite::createWithSpriteFrameName("BTN_PUNTAJE.png");
	btn_puntaje->setPosition(Vec2(AN - AN *0.2, AL - AL*0.6));
	btn_puntaje->setScaleY(AL*0.1 / btn_puntaje->getContentSize().height);
	btn_puntaje->setScaleX(AN*0.2 / btn_puntaje->getContentSize().width);

	this->addChild(btn_puntaje, 2);

	//BTN CREDITOS
	btn_creditos = Sprite::createWithSpriteFrameName("BTN_CREDITOS.png");
	btn_creditos->setPosition(Vec2(AN - AN *0.2, AL - AL*0.8));
	btn_creditos->setScaleY(AL*0.1 / btn_creditos->getContentSize().height);
	btn_creditos->setScaleX(AN*0.2 / btn_creditos->getContentSize().width);

	this->addChild(btn_creditos, 2);

	//BTN CREDITOS
	btn_cerrar = Sprite::createWithSpriteFrameName("CloseSelected.png");
	btn_cerrar->setPosition(Vec2(AN - AN *0.95, AL - AL*0.8));
	btn_cerrar->setScaleY(AL*0.4 / btn_creditos->getContentSize().height);
	btn_cerrar->setScaleX(AN*1.2 / btn_creditos->getContentSize().width);

	this->addChild(btn_cerrar, 2);
	/////////////////////////////
	//CREAR OBU
	obu = Sprite::createWithSpriteFrameName("obu.png");
	obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(AN/2, AL/2));
	obu->setScale(AL*0.1 / obu->getContentSize().height);

	addChild(obu,2);

	////////////////////////////////////////////////////////////////////////////////
	//CERRAR MENU PAPU
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(IntroGeneral::menuCloseCallback, this));

	closeItem->setPosition(Vec2(AN - AN *0.95, AL - AL*0.8));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	
	ayuda = Sprite::createWithSpriteFrameName("infografia_obu.png");
    ayuda->setPosition(Vec2(240, 160));
    ayuda->setScaleY(AL*0.90/ayuda->getContentSize().height);
    ayuda->setScaleX(AN*1.0/ayuda->getContentSize().width);
    ayuda->setVisible(false);
	addChild(ayuda);
	
	/*
	///////////////////////////////////////////////////////////////////////////////////
	//MENU PAPU
	Vector <MenuItem*> MenuItems;
	auto nuevo = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(IntroGeneral::intentObuWorld, this));
	nuevo->setPosition(Vec2(origin.x, origin.y - alto*0.2));
	//nuevo->addChild(nuevo, 1);
	MenuItems.pushBack(nuevo);
	auto lvl = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(IntroGeneral::intentNiveles, this));
	lvl->setPosition(Vec2(origin.x, origin.y - alto*0.3));
	//lvl->addChild(lvl, 1);
	MenuItems.pushBack(lvl);
	auto credito = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(IntroGeneral::intentCreditos, this));
	credito->setPosition(Vec2(origin.x, origin.y - alto*0.4));
	//credito->addChild(credito,1);
	MenuItems.pushBack(credito);
	//miMenu->setAnchorPoint(Vec2::ZERO);
	//miMenu->setPosition(Vec2(ancho*0.5 - miMenu->getContentSize().width*0.5, alto*0.4 - miMenu->getContentSize().height*0.5));
	auto miMenu = Menu::createWithArray(MenuItems);
	this->addChild(miMenu, 1);
	/////////////////////////////
	
	*/
	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(IntroGeneral::onAcceleration, this));

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	

	return true;
}


void IntroGeneral::menuCloseCallback(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/despresio.mp3");
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void IntroGeneral::intentObuWorld(Ref* pSender)
{
	auto callbackJump = CallFunc::create([]() {
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

		auto scene = Nivel1::createScene();
		Director::getInstance()->replaceScene(scene);
		});
		
		
		siguiente=1;
		
		btn_jugar->setVisible(false);
		btn_niveles->setVisible(false);
		btn_puntaje->setVisible(false);
		btn_creditos->setVisible(false);
		btn_cerrar->setVisible(false);
		obu->setVisible(false);
		OBULogo->setVisible(false);
		
		//titulo->setString("");
		
		
		auto delayMedio3 = DelayTime::create(10);
		auto fadeIn4 = FadeIn::create(0.1f);
		auto delay4 = DelayTime::create(3);
		auto fadeOut4 = FadeOut::create(0.1f);
		
		ayuda->setVisible(true);

		ayuda->runAction(
		Sequence::create(delayMedio3, fadeIn4, delay4, fadeOut4, callbackJump, nullptr)
		);

}
void IntroGeneral::intentNiveles(Ref* pSender)
{
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

	auto scene = Niveles::createScene();
	Director::getInstance()->pushScene(scene);

}
void IntroGeneral::intentCreditos(Ref* pSender)
{
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

	auto scene = Creditos::createScene();
	Director::getInstance()->replaceScene(scene);

}

void IntroGeneral::intentPuntaje(Ref* pSender)
{
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/next.mp3");

	auto scene = Puntaje::createScene();
	Director::getInstance()->replaceScene(scene);

}

void IntroGeneral::onAcceleration(cocos2d::Acceleration * acc, cocos2d::Event * event)
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
	
	if(   (X<AN-25 && Y<AL-40)  && (X>5 && Y>15) && siguiente==0 )  {
	obu->setPosition(X, Y);
		}
		
	Rect Rcerrar = btn_cerrar->getBoundingBox();
	Rect Rjugar = btn_jugar->getBoundingBox();
	Rect Rniveles = btn_niveles->getBoundingBox();
	Rect Rpuntaje = btn_puntaje->getBoundingBox();
	Rect Rcreditos = btn_creditos->getBoundingBox();


	Rect bbObu = obu->getBoundingBox();


	if (bbObu.intersectsRect(Rcerrar)) {
		IntroGeneral::menuCloseCallback(this);
	}
	else if (bbObu.intersectsRect(Rjugar)) {
		IntroGeneral::intentObuWorld(this);
	}
	else if (bbObu.intersectsRect(Rniveles)) {
		IntroGeneral::intentNiveles(this);
	}
	else if (bbObu.intersectsRect(Rpuntaje)) {
		IntroGeneral::intentPuntaje(this);
		
	}
	else if (bbObu.intersectsRect(Rcreditos)) {
		IntroGeneral::intentCreditos(this);
	}
	

}


