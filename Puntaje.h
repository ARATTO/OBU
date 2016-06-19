#ifndef __PUNTAJE_H__
#define __PUNTAJE_H__

#include "cocos2d.h"
#include "sqlite3.h"

class Puntaje : public cocos2d::Layer
{
private:

	cocos2d::Sprite *obu;
	cocos2d::Sprite *btn_regresar;

	float AN;
	float AL;
	
	sqlite3 *pdb=NULL;
	int result;
	std::string sql;
	
	int pos =200;


public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void intentRegresar(Ref * pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Puntaje);

	void  onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
};

#endif // __NIVELES_H__


