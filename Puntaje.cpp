#include "Puntaje.h"
#include "IntroGeneral.h"
#include "cocos2d.h"
#include "ObuWorld.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* Puntaje::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Puntaje::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Puntaje::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	
	pdb=NULL;//1
    std::string path= FileUtils::getInstance()->getWritablePath()+"obu.s3db";//2   
	    
    result=sqlite3_open(path.c_str(),&pdb);//3
    if(result!=SQLITE_OK)
    {
        CCLOG("open database failed,  number%d",result);
    }


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	double alto = visibleSize.height;
	double ancho = visibleSize.width;

	Size TM = Director::getInstance()->getWinSize();

	AN = TM.width;
	AL = TM.height;

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

	auto titulo = Label::createWithSystemFont("PUNTAJE", "fonts/Marker Felt.ttf", 35);
	titulo->enableShadow();
	titulo->enableOutline(Color4B::BLACK, 2);
	titulo->setPosition(Vec2(AN / 2, AL - AL * 0.2));

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
		CC_CALLBACK_1(Puntaje::intentRegresar, this));

	closeItem->setPosition(Vec2(AN - AN * 0.95, AL - AL*0.85));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	///////////////////////////////////
	
	
		/*SACA DE LA BASE*/
			char **re;
			  int r,c;
				   		
   			sqlite3_get_table(pdb,"select * from game order by ID DESC ",&re,&r,&c,NULL);//1
			CCLOG("row is %d,column is %d",r,c);
				int p =2;
				int valores=0;
				
				
		    for(int i=1;i<=r;i++)//2
			    {
		        //for(int j=1;j<c;j++)
			      //  {
			        
			        std::string score = StringUtils::format("%s",re[i*c+1]);
			        
			        auto puntaje = Label::createWithSystemFont("PUNTAJE: "+score, "fonts/Marker Felt.ttf", 20);
			        puntaje->setPosition(140, pos);
			        
			        addChild(puntaje,p);
			        p++;
			        
			        
			        std::string nivel = StringUtils::format("%s",re[i*c+2]);
			        
			        auto level = Label::createWithSystemFont("NIVEL: "+nivel, "fonts/Marker Felt.ttf", 20);
			        level->setPosition(300, pos);
			        
			        addChild(level,p);
			        
			        p++;
			        pos = pos-40;
		            CCLOG("puntaje: %s",re[i*c+1]);
		            CCLOG("nivel: %s",re[i*c+2]);
			      //  }
			      valores++;
			        
			        if(valores==5){
			        	break;
			        }
			        
	   		    }
		    sqlite3_free_table(re);
 	/*SACA DE LA BASE*/
	
	
	

	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(Puntaje::onAcceleration, this));

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void Puntaje::intentRegresar(Ref * pSender)
{
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/atras.mp3");

	auto scene = IntroGeneral::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Puntaje::onAcceleration(cocos2d::Acceleration * acc, cocos2d::Event * event)
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
	
	if(   (X<AN-25 && Y<AL-40)  && (X>5 && Y>15))  {
	obu->setPosition(X, Y);
		}

	Rect Rregresar = btn_regresar->getBoundingBox();


	Rect bbObu = obu->getBoundingBox();


	if (bbObu.intersectsRect(Rregresar)) {
		Puntaje::intentRegresar(this);
	}
	


}




