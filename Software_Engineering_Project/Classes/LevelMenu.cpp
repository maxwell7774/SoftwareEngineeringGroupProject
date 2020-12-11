#include "LevelMenu.h"
#include "Level1.h"
#include "Level2.h"
#include "GameOver.h"
#include "MainMenu.h"
USING_NS_CC;

Scene* LevelMenu::createScene()
{
    return LevelMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Menu.cpp\n");
}

// on "init" you need to initialize your instance
bool LevelMenu::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto background = Sprite::create("res/PNG/Backgrounds/colored_grass.png");
    background->setScale(0.5f);
    background->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
    this->addChild(background);

    auto title = Label::createWithSystemFont("Level Selector:", "Arial", 48);
    title->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 3*Director::getInstance()->getVisibleSize().height / 4));
    title->setColor(Color3B::BLACK);
    this->addChild(title);

    Vector<MenuItem*> MenuItems;

    auto lvl1 = MenuItemLabel::create(Label::createWithSystemFont("Level 1", "Arial", 24), CC_CALLBACK_1(LevelMenu::toLevel1, this));
    lvl1->setColor(Color3B::BLACK);
    lvl1->setPosition(Vec2(0, 20));
    MenuItems.pushBack(lvl1);

    auto lvl2 = MenuItemLabel::create(Label::createWithSystemFont("Level 2", "Arial", 24), CC_CALLBACK_1(LevelMenu::toLevel2, this));
    lvl2->setColor(Color3B::BLACK);
    lvl2->setPosition(Vec2(0, -20));
    MenuItems.pushBack(lvl2);

    auto lvl3 = MenuItemLabel::create(Label::createWithSystemFont("Level 3", "Arial", 24), CC_CALLBACK_1(LevelMenu::toLevel3, this));
    lvl3->setColor(Color3B::BLACK);
    lvl3->setPosition(Vec2(0, -60));
    MenuItems.pushBack(lvl3);

    auto lvl4 = MenuItemLabel::create(Label::createWithSystemFont("Level 4", "Arial", 24), CC_CALLBACK_1(LevelMenu::toLevel4, this));
    lvl4->setColor(Color3B::BLACK);
    lvl4->setPosition(Vec2(0, -100));
    MenuItems.pushBack(lvl4);

    auto lvl5 = MenuItemLabel::create(Label::createWithSystemFont("Level 5", "Arial", 24), CC_CALLBACK_1(LevelMenu::toLevel5, this));
    lvl5->setColor(Color3B::BLACK);
    lvl5->setPosition(Vec2(0, -140));
    MenuItems.pushBack(lvl5);

    auto back = MenuItemLabel::create(Label::createWithSystemFont("Back", "Arial", 24), CC_CALLBACK_1(LevelMenu::toMainMenu, this));
    back->setColor(Color3B::BLACK);
    back->setPosition(Vec2(-200, 140));
    MenuItems.pushBack(back);


    // create menu, it's an autorelease object
    auto menu = Menu::createWithArray(MenuItems);
    //menu->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height-200));

    this->addChild(menu);

    return true;
}

void LevelMenu::toLevel1(cocos2d::Ref* pSender) {
    auto level1 = Level1::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, level1));
}
void LevelMenu::toLevel2(cocos2d::Ref* pSender) {
    auto level2 = Level2::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, level2));
}
void LevelMenu::toLevel3(cocos2d::Ref* pSender) {

}
void LevelMenu::toLevel4(cocos2d::Ref* pSender) {

}
void LevelMenu::toLevel5(cocos2d::Ref* pSender) {
    auto level5 = GameOver::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, level5));
}
void LevelMenu::toMainMenu(cocos2d::Ref* pSender) {
    auto main = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, main));
}