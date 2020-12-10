#include "Player.h"
#include "GameOver.h"

Player::Player() {
	x = 0;
	y = 0;
	lives = 3;
	color = "Yellow";

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

	h1 = Sprite::create("res/PNG/HUD/hudHeart_full.png");
	h2 = Sprite::create("res/PNG/HUD/hudHeart_full.png");
	h3 = Sprite::create("res/PNG/HUD/hudHeart_full.png");

	h1->setPosition(Vec2(sprite->getPositionX() - 400, sprite->getPositionY() - 200));
	h2->setPosition(Vec2(sprite->getPositionX() - 300, sprite->getPositionY() - 200));
	h3->setPosition(Vec2(sprite->getPositionX() - 200, sprite->getPositionY() - 200));
}

Player::Player(std::string name, std::string color) {
    x = 300;
    y = 600;
    lives = 3;
    this->name = name;
	this->color = color;

    sprite = Sprite::create("res/PNG/Players/128x256/"+color+"/alien"+color+"_stand.png");
    playerBody = PhysicsBody::createBox(Size(80, 138), PhysicsMaterial(0, 0, 0));
    playerBody->setPositionOffset(Vec2(0, -60));
    sprite->setPhysicsBody(playerBody);
    sprite->setPosition( x, y );
    playerBody->setRotationEnable(false);

    walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_walk1.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_walk2.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    animateWalk = Animate::create(Animation::createWithSpriteFrames(walk, 0.15f));

    jump.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_jump.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    animateJump = Animate::create(Animation::createWithSpriteFrames(jump, 0.15f));

    duck.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_duck.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    animateDuck = Animate::create(Animation::createWithSpriteFrames(duck, 0.15f));

    h1 = Sprite::create("res/PNG/HUD/hudHeart_full.png");
    h2 = Sprite::create("res/PNG/HUD/hudHeart_full.png");
    h3 = Sprite::create("res/PNG/HUD/hudHeart_full.png");

    h1->setPosition(Vec2(sprite->getPositionX() + 400, sprite->getPositionY() + 250));
    h2->setPosition(Vec2(sprite->getPositionX() + 300, sprite->getPositionY() + 250));
    h3->setPosition(Vec2(sprite->getPositionX() + 200, sprite->getPositionY() + 250));
}

int Player::getLives() { return lives; }
int Player::getX() { return x; }
int Player::getY() { return y; }
void Player::subtractLife() {
	if (isAlive()) {
		lives--;
		if (getLives() == 2) {
			h3->setTexture("res/PNG/HUD/hudHeart_empty.png");
		}
		if (getLives() == 1) {
			h2->setTexture("res/PNG/HUD/hudHeart_empty.png");
		}
        if (getLives() == 0) {
            h1->setTexture("res/PNG/HUD/hudHeart_empty.png");
            auto gameover = GameOver::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(0.5f, gameover));
        }
	}
}

bool Player::isAlive() {
	if (lives > 0)
		return true;
	return false;
}

void Player::setActions(std::string dir){
    auto animateWalk = Animate::create(Animation::createWithSpriteFrames(walk, 0.15f));
    auto animateJump = Animate::create(Animation::createWithSpriteFrames(jump, 0.15f));
    
    if(dir == "left"){
        sprite->setFlippedX(true);
        sprite->runAction(RepeatForever::create(animateWalk));
        sprite->getPhysicsBody()->setVelocity(Vec2(-450, 0));
    }
    else if(dir == "right"){
        sprite->setFlippedX(false);
        sprite->runAction(RepeatForever::create(animateWalk));
        sprite->getPhysicsBody()->setVelocity(Vec2(450, 0));
    }
    else if(dir == "jump"){
        sprite->runAction(animateJump);
        sprite->getPhysicsBody()->setVelocity(Vec2(0, 600));
    }
}

void Player::stopActions(){
    sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
    sprite->stopAllActions();
}
