#include "CompositeShapes.h"
#include "gameConfig.h"
#include <iostream>
#include "grid.h"   	


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Sign::Sign(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point topRef = ref;
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}
void Sign::resize(double size)
{
	point nbase;
	nbase = { (base->getRefPoint().x - top->getRefPoint().x) * size + top->getRefPoint().x, (base->getRefPoint().y - top->getRefPoint().y) * size + top->getRefPoint().y };
	base->setRefPoint(nbase);
	top->resize(size);
	base->resize(size);	
	resizecount++;
	
}
void Sign::rotate(int AddONAngle) {

	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);

	point nref;
	nref.x = (base->getRefPoint().x - top->getRefPoint().x) * coss - (base->getRefPoint().y - top->getRefPoint().y) * sinn + top->getRefPoint().x;
	nref.y = (base->getRefPoint().y - top->getRefPoint().y) * coss + (base->getRefPoint().x - top->getRefPoint().x) * sinn + top->getRefPoint().y;

	base->setRefPoint(nref);

	base->rotate(AddONAngle);
	top->rotate(AddONAngle);
	rotationcount++;
}
void Sign::draw() const
{
	base->draw();
	top->draw();
}
void Sign::move(point dir)
{
	top->move(dir);
	base->move(dir);
}
Sign::~Sign() {
	delete base;
	delete top;
}
int Sign::getType()
{
	return 4;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tree::Tree(game* r_pGame, point ref) : shape(r_pGame, ref)
{


	point baseRef = RefPoint;
	point topref, topref2, pbell;

	topref = { RefPoint.x, RefPoint.y - config.TreeShape.baseHeight / 2 - config.TreeShape.topbheight };
	topref2 = { RefPoint.x, topref.y - config.TreeShape.topbheight };

	pbell.x = topref.x;
	pbell.y = topref2.y - 37;

	bell = new circle(pGame, pbell, 7);
	base = new Rect(pGame, baseRef, config.TreeShape.baseHeight, config.TreeShape.baseWdth);
	top = new Tria(pGame, topref, config.TreeShape.shrub.up, config.TreeShape.shrub.wide);
	top2 = new Tria(pGame, topref2, config.TreeShape.shrub.up, config.TreeShape.shrub.wide);

}
void Tree::resize(double size)
{

	point ntop;
	ntop = { (top->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (top->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	top->setRefPoint(ntop);
	point ntop2;
	ntop2 = { (top2->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (top2->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	top2->setRefPoint(ntop2);
	point nbell;
	nbell = { (bell->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (bell->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	bell->setRefPoint(nbell);


	base->resize(size);
	top->resize(size);
	top2->resize(size);
	bell->resize(size);
	resizecount++;

}
void Tree::rotate(int AddONAngle) {

	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);

	point ntop, ntop2, nbell;

	ntop.x = (top->getRefPoint().x - base->getRefPoint().x) * coss - (top->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	ntop.y = (top->getRefPoint().y - base->getRefPoint().y) * coss + (top->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	ntop2.x = (top2->getRefPoint().x - base->getRefPoint().x) * coss - (top2->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	ntop2.y = (top2->getRefPoint().y - base->getRefPoint().y) * coss + (top2->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	nbell.x = (bell->getRefPoint().x - base->getRefPoint().x) * coss - (bell->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nbell.y = (bell->getRefPoint().y - base->getRefPoint().y) * coss + (bell->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	bell->setRefPoint(nbell);
	top->setRefPoint(ntop);
	top2->setRefPoint(ntop2);
	base->rotate(AddONAngle);
	top->rotate(AddONAngle);
	bell->rotate(AddONAngle);
	top2->rotate(AddONAngle);
	rotationcount++;
}
void Tree::draw() const
{
	bell->draw();
	base->draw();
	top->draw();
	top2->draw();
}
void Tree::move(point dir)
{
	bell->move(dir);
	base->move(dir);
	top->move(dir);
	top2->move(dir);
}
Tree::~Tree() {
	delete base;
	delete top;
	delete top2;
	delete bell;
}
int Tree::getType()
{
	return 5;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
House::House(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseref = ref;
	point topref, topref2;
	topref.x = ref.x;
	topref.y = ref.y - 40;



	base = new Rect(pGame, baseref, config.HouseShape.baseHeight, config.HouseShape.baseWdth);
	top = new Tria(pGame, topref, config.HouseShape.t.up, config.HouseShape.t.wide);

}
void House::rotate(int AddONAngle)
{
	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);
	point ntop;
	ntop.x = (top->getRefPoint().x - base->getRefPoint().x) * coss - (top->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	ntop.y = (top->getRefPoint().y - base->getRefPoint().y) * coss + (top->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;
	top->setRefPoint(ntop);
	base->rotate(AddONAngle);
	top->rotate(AddONAngle);
	rotationcount++;
}
void House::resize(double size) {
	point ntop;
	ntop = { (top->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (top->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	top->setRefPoint(ntop);
	top->resize(size);
	base->resize(size);
	resizecount++;
}
void House::draw() const
{
	base->draw();
	top->draw();
}
void House::move(point dir)
{
	base->move(dir);
	top->move(dir);

}
House::~House() {
	delete base;
	delete top;
}

int House::getType()
{
	return 6;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bfly::bfly(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseref = ref;
	point pwing11, pwing12, pwing21, pwing22, feelerr1, feelerr2;
	pwing11.x = baseref.x - 22.5;
	pwing11.y = baseref.y - 15;

	pwing12.x = pwing11.x + 4;
	pwing12.y = baseref.y + 26;
	
	pwing21.x = baseref.x + 22.5;
	pwing21.y = baseref.y - 15;

	pwing22.x = pwing21.x - 4;
	pwing22.y = baseref.y + 26;

	feelerr1.x = baseref.x - 5;
	feelerr1.y = baseref.y - 45;

	feelerr2.x = baseref.x + 5;
	feelerr2.y = baseref.y - 45;

	feeler1 = new Tria(pGame, feelerr1, config.bflybod.baseHeight / 10, config.bflybod.baseWdth / 4);
	feeler2 = new Tria(pGame, feelerr2, config.bflybod.baseHeight / 10, config.bflybod.baseWdth / 4);
	bflybod = new Rect(pGame, baseref, config.bflybod.baseHeight, config.bflybod.baseWdth);
	wing11 = new circle(pGame, pwing11, config.bflybod.Lradius);
	wing12 = new circle(pGame, pwing12, config.bflybod.Sradius);
	wing21 = new circle(pGame, pwing21, config.bflybod.Lradius);
	wing22 = new circle(pGame, pwing22, config.bflybod.Sradius);

}
void bfly::resize(double size) {


	point nwing11;
	nwing11 = { (wing11->getRefPoint().x - bflybod->getRefPoint().x) * size + bflybod->getRefPoint().x, (wing11->getRefPoint().y - bflybod->getRefPoint().y) * size + bflybod->getRefPoint().y };
	wing11->setRefPoint(nwing11);
	point nwing12;
	nwing12 = { (wing12->getRefPoint().x - bflybod->getRefPoint().x) * size + bflybod->getRefPoint().x, (wing12->getRefPoint().y - bflybod->getRefPoint().y) * size + bflybod->getRefPoint().y };
	wing12->setRefPoint(nwing12);
	point nwing21;
	nwing21 = { (wing21->getRefPoint().x - bflybod->getRefPoint().x) * size + bflybod->getRefPoint().x, (wing21->getRefPoint().y - bflybod->getRefPoint().y) * size + bflybod->getRefPoint().y };
	wing21->setRefPoint(nwing21);
	point nwing22;
	nwing22 = { (wing22->getRefPoint().x - bflybod->getRefPoint().x) * size + bflybod->getRefPoint().x, (wing22->getRefPoint().y - bflybod->getRefPoint().y) * size + bflybod->getRefPoint().y };
	wing22->setRefPoint(nwing22);
	point nfeeler1;
	nfeeler1 = { (feeler1->getRefPoint().x - bflybod->getRefPoint().x) * size + bflybod->getRefPoint().x, (feeler1->getRefPoint().y - bflybod->getRefPoint().y) * size + bflybod->getRefPoint().y };
	feeler1->setRefPoint(nfeeler1);
	point nfeeler2;
	nfeeler2 = { (feeler2->getRefPoint().x - bflybod->getRefPoint().x) * size + bflybod->getRefPoint().x, (feeler2->getRefPoint().y - bflybod->getRefPoint().y) * size + bflybod->getRefPoint().y };
	feeler2->setRefPoint(nfeeler2);
	wing11->resize(size);
	wing12->resize(size);
	wing21->resize(size);
	wing22->resize(size);
	bflybod->resize(size);
	feeler1->resize(size);
	feeler2->resize(size);
	resizecount++;

}
void bfly::rotate(int AddONAngle)
{
	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);
	point nwing11, nwing12, nwing21, nwing22, nfeeler1, nfeeler2;
	nwing11.x = (wing11->getRefPoint().x - bflybod->getRefPoint().x) * coss - (wing11->getRefPoint().y - bflybod->getRefPoint().y) * sinn + bflybod->getRefPoint().x;
	nwing11.y = (wing11->getRefPoint().y - bflybod->getRefPoint().y) * coss + (wing11->getRefPoint().x - bflybod->getRefPoint().x) * sinn + bflybod->getRefPoint().y;

	nwing12.x = (wing12->getRefPoint().x - bflybod->getRefPoint().x) * coss - (wing12->getRefPoint().y - bflybod->getRefPoint().y) * sinn + bflybod->getRefPoint().x;
	nwing12.y = (wing12->getRefPoint().y - bflybod->getRefPoint().y) * coss + (wing12->getRefPoint().x - bflybod->getRefPoint().x) * sinn + bflybod->getRefPoint().y;

	nwing21.x = (wing21->getRefPoint().x - bflybod->getRefPoint().x) * coss - (wing21->getRefPoint().y - bflybod->getRefPoint().y) * sinn + bflybod->getRefPoint().x;
	nwing21.y = (wing21->getRefPoint().y - bflybod->getRefPoint().y) * coss + (wing21->getRefPoint().x - bflybod->getRefPoint().x) * sinn + bflybod->getRefPoint().y;

	nwing22.x = (wing22->getRefPoint().x - bflybod->getRefPoint().x) * coss - (wing22->getRefPoint().y - bflybod->getRefPoint().y) * sinn + bflybod->getRefPoint().x;
	nwing22.y = (wing22->getRefPoint().y - bflybod->getRefPoint().y) * coss + (wing22->getRefPoint().x - bflybod->getRefPoint().x) * sinn + bflybod->getRefPoint().y;

	nfeeler1.x = (feeler1->getRefPoint().x - bflybod->getRefPoint().x) * coss - (feeler1->getRefPoint().y - bflybod->getRefPoint().y) * sinn + bflybod->getRefPoint().x;
	nfeeler1.y = (feeler1->getRefPoint().y - bflybod->getRefPoint().y) * coss + (feeler1->getRefPoint().x - bflybod->getRefPoint().x) * sinn + bflybod->getRefPoint().y;

	nfeeler2.x = (feeler2->getRefPoint().x - bflybod->getRefPoint().x) * coss - (feeler2->getRefPoint().y - bflybod->getRefPoint().y) * sinn + bflybod->getRefPoint().x;
	nfeeler2.y = (feeler2->getRefPoint().y - bflybod->getRefPoint().y) * coss + (feeler2->getRefPoint().x - bflybod->getRefPoint().x) * sinn + bflybod->getRefPoint().y;

	wing11->setRefPoint(nwing11); wing12->setRefPoint(nwing12); wing21->setRefPoint(nwing21); wing22->setRefPoint(nwing22); feeler1->setRefPoint(nfeeler1); feeler2->setRefPoint(nfeeler2);
	wing11->rotate(AddONAngle);
	wing12->rotate(AddONAngle);
	wing21->rotate(AddONAngle);
	wing22->rotate(AddONAngle);
	bflybod->rotate(AddONAngle);
	feeler1->rotate(AddONAngle);
	feeler2->rotate(AddONAngle);
	rotationcount++;
}
void bfly::draw() const
{
	wing22->draw();
	wing21->draw();
	wing12->draw();
	wing11->draw();
	feeler1->draw(); 
	feeler2->draw();
	bflybod->draw();

}
void bfly::move(point dir)
{
	bflybod->move(dir);
	feeler1->move(dir);
	feeler2->move(dir);
	wing21->move(dir);
	wing22->move(dir);
	wing11->move(dir);
	wing12->move(dir);

}
bfly::~bfly() {
	delete feeler1;
	delete feeler2;
	delete bflybod;
	delete wing11;
	delete wing12;
	delete wing21;
	delete wing22;
}
int bfly::getType()
{
	return 7;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
truck::truck(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseref = ref;
	point wheely1, wheely2, pwindow, pspoiler;
	pwindow.x = baseref.x - 20;
	pwindow.y = baseref.y - 30;
	wheely1.x = baseref.x - 30;
	wheely1.y = baseref.y + 20; wheely2.y = wheely1.y;
	wheely2.x = baseref.x + 30;
	pspoiler.x = baseref.x + config.car.carWdth / 2.25;
	pspoiler.y = baseref.y - (config.car.carHeight / 2) - (config.car.shght / 2);
	spoiler = new Tria(pGame, pspoiler, config.car.shght, config.car.sbase);
	base = new Rect(pGame, baseref, config.car.carHeight, config.car.carWdth);
	windoww = new Rect(pGame, pwindow, config.car.winhght, config.car.winwdth);
	wheel1 = new circle(pGame, wheely1, config.car.wrad);
	wheel2 = new circle(pGame, wheely2, config.car.wrad);


}
void truck::resize(double size)
{
	point nwheel1;
	nwheel1 = { (wheel1->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (wheel1->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	wheel1->setRefPoint(nwheel1);
	point nwheel2;
	nwheel2 = { (wheel2->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (wheel2->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	wheel2->setRefPoint(nwheel2);
	point nwindoww;
	nwindoww = { (windoww->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (windoww->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	windoww->setRefPoint(nwindoww);
	point nspoiler;
	nspoiler = { (spoiler->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (spoiler->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	spoiler->setRefPoint(nspoiler);

	base->resize(size);
	wheel1->resize(size);
	wheel2->resize(size);
	windoww->resize(size);
	spoiler->resize(size);
	resizecount++;

}
void truck::rotate(int AddONAngle)
{
	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);

	point nwheel1, nwheel2, nwindow, nspoiler;
	nwheel1.x = (wheel1->getRefPoint().x - base->getRefPoint().x) * coss - (wheel1->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nwheel1.y = (wheel1->getRefPoint().y - base->getRefPoint().y) * coss + (wheel1->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;
	nwheel2.x = (wheel2->getRefPoint().x - base->getRefPoint().x) * coss - (wheel2->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nwheel2.y = (wheel2->getRefPoint().y - base->getRefPoint().y) * coss + (wheel2->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;
	nwindow.x = (windoww->getRefPoint().x - base->getRefPoint().x) * coss - (windoww->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nwindow.y = (windoww->getRefPoint().y - base->getRefPoint().y) * coss + (windoww->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;
	nspoiler.x = (spoiler->getRefPoint().x - base->getRefPoint().x) * coss - (spoiler->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nspoiler.y = (spoiler->getRefPoint().y - base->getRefPoint().y) * coss + (spoiler->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	wheel1->setRefPoint(nwheel1), wheel2->setRefPoint(nwheel2), windoww->setRefPoint(nwindow), spoiler->setRefPoint(nspoiler);
	spoiler->rotate(AddONAngle);
	base->rotate(AddONAngle);
	wheel1->rotate(AddONAngle);
	wheel2->rotate(AddONAngle);
	windoww->rotate(AddONAngle);
	rotationcount++;
}
void truck::draw() const
{
	spoiler->draw();
	base->draw();
	wheel1->draw();
	wheel2->draw();
	windoww->draw();

}
void truck::move(point dir)
{
	spoiler->move(dir);
	base->move(dir);
	wheel1->move(dir);
	wheel2->move(dir);
	windoww->move(dir);
}
truck::~truck() {
	delete spoiler;
	delete base;
	delete wheel1;
	delete wheel2;
	delete windoww;
}
int truck::getType()
{
	return 8;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
icy::icy(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseref = ref;
	point pball;
	pball.x = baseref.x;
	pball.y = baseref.y + config.icy.conehght - 20;

	ball = new circle(pGame, pball, config.icy.ball.rad);
	cone = new Tria(pGame, baseref, config.icy.conehght, config.icy.conebase);
}
void icy::resize(double size)
{

	cone->resize(size);
	point nball;
	nball = { (ball->getRefPoint().x - cone->getRefPoint().x) * size + cone->getRefPoint().x, (ball->getRefPoint().y - cone->getRefPoint().y) * size + cone->getRefPoint().y };
	ball->setRefPoint(nball);
	ball->resize(size);
	resizecount++;
}
void icy::rotate(int AddONAngle)
{
	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);

	point ballref;
	ballref.x = (ball->getRefPoint().x - cone->getRefPoint().x) * coss - (ball->getRefPoint().y - cone->getRefPoint().y) * sinn + cone->getRefPoint().x;
	ballref.y = (ball->getRefPoint().y - cone->getRefPoint().y) * coss + (ball->getRefPoint().x - cone->getRefPoint().x) * sinn + cone->getRefPoint().y;
	ball->setRefPoint(ballref);

	ball->rotate(AddONAngle);
	cone->rotate(AddONAngle);
	rotationcount++;
}
void icy::draw() const
{

	ball->draw();
	cone->draw();
}
void icy::move(point dir)
{
	cone->move(dir);
	ball->move(dir);
}
icy::~icy() {
	delete cone;
	delete ball;
}
int icy::getType()
{
	return 9;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
rckt::rckt(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	point baseref = ref;
	point topref, lowref, ball1ref, ball2ref;
	topref.x = ref.x;
	topref.y = ref.y - 80;
	lowref.x = topref.x;
	lowref.y = ref.y + 60;
	ball1ref.x = ref.x - 20;
	ball2ref.x = ref.x + 20;
	ball1ref.y = lowref.y + config.rckt.lowup;
	ball2ref.y = ball1ref.y;

	ball1 = new circle(pGame, ball1ref, 10);
	ball2 = new circle(pGame, ball2ref, 10);
	base = new Rect(pGame, baseref, config.rckt.rckthght, config.rckt.rcktwdth);
	top = new Tria(pGame, topref, config.rckt.topup, config.rckt.topwide);
	low = new Tria(pGame, lowref, config.rckt.lowup, config.rckt.lowwide);



}
void rckt::resize(double size)
{
	point ntop;
	ntop = { (top->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (top->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	top->setRefPoint(ntop);

	point nlow;
	nlow = { (low->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (low->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	low->setRefPoint(nlow);

	point nball1;
	nball1 = { (ball1->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (ball1->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	ball1->setRefPoint(nball1);

	point nball2;
	nball2 = { (ball2->getRefPoint().x - base->getRefPoint().x) * size + base->getRefPoint().x, (ball2->getRefPoint().y - base->getRefPoint().y) * size + base->getRefPoint().y };
	ball2->setRefPoint(nball2);

	base->resize(size);
	top->resize(size);
	low->resize(size);
	ball1->resize(size);
	ball2->resize(size);
	resizecount++;

}
void rckt::rotate(int AddONAngle)
{
	double theta = AddONAngle * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double coss = cos(theta);
	double sinn = sin(theta);

	point ntop, nlow, nball1, nball2;
	ntop.x = (top->getRefPoint().x - base->getRefPoint().x) * coss - (top->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	ntop.y = (top->getRefPoint().y - base->getRefPoint().y) * coss + (top->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	nlow.x = (low->getRefPoint().x - base->getRefPoint().x) * coss - (low->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nlow.y = (low->getRefPoint().y - base->getRefPoint().y) * coss + (low->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	nball1.x = (ball1->getRefPoint().x - base->getRefPoint().x) * coss - (ball1->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nball1.y = (ball1->getRefPoint().y - base->getRefPoint().y) * coss + (ball1->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;

	nball2.x = (ball2->getRefPoint().x - base->getRefPoint().x) * coss - (ball2->getRefPoint().y - base->getRefPoint().y) * sinn + base->getRefPoint().x;
	nball2.y = (ball2->getRefPoint().y - base->getRefPoint().y) * coss + (ball2->getRefPoint().x - base->getRefPoint().x) * sinn + base->getRefPoint().y;


	low->setRefPoint(nlow);
	top->setRefPoint(ntop);
	ball1->setRefPoint(nball1);
	ball2->setRefPoint(nball2);
	base->rotate(AddONAngle);
	top->rotate(AddONAngle);
	low->rotate(AddONAngle);
	ball1->rotate(AddONAngle);
	ball2->rotate(AddONAngle);
	rotationcount++;
}
void rckt::draw() const
{
	ball1->draw();
	ball2->draw();
	low->draw();
	base->draw();
	top->draw();

;
}
void rckt::move(point dir)
{
	base->move(dir);
	top->move(dir);
	low->move(dir);
	ball1->move(dir);
	ball2->move(dir);
}
rckt::~rckt() {
	delete base;
	delete top;
	delete low;
	delete ball1;
	delete ball2;
}
int rckt::getType()
{
	return 10;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////