#ifndef GAMEHUD_H
#define GAMEHUD_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class GameHud : public Layer {
	public:
		virtual bool init();
		CREATE_FUNC(GameHud);
		
	
		ui::Button* forwardbtn;
		ui::Button* backbtn;
		ui::Button* jumpbtn;

};
#endif