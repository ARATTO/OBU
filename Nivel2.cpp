#include "Nivel2.h"
#include "SimpleAudioEngine.h"


#include "Nivel3.h"
#include "sqlite3.h"
#include "IntroGeneral.h"
USING_NS_CC;

Scene* Nivel2::createScene(){
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Nivel2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Nivel2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
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
    
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("audio/mainMarcos.mp3", true);
	
	
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Nivel2::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


	cerrar = Sprite::create("CloseSelected.png"); 
	cerrar->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

   	addChild(cerrar);
   	
   	//felicidades = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
   	//felicidades->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
   	
   	
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    label = Label::createWithTTF("puntaje: 0", "fonts/Marker Felt.ttf", 20);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(40,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
	salud = Label::createWithTTF("Salud", "fonts/Marker Felt.ttf", 25);   
    salud->setPosition(Vec2(50,230));
    
    this->addChild(salud, 2);
    
    numNivel = Label::createWithTTF("2", "fonts/Marker Felt.ttf", 25); 
     
    Size TM = Director::getInstance()->getWinSize();

    AN = TM.width;
    AL = TM.height;
    
    CCLOG("alto: %f  ancho: %f",AL,AN);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Elementos.plist");
    
    fondo = Sprite::createWithSpriteFrameName("cielo.png");
    fondo->setPosition(Vec2(225, 150));
    fondo->setScaleY(AL*1.0/fondo->getContentSize().height);
    fondo->setScaleX(AN*1.1/fondo->getContentSize().width);
	addChild(fondo);
	
	
	BarraVertical = Sprite::createWithSpriteFrameName("barra.png");
    BarraVertical->setPosition(Vec2(105, 150));
    //BarraVertical->setScaleY(AL*0.8/BarraVertical->getContentSize().height);
    //BarraVertical->setScaleX(AN*0.08/BarraVertical->getContentSize().width);
    BarraVertical->setScale(AL*1.1/BarraVertical->getContentSize().height);
	addChild(BarraVertical);	
	
	/*BarraHorizontal = Sprite::createWithSpriteFrameName("barra 2.png");
    BarraHorizontal->setPosition(Vec2(105, 250));
    BarraHorizontal->setScale(AL*0.07/BarraHorizontal->getContentSize().height);
	addChild(BarraHorizontal);*/

  	Spausa = Sprite::createWithSpriteFrameName("botonPausa.png");
    Spausa->setPosition(Vec2(134, 25));
    Spausa->setScale(AL*0.05/Spausa->getContentSize().height);
	addChild(Spausa);
  
	explosion = Sprite::createWithSpriteFrameName("explosion.png");
 	//explosion->setAnchorPoint(Vec2(0.1, 0.1));
	explosion->setPosition(Vec2(110, 110));
   	explosion->setScale(AL*0.2/explosion->getContentSize().height);
   	explosion->setVisible(false);
   	fondo:addChild(explosion);
	 
	
	vida1 = Sprite::createWithSpriteFrameName("vida+1.png");
 	//explosion->setAnchorPoint(Vec2(0.1, 0.1));
	vida1->setPosition(Vec2(50, 180));
   	vida1->setScale(AL*0.15/vida1->getContentSize().height);
   	addChild(vida1);
	   
	vida2 = Sprite::createWithSpriteFrameName("vida+2.png");
 	//explosion->setAnchorPoint(Vec2(0.1, 0.1));
	vida2->setPosition(Vec2(50, 160));
   	vida2->setScale(AL*0.15/vida2->getContentSize().height);
   	
   	addChild(vida2);  
	
	vida3 = Sprite::createWithSpriteFrameName("vida+3.png");
 	//explosion->setAnchorPoint(Vec2(0.1, 0.1));
	vida3->setPosition(Vec2(50, 140));
   	vida3->setScale(AL*0.15/vida3->getContentSize().height);
   	
   	nivel = Sprite::createWithSpriteFrameName("hexagono vida.png");
 	nivel->setPosition(Vec2(50, 80));
   	nivel->setScale(AL*0.2/nivel->getContentSize().height);
   	
   	addChild(nivel);
   	
   	numNivel->setPosition(Vec2(50,80));
    
    this->addChild(numNivel, 3);
   	
   	addChild(vida3);
	
	dark.reserve(5);
	light.reserve(6);
	fire.reserve(5);
	
	for (int i=2;i < 10; i++){
		
		if(i%2==0){
			ranOXmin+=(AN-130)/10;
			ranOXmax = ranOXmin+20;
			
			CCLOG("minimo X: %i",ranOXmin);

		}else{
			ranOXmin+=(AN-130)/10 +5;
			ranOXmax= ranOXmin+15;

			CCLOG("minimo X: %i",ranOXmin);
		}

		ranx = cocos2d::RandomHelper::random_int(ranOXmin, ranOXmax);
		rany = cocos2d::RandomHelper::random_int(40, 130);	
		
		
	if(i==3 || i==6 || i==9){
		
		luz = Sprite::createWithSpriteFrameName("luz.png");
    	//luz->setAnchorPoint(Vec2(0.1, 0.1));
		luz->setPosition(Vec2(ranx, rany));
    	luz->setScale(AL*0.1/luz->getContentSize().height);
    	luz->setTag(i);
    
    	light.push_back(luz);
    
		addChild(luz);	
		
	}else if(i==4 || i==7){
		oscuridad1 = Sprite::createWithSpriteFrameName("oscuridad.png");
    	//oscuridad1->setAnchorPoint(Vec2(0.1, 0.1));
		oscuridad1->setPosition(Vec2(ranx, rany));
    	oscuridad1->setScale(AL*0.1/oscuridad1->getContentSize().height);
    	oscuridad1->setTag(i);
    
    	dark.push_back(oscuridad1);
    
		addChild(oscuridad1);
			
	}else{
		fuego = Sprite::createWithSpriteFrameName("fuego.png");
		fuego->setPosition(Vec2(ranx, rany));
    	fuego->setScale(AL*0.1/fuego->getContentSize().height);
    	fuego->setTag(i);
    
    	fire.push_back(fuego);
    
		addChild(fuego);
	}
   	
		
	}
	
	ranOXmin=140;
	ranOXmax=0;
	
		for (int i=12;i < 20; i++){
		
		if(i%2==0){
			ranOXmin+=(AN-130)/10;
			ranOXmax = ranOXmin+20;
			
			CCLOG("minimo X: %i",ranOXmin);

		}else{
			ranOXmin+=(AN-130)/10 +5;
			ranOXmax= ranOXmin+15;

			CCLOG("minimo X: %i",ranOXmin);
		}

		ranx = cocos2d::RandomHelper::random_int(ranOXmin, ranOXmax);
		rany = cocos2d::RandomHelper::random_int(160, 275);	
		
		
	if(i==14 || i==16 || i==18){
		
		luz = Sprite::createWithSpriteFrameName("luz.png");
    	//luz->setAnchorPoint(Vec2(0.1, 0.1));
		luz->setPosition(Vec2(ranx, rany));
    	luz->setScale(AL*0.1/luz->getContentSize().height);
    	luz->setTag(i);
    
    	light.push_back(luz);
    
		addChild(luz);	
		
	}else if(i==12 || i==17 || i==19){
		oscuridad1 = Sprite::createWithSpriteFrameName("oscuridad.png");
    	//oscuridad1->setAnchorPoint(Vec2(0.1, 0.1));
		oscuridad1->setPosition(Vec2(ranx, rany));
    	oscuridad1->setScale(AL*0.1/oscuridad1->getContentSize().height);
    	oscuridad1->setTag(i);
    
    	dark.push_back(oscuridad1);
    
		addChild(oscuridad1);
			
	}else{
		fuego = Sprite::createWithSpriteFrameName("fuego.png");
		fuego->setPosition(Vec2(ranx, rany));
    	fuego->setScale(AL*0.1/fuego->getContentSize().height);
    	fuego->setTag(i);
    
    	fire.push_back(fuego);
    
		addChild(fuego);
	}
   	
		
	}
	
	obu = Sprite::createWithSpriteFrameName("obu.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(125, 100));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
    
    cambioAgua = Sprite::createWithSpriteFrameName("aguaCambio.png");
	cambioAgua->setPosition(Vec2(135, 250));
    cambioAgua->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(cambioAgua);
   	
   	 obuPausa = Sprite::createWithSpriteFrameName("obu.png");
     obuPausa->setAnchorPoint(Vec2(0.1, 0.1));
	 obuPausa->setPosition(Vec2(200, 100));
     obuPausa->setScale(AL*0.1/obu->getContentSize().height);
     obuPausa->setVisible(false);
    
	 addChild(obuPausa);
	 
	 siguiente = Sprite::createWithSpriteFrameName("siguiente.png");
   	 siguiente->setPosition(Vec2(125, 100));
     siguiente->setScale(AL*0.2/siguiente->getContentSize().height);
     siguiente->setVisible(false);
    
	 addChild(siguiente);
	 
	 atras= Sprite::createWithSpriteFrameName("atras.png");
   	 atras->setPosition(Vec2(125, 100));
     atras->setScale(AL*0.2/atras->getContentSize().height);
     atras->setVisible(false);
    
	 addChild(atras);
	 
	 home = Sprite::createWithSpriteFrameName("home.png");
   	 home->setPosition(Vec2(125, 100));
     home->setScale(AL*0.2/home->getContentSize().height);
     home->setVisible(false);
    
	 addChild(home);
	 
	 reinicio = Sprite::createWithSpriteFrameName("reiniciar.png");
   	 reinicio->setPosition(Vec2(125, 100));
     reinicio->setScale(AL*0.2/reinicio->getContentSize().height);
     reinicio->setVisible(false);
    
	 addChild(reinicio);
	 

	 play = Sprite::createWithSpriteFrameName("play.png");
   	 play->setPosition(Vec2(125, 100));
     play->setScale(AL*0.2/play->getContentSize().height);
     play->setVisible(false);
    
	 addChild(play);
	 
	 SPausa = Sprite::createWithSpriteFrameName("pausa.png");
	 SPausa->setAnchorPoint(Vec2(0.1, 0.1));
	 SPausa->setPosition(Vec2(AN/2 - 40, AL/2+50));
	 SPausa->setScale(AL*0.3/SPausa->getContentSize().height);
	 SPausa->setVisible(false);
	    	
	 addChild(SPausa);
	 
	 CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/explo.mp3");
	

	

	/*FUNCION DE LLAMADO Y GENERADOR DE EVENTO DEL ACELEROMETRO*/
	Device::setAccelerometerEnabled(true);
	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(Nivel2::onAcceleration, this));
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	
	
	
	
	
	CCLOG("SE TERMINO EL INIT");
	
    return true;
}



void Nivel2::crearObu(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("obu.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}


void Nivel2::crearViento(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("viento.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}

void Nivel2::crearFuego(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("fuego.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void Nivel2::crearAgua(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("agua.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void Nivel2::crearLuz(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("luz.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void Nivel2::crearTierra(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("tierra.png");
    //obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}
void Nivel2::crearPlanta(){
	
	float X = obu->getPosition().x;
    float Y = obu->getPosition().y;
	
	this->removeChild(obu);
	
	obu = Sprite::createWithSpriteFrameName("planta.png");
   // obu->setAnchorPoint(Vec2(0.1, 0.1));
	obu->setPosition(Vec2(X, Y));
    obu->setScale(AL*0.1/obu->getContentSize().height);
    
    addChild(obu);
	
}


void Nivel2::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
{
    
    float posX= acc->x;
	float posY =acc->y;	

	Size screenSize = Director::getInstance()->getWinSize();

    float w = screenSize.width;
    float h = screenSize.height;
    
  
    
      
   	   
   	   
   	if(puntajeL!=6 && vida>0 && pausa==0)   {
   		obu->setVisible(true);
   		SPausa->setVisible(false); 
   		siguiente->setVisible(false); 
   		obuPausa->setVisible(false); 
   		
   		 float X = obu->getPosition().x;
    	 float Y = obu->getPosition().y;
    
    
    	X = X + (posX* w *0.03);
    	Y = Y + (posY* h *0.03);
    	
    	 CCLOG("aca es X: %f", X);
   	     CCLOG("aca es Y: %f", Y);
   		
   		  if(   (X<AN-25 && Y<AL-40)  && (X>115 && Y>30)  )  {
    			obu->setPosition(X, Y);
    			degradado = degradado -10;
    	
    			if(degradado<=0){
    					degradado =0;
    			}
				explosion->setOpacity(degradado);
				
    		}
    		
    		
    		
    		float ancho = obu->getScaleX(); 
			float alto = obu->getScaleY();
		
    		Rect bbObu = obu->getBoundingBox();	
    		
    		Rect Cagua = cambioAgua->getBoundingBox();
    		
    		if(bbObu.intersectsRect(Cagua)){
    			agua=1;
    			cambioAgua->setVisible(false);
    			Nivel2::crearAgua();
    		}
	
			for(auto sp : dark){	
				
				sp->setVisible(true);
				
				Rect bbOscuridad = sp->getBoundingBox();
				
				
				float X = sp->getPosition().x;
		    	float Y = sp->getPosition().y;
		    	
		    	float r = sp->getScaleX();
		
				
				if(bbObu.intersectsCircle( Vec2(X, Y) , r+2.0) ){
				    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/explo.mp3");
					degradado =250;
					explosion->setOpacity(degradado);
		
					float posx = obu->getPosition().x;
					float posy = obu->getPosition().y;
				
					obu->setVisible(false);
					explosion->setPosition(Vec2(posx, posy));
					explosion->setVisible(true);
				
					obu->setPosition(Vec2(120, 150));
					obu->setVisible(true);
					
					cambioAgua->setVisible(true);
					Nivel2::crearObu();
						
					vida--;
					
					if(vida==2){
						vida3->setVisible(false);
					}else if(vida==1){
						vida2->setVisible(false);
					}else if(vida==0){
						vida1->setVisible(false);
						siguiente->setPosition(390, AL/2-80);	
					
						obu->setPosition(200, AL/2-70);
					}
					
				}
	

			}
			
		
		for(auto sp : fire){	
				
				//sp->setVisible(true);
				
				Rect bbFuego = sp->getBoundingBox();
				
				
				float X = sp->getPosition().x;
		    	float Y = sp->getPosition().y;
		    	
		    	float r = sp->getScaleX();
		
				
				if(bbObu.intersectsCircle( Vec2(X, Y) , r+2.0)  && agua==0){
				    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/explo.mp3");
					degradado =250;
					explosion->setOpacity(degradado);
		
					float posx = obu->getPosition().x;
					float posy = obu->getPosition().y;
				
					obu->setVisible(false);
					explosion->setPosition(Vec2(posx, posy));
					explosion->setVisible(true);
				
					obu->setPosition(Vec2(120, 100));
					obu->setVisible(true);
						
					vida--;
					
					if(vida==2){
						vida3->setVisible(false);
					}else if(vida==1){
						vida2->setVisible(false);
					}else if(vida==0){
						vida1->setVisible(false);
						siguiente->setPosition(390, AL/2-80);	
					
						obu->setPosition(200, AL/2-70);
					}
					
				}else if(bbObu.intersectsCircle( Vec2(X, Y) , r+2.0)  && agua==1){
					
					if(sp->isVisible()){
						
						sp->setVisible(false);
					
						puntaje+=2;
			
						std::string punt = StringUtils::format("puntaje: %d",this->puntaje);
					
						label->setString(punt);
											
					}
					
				}
	

			}
	
	
			for(auto sp : light){

				Rect bbLuz= sp->getBoundingBox();
			
				float X = sp->getPosition().x;
		    	float Y = sp->getPosition().y;
		    	
		    	float r = sp->getScaleX();
		    		
				
				if(bbObu.intersectsCircle( Vec2(X, Y) , r+2.0) ){
				
				
					if(sp->isVisible()){
						
						sp->setVisible(false);
					
						puntaje++;
						puntajeL++;
			
						std::string punt = StringUtils::format("puntaje: %d",this->puntaje);
					
						label->setString(punt);
						
						if(puntajeL==6){
							obu->setPosition(250, AL/2-30);
							
							
							/*INSERTA EN LA TABLA*/
					   		
					   		   char **re;
				    			int r,c;

					   		
					   		sqlite3_get_table(pdb,"select * from game",&re,&r,&c,NULL);
					   		
					   		lvl2=r+1;
					   		
					   		std::string llave2 = StringUtils::format("%d",this->lvl2);
							std::string score = StringUtils::format("%d",this->puntaje);
			
					   		sql="insert into game  values('"+ llave2 +  "','" + score + "',2)";
					   		    
				    			result=sqlite3_exec(pdb,sql.c_str(),NULL,NULL,NULL);
				    				if(result!=SQLITE_OK)
				        				CCLOG("FALLO DE INSERCION!");
				        	/*INSERTA EN LA TABLA*/
					   		
					   		
					   		/*SACA DE LA BASE*/
					   		 
				    			sqlite3_get_table(pdb,"select * from game",&re,&r,&c,NULL);//1
				    				CCLOG("row is %d,column is %d",r,c);
				
							    for(int i=1;i<=r;i++)//2
							    {
							        for(int j=0;j<c;j++)
							        {
							            CCLOG("%s",re[i*c+j]);
							        }
							    }
							    sqlite3_free_table(re);
							/*SACA DE LA BASE*/
							
						}
					
					}
	
				
				}
	
			}	
		
	
			Rect Rcerrar = cerrar->getBoundingBox();
			Rect Rpausa = Spausa->getBoundingBox();
			
			if(bbObu.intersectsRect(Rcerrar)){
				//pausa = 1;
				//obu->setPosition(X-20, Y);
				Nivel2::cerrarPantalla();
			}else if(bbObu.intersectsRect(Rpausa)){
				pausa = 1;
				obu->setPosition(X, 175);
			}
    		
   		}else if(vida==0){
 			obu->setVisible(true);
	   		SPausa->setVisible(false); 
	   		obuPausa->setVisible(false); 
	   		
	   		
	   		float XP = obu->getPosition().x;
	   		 XP = XP + (posX* w *0.03);

	   			if(XP>120 && XP<400){
	   				obu->setPosition(XP, AL/2-70);	
	   			}
	   			
    			degradado = degradado -10;
    	
    			if(degradado<=0){
    					degradado =0;
    				}
				explosion->setOpacity(degradado);
	   		
	   		
	   		
	   		for(auto sp : dark) {
	   			this->removeChild(sp,true);
	   		}
	   		
	   		dark.erase(dark.begin(),dark.end());	
	   		
	   		for(auto sp: light){
	   			this->removeChild(sp,true);
	   		}
	   		
	   		light.erase(light.begin(),light.end());
	   		
	   		
	   		for(auto sp: fire){
	   			this->removeChild(sp,true);
	   		}
	   		
	   		fire.erase(fire.begin(),fire.end());
	   		
	   		this->removeChild(cambioAgua,true);
	   		
	   		HPV = Sprite::createWithSpriteFrameName("adiosVaquero.png");
			HPV->setPosition(Vec2(AN/2 +50, AL/2 +70));
	    	HPV->setScale(AL*0.4/HPV->getContentSize().height);
	    	
	    	addChild(HPV);
	    	
	    	reinicio->setPosition(390, 100);
	   		reinicio->setVisible(true); 
	   		
	   		Rect obuP = obu->getBoundingBox();
	   		Rect SPe =  reinicio->getBoundingBox();
	   		
	   		if(obuP.intersectsRect(SPe)){
	   			
	   			Nivel2::reiniciar();
	   			
	   		}
	   		
	   		
   		
	   	}else if(puntajeL==6){
	   		obu->setVisible(true);
	   		SPausa->setVisible(false); 
	   		obuPausa->setVisible(false); 
	   		
	   		
	   		float X1 = obu->getPosition().x;
	   		 X1 = X1 + (posX* w *0.03);
	   		 
	   			
	   		
	   			if(X1>120 && X1<400){
	   				obu->setPosition(X1, AL/2-30);	
	   			}
	   			
    			degradado = degradado -10;
    	
    			if(degradado<=0){
    					degradado =0;
    				}
				explosion->setOpacity(degradado);
	   		
	   		
	   		
	   		for(auto sp : dark) {
	   			this->removeChild(sp,true);
	   		}
	   		
	   		dark.erase(dark.begin(),dark.end());	
	   		
	   		for(auto sp: light){
	   			this->removeChild(sp,true);
	   		}
	   		
	   		light.erase(light.begin(),light.end());
	   		
	   		for(auto sp: fire){
	   			this->removeChild(sp,true);
	   		}
	   		
	   		fire.erase(fire.begin(),fire.end());
	   		
	   		this->removeChild(cambioAgua,true);
	   		
	   		gano = Sprite::createWithSpriteFrameName("felicidades.png");
			gano->setPosition(Vec2(AN/2 +50, AL/2 +80));
	    	gano->setScale(AL*0.3/gano->getContentSize().height);
	    	
	    	addChild(gano);	
	    	
	    	siguiente->setPosition(390, AL/2-20);	
	   		siguiente->setVisible(true); 
	   		
	   		home->setPosition(160, AL/2-20);	
	   		home->setVisible(true); 
	   		
	   		Rect obuS = obu->getBoundingBox();
	   		Rect Si =  siguiente->getBoundingBox();
	   		Rect HO =  home->getBoundingBox();
	   		
	   		if(obuS.intersectsRect(Si)){
	   			
	   			Nivel2::siguienteNivel();
	   			
	   		}else if(obuS.intersectsRect(HO)){
	   			/*CODIGO PÁRA QUE SE VAYA AL MENU PRINCIPAL*/
	   			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/atras.mp3");

				auto scene = IntroGeneral::createScene();
				Director::getInstance()->replaceScene(scene);
			   }
	    
	    	
	   	}
	   	else if(pausa==1){
	   		
	   		for (auto sp : dark){
	   			sp->setVisible(false);
	   		}
	   		
	   		/*for(auto sp: fire){
	   			sp->setVisible(false);
	   		}*/
	   		
	   		
	   		
	   		obu->setVisible(false);
	   		
	   		float X1 = obuPausa->getPosition().x;
	   		 X1 = X1 + (posX* w *0.03);
	   			
	   			if(X1>120 && X1<400){
	   				obuPausa->setPosition(X1, AL/2-30);	
	   			}
	   		
	   		obuPausa->setVisible(true); 
	   		
	   		play->setPosition(390, AL/2 -20);	
	   		play->setVisible(true); 
	   		
	   		home->setPosition(160, AL/2 -20);	
	   		home->setVisible(true); 
	   		
	   		
	   		SPausa->setVisible(true);
	   		
	   		Rect OB = obuPausa->getBoundingBox();
	   		Rect S =  play->getBoundingBox();
	   		Rect H =  home->getBoundingBox();
	   		
	   		if(OB.intersectsRect(S)){
	   			pausa=0;
	   			 obuPausa->setPosition(Vec2(200, 100));
	   			 play->setVisible(false);
	   			 	home->setVisible(false); 
	   		}else if(OB.intersectsRect(H)){
	   			/*CODIGO PÁRA QUE SE VAYA AL MENU PRINCIPAL*/
	   			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/atras.mp3");

				auto scene = IntroGeneral::createScene();
				Director::getInstance()->replaceScene(scene);
			   }
	   	
	   		
	   	}
   			 

}


void Nivel2::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



void Nivel2::cerrarPantalla(){
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}




void Nivel2::reiniciar(){
	auto scene = Nivel2::createScene();
	Director::getInstance()->pushScene(scene);
}


void Nivel2::siguienteNivel(){
	auto scene = Nivel3::createScene();
	Director::getInstance()->pushScene(scene);
}

    /*
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
  	
    	
    }*/
    
		
		/*
		if(puntaje==20){
			Nivel2::crearViento();
		}else if(puntaje==30){
			Nivel2::crearFuego();
		}else if(puntaje==40){
			Nivel2::crearAgua();
		}else if(puntaje==50){
			Nivel2::crearLuz();
		}else if(puntaje==60){
			Nivel2::crearTierra();
		}else if(puntaje==70){
			Nivel2::crearPlanta();
		}*/
