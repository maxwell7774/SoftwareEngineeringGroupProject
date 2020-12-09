#include "GameHud.h"

USING_NS_CC;

bool GameHud::init() {
	if (!Layer::init()) {
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	forwardbtn = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
	backbtn = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
	jumpbtn = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");

	forwardbtn->setPosition(Vec2((visibleSize.width/2) + 400, (visibleSize.height / 2) - 200));
	backbtn->setPosition(Vec2((visibleSize.width / 2) - 400, (visibleSize.height / 2) - 200));
	jumpbtn->setPosition(Vec2((visibleSize.width / 2), (visibleSize.height / 2) - 200));

	forwardbtn->setTag(999);
	backbtn->setTag(111);
	jumpbtn->setTag(555);

	forwardbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			/*player.sprite->getPhysicsBody()->setVelocity(Vec2(300, 0));
			this->getDefaultCamera()->setPosition(player.sprite->getPosition());
			forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
			backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
			jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));*/

			break;
		case ui::Widget::TouchEventType::ENDED:
			/*player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));*/
			break;
		default:
			break;
		}
		});
	backbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			/*player.sprite->getPhysicsBody()->setVelocity(Vec2(-300, 0));
			this->getDefaultCamera()->setPosition(player.sprite->getPosition());
			forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
			backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
			jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));*/
			break;
		case ui::Widget::TouchEventType::ENDED:
			//player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
		});

	jumpbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			/*player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 300));
			this->getDefaultCamera()->setPosition(player.sprite->getPosition());
			forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
			backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
			jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));*/

			break;
		case ui::Widget::TouchEventType::ENDED:
			//player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
		});

	addChild(forwardbtn);
	addChild(backbtn);
	addChild(jumpbtn);

	return true;
}