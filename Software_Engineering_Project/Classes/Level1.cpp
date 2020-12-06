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
    //this->addChild(map, 0, 99);
    
    auto background = Sprite::create("res/MapTMX/MapTest1.png");
    auto edgeBody = PhysicsBody::createEdgeBox(background->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 3);
    //edgeBody->setGravityEnable(false);
    background->setPhysicsBody(edgeBody);
    this->addChild(background);

    player = Player("Bob", "Green");
    player.sprite->getPhysicsBody()->setGravityEnable(false);
    this->addChild(player.sprite);
    //this->getDefaultCamera()->setScale(0.5f);

    player.sprite->runAction(RepeatForever::create(player.animateWalk));

    auto forwardButton = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
    forwardButton->setPosition(Vec2(150, 50));
    
    forwardButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        auto moveBy = MoveBy::create(0.5f, Vec2(50, 0));
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            player.sprite->runAction(moveBy);
            this->getDefaultCamera()->setPosition(player.sprite->getPosition());
            break;
        case ui::Widget::TouchEventType::ENDED:
           
            break;
        default:
            break;
        }
        });
    this->addChild(forwardButton);

    auto backwardButton = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
    backwardButton->setPosition(Vec2(50, 50));
    backwardButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        auto moveBy = MoveBy::create(0.5f, Vec2(-50, 0));
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            player.sprite->runAction(moveBy);
            break;
        case ui::Widget::TouchEventType::ENDED:

            break;
        default:
            break;
        }
        });
    this->addChild(backwardButton);

    auto jumpButton = ui::Button::create("res/PNG/HUD/hudJewel_green_empty.png", "res/PNG/HUD/hudJewel_green.png");
    jumpButton->setPosition(Vec2(100, 150));
    jumpButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        auto moveBy = MoveBy::create(0.5f, Vec2(0, 50));
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            player.sprite->runAction(moveBy);
            break;
        case ui::Widget::TouchEventType::ENDED:

            break;
        default:
            break;
        }
        });
    this->addChild(jumpButton);

    return true;
}
