#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"
#include <iostream>
#include <vector>
#include "ui/CocosGUI.h"

USING_NS_CC;

class Player {

private:
	int lives, x, y;
	

public:
	Sprite* sprite;
	PhysicsBody* playerBody;
	Vector<SpriteFrame*> walkRight;
	Vector<SpriteFrame*> walkLeft;
	Vector<SpriteFrame*> jump;
	Vector<SpriteFrame*> duck;
	Animate* animateWalkRight;

	Player();
	Player(std::string, std::string);

	int getLives();
	int getX();
	int getY();
	void subtractLife();
	void setX();
	void setY();
};

#endif