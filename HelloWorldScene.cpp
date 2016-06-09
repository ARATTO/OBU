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
    
    label = Label::createWithTTF("puntaje: 0", "fonts/Marker Felt.ttf", 18);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(38,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    Size TM = Director::getInstance()->getWinSize();

    AN = TM.width;
    AL = TM.height;
    
    CCLOG("alto: %f  ancho: %f",AL,AN);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Elementos.plist");
    
    fondo = Sprite::createWithSpriteFrameName("cielo.png");
    fondo->setPosition(Vec2(293, 150));
    fondo->setScaleY(AL*1.0/fondo->getContentSize().height);
    fondo->setScaleX(AN*0.80/fondo->getContentSize().width);
	addChild(fondo);	
	

    
	
		
    obu = Sprite::createWithSpriteFrameName("obu.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(125, 100));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
   	
   	
  
	
	explosion = Sprite::createWithSpriteFrameName("explosion.png");
 	explosion->setAnchorPoint(Vec2(0.1, 0.1));
	explosion->setPosition(Vec2(110, 110));
   	explosion->setScale(AL*0.2/explosion->getContentSize().height);
   	explosion->setVisible(false);
   	fondo:addChild(explosion);
	
	dark.reserve(8);
	dark.reserve(3);
	
	for (int i=2;i < dark.capacity()+5; i++){
		
		if(i%2==0){
			ranOXmin+=(AN-130)/10  - 5;
			ranOXmax = ranOXmin+20;
			
			CCLOG("minimo X: %i",ranOXmin);

		}else{
			ranOXmin+=(AN-130)/10;
			ranOXmax= ranOXmin+15;

			CCLOG("minimo X: %i",ranOXmin);
		}

		ranx = cocos2d::RandomHelper::random_int(ranOXmin, ranOXmax);
		rany = cocos2d::RandomHelper::random_int(10, 290);	
		
		
	if(i==4 || i== 7 || i==10){
		
		luz = Sprite::createWithSpriteFrameName("luz.png");
    	luz->setAnchorPoint(Vec2(0.1, 0.1));
		luz->setPosition(Vec2(ranx, rany));
    	luz->setScale(AL*0.1/oscuridad1->getContentSize().height);
    	luz->setTag(i);
    
    	light.push_back(luz);
    
		addChild(luz);	
		
	}else
	{
		oscuridad1 = Sprite::createWithSpriteFrameName("oscuridad.png");
    	oscuridad1->setAnchorPoint(Vec2(0.1, 0.1));
		oscuridad1->setPosition(Vec2(ranx, rany));
    	oscuridad1->setScale(AL*0.1/oscuridad1->getContentSize().height);
    	oscuridad1->setTag(i);
    
    	dark.push_back(oscuridad1);
    
		addChild(oscuridad1);	
	}
   	
		
	}
	
	

	/*FUNCION DE LLAMADO Y GENERADOR DE EVENTO DEL ACELEROMETRO*/
	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(HelloWorld::onAcceleration, this));
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	
	CCLOG("SE TERMINO EL INIT");
	
    return true;
}




void HelloWorld::crearViento(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("viento.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}

void HelloWorld::crearFuego(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("fuego.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void HelloWorld::crearAgua(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("agua.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void HelloWorld::crearLuz(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("luz.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void HelloWorld::crearTierra(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("tierra.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void HelloWorld::crearPlanta(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("planta.png");
    obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}


void HelloWorld::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
{
    
    float posX= acc->x;
	float posY =acc->y;	

	Size screenSize = Director::getInstance()->getWinSize();

    float w = screenSize.width;
    float h = screenSize.height;
    
    float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
    
    
    X = X + (posX* w *0.03);
    Y = Y + (posY* h *0.03);
    
       CCLOG("aca es X: %f", X);
   	   CCLOG("aca es Y: %f", Y);
    
    if(   (X<480 && Y<280)  && (X>111 && Y>15)  )  {
    	obu->setPosition(X, Y);
    	degradado = degradado -10;
    	
    	if(degradado<=0){
    		degradado =0;
    	}
		explosion->setOpacity(degradado);
    }
    else{
    	
    	
    	if(X>460){
    		auto choqueXD = MoveTo::create(1,Point(X-25,Y));
    		obu->runAction(choqueXD);
    	}else
     	if(X<115){
    		auto choqueXI = MoveTo::create(1,Point(X+25,Y));	
    		obu->runAction(choqueXI);
    	}else
    	if(Y>280){
    		auto choqueYA = MoveTo::create(1,Point(X,Y-25));
    		obu->runAction(choqueYA);
    	}else
    	if(Y<15){
    		auto choqueYAb = MoveTo::create(1,Point(X,Y+25));
    		obu->runAction(choqueYAb);
    	}
  	
    	
    }
    
		float ancho = obu->getScaleX(); 
		float alto = obu->getScaleY();
		
    	Rect bbObu = obu->getBoundingBox();	

	
	for(auto sp : dark){
		
		Rect bbOscuridad = sp->getBoundingBox();
		
		float X = sp->getPosition().x;
    	float Y = sp->getPosition().y;
    	
    	float r = sp->getScaleX();
    	
    	CCLOG("el tamano de X es: %f",r);

		
		if(bbObu.intersectsCircle( Vec2(X, Y) , r+0.2) ){
		degradado =250;
		explosion->setOpacity(degradado);

			float posx = obu->getPosition().x;
			float posy = obu->getPosition().y;
		
			obu->setVisible(false);
			explosion->setPosition(Vec2(posx, posy));
			explosion->setVisible(true);
		
			obu->setPosition(Vec2(120, 100));
			obu->setVisible(true);
				
		
		}
	

	}
	
	
		for(auto sp : light){
			int i= 0;
			
			Rect bbLuz= sp->getBoundingBox();
		
			float X = sp->getPosition().x;
	    	float Y = sp->getPosition().y;
	    	
	    	float r = sp->getScaleX();
	    	
	    	CCLOG("el tamano de X es: %f",r);
	
			
			if(bbObu.intersectsCircle( Vec2(X, Y) , r+0.2) ){
			
				sp->setVisible(false);
				
				puntaje++;
		
				std::string punt = StringUtils::format("puntaje: %d",this->puntaje);
				
				label->setString(punt);
				
				light.erase(light.begin()+i);	
				
			}
			
			i++;
		}
			
	
	 

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



		
		/*
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
		}*/
