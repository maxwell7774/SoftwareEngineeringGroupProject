#ifndef WINSCREEN_H
#define WINSCREEN_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
class WinScreen : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void toMainMenu(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(WinScreen);
};

#endif
