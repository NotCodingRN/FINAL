//ARROW KEYS ASCII
#define KEY_UP 8
#define KEY_DOWN 2
#define KEY_LEFT 4
#define KEY_RIGHT 6
#include "game.h"
#include "gameConfig.h"
#include <iostream>



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();
	
	//Create and draw the grid
	createGrid();
	shapesGrid->GenRandShape();
	shapesGrid->draw();	//draw the grid and all shapes it contains.
	
	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
	
}


void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this); printMessage("You clicked on Draw Sign");
		break;
	case ITM_TRUCK:
		op = new operAddTruck(this); printMessage("You clicked on Draw Truck");
		break;
	case ITM_TREE:
		op = new operAddTree(this); printMessage("You clicked on Draw Tree");
		break;
	case ITM_HOUSE:
		op = new operAddHouse(this); printMessage("You clicked on Draw House");
		break;
	case ITM_ROCKET:
		op = new operAddRocket(this); printMessage("You clicked on Draw Rocket");
		break;
	case ITM_ICECREAM:
		op = new operAddIcecream(this); printMessage("You clicked on Draw IceCream");
		break;
	case ITM_BUTTERFLY:
		op = new operAddButterfly(this); printMessage("You clicked on Draw Butterfly");
		break;
	case ITM_DEL:
		op = new operDelete(this); printMessage("You clicked on Delete");
		break;
	case ITM_SCLUP:
		op = new operSCLUP(this); printMessage("You clicked on ScaleUp");
		break;
	case ITM_SCLDWN:
		op = new operSCLDWN(this); printMessage("You clicked on ScaleDown");
		break;
	case ITM_ROT:
		op = new operROT(this); printMessage("You clicked on Rotation");
		break;
	case ITM_SAVE:
		op = new operSave(this); printMessage("file saved");
		break;
	case ITM_REF:
		op = new operREF(this); printMessage("You clicked on Refresh");
		break;
	
	}
	
	return op;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}




window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}

string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}











//MOVEMENT ACTIVATION FUNCTION
void game::movekey(char K) {

	double Step = 5;

	shape* activeShape = shapesGrid->getActiveShape();

	if (activeShape != nullptr) {
		switch (K) {
		case KEY_UP:
		case 'W':
		case 'w':
			
			activeShape->move({ 0, -Step });
			break;

		case KEY_DOWN:
		case 'S':
		case 's':
			
			activeShape->move({ 0, Step });
			break;

		case KEY_LEFT:
		case 'A':
		case 'a':
			
			activeShape->move({ -Step, 0 });
			break;

		case KEY_RIGHT:
		case 'D':
		case 'd':
		
			activeShape->move({ Step, 0 });
			break;

		case 'q':
			shapesGrid->matching();
			break;
		}

		
		shapesGrid->draw();
	}
}

////////////////////////////////////////////////////////////////////////
void game::run()
{
	int x, y;
	toolbarItem clickedItem = ITM_CNT;
	bool shapeGenerated = false; 

	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");

	shape* activeShape = shapesGrid->getActiveShape();
	char key;
	do
	{
		while (pWind->GetKeyPress(key))
		{
			movekey(key);
		}

		pWind->GetMouseClick(x, y);

		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);

			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			shapesGrid->draw();

	
			
			
		}
	} while (clickedItem != ITM_EXIT);
}


