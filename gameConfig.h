#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)

struct scale { double h, w; };

__declspec(selectany) //This line to prevent "redefinition error"
struct
{
	int lives = 5;
	int score = 0;
	int level = 2;

	int	windWidth = 1280, windHeight = 800,	//Window width and height
		wx = 5, wy = 5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight = 60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight = 50;	//Status Bar Height

	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = NAVY,			//color used to draw borders/write messages
		fillColor =NAVY,	//shapes fill color (Default)
		bkGrndColor = SNOW,		//Screen Background color
		statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth = 3;			//width of the pen that draws shapes

	color gridDotsColor = DARKCYAN;
	int gridSpacing = 55;	
	int RefX = windWidth * (2.0 / 3);
	int RefY = windHeight * (0.5);






	////---------  Shape Confogurations ---------////
	struct {
		double baseWdth = 20, baseHeight = 80;
		double topWdth = 100, topHeight = 50;
	}sighShape;

	struct {
		double baseWdth = 20, baseHeight = 80;
		double topwdth = 20, topbheight = 30;
		struct {
			int	wide = 80, up = 30;
		}shrub;
	}TreeShape;

	struct {
		double baseWdth = 50, baseHeight = 40;

		struct {
			double up = 20, wide = 80;
		}t;


	}HouseShape;


	struct {
		double baseWdth = 16 , baseHeight = 83;
		double Lradius = 27, Sradius = 22;
	}bflybod;

	struct {
		double carWdth = 120, carHeight = 40, wrad = 25;
		double winwdth = 50, winhght = 25;
		double shght = 5; double sbase = 20;
	}car;

	struct {
		double conebase = 50; double conehght = -50;
		struct {
			double rad = 30;
		}ball;
	}icy;

	struct {
		double rckthght = 125;
		double rcktwdth = 40;
		double topup = 20, topwide = 45;
		double lowup = 20, lowwide = 80;
	}rckt;


}config;






enum toolbarItem //The items of the  toolbar (you should add more items)
{
	
	ITM_SIGN,
	ITM_HOUSE,
	ITM_TREE,
	ITM_ROCKET,
	ITM_ICECREAM,
	ITM_BUTTERFLY,
	ITM_TRUCK,
	ITM_SCLUP,
	ITM_SCLDWN,
	ITM_ROT,
	ITM_DEL,
	ITM_REF,
	ITM_HINT,
	ITM_LVL,
	ITM_SAVE,
	ITM_EXIT,


	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};
