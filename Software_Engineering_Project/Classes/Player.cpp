#include "Player.h"

Player::Player() {
	x = 0;
	y = 0;
	lives = 3;

	sprite = Sprite::create("res/PNG/Players/128x256/Yellow/alienYellow_stand.png");
	
	playerBody = PhysicsBody::createBox(Size(110, 138), PhysicsMaterial(0, 1, 0));
	playerBody->setPositionOffset(Vec2(0, -60));
	sprite->setPhysicsBody(playerBody);

	walkRight.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk1.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	walkRight.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk2.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateWalkRight = Animate::create(Animation::createWithSpriteFrames(walkRight, 0.15f));


}