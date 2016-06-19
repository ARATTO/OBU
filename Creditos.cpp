#include "Creditos.h"
#include "IntroGeneral.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"


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

	Size TM = Director::getInstance()->getWinSize();

	AN = TM.width;
	AL = TM.height;
	/////////////////////////////

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("audio/intro2.mp3", true);

	/////////////////////////////LOGO

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Motto.plist");

	/////////////////////////////
	//CREAR OBU
	obu = Sprite::createWithSpriteFrameName("obu.png");
	obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(AN - AN *0.9, AL - AL * 0.2));
	obu->setScale(AL*0.1 / obu->getContentSize().height);

	addChild(obu, 2);
	//BTN REGRESAR
	btn_regresar = Sprite::createWithSpriteFrameName("OBU_LOGO.png");
	btn_regresar->setPosition(Vec2(AN - AN * 0.9, AL - AL*0.85));
	btn_regresar->setScaleY(AL*0.15 / btn_regresar->getContentSize().height);
	btn_regresar->setScaleX(AN*0.11 / btn_regresar->getContentSize().width);

	this->addChild(btn_regresar, 2);

	///////////////////////////////////
	auto callbackJump = CallFunc::create([]() {
		auto scene = IntroGeneral::createScene();
		Director::getInstance()->replaceScene(scene);
	});
	///////////////////////////////////

	auto T1 = Label::createWithSystemFont("PRODUCCION GENERAL", "fonts/Marker Felt.ttf", 30);
	T1->enableShadow();
	T1->setPosition(Vec2(AN / 2, AL - AL * 0.3));
	T1->setColor(Color3B::RED);
	T1->setOpacity(0);

	this->addChild(T1, 1);

	auto T1_1 = Label::createWithSystemFont("DARIO MOTTO \n\nRODRIGO SEGOVIA", "fonts/Marker Felt.ttf", 35);
	T1_1->enableShadow();
	T1_1->setPosition(Vec2(AN / 2, AL - AL * 0.6));
	T1_1->setOpacity(0);

	this->addChild(T1_1, 1);

	auto fadeIn1 = FadeIn::create(1.0f);
	auto fadeOut1 = FadeOut::create(1.0f);
	auto delay1 = DelayTime::create(2);
	auto fadeIn1_1 = FadeIn::create(1.0f);
	auto fadeOut1_1 = FadeOut::create(1.0f);
	auto delay1_1 = DelayTime::create(2);

	T1->runAction(
		Sequence::create(fadeIn1, delay1, fadeOut1, nullptr)
		);
	T1_1->runAction(
		Sequence::create(fadeIn1_1, delay1_1, fadeOut1_1, nullptr)
		);

	///////////////////////////////////
	///////////////////////////////////

	auto T2 = Label::createWithSystemFont("PRODUCTOR DE CONTENIDO GRAFICO", "fonts/Marker Felt.ttf", 22);
	T2->enableShadow();
	T2->setPosition(Vec2(AN / 2, AL - AL * 0.3));
	T2->setColor(Color3B::RED);
	T2->setOpacity(0);

	this->addChild(T2, 1);

	auto T2_2 = Label::createWithSystemFont("RICARDO 'Takashi' MOTTO", "fonts/Marker Felt.ttf", 35);
	T2_2->enableShadow();
	T2_2->setPosition(Vec2(AN / 2, AL - AL * 0.6));
	T2_2->setOpacity(0);

	this->addChild(T2_2, 1);

	auto fadeIn2 = FadeIn::create(1.0f);
	auto fadeOut2 = FadeOut::create(1.0f);
	auto delay2 = DelayTime::create(2);
	auto fadeIn2_2 = FadeIn::create(1.0f);
	auto fadeOut2_2 = FadeOut::create(1.0f);
	auto delay2_2 = DelayTime::create(2);
	auto delayMedio2 = DelayTime::create(5); //++5
	auto delayMedio2_2 = DelayTime::create(5);

	T2->runAction(
		Sequence::create(delayMedio2,fadeIn2, delay2, fadeOut2, nullptr)
		);
	T2_2->runAction(
		Sequence::create(delayMedio2_2,fadeIn2_2, delay2_2, fadeOut2_2, nullptr)
		);

	///////////////////////////////////
	///////////////////////////////////

	auto T3 = Label::createWithSystemFont("PRODUCTOR DE SONIDO", "fonts/Marker Felt.ttf", 30);
	T3->enableShadow();
	T3->setPosition(Vec2(AN / 2, AL - AL * 0.3));
	T3->setColor(Color3B::RED);
	T3->setOpacity(0);

	this->addChild(T3, 1);

	auto T3_3 = Label::createWithSystemFont("MARCOS 'El Papu' BARRERA", "fonts/Marker Felt.ttf", 30);
	T3_3->enableShadow();
	T3_3->setPosition(Vec2(AN / 2, AL - AL * 0.6));
	T3_3->setOpacity(0);

	this->addChild(T3_3, 1);

	auto fadeIn3 = FadeIn::create(1.0f);
	auto fadeOut3 = FadeOut::create(1.0f);
	auto delay3 = DelayTime::create(2);
	auto fadeIn3_3 = FadeIn::create(1.0f);
	auto fadeOut3_3 = FadeOut::create(1.0f);
	auto delay3_3 = DelayTime::create(2);
	auto delayMedio3 = DelayTime::create(10); //++5
	auto delayMedio3_3 = DelayTime::create(10);

	T3->runAction(
		Sequence::create(delayMedio3, fadeIn3, delay3, fadeOut3, nullptr)
		);
	T3_3->runAction(
		Sequence::create(delayMedio3_3, fadeIn3_3, delay3_3, fadeOut3_3, nullptr)
		);

	///////////////////////////////////
	///////////////////////////////////

	auto T4 = Label::createWithSystemFont("PROGRAMADORES ADICIONALES", "fonts/Marker Felt.ttf", 25);
	T4->enableShadow();
	T4->setPosition(Vec2(AN / 2, AL - AL * 0.2));
	T4->setColor(Color3B::RED);
	T4->setOpacity(0);

	this->addChild(T4, 1);

	auto T4_4 = Label::createWithSystemFont("\n Dario Motto \nRodrigo Daniel \n Alex Bautista \n\n\n Jose Marmol \n Jhony Rogel", "fonts/Marker Felt.ttf", 20);
	T4_4->enableShadow();
	T4_4->setPosition(Vec2(AN / 2, AL /2));
	T4_4->setOpacity(0);

	this->addChild(T4_4, 1);

	auto fadeIn4 = FadeIn::create(1.0f);
	auto fadeOut4 = FadeOut::create(1.0f);
	auto delay4 = DelayTime::create(2);
	auto fadeIn4_4 = FadeIn::create(1.0f);
	auto fadeOut4_4 = FadeOut::create(1.0f);
	auto delay4_4 = DelayTime::create(2);
	auto delayMedio4 = DelayTime::create(15); //++5
	auto delayMedio4_4 = DelayTime::create(15);

	T4->runAction(
		Sequence::create(delayMedio4, fadeIn4, delay4, fadeOut4, nullptr)
		);
	T4_4->runAction(
		Sequence::create(delayMedio4_4, fadeIn4_4, delay4_4, fadeOut4_4, nullptr)
		);

	///////////////////////////////////
	///////////////////////////////////

	auto T5 = Label::createWithSystemFont("AGRADECIMIENTOS ESPECIALES", "fonts/Marker Felt.ttf", 25);
	T5->enableShadow();
	T5->setPosition(Vec2(AN / 2, AL - AL * 0.2));
	T5->setColor(Color3B::RED);
	T5->setOpacity(0);

	this->addChild(T5, 1);

	auto T5_5 = Label::createWithSystemFont("\n - MENTIQ Games     - StackOverFlow \n - PDM     - Futura Materia de Juegos \n - WikiPedia     - Rincon del Vago \n - Yahoo Respuestas     - SDLG \n - MUSCA SR     - DROSS \n - La resurreccion de Jon Snow \n - ZELDA     - POKEMON ", "fonts/Marker Felt.ttf", 20);
	T5_5->enableShadow();
	T5_5->setPosition(Vec2(AN/2, AL/2));
	T5_5->setColor(Color3B::ORANGE);
	T5_5->setOpacity(0);

	this->addChild(T5_5, 1);

	auto fadeIn5 = FadeIn::create(1.0f);
	auto fadeOut5 = FadeOut::create(1.0f);
	auto delay5 = DelayTime::create(15);
	auto fadeIn5_5 = FadeIn::create(1.0f);
	auto fadeOut5_5 = FadeOut::create(1.0f);
	auto delay5_5 = DelayTime::create(15);
	auto delayMedio5 = DelayTime::create(20); //++5
	auto delayMedio5_5 = DelayTime::create(20);

	T5->runAction(
		Sequence::create(delayMedio5, fadeIn5, delay5, fadeOut5, nullptr)
		);
	T5_5->runAction(
		Sequence::create(delayMedio5_5, fadeIn5_5, delay5_5, fadeOut5_5, nullptr)
		);

	///////////////////////////////////
	//ANIMACION HailBEHELIT
	auto HailBEHELIT = Sprite::createWithSpriteFrameName("behelit.png");
	HailBEHELIT->setPosition(Vec2(AN / 2, AL / 2));
	HailBEHELIT->setScaleY(AL*0.6 / HailBEHELIT->getContentSize().height);
	HailBEHELIT->setScaleX(AN*0.9 / HailBEHELIT->getContentSize().width);
	HailBEHELIT->setOpacity(0);
	this->addChild(HailBEHELIT, 2);

	auto fadeIn6 = FadeIn::create(1.0f);
	auto fadeOut6 = FadeOut::create(1.0f);
	auto delay6 = DelayTime::create(5);
	auto delayMedio6 = DelayTime::create(35); //++5

	HailBEHELIT->runAction(
		Sequence::create(delayMedio6, fadeIn6, delay6, fadeOut6, callbackJump, nullptr)
		);

	///////////////////////////////////
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Creditos::intentRegresar, this));

	closeItem->setPosition(Vec2(AN - AN * 0.9, AL - AL*0.85));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(Creditos::onAcceleration, this));

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void Creditos::intentRegresar(Ref * pSender)
{

	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/atras.mp3");

	auto scene = IntroGeneral::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Creditos::onAcceleration(cocos2d::Acceleration * acc, cocos2d::Event * event)
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

	if(   (X<AN-25 && Y<AL-40)  && (X>5 && Y>15)  )  {
	obu->setPosition(X, Y);
		}
		

	Rect Rregresar = btn_regresar->getBoundingBox();


	Rect bbObu = obu->getBoundingBox();


	if (bbObu.intersectsRect(Rregresar)) {

		Creditos::intentRegresar(this);
	}
	
}




