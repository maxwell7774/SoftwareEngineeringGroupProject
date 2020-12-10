#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
class GameOver : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void toLevelMenu(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);
};

#endif
