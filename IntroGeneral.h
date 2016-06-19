#ifndef __INTROGENERAL_H__
#define __INTROGENERAL_H__

#include "cocos2d.h"


class IntroGeneral: public cocos2d::Layer
{
private:

	cocos2d::Sprite *obu;
	cocos2d::Sprite *btn_jugar;
	cocos2d::Sprite *btn_niveles;
	cocos2d::Sprite *btn_puntaje;
	cocos2d::Sprite *btn_creditos;
	cocos2d::Sprite *btn_cerrar;

	float AN;
	float AL;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void intentObuWorld(Ref * pSender);
	void intentNiveles(Ref * pSender);
	void intentCreditos(Ref * pSender);
	
	// implement the "static create()" method manually
	CREATE_FUNC(IntroGeneral);

	void  onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);

};

#endif // __HELLOWORLD_SCENE_H__