#ifndef __CREDITOS_H__
#define __CREDITOS_H__

#include "cocos2d.h"

class Creditos : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Creditos);
};

#endif // __CREDITOS_H__

