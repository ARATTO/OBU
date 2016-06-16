#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"



class HelloWorld : public cocos2d::Layer
{
private:

	
	cocos2d::Sprite *obu;
	cocos2d::Sprite *oscuridad1;
	cocos2d::Sprite *explosion;
	cocos2d::Sprite *fondo;
	cocos2d::Sprite *luz;
	cocos2d::Sprite *gano;
	cocos2d::Sprite *obuPausa;
	cocos2d::Sprite *SPausa;
	cocos2d::Sprite *siguiente;
	cocos2d::Label *label;
	cocos2d::Label *HPV;
	cocos2d::Label *felicidades;
	std::vector<cocos2d::Sprite*> dark;
	std::vector<cocos2d::Sprite*> light;
	cocos2d::Sprite *cerrar;
	
	
	float _shipPointsPerSecY;
	int puntaje=0;
	float AN;
	float AL;
	float degradado=250;
	int ranx;
	int rany;
	int ranOXmin=120;
	int ranOXmax;
	int vida =3;
	int pausa =0;

	void crearViento();
	void crearFuego();
	void crearAgua();
	void crearLuz();
	void crearTierra();
	void crearPlanta();
	
	
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void cerrarPantalla();
    void pausar();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void  onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
    void  update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__

