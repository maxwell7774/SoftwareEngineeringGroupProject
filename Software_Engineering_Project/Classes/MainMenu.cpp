#include "MainMenu.h"
#include "LevelMenu.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Menu.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("res/PNG/Backgrounds/colored_grass.png");
    background->setScale(0.5f);
    background->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
    this->addChild(background);

    auto title = Label::createWithSystemFont("Send Me Home!", "Arial", 48);
    title->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2, 3*Director::getInstance()->getVisibleSize().height/4));
    title->setColor(Color3B::BLACK);
    this->addChild(title);

    auto play = MenuItemImage::create("res/PNG/tiles/boxCrate.png", "res/PNG/tiles/boxCrate_double.png", CC_CALLBACK_1(MainMenu::toLevelMenu, this));

    auto playText = Label::createWithSystemFont("Play", "Arial", 20);
    playText->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 3));

    // create menu, it's an autorelease object
    auto menu = Menu::create(play, NULL);
    menu->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 3));
    this->addChild(menu);
    this->addChild(playText);

    return true;
}


void MainMenu::toLevelMenu(Ref* pSender)
{
    auto lvlmenu = LevelMenu::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f,lvlmenu));
}
