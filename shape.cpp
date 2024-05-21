#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <iostream>
#include<fstream>



shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
	rotationcount = 0;
	resizecount = 0;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
point shape::getRefPoint() 
{

	return RefPoint;
}


void shape::move(point dir)
{
	RefPoint.x += dir.x;
	RefPoint.y += dir.y;
}


void shape::setcolor(color f,color p)
{
	config.fillColor = f;
	config.penColor = p;
}

int shape::getType() {
	return 0;
}

void shape::save(ofstream& o)
{
	o << getType() << " " << RefPoint.x << " " << RefPoint.y << " " << rotationcount << " " << resizecount << endl;
}

int shape::getRotationCount() const
{
	return rotationcount % 4;
}

int shape::getResizeCount() const
{
	return resizecount;
}



//void shape::load(ifstream& b) {
//	b << setType() << " " << RefPoint.x << " " << RefPoint.y << " " << rotationcount << " " << resizecount << endl;
//}
