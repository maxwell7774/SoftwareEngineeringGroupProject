#include "Level1.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* Level1::createScene()
{
    auto scene = Level1::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getDefaultCamera()->setScale(2, 2);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Menu.cpp\n");
}

// on "init" you need to initialize your instance
bool Level1::init()
{   
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto map = TMXTiledMap::create("res/MapTMX/MapTest1.tmx");
    auto collisions = map->getObjectGroup("GroundCollisions");
    auto arr = collisions->getObjects();
    
    //Node* physicsBodys[arr.size()];
    
    for(int i = 0; i < arr.size(); i++){
        int x = arr[i].asValueMap()["x"].asInt();
        int y = arr[i].asValueMap()["y"].asInt();
        int width = arr[i].asValueMap()["width"].asInt();
        int height = arr[i].asValueMap()["height"].asInt();
        auto node = Node::create();
        node->setAnchorPoint(Vec2(0,0));
        node->setPosition(Vec2(x,y));
        node->addComponent(PhysicsBody::createEdgeBox(Size(width,height)));
        node->getPhysicsBody()->setDynamic(false);
        node->getPhysicsBody()->setPositionOffset(Vec2(width/2,height/2));
        this->addChild(node);
        
    }
    
    auto background = Sprite::create("res/MapTMX/MapTest1.png");
    background->setAnchorPoint(Vec2(0,0));
    auto edgeBody = PhysicsBody::createEdgeBox(map->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 3);
    map->setAnchorPoint(Vec2(0,0));
    map->addComponent(edgeBody);
    this->addChild(map);

    e1 = Enemy();
    e1.playerBody->setGravityEnable(false);
    this->addChild(e1.sprite);
	e1.sprite->runAction(RepeatForever::create(e1.animateMove));
    

    player = Player("Bob", "Green");
    this->addChild(player.sprite);
	
    player.sprite->runAction(RepeatForever::create(player.animateWalk));

	this->addChild(player.h1);
	this->addChild(player.h2);
	this->addChild(player.h3);
    


	forwardbtn = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
	backbtn = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
	jumpbtn = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");

	forwardbtn->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
	backbtn->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
	jumpbtn->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));

	forwardbtn->setTag(999);
	backbtn->setTag(111);
	jumpbtn->setTag(555);



	forwardbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:

				player.sprite->getPhysicsBody()->setVelocity(Vec2(300, 0));
				this->getDefaultCamera()->setPosition(player.sprite->getPosition());
				forwardbtn->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
				backbtn->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
				jumpbtn->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));

				break;
		case ui::Widget::TouchEventType::ENDED:
			player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
		});
	backbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			player.sprite->getPhysicsBody()->setVelocity(Vec2(-300, 0));
			this->getDefaultCamera()->setPosition(player.sprite->getPosition());
			forwardbtn->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
			backbtn->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
			jumpbtn->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));
			break;
		case ui::Widget::TouchEventType::ENDED:
			player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
		});

	jumpbtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 300));
			
			forwardbtn->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
			backbtn->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
			jumpbtn->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));

			break;
		case ui::Widget::TouchEventType::ENDED:
			player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
			break;
		default:
			break;
		}
		});

	addChild(forwardbtn);
	addChild(backbtn);
	addChild(jumpbtn);
	this->scheduleUpdate();
    return true;
}

void Level1::update(float dt) {
	this->getDefaultCamera()->setPosition(player.sprite->getPosition());
	this->getDefaultCamera()->update(dt);
	forwardbtn->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
	backbtn->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
	jumpbtn->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));
	player.h1->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() + 250));
	player.h2->setPosition(Vec2(player.sprite->getPositionX() + 300, player.sprite->getPositionY() + 250));
	player.h3->setPosition(Vec2(player.sprite->getPositionX() + 200, player.sprite->getPositionY() + 250));
}
