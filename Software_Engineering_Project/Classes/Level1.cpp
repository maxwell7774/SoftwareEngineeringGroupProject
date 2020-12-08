#include "Level1.h"
#include <vector>
#include "Player.h"
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
    
    Node* physicsBodys[arr.size()];
    
    for(int i = 0; i < arr.size(); i++){
        int x = arr[i].asValueMap()["x"].asInt();
        int y = arr[i].asValueMap()["y"].asInt();
        int width = arr[i].asValueMap()["width"].asInt();
        int height = arr[i].asValueMap()["height"].asInt();
        physicsBodys[i] = Node::create();
        physicsBodys[i]->setAnchorPoint(Vec2(0,0));
        physicsBodys[i]->setPosition(Vec2(x,y));
        physicsBodys[i]->addComponent(PhysicsBody::createEdgeBox(Size(width,height)));
        physicsBodys[i]->getPhysicsBody()->setDynamic(false);
        physicsBodys[i]->getPhysicsBody()->setPositionOffset(Vec2(width/2,height/2));
        this->addChild(physicsBodys[i]);
        
    }
    
    auto background = Sprite::create("res/MapTMX/MapTest1.png");
    background->setAnchorPoint(Vec2(0,0));
    auto edgeBody = PhysicsBody::createEdgeBox(map->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 3);
    map->setAnchorPoint(Vec2(0,0));
    map->addComponent(edgeBody);
    this->addChild(map);

    player = Player("Bob", "Green");
    this->addChild(player.sprite);
    player.sprite->runAction(RepeatForever::create(player.animateWalk));


    forwardButton = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
    backwardButton = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
    jumpButton = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");

    forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
    backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
    jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));

    forwardButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
                player.sprite->getPhysicsBody()->setVelocity(Vec2(300, 0));
            this->getDefaultCamera()->setPosition(player.sprite->getPosition());
            forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
            backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
            jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));

            break;
        case ui::Widget::TouchEventType::ENDED:
                player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
            break;
        default:
            break;
        }
        });
    
    backwardButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
                player.sprite->getPhysicsBody()->setVelocity(Vec2(-300, 0));
            this->getDefaultCamera()->setPosition(player.sprite->getPosition());
            forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
            backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
            jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));
            break;
        case ui::Widget::TouchEventType::ENDED:
                player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
            break;
        default:
            break;
        }
        });

    jumpButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
                player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 300));
            this->getDefaultCamera()->setPosition(player.sprite->getPosition());
            forwardButton->setPosition(Vec2(player.sprite->getPositionX() + 400, player.sprite->getPositionY() - 200));
            backwardButton->setPosition(Vec2(player.sprite->getPositionX() - 400, player.sprite->getPositionY() - 200));
            jumpButton->setPosition(Vec2(player.sprite->getPositionX(), player.sprite->getPositionY() - 200));
            
            break;
        case ui::Widget::TouchEventType::ENDED:
                player.sprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
            break;
        default:
            break;
        }
        });
    this->addChild(forwardButton);
    this->addChild(backwardButton);
    this->addChild(jumpButton);
    return true;
}
