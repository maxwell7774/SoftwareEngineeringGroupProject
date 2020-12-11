#include "WinScreen.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* WinScreen::createScene()
{
    return WinScreen::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Menu.cpp\n");
}

// on "init" you need to initialize your instance
bool WinScreen::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("res/MapTMX/Level1.png");
    background->setPosition(-500, Director::getInstance()->getVisibleSize().height / 2);
    this->addChild(background);

    auto title = Label::createWithSystemFont("You Won!", "Arial", 140);
    title->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 3 * Director::getInstance()->getVisibleSize().height / 4));
    title->setColor(Color3B::BLACK);
    this->addChild(title);

    auto play = MenuItemImage::create("res/PNG/tiles/boxCrate.png", "res/PNG/tiles/boxCrate_double.png", CC_CALLBACK_1(WinScreen::toMainMenu, this));
    play->setScale(2.5, 2.5);

    auto playText = Label::createWithSystemFont("Play Again", "Arial", 90);
    playText->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 3));

    // create menu, it's an autorelease object
    auto menu = Menu::create(play, NULL);
    menu->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 3));
    this->addChild(menu);
    this->addChild(playText);

    return true;
}


void WinScreen::toMainMenu(Ref* pSender)
{
    auto menu = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, menu));
}
