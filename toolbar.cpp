#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	lives = config.lives;
	score = config.score;
	level = config.level;

	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_sign.jpg";
	toolbarItemImages[ITM_HOUSE] = "images\\toolbarItems\\toolbar_house.jpg";
	toolbarItemImages[ITM_TREE] = "images\\toolbarItems\\toolbar_tree.jpg";
	toolbarItemImages[ITM_ROCKET] = "images\\toolbarItems\\toolbar_rocket.jpg";
	toolbarItemImages[ITM_ICECREAM] = "images\\toolbarItems\\toolbar_icecream.jpg";
	toolbarItemImages[ITM_BUTTERFLY] = "images\\toolbarItems\\toolbar_butterfly.jpg";
	toolbarItemImages[ITM_TRUCK] = "images\\toolbarItems\\toolbar_truck.jpg";
	toolbarItemImages[ITM_DEL] = "images\\toolbarItems\\toolbar_Del.jpg";
	toolbarItemImages[ITM_SCLUP] = "images\\toolbarItems\\toolbar_up.jpg";
	toolbarItemImages[ITM_SCLDWN] = "images\\toolbarItems\\toolbar_down.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_ROT] = "images\\toolbarItems\\toolbar_rotate.jpg";
	toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\toolbar_save.jpg";
	toolbarItemImages[ITM_HINT] = "images\\toolbarItems\\toolbar_hint.jpg";
	toolbarItemImages[ITM_REF] = "images\\toolbarItems\\toolbar_refresh.jpg";;
	toolbarItemImages[ITM_LVL] = "images\\toolbarItems\\toolbar_lvl.jpg";
	

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
	//line under toolbar 
	pWind->SetPen(PURPLE, 3);
	pWind->DrawLine(0, height, width, height);



	status();
}

void toolbar::status()
{

	window* pWind = pGame->getWind();
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(config.windWidth*0.9, config.windHeight * 0.0745, config.windWidth, 0, FILLED);
	
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->SetPen(RED, 50);

	pWind->DrawString((16.9) * config.toolbarItemWidth, 0, "LIVES LEFT: ");
	pWind->DrawInteger((17.9) * config.toolbarItemWidth, 0, lives);
	pWind->SetPen(GREEN, 50);
	pWind->DrawString((16.9) * config.toolbarItemWidth, 20, "SCORE: ");
	pWind->DrawInteger((17.7) * config.toolbarItemWidth, 20, score);
	pWind->SetPen(ORANGE, 50);
	pWind->DrawString((16.9) * config.toolbarItemWidth, 40, "LEVEL: ");
	pWind->DrawInteger((17.5) * config.toolbarItemWidth, 40, level);
}

toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	return (toolbarItem)(x / config.toolbarItemWidth);

}

