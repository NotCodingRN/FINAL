#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	double x, y;
};


enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign
	RCKT,
	TRUCK,
	ICY,
	HOUSE,
	BFLY,
	TREE,


	//TODO: Add more types
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
	game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	int rotationAngle;
	int rotationcount;
	int resizecount;
public:
	shape(game* r_pGame, point ref);
	virtual void draw() const = 0;//for a shape to draw itself on the screen
	virtual void resize(double size) = 0;
	virtual void rotate(int AddONAngle) = 0;
	virtual void move(point dir) = 0;
	virtual int getType();

	void setRefPoint(point p);
	point getRefPoint();
	
	void setcolor(color c, color p);
	void save(ofstream& out);
	int getRotationCount() const;
	int getResizeCount() const;

	void load(ifstream& in);
	/*
	TO DO:
	1-virtual void save(ofstream &OutFile) = 0;
	2-virtual void load(ifstream &Infile) = 0;
	*/

};