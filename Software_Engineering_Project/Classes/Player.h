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
    bool aPressed, dPressed, spacePressed;
	std::string name;
	

public:
	std::string color;
	Sprite* sprite;
	PhysicsBody* playerBody;

	Vector<SpriteFrame*> walk;
	Vector<SpriteFrame*> jump;
	Vector<SpriteFrame*> duck;

	Player();
	Player(std::string name, std::string color);

	int getLives();
	int getX();
	int getY();
	
	void subtractLife();
	bool isAlive();
    void setActions(std::string dir);
    void stopActions();
    void switchKey(char key);

	Sprite* h1;
	Sprite* h2;
	Sprite* h3;


};

#endif
