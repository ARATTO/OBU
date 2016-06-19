#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "sqlite3.h"

class HelloWorld : public cocos2d::Layer
{
private:

	
	cocos2d::Sprite *obu;
	cocos2d::Sprite *vida1;
	cocos2d::Sprite *vida2;
	cocos2d::Sprite *vida3;
	cocos2d::Sprite *oscuridad1;
	cocos2d::Sprite *explosion;
	cocos2d::Sprite *fondo;
	cocos2d::Sprite *BarraHorizontal;
	cocos2d::Sprite *BarraVertical;
	cocos2d::Sprite *luz;
	cocos2d::Sprite *gano;
	cocos2d::Sprite *obuPausa;
	cocos2d::Sprite *SPausa;
	cocos2d::Sprite *siguiente;
	cocos2d::Sprite *play;
	cocos2d::Sprite *atras;
	cocos2d::Sprite *home;
	cocos2d::Sprite *reinicio;
	cocos2d::Sprite *Spausa;
	cocos2d::Sprite *HPV;
	cocos2d::Sprite *nivel;
	cocos2d::Label *label;
	cocos2d::Label *salud;
	cocos2d::Label *numNivel;
	cocos2d::Label *felicidades;
	std::vector<cocos2d::Sprite*> dark;
	std::vector<cocos2d::Sprite*> light;
	cocos2d::Sprite *cerrar;
	
	
	sqlite3 *pdb=NULL;
	int result;
	std::string sql;
	
	
	float _shipPointsPerSecY;
	int puntaje=0;
	float AN;
	float AL;
	float degradado=250;
	int ranx;
	int rany;
	int ranOXmin=145;
	int ranOXmax;
	int vida =3;
	int pausa =0;
	int lvl1;

	
	
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void cerrarPantalla();
    void reiniciar();
    void siguienteNivel();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    //METODO DE ACELEROMETRO
    void  onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
};

#endif // __HELLOWORLD_SCENE_H__

