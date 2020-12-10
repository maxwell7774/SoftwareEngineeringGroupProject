#ifndef LEVEL1_H
#define LEVEL1_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player.h"
#include "Enemy.h"


class Level1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    

    virtual bool init();
    void update(float);
    void toLevel2(cocos2d::Ref* pSender);
    CREATE_FUNC(Level1);
    Player player;
    Enemy e1;
    cocos2d::ui::Button* forwardbtn;
    cocos2d::ui::Button* backbtn;
    cocos2d::ui::Button* jumpbtn;
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, Event* event);
    
private:
    //cocos2d::PhysicsWorld* sceneWorld;
    //void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
   
};

#endif
