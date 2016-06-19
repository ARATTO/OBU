#ifndef __CREDITOS_H__
#define __CREDITOS_H__

#include "cocos2d.h"

class Creditos : public cocos2d::Layer
{
private:

	cocos2d::Sprite *obu;
	cocos2d::Sprite *btn_regresar;

	float AN;
	float AL;


public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void intentRegresar(Ref * pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Creditos);

	void  onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
};

#endif // __CREDITOS_H__

