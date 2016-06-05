#include "HelloWorldScene.h"


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
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    label = Label::createWithTTF("puntaje: 0", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    Size TM = Director::getInstance()->getWinSize();

    AN = TM.width;
    AL = TM.height;
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Elementos.plist");
    
    fondo = Sprite::createWithSpriteFrameName("cielo.png");
    fondo->setPosition(Vec2(150, 150));
    fondo->setScale(AL*1.2/fondo->getContentSize().height);
	addChild(fondo);	
	

    
	
		
    puntoVerde = Sprite::createWithSpriteFrameName("planta.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(100, 100));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
   	//addChild(puntoVerde);
   	
   		int ranx = cocos2d::RandomHelper::random_int(1, 300);
		int rany = cocos2d::RandomHelper::random_int(10, 200);
		
   	   	
   	oscuridad = Sprite::createWithSpriteFrameName("oscuridad.png");
    oscuridad->setAnchorPoint(Vec2(0.1, 0.1));
	oscuridad->setPosition(Vec2(ranx, rany));
    oscuridad->setScale(AL*0.1/oscuridad->getContentSize().height);
    
	addChild(oscuridad);
	
			explosion = Sprite::createWithSpriteFrameName("explosion.png");
    		explosion->setAnchorPoint(Vec2(0.1, 0.1));
			explosion->setPosition(Vec2(110, 110));
    		explosion->setScale(AL*0.2/explosion->getContentSize().height);
    		explosion->setVisible(false);
        	fondo:addChild(explosion);
	
	

	/*FUNCION DE LLAMADO Y GENERADOR DE EVENTO DEL ACELEROMETRO*/
	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(HelloWorld::onAcceleration, this));
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	
	
	
    return true;
}




void HelloWorld::crearViento(){
	
	float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
	
	this->removeChild(puntoVerde);
	
	puntoVerde = Sprite::createWithSpriteFrameName("viento.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(X, Y));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
	
}

void HelloWorld::crearFuego(){
	
	float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
	
	this->removeChild(puntoVerde);
	
	puntoVerde = Sprite::createWithSpriteFrameName("fuego.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(X, Y));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
	
}
void HelloWorld::crearAgua(){
	
	float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
	
	this->removeChild(puntoVerde);
	
	puntoVerde = Sprite::createWithSpriteFrameName("agua.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(X, Y));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
	
}
void HelloWorld::crearLuz(){
	
	float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
	
	this->removeChild(puntoVerde);
	
	puntoVerde = Sprite::createWithSpriteFrameName("luz.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(X, Y));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
	
}
void HelloWorld::crearTierra(){
	
	float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
	
	this->removeChild(puntoVerde);
	
	puntoVerde = Sprite::createWithSpriteFrameName("tierra.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(X, Y));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
	
}
void HelloWorld::crearPlanta(){
	
	float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
	
	this->removeChild(puntoVerde);
	
	puntoVerde = Sprite::createWithSpriteFrameName("planta.png");
    puntoVerde->setAnchorPoint(Vec2(0.1, 0.1));
	puntoVerde->setPosition(Vec2(X, Y));
    puntoVerde->setScale(AL*0.1/puntoVerde->getContentSize().height);
    
    addChild(puntoVerde);
	
}


void HelloWorld::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
{
 
    
      #define KFILTERINGFACTOR 0.1
    #define KRESTACCELX -0.6
    #define KSHIPMAXPOINTSPERSEC (winSize.height*0.5)
    #define KMAXDIFFX 0.2

    
    double rollingX;
   
    
    float posX= acc->x;
	float posY =acc->y;	

	Size screenSize = Director::getInstance()->getWinSize();

    float w = screenSize.width;
    float h = screenSize.height;
    
    float X = puntoVerde->getPosition().x;
    float Y = puntoVerde->getPosition().y;
    
    
    X = X + (posX* w *0.03);
    Y = Y + (posY* h *0.03);
    
       CCLOG("aca es X: %f", X);
    CCLOG("aca es Y: %f", Y);
    
    if(   (X<410 && Y<280)  && (X>10 && Y>15)  )  {
    	puntoVerde->setPosition(X, Y);
    	degradado = degradado -10;
    	
    	if(degradado<=0){
    		degradado =0;
    	}
		explosion->setOpacity(degradado);
    }
    else{
    	
    	
    	if(X>410){
    		auto choqueXD = MoveTo::create(1,Point(X-25,Y));
    		puntoVerde->runAction(choqueXD);
    	}else
     	if(X<10){
    		auto choqueXI = MoveTo::create(1,Point(X+25,Y));	
    		puntoVerde->runAction(choqueXI);
    	}else
    	if(Y>280){
    		auto choqueYA = MoveTo::create(1,Point(X,Y-25));
    		puntoVerde->runAction(choqueYA);
    	}else
    	if(Y<15){
    		auto choqueYAb = MoveTo::create(1,Point(X,Y+25));
    		puntoVerde->runAction(choqueYAb);
    	}
    		
    	
    	    	
    	
    }
    
    
    
    
    
    Rect bbObu = puntoVerde->getBoundingBox();
	Rect bbOscuridad = oscuridad->getBoundingBox();
	
	if(bbObu.intersectsRect(bbOscuridad)){
		degradado =250;
		explosion->setOpacity(degradado);
		
		float posx = oscuridad->getPosition().x;
		float posy = oscuridad->getPosition().y;
			
			oscuridad->setVisible(false);
			explosion->setVisible(true);
			explosion->setPosition(Vec2(posx, posy));
		    		
		
		puntaje++;
		int ranx = cocos2d::RandomHelper::random_int(1, 300);
		int rany = cocos2d::RandomHelper::random_int(10, 200);
		
		
		oscuridad->setPosition(Vec2(ranx, rany));

		oscuridad->setVisible(true);
	

		std::string punt = StringUtils::format("puntaje: %d",this->puntaje);
		
		label->setString(punt);
		
		if(puntaje==20){
			HelloWorld::crearViento();
		}else if(puntaje==30){
			HelloWorld::crearFuego();
		}else if(puntaje==40){
			HelloWorld::crearAgua();
		}else if(puntaje==50){
			HelloWorld::crearLuz();
		}else if(puntaje==60){
			HelloWorld::crearTierra();
		}else if(puntaje==70){
			HelloWorld::crearPlanta();
		}
		
		
		
		
	}

  	
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
