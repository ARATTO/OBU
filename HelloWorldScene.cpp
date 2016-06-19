#include "HelloWorldScene.h"
//#include "cocos2d.h"
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

	Size TM = Director::getInstance()->getWinSize();

	AN = TM.width;
	AL = TM.height;

	CCLOG("alto: %f  ancho: %f", AL, AN);
	
	//////////////////////////////////////
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Motto.plist");
	//////////////////////////////////////

	//ANIMACION COCOS
	cocosLogo = Sprite::createWithSpriteFrameName("cocos_logo.png");
	cocosLogo->setPosition(Vec2(AN/2, AL/2));
	cocosLogo->setScaleY(AL*0.7 / cocosLogo->getContentSize().height);
	cocosLogo->setScaleX(AN*0.4 / cocosLogo->getContentSize().width);
	cocosLogo->setOpacity(0);
	this->addChild(cocosLogo, 1);

	//ANIMACION OBU
	auto OBULogo = Sprite::createWithSpriteFrameName("prueba.png");
	OBULogo->setPosition(Vec2(AN / 2, AL / 2));
	OBULogo->setScaleY(AL*0.4 / OBULogo->getContentSize().height);
	OBULogo->setScaleX(AN*0.8 / OBULogo->getContentSize().width);
	OBULogo->setOpacity(0);
	this->addChild(OBULogo, 1);

	//ANIMACION BEHELIT
	auto BEHELITLogo = Sprite::createWithSpriteFrameName("behelit_logo.jpg");
	BEHELITLogo->setPosition(Vec2(AN / 2, AL / 2));
	BEHELITLogo->setScaleY(AL / BEHELITLogo->getContentSize().height);
	BEHELITLogo->setScaleX(AN / BEHELITLogo->getContentSize().width);
	BEHELITLogo->setOpacity(0);
	this->addChild(BEHELITLogo, 1);
	
	auto fadeIn1 = FadeIn::create(5.0f);
	auto fadeOut1 = FadeOut::create(1.0f);
	auto delay1 = DelayTime::create(1);

	auto fadeIn2 = FadeIn::create(5.0f);
	auto fadeOut2 = FadeOut::create(1.0f);
	auto delay2 = DelayTime::create(1);

	auto fadeIn3 = FadeIn::create(5.0f);
	auto fadeOut3 = FadeOut::create(1.0f);
	auto delay3 = DelayTime::create(1);


	auto delayMedio1 = DelayTime::create(7);
	auto delayMedio2 = DelayTime::create(14);


	auto callbackJump = CallFunc::create([]() {
		auto scene = IntroGeneral::createScene();
		Director::getInstance()->replaceScene(scene);
	});



	cocosLogo->runAction(
		Sequence::create(fadeIn1,delay1, fadeOut1, nullptr)
		);

	OBULogo->runAction(
		Sequence::create(delayMedio1,fadeIn2, delay2, fadeOut2, nullptr)
		);
	
	BEHELITLogo->runAction(
		Sequence::create(delayMedio2,fadeIn3, delay3, fadeOut3, callbackJump, nullptr)
		);


    return true;
}




