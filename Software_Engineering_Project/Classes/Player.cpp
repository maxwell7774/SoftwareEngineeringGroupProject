#include "Player.h"

Player::Player() {
	x = 0;
	y = 0;
	lives = 3;

	sprite = Sprite::create("res/PNG/Players/128x256/Yellow/alienYellow_stand.png");
	playerBody = PhysicsBody::createBox(Size(110, 138), PhysicsMaterial(0, 1, 0));
	playerBody->setPositionOffset(Vec2(0, -60));
	sprite->setPhysicsBody(playerBody);
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);

	walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk1.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk2.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateWalk = Animate::create(Animation::createWithSpriteFrames(walk, 0.15f));

	jump.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_jump.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateJump = Animate::create(Animation::createWithSpriteFrames(jump, 0.15f));

	duck.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_duck.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateDuck = Animate::create(Animation::createWithSpriteFrames(duck, 0.15f));
}

Player::Player(std::string name, std::string color) {
	x = Director::getInstance()->getVisibleSize().width / 2;
	y = Director::getInstance()->getVisibleSize().height / 2;
	lives = 3;
	this->name = name;

	sprite = Sprite::create("res/PNG/Players/128x256/"+color+"/alien"+color+"_stand.png");
	playerBody = PhysicsBody::createBox(Size(110, 138), PhysicsMaterial(0, 1, 0));
	playerBody->setPositionOffset(Vec2(0, -60));
	sprite->setPhysicsBody(playerBody);
	sprite->setPosition( x, y );

	walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_walk1.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_walk2.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateWalk = Animate::create(Animation::createWithSpriteFrames(walk, 0.15f));

	jump.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_jump.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateJump = Animate::create(Animation::createWithSpriteFrames(jump, 0.15f));

	duck.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_duck.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateDuck = Animate::create(Animation::createWithSpriteFrames(duck, 0.15f));
}

int Player::getLives() { return lives; }
int Player::getX() { return x; }
int Player::getY() { return y; }
void Player::subtractLife() {
	if (isAlive()) {
		lives--;
	}
}

bool Player::isAlive() {
	if (lives > 0)
		return true;
	return false;
}