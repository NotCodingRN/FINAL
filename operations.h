#pragma once
#include "toolbar.h"

class game;
class operation
{
protected:
	game* pGame; //pointer to the game class
	toolbar* tBar;	
public:
	operation(game* r_pGame);
	virtual void Act() = 0;
};

class operLoad : public operation
{
public:
	operLoad(game* r_pGame);
	virtual void Act();
};




class operREF : public operation
{
public:
	operREF(game* r_pGame);
	virtual void Act();
};


//////////////////////////////	CALL del function  ////////////////////
class operDelete : public operation
{
public:
	operDelete(game* r_pGame);
	virtual void Act();
};
//////////////////////////////////////////////////////////////////////


class operROT :public operation
{
public:
	operROT(game* r_pGame);
	virtual void Act();
};


/////////////////////	CALL Resizing functions	////////////////////
class operSCLUP :public operation
{
public:
	operSCLUP(game* r_pGame);
	virtual void Act();
};

class operSCLDWN :public operation
{
public:
	operSCLDWN(game* r_pGame);
	virtual void Act();
};
///////////////////////////////////////////////////////////////////



////////////////////////////	CALL SHAPES	   ////////////////////
class operAddSign :public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};
class operAddTruck :public operation
{

public:
	operAddTruck(game* r_pGame);
	virtual void Act();
};
class operAddTree :public operation
{
public:
	operAddTree(game* r_pGame);
	virtual void Act();
};
class operAddIcecream :public operation
{
public:
	operAddIcecream(game* r_pGame);
	virtual void Act();
};
class operAddRocket :public operation
{
public:
	operAddRocket(game* r_pGame);
	virtual void Act();
};
class operAddHouse :public operation
{
public:
	operAddHouse(game* r_pGame);
	virtual void Act();
};
class operAddButterfly :public operation
{
public:
	operAddButterfly(game* r_pGame);
	virtual void Act();
};


class operSave : public operation
{
public:
	operSave(game* r_pGame);
	virtual void Act();
};
///////////////////////////////////////////////////////////////////