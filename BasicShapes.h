//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

class Rect :public shape
{
	double hght, wdth;	//height and width of the rectangle

public:
	Rect(game* r_pGame, point ref, double r_hght, double r_wdth);

	virtual void draw() const override;
	virtual void resize(double size) override;
	virtual void rotate(int AddONAngle) override;
	point getRefPoint() const;
	virtual void move(point dir);
	int getrotation();
	int getType();
};

class Tria :public shape
{
	double hght, basee;
	double rotationAngle;
	point x, y, z;

public:
	Tria(game* r_pGame, point ref, double hight, double base);

	virtual void draw() const override;
	virtual void resize(double size) override;
	void update(point p1,point p2,point p3);
	virtual void rotate(int AddONAngle) override;
	point getRefPoint() const;
	virtual void move(point dir);
	int getrotation();
	int getType();
};

class circle :public shape
{
	//Add data memebrs for class circle
	double rad;

public:
	circle(game* r_pGame, point ref, double r);	//add more parameters for the constructor if needed

	virtual void draw() const override;
	virtual void resize(double size) override;
	virtual void rotate(int AddONAngle) override;
	point getRefPoint() const;
	virtual void move(point dir);
	int getrotation();
	int getType();
};