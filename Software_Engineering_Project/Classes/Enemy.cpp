#include "Enemy.h"

Enemy::Enemy() {
	x = 0;
	y = 0;

	sprite = Sprite::create("res/PNG/Enemies/fly.png");
	playerBody = PhysicsBody::createBox(Size(128, 128), PhysicsMaterial(0, 1, 0));
	sprite->setPhysicsBody(playerBody);
	sprite->setPosition(Vec2(500,200));

	move.pushBack(SpriteFrame::create("res/PNG/Enemies/fly.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	move.pushBack(SpriteFrame::create("res/PNG/Enemies/fly_dead.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	animateMove = Animate::create(Animation::createWithSpriteFrames(move, 0.15f));
}
int Enemy::getX() { return x; }
int Enemy::getY() { return y; }
