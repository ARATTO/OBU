#ifndef __NIVELES_H__
#define __NIVELES_H__

#include "cocos2d.h"

class Niveles : public cocos2d::Layer
{
private:
	
	cocos2d::Sprite *ayuda;
	cocos2d::Sprite *obu;
	cocos2d::Sprite *btn_lvl_1;
	cocos2d::Sprite *btn_lvl_2;
	cocos2d::Sprite *btn_lvl_3;
	cocos2d::Sprite *btn_regresar;

	float AN;
	float AL;
	
	int siguiente = 0;
	
	cocos2d::Label *titulo;


public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void intentRegresar(Ref * pSender);
	void intentLvl_1(Ref * pSender);
	void intentLvl_2(Ref * pSender);
	void intentLvl_3(Ref * pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Niveles);

	void  onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
};

#endif // __NIVELES_H__

