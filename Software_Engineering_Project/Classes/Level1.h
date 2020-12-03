#ifndef LEVEL1_H
#define LEVEL1_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Level1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Level1);
};

#endif