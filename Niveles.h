#ifndef __NIVELES_H__
#define __NIVELES_H__

#include "cocos2d.h"

class Niveles : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Niveles);
};

#endif // __NIVELES_H__

