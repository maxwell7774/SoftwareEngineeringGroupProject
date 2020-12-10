#ifndef LEVELMENU_H
#define LEVELMENU_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class LevelMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void toLevel1(cocos2d::Ref* pSender);
    void toLevel2(cocos2d::Ref* pSender);
    void toLevel3(cocos2d::Ref* pSender);
    void toLevel4(cocos2d::Ref* pSender);
    void toLevel5(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(LevelMenu);
};


#endif
