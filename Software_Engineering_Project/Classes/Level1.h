#ifndef LEVEL1_H
#define LEVEL1_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player.h"

class Level1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    

    virtual bool init();

    CREATE_FUNC(Level1);
    Player player;
    ui::Button* forwardButton;
    cocos2d::ui::Button* backwardButton;
    cocos2d::ui::Button* jumpButton;
    
    
private:
    //cocos2d::PhysicsWorld* sceneWorld;
    //void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
   
};

#endif