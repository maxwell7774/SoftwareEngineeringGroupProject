#include "Level1.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "ui/CocosGUI.h"
#include "GameHud.h"

USING_NS_CC;

Scene* Level1::createScene()
{
    auto scene = Level1::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getDefaultCamera()->setScale(2, 2);
    GameHud* hud = GameHud::create();
    scene->addChild(hud,123, 5);
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
    

    player = Player("Bob", "Green");
    this->addChild(player.sprite);
    player.sprite->runAction(RepeatForever::create(player.animateWalk));
    
    return true;
}
