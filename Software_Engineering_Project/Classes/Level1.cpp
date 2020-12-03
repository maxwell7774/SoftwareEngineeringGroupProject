#include "Level1.h"
#include <vector>

USING_NS_CC;

Scene* Level1::createScene()
{
    auto scene = Level1::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = Level1::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
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
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto map = TMXTiledMap::create("res/MapTMX/MapTest1.tmx");
    //map->setAnchorPoint(Vec2(900, 900));
    map->setPosition(0,-352);
    this->addChild(map, 0, 99);

    auto player = Sprite::create("res/PNG/Players/128x256/Yellow/alienYellow_stand.png");
    player->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
    this->addChild(player);

    Vector<SpriteFrame*> playerWalk;

    playerWalk.reserve(2);
    playerWalk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk1.png",Rect(0,0,player->getContentSize().width,player->getContentSize().height)));
    playerWalk.pushBack(SpriteFrame::create("res/PNG/Players/128x256/Yellow/alienYellow_walk2.png",Rect(0,0,player->getContentSize().width,player->getContentSize().height)));

    Animation* animateWalk = Animation::createWithSpriteFrames(playerWalk, 0.15f);
    Animate* animate = Animate::create(animateWalk);

    player->runAction(RepeatForever::create(animate));

    return true;
}


void Level1::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
