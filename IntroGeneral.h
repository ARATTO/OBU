#ifndef __INTROGENERAL_H__
#define __INTROGENERAL_H__

#include "cocos2d.h"


class IntroGeneral: public cocos2d::Layer
{

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

};

#endif // __HELLOWORLD_SCENE_H__
