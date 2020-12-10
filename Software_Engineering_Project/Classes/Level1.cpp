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

    auto map = TMXTiledMap::create("res/MapTMX/Level1.tmx");
    auto collisions = map->getObjectGroup("ground_collisions");
    auto arr = collisions->getObjects();
    
    auto background = Sprite::create("res/MapTMX/Level1.png");
    auto edgeBody = PhysicsBody::createEdgeBox(background->getContentSize(), PhysicsMaterial(0,0,0), 3);
    background->addComponent(edgeBody);
    
    for(int i = 0; i < arr.size(); i++){
        int x = arr[i].asValueMap()["x"].asInt();
        int y = arr[i].asValueMap()["y"].asInt();
        int width = arr[i].asValueMap()["width"].asInt();
        int height = arr[i].asValueMap()["height"].asInt();
        auto shape = PhysicsShapeBox::create(Size(width, height), PhysicsMaterial(0,0,0), Vec2(x-(background->getContentSize().width/2)+width/2, y-(background->getContentSize().height/2)+height/2));
        background->getPhysicsBody()->addShape(shape);
    }
    
    this->getPhysicsWorld()->setGravity(Vec2(0,-1000));
    this->addChild(background);

    e1 = Enemy();
    e1.playerBody->setGravityEnable(false);
    this->addChild(e1.sprite);
	e1.sprite->runAction(RepeatForever::create(e1.animateMove));
    e1.sprite->runAction(RepeatForever::create(e1.flyAround));
    

    player = Player("Bob", "Green");
    this->addChild(player.sprite);
	
	this->addChild(player.h1);
	this->addChild(player.h2);
	this->addChild(player.h3);
    

    // creating a keyboard event listener
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Level1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level1::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();
    return true;
}

void Level1::update(float dt) {
	this->getDefaultCamera()->setPosition(player.sprite->getPosition());
	this->getDefaultCamera()->update(dt);

	player.h1->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() + 250));
	player.h2->setPosition(Vec2(player.sprite->getPositionX() - 300, player.sprite->getPositionY() + 250));
	player.h3->setPosition(Vec2(player.sprite->getPositionX() - 200, player.sprite->getPositionY() + 250));
}

// Implementation of the keyboard event callback function prototype
void Level1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
{

        log("Key with keycode %d pressed", keyCode);
    switch(keyCode){
        case EventKeyboard::KeyCode::KEY_A:
            player.setActions("left");
            break;
        case EventKeyboard::KeyCode::KEY_D:
            player.setActions("right");
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
            player.setActions("jump");
            break;
    }
}

void Level1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
{
    switch(keyCode){
        case EventKeyboard::KeyCode::KEY_A:
            player.switchKey('a');
            break;
        case EventKeyboard::KeyCode::KEY_D:
            player.switchKey('d');
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
            player.switchKey('s');
            break;
    }
}

void toLevel2(cocos2d::Ref* pSender) {

}
