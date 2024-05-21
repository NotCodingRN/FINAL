#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include "time.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>

grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
			if (shapeList[i])
				shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}



//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;

}

void grid::Delete()
{
    clearGridArea();
    window* pWind = pGame->getWind();

    pWind->SetPen(config.gridDotsColor, 1);
    pWind->SetBrush(config.gridDotsColor);

    //draw dots showing the grid reference points
    for (int r = 1; r < rows; r++)
        for (int c = 0; c < cols; c++)
            pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
    //pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
    for (int i = 0; i < shapeCount; i++)
        if (shapeList[i])
            shapeList[i]->draw();	//draw each shape
    if (activeShape) {
        delete activeShape;
        activeShape = nullptr;
    }
}


shape* grid::getshapeList() {
	for (int i = 0; i < 1000; i++)
	{
		return shapeList[i];
	}
}

shape* grid::getActiveShape() const
{
	return activeShape;
}


void grid::RestartGEN()
{
    
    for (int i = 0; i < shapeCount; i++) 
    {
        delete shapeList[i];
        shapeList[i] = nullptr;

    }

}

shape* grid::GenRandShape()
{
    window* pw = pGame->getWind();
    shape* gen = nullptr;
    srand(time(0));
    int keep = 0;
    int shapesToDraw = (2 * config.level) - 1;

    while (keep < shapesToDraw)
    {
        
        int rRot = rand() % 4;
        int rShape = rand() % 7;
        int rSize = 1 + rand() % 5;
       
        gen = 0;

        int miny = 100;
        int maxy = 600;
        int minx = 80;
        int maxx = 1080;
        int index = 10;

        if (config.level >= 3) {
            gen->setcolor(BLACK , BLACK);
        }
        else 
        {
            int choice = rand() % 8; 

            switch (choice) {
            case 0:  gen->setcolor(RED, BLACK); break;
            case 1:  gen->setcolor(GREEN, BLACK); break;
            case 2:  gen->setcolor(BLUE, BLACK); break;
            case 3:  gen->setcolor(CYAN, BLACK); break;
            case 4:  gen->setcolor(MAGENTA, BLACK); break;
            case 5:  gen->setcolor(YELLOW, BLACK); break;
            case 6:  gen->setcolor(ORANGE, BLACK); break;
            case 7:  gen->setcolor(PURPLE, BLACK); break;
            default: gen->setcolor(WHITE, BLACK); break; 
            }
        }


            double y = miny + (rand() % (maxy - miny + 1)) + index;
            double x = minx + (rand() % (maxx - minx + 1)) + index;
            point ref = { x,y };
        
            switch (rShape)
            {
            case 0:
                gen = new icy(pGame, ref);
                break;
            case 1:
                gen = new truck(pGame, ref);
                break;
            case 2:
                gen = new bfly(pGame, ref);
                break;
            case 3:
                gen = new Tree(pGame, ref);
                break;
            case 4:
                gen = new House(pGame, ref);
                break;
            case 5:
                gen = new rckt(pGame, ref);
                break;
            case 6:
                gen = new Sign(pGame, ref);
                break;
            }
        
            addShape(gen);

        for (int i = 0; i < rSize; ++i) {
            float RndSize;
            if (rand() % 2 == 0) {
                RndSize = 0.9;
            }
            else {
                RndSize = 1 / 0.9;
            }
            gen->resize(RndSize);
        }

        for (int i = 0; i < rRot; ++i)
        {
            gen->rotate(90);
        }
        cout << gen->getRefPoint().x << "," << gen->getRefPoint().y << endl;
        keep++;
    }
 
    draw();
    return nullptr;
}


void grid::saving(ofstream& SA) const
{
    for (int i = 0; i < shapeCount; i++)
    {
        if (shapeList[i] != nullptr)
        {
            shapeList[i]->save(SA);
        }
    }
}


bool grid::checkref(point p1, point p2)
{
    if (p1.x<p2.x + 25 && p1.x > p2.x - 25) {
        if (p1.y<p2.y + 25 && p1.y > p2.y - 25) {
            return true;
        }
    }
    else
    {
        return false;
    }
}


bool grid::levelup()
{
    for (int i = 0; i < MaxShapeCount; i++) {
        if (shapeList[i] != nullptr) {
            return false;
        }
    }
    return true;
}


void grid::matching()
{
    toolbar* tBar;

    for (int i = 0; i < shapeCount; i++) 
    {
        if (activeShape && shapeList[i]) 
        {
            if (activeShape->getType() == shapeList[i]->getType()) 
            {
                if (checkref(activeShape->getRefPoint(), shapeList[i]->getRefPoint())) 
                {
                    if ((activeShape->getRotationCount() % 4) == (shapeList[i]->getRotationCount() % 4)) 
                    {
                        if (levelup())
                        {
                            config.level = config.level + 1;
                            tBar = new toolbar(pGame);
                        }
                        delete shapeList[i];
                        shapeList[i] = nullptr;
                        Delete();
                        config.score = config.score + 5;
                        tBar = new toolbar(pGame);
                    }
                    draw();
                }
            }
        }
    }
   
}




