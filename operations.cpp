#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include<fstream>
using namespace std;



/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
	tBar = nullptr;
}


operREF::operREF(game* r_pGame) : operation(r_pGame)
{
}
void operREF::Act()
{

	grid* shapesGrid = pGame->getGrid();
	shapesGrid->RestartGEN();
	shapesGrid->GenRandShape();



	grid* gridd = pGame->getGrid();
	config.lives = config.lives - 1;
	tBar = new toolbar(pGame);
	

}



//REEM'S SAVE FUNCTION
/*

/////////////////////////////////// class operSave  //////////////////
operSave::operSave(game* r_pGame) :operation(r_pGame)
void operSave::Act()
fstream file("new data.txt");
file* newdata = fopen(newdata.txt)
fprint * getlevel{
	return level;
}
fprint* getscore{
	return score;
}
fprint* getlives{
	return lives;
}
// getters from game for score, level, and lives
// for (int i=0, i=)
 shapelist[i}.save;
 shape* newdata= pgame->getgrid->pGrid-> getactiveshape;
 newdata.save("newdata.txt");

*/








/////////////////////////////////// class operDelete ////////////////////
operDelete::operDelete(game* r_pGame) : operation(r_pGame)
{
}
void operDelete::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->Delete();

}



operROT::operROT(game* r_pGame) :operation(r_pGame)
{
}
void operROT::Act()
{

	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();
	if (activeShape != nullptr) {
		activeShape->rotate(90);
		pGrid->draw();
	}
}


////////////////////////////////////  RESIZINGGGGG  /////////////////////////////
operSCLUP::operSCLUP(game* r_pGame) :operation(r_pGame)
{
}
void operSCLUP::Act() 
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();
	if (activeShape != nullptr) {
		activeShape->resize(1 / 0.9);
		pGrid->draw();
	}

}
operSCLDWN::operSCLDWN(game* r_pGame) :operation(r_pGame)
{
}
void operSCLDWN::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();
	if (activeShape != nullptr) {
		activeShape->resize(0.9);
		pGrid->draw();
	}
}


///////////////////////////////////////////////////////////////////


/////////////////////////////////// class operAddSign  //////////////////
operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
{
}
void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = nullptr;
	psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();

}


/////////////////////////////////// class operAddTree  //////////////////
operAddTree::operAddTree(game* r_pGame) :operation(r_pGame)
{
}
void operAddTree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point TreeShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Tree(pGame, TreeShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}


/////////////////////////////////// class operAddTruck  //////////////////
operAddTruck::operAddTruck(game* r_pGame) :operation(r_pGame)
{
}
void operAddTruck::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point TruckShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new truck(pGame, TruckShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}




/////////////////////////////////// class operAddRocket  //////////////////
operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}
void operAddRocket::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point RocketShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new rckt(pGame, RocketShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}


/////////////////////////////////// class operAddHouse  //////////////////
operAddHouse::operAddHouse(game* r_pGame) :operation(r_pGame)
{
}
void operAddHouse::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point HouseShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new House(pGame, HouseShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
/////////////////////////////////// class operAddButterfly  //////////////////
operAddButterfly::operAddButterfly(game* r_pGame) :operation(r_pGame)
{
}
void operAddButterfly::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point ButterflyShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new bfly(pGame, ButterflyShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}


/////////////////////////////////// class operAddIcy  //////////////////
operAddIcecream::operAddIcecream(game* r_pGame) :operation(r_pGame)
{
}
void operAddIcecream::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point icyShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new icy(pGame, icyShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}


operSave::operSave(game* r_pGame) : operation(r_pGame) {

}

void operSave::Act()
{
	grid* shapesGrid = pGame->getGrid();
	ofstream GameProgress("GameProgress.txt");
	FILE* progress = fopen("GameProgress.txt", "w");

	int lives = config.lives;
	int score = config.score;
	int level = config.level;

	GameProgress << lives << " ";
	GameProgress << score << " ";
	GameProgress << level << endl;

	shape* sh = shapesGrid->getActiveShape();
	sh->save(GameProgress);

	shapesGrid->saving(GameProgress);



	GameProgress.close();
}