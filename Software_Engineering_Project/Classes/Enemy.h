#ifndef ENEMY_H
#define ENEMY_H

#include "cocos2d.h"
#include <iostream>
#include <vector>
#include "ui/CocosGUI.h"

USING_NS_CC;

class Enemy {

private:
	int x, y;
	std::string name;

public:
	Sprite* sprite;
	PhysicsBody* playerBody;

	Vector<SpriteFrame*> move;

	Animate* animateMove;
	MoveBy* flyUp = MoveBy::create(2.0f, Vec2(0, 256));
	MoveBy* flyDown = MoveBy::create(2.0f, Vec2(0, -256));
	DelayTime* wait = DelayTime::create(2.0f);

	Sequence* flyAround = Sequence::create(flyUp, wait, flyDown, wait, nullptr);


	Enemy();
	//Enemy(std::string name, std::string color);
	int getX();
	int getY();
};

#endif