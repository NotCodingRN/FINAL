#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#include <iostream>

////////////////////////////////////////////////////  class Tria  ///////////////////////////////////////
Tria::Tria(game* r_pGame, point ref, double height, double base) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	basee = base;
	hght = -height;
	rotationAngle = 0;
	x.x = RefPoint.x - basee / 2;
	y.x = RefPoint.x + basee / 2;
	z.x = RefPoint.x;
	x.y = RefPoint.y - hght;
	y.y = x.y;
	z.y = RefPoint.y + hght;

}
void Tria::resize(double size)
{
	
	basee = basee * size;
	hght = hght * size;
	rotate(90); rotate(90); rotate(90); rotate(90);

}

void Tria::draw() const
{
	
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	pW->DrawTriangle(x.x, x.y, y.x, y.y, z.x, z.y, FILLED);
}
point Tria::getRefPoint() const 
{
	return RefPoint;
}
void Tria::rotate(int AddONAngle)
{

	rotationAngle += 90;

	double theta = rotationAngle * 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217 / 180.0;
	double cosTheta = cos(theta);
	double sinTheta = sin(theta);

	// Define triangle vertices
	point vertices[3] = { {RefPoint.x - basee / 2,RefPoint.y - hght}, {RefPoint.x + basee / 2, RefPoint.y - hght}, {RefPoint.x, RefPoint.y + hght} };

	// Rotate each vertex around the reference point
	for (int i = 0; i < 3; ++i) {
		double newX = cosTheta * (vertices[i].x - RefPoint.x) - sinTheta * (vertices[i].y - RefPoint.y) + RefPoint.x; double newY = sinTheta * (vertices[i].x - RefPoint.x) + cosTheta * (vertices[i].y - RefPoint.y) + RefPoint.y;

		vertices[i].x = newX;
		vertices[i].y = newY;
	}
	x = vertices[0];
	y = vertices[1];
	z = vertices[2];
	draw();
	
}
void Tria::move(point dir)
{
	RefPoint.x += dir.x;
	RefPoint.y += dir.y;
	rotate(90); rotate(90); rotate(90); rotate(90);
}
int Tria::getrotation()
{
	return rotationAngle;
}

int Tria::getType()
{
	return 3;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
Rect::Rect(game* r_pGame, point ref, double r_hght, double r_wdth) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;

}
void Rect::resize(double size)
{
	wdth = wdth * size;
	hght = hght * size;

}
void Rect::rotate(int AddONAngle)
{
	int temp = hght;
	hght = wdth;
	wdth = temp; draw();
}
void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = (RefPoint.x - wdth / 2);
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}
point Rect::getRefPoint() const {
	return RefPoint;
}
void Rect::move(point dir)
{
	RefPoint.x += dir.x;
	RefPoint.y += dir.y;
}
int Rect::getrotation()
{
	return rotationAngle;
}

int Rect::getType()
{
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 
//
////////////////////////////////////////////////////  class circle  /////////////////////////////////////
circle::circle(game* r_pGame, point ref, double r) :shape(r_pGame, ref)
{
	rad = r;
}
void circle::resize(double size)
{
	rad = rad * size;
}
void circle::rotate(int AddONAngle) 
{
	draw();
}
void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}
point circle::getRefPoint() const {
	return RefPoint;
}
void circle::move(point dir)
{
	RefPoint.x += dir.x;
	RefPoint.y += dir.y;
}
int circle::getrotation()
{
	return rotationAngle;
}


int circle::getType()
{
	return 2;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////