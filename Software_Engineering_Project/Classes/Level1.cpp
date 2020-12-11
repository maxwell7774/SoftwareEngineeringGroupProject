#include "Level1.h"
#include "Level2.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* Level1::createScene()
{
    auto scene = Level1::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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

        background = Sprite::create("res/MapTMX/Level1.png");
        auto edgeBody = PhysicsBody::createEdgeBox(background->getContentSize(), PhysicsMaterial(0,0,0), 3);
        background->addComponent(edgeBody);
        this->addChild(background);
        
        auto map = TMXTiledMap::create("res/MapTMX/Level1.tmx");
        auto collisions = map->getObjectGroup("ground_collisions");
        auto enemies = map->getObjectGroup("enemies");
        auto spawn = map->getObjectGroup("spawn");
        auto keyGroup = map->getObjectGroup("key");
        auto collisionsArr = collisions->getObjects();
        auto enemiesArr = enemies->getObjects();
        auto spawnArr = spawn->getObjects();
        auto keyArr = keyGroup->getObjects();
        key = Sprite::create("res/PNG/Items/keyBlue.png");
        keyBody = PhysicsBody::createBox(Size(128, 128), PhysicsMaterial(0, 1, 0));
        key->setPhysicsBody(keyBody);
        key->getPhysicsBody()->setCollisionBitmask(9);
        key->getPhysicsBody()->setContactTestBitmask(true);
        key->setPosition(Vec2(keyArr[0].asValueMap()["x"].asInt()-background->getContentSize().width/2, keyArr[0].asValueMap()["y"].asInt()-background->getContentSize().height/2));
        this->addChild(key);
        
        for(int i = 0; i < collisionsArr.size(); i++){
            int x = collisionsArr[i].asValueMap()["x"].asInt();
            int y = collisionsArr[i].asValueMap()["y"].asInt();
            int width = collisionsArr[i].asValueMap()["width"].asInt();
            int height = collisionsArr[i].asValueMap()["height"].asInt();
            auto shape = PhysicsShapeBox::create(Size(width, height), PhysicsMaterial(0,0,0), Vec2(x-(background->getContentSize().width/2)+width/2, y-(background->getContentSize().height/2)+height/2));
            background->getPhysicsBody()->addShape(shape);
        }
        
        for(int i = 0; i < enemiesArr.size(); i++){
            int x = enemiesArr[i].asValueMap()["x"].asInt();
            int y = enemiesArr[i].asValueMap()["y"].asInt();
            auto enemy = Enemy();
            enemy.playerBody->setGravityEnable(false);
            
            enemy.sprite->setPosition(Vec2(x-background->getContentSize().width/2, y-background->getContentSize().height/2));
            
            this->addChild(enemy.sprite);
            
            enemy.sprite->runAction(RepeatForever::create(enemy.animateMove));
            enemy.sprite->runAction(RepeatForever::create(enemy.flyAround));
        }
        
        background->getPhysicsBody()->setCollisionBitmask(3);
        background->getPhysicsBody()->setContactTestBitmask(true);

        this->getPhysicsWorld()->setGravity(Vec2(0,-1000));

        player = Player("Bob", "Green", spawnArr[0].asValueMap()["x"].asInt()-background->getContentSize().width/2, spawnArr[0].asValueMap()["y"].asInt()-background->getContentSize().height/2);
    
        this->addChild(player.sprite);
        getDefaultCamera()->setPosition(player.sprite->getPosition());
        
        this->addChild(player.h1);
        this->addChild(player.h2);
        this->addChild(player.h3);
        
    

    // creating a keyboard event listener
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Level1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level1::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Level1::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	this->scheduleUpdate();
    return true;
}

void Level1::update(float dt) {
    if(player.sprite->getPosition().x > -(background->getContentSize().width/2)+getContentSize().width/2 && player.sprite->getPosition().x < (background->getContentSize().width/2)-getContentSize().width/2)
        this->getDefaultCamera()->setPosition(player.sprite->getPosition().x,getDefaultCamera()->getPosition().y);
    else if(player.sprite->getPosition().x < -(background->getContentSize().width/2)+getContentSize().width/2)
        this->getDefaultCamera()->setPosition(-(background->getContentSize().width/2)+getContentSize().width/2,getDefaultCamera()->getPosition().y);
    else if(player.sprite->getPosition().x > (background->getContentSize().width/2)-getContentSize().width/2)
        this->getDefaultCamera()->setPosition(background->getContentSize().width/2-getContentSize().width/2,getDefaultCamera()->getPosition().y);

    if(player.sprite->getPosition().y > -(background->getContentSize().height/2)+getContentSize().height/2 && player.sprite->getPosition().y < (background->getContentSize().height/2)-getContentSize().height/2)
        this->getDefaultCamera()->setPosition(getDefaultCamera()->getPosition().x,player.sprite->getPosition().y);
    else if(player.sprite->getPosition().y < -(background->getContentSize().height/2)+getContentSize().height/2)
        this->getDefaultCamera()->setPosition(getDefaultCamera()->getPosition().x,-(background->getContentSize().height/2)+getContentSize().height/2);
    else if(player.sprite->getPosition().y > (background->getContentSize().height/2)-getContentSize().height/2)
        this->getDefaultCamera()->setPosition(getDefaultCamera()->getPosition().x,(background->getContentSize().height/2)-getContentSize().height/2);
        
	this->getDefaultCamera()->update(dt);

	player.h1->setPosition(Vec2(getDefaultCamera()->getPositionX() - 900, getDefaultCamera()->getPositionY() + 650));
	player.h2->setPosition(Vec2(getDefaultCamera()->getPositionX() - 800, getDefaultCamera()->getPositionY() + 650));
	player.h3->setPosition(Vec2(getDefaultCamera()->getPositionX() - 700, getDefaultCamera()->getPositionY() + 650));
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

void Level1::toLevel2() {
    auto level2 = Level2::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, level2));
}

bool Level1::onContactBegin(cocos2d::PhysicsContact& contact) {
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();
    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())) {
        CCLOG("Collision has occurred.");
        player.subtractLife();
    }

    if ((3 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 3 == b->getCollisionBitmask())) {
        CCLOG("On Ground.");
    }

    if ((9 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 9 == b->getCollisionBitmask())) {
        toLevel2();
    }

    return true;
}
