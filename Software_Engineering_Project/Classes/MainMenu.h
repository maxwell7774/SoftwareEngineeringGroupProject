#ifndef MENU_H
#define MENU_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};

#endif
