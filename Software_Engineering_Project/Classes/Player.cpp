#include "Player.h"
#include "GameOver.h"

Player::Player() {
	x = 300;
	y = 600;
	lives = 3;
	color = "Yellow";
    aPressed = false;
    dPressed = false;
    spacePressed = false;

	sprite = Sprite::create("res/PNG/Players/128x256/Yellow/alienYellow_stand.png");
	playerBody = PhysicsBody::createBox(Size(110, 138), PhysicsMaterial(0, 1, 0));
	playerBody->setPositionOffset(Vec2(0, -60));
	sprite->setPhysicsBody(playerBody);
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
    sprite->getPhysicsBody()->setCollisionBitmask(2);
//    sprite->getPhysicsBody()->setContactTestBitmask(true);
	

	walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk1.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
	walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk2.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));

	jump.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_jump.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));

	idle.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_front.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    idle.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_stand.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    switchKey('a');

	h1 = Sprite::create("res/PNG/HUD/hudHeart_full.png");
	h2 = Sprite::create("res/PNG/HUD/hudHeart_full.png");
	h3 = Sprite::create("res/PNG/HUD/hudHeart_full.png");

	h1->setPosition(Vec2(sprite->getPositionX() - 900, sprite->getPositionY() - 650));
	h2->setPosition(Vec2(sprite->getPositionX() - 800, sprite->getPositionY() - 650));
	h3->setPosition(Vec2(sprite->getPositionX() - 700, sprite->getPositionY() - 650));
}

Player::Player(std::string name, std::string color) {
    x = 300;
    y = 300;
    lives = 3;
    this->name = name;
	this->color = color;
    aPressed = false;
    dPressed = false;
    spacePressed = false;

    sprite = Sprite::create("res/PNG/Players/128x256/"+color+"/alien"+color+"_stand.png");
    playerBody = PhysicsBody::createBox(Size(80, 138), PhysicsMaterial(0, 0, 0));
    playerBody->setPositionOffset(Vec2(0, -60));
    playerBody->setRotationEnable(false);
    sprite->setPhysicsBody(playerBody);
    sprite->setPosition( x, y );
    sprite->getPhysicsBody()->setCollisionBitmask(2);
    sprite->getPhysicsBody()->setContactTestBitmask(true);


    walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_walk1.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    walk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_walk2.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));

    jump.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_jump.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));

    idle.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_front.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));

    idle.pushBack(SpriteFrame::create("res/PNG/Players/128x256/" + color + "/alien" + color + "_stand.png", Rect(0, 0, sprite->getContentSize().width, sprite->getContentSize().height)));
    switchKey('a');
    
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
    stopActions();
    
    if(dir == "left"){
        sprite->setFlippedX(true);
        sprite->runAction(RepeatForever::create(animateWalk));
        if(!aPressed){
            aPressed = true;
            dPressed = false;
            sprite->getPhysicsBody()->setVelocity(Vec2(-450, sprite->getPhysicsBody()->getVelocity().y));
        }
    }
    else if(dir == "right"){
        sprite->setFlippedX(false);
        sprite->runAction(RepeatForever::create(animateWalk));
        if(!dPressed){
            dPressed = true;
            aPressed = false;
            sprite->getPhysicsBody()->setVelocity(Vec2(450, sprite->getPhysicsBody()->getVelocity().y));
        }
    }
    else if(dir == "jump"){
        spacePressed = true;
        sprite->runAction(RepeatForever::create(animateJump));
        if(aPressed){
            sprite->getPhysicsBody()->setVelocity(Vec2(-450, 800));
        }
        else if(dPressed){
            sprite->getPhysicsBody()->setVelocity(Vec2(450, 800));
        }
        else{
            sprite->getPhysicsBody()->setVelocity(Vec2(0, 800));
        }
    }
    
}

void Player::stopActions(){
    sprite->stopAllActions();
}

void Player::switchKey(char key){
    if(key == 'a')
        aPressed = false;
    else if(key == 'd')
        dPressed = false;
    else if(key == 's'){
        spacePressed = false;
        if(aPressed)
            setActions("left");
        else if(dPressed)
            setActions("right");
    }
    if(!aPressed && !dPressed && !spacePressed){
        sprite->getPhysicsBody()->setVelocity(Vec2(0,0));
        stopActions();
        
        auto animateIdle = Animate::create(Animation::createWithSpriteFrames(idle, 0.3f));
        sprite->runAction(RepeatForever::create(animateIdle));
    }
}
