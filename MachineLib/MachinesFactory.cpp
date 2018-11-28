#include "stdafx.h"
#include "MachinesFactory.h"
#include "MachineActual.h"
#include <memory>
#include "Component.h"
#include <cmath>



using namespace std;
using namespace Gdiplus;

const double PI = 3.14159;

CMachinesFactory::CMachinesFactory()
{
}

CMachinesFactory::~CMachinesFactory()
{
}

const int widthBase = 550;
const int heightBase = 40;
const int xBase = 230;
const int yBase = 510;
const int postHeight = 110;
const int postWidth = 25;
const int barHeight = postHeight;
const int barY = yBase - heightBase - 160;
const int insidePulleyRadius = 30;
const int littlePulleyRadius = 15;
const int postSpacing = 70;
const int machineFrameHeight = 70;
const int machineFrameWidth = 70;

void CMachinesFactory::CreatePost(shared_ptr<CMachineActual>& machine, int x, Gdiplus::Color color)
{
	auto post = make_shared<CComponent>();
	post->SetColor(color); //blue
	post->Rectangle(x, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(post);
}



void CMachinesFactory::CreateBar(shared_ptr<CMachineActual>& machine, int x, std::wstring filename)
{
	auto bar = make_shared<CComponent>();
	
	bar->Rectangle(x, barY, postWidth, postHeight);
	bar->SetImage(filename);
	machine->AddComponent(bar);
}

// x2, y2 are points to the left
static double Distance(double x1, double y1, double x2, double y2)
{
	double deltaX = x2 - x1;
	double deltaY = y2 - y1;

	double intermediate = (deltaX * deltaX) + (deltaY * deltaY);

	return sqrt(intermediate);
}

static double Angle(double x1, double y1, double x2, double y2)
{
	double deltaX = x2 - x1;
	double deltaY = y2 - y1;

	double angleRad = atan2(deltaY, deltaX);
	
	return fabs(angleRad / (2.0 * PI));
}

/// Make machine of type 1 here!
std::shared_ptr<CMachineActual> CMachinesFactory::CreateMachine1()
{
	auto machine = make_shared<CMachineActual>();

	auto base = make_shared<CComponent>();
	base->Rectangle(xBase, yBase, widthBase, heightBase);
	base->SetImage(L"images/base.png");
	machine->AddComponent(base);

	CreatePost(machine, xBase + 60, Color::Blue);

	int firstPostX = xBase + 180;
	
	CreatePost(machine, firstPostX + postSpacing * 0);
	CreatePost(machine, firstPostX + postSpacing * 1);
	CreatePost(machine, firstPostX + postSpacing * 2);
	CreatePost(machine, firstPostX + postSpacing * 3);
	CreatePost(machine, firstPostX + postSpacing * 4);

	CreateBar(machine, firstPostX + postSpacing * 0, L"images/bar-cyan.png");
	CreateBar(machine, firstPostX + postSpacing * 1, L"images/bar-grn.png");
	CreateBar(machine, firstPostX + postSpacing * 2, L"images/bar-pur.png");
	CreateBar(machine, firstPostX + postSpacing * 3, L"images/bar-yel.png");
	CreateBar(machine, firstPostX + postSpacing * 4, L"images/bar-red.png");

	auto pulley1 = make_shared<CComponent>(firstPostX + (postWidth/2), yBase - heightBase - postHeight);
	pulley1->Circle(insidePulleyRadius);
	pulley1->SetImage(L"images/pulley.png");
	pulley1->SetCanMove(true);
	machine->AddComponent(pulley1);

	auto pulley2 = make_shared<CComponent>(firstPostX + postSpacing * 1 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley2->Circle(insidePulleyRadius);
	pulley2->SetImage(L"images/pulley.png");
	pulley2->SetCanMove(true);
	machine->AddComponent(pulley2);

	auto pulley3 = make_shared<CComponent>(firstPostX + postSpacing * 2 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley3->Circle(insidePulleyRadius);
	pulley3->SetImage(L"images/pulley.png");
	pulley3->SetCanMove(true);
	machine->AddComponent(pulley3);

	auto pulley4 = make_shared<CComponent>(firstPostX + postSpacing * 3 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley4->Circle(insidePulleyRadius);
	pulley4->SetImage(L"images/pulley.png");
	pulley4->SetCanMove(true);
	machine->AddComponent(pulley4);

	auto pulley5 = make_shared<CComponent>(firstPostX + postSpacing * 4 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley5->Circle(insidePulleyRadius);
	pulley5->SetImage(L"images/pulley.png");
	pulley5->SetCanMove(true);
	machine->AddComponent(pulley5);

	double midX = (xBase + 60 + (postWidth / 2) + xBase + 120 - postWidth + machineFrameWidth / 2) / 2.0;
	double midY = (yBase - heightBase - postHeight + yBase - heightBase - machineFrameHeight / 2) / 2.0;

	auto pulley0 = make_shared<CComponent>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley0->Circle(40);
	pulley0->SetColor(Color(68, 114, 196));
	pulley0->SetImage(L"images/pulley.png");
	pulley0->SetCanMove(true);
	machine->AddComponent(pulley0);

	


	int miniPulley0X = xBase + 60 + (postWidth / 2);
	int miniPulley0Y = yBase - heightBase - postHeight;
	auto miniPulley0 = make_shared<CComponent>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight);
	miniPulley0->Circle(littlePulleyRadius);
	miniPulley0->SetImage(L"images/pulley2.png");
	miniPulley0->SetCanMove(true);
	machine->AddComponent(miniPulley0);

	auto motorFrame = make_shared<CComponent>();
	motorFrame->Rectangle(xBase + 120 - postWidth, yBase - heightBase, machineFrameHeight, machineFrameWidth);
	motorFrame->SetImage(L"images/motor2.png");
	machine->AddComponent(motorFrame);


	int rotorX = xBase + 120 - postWidth + machineFrameWidth / 2;
	int rotorY = yBase - heightBase - machineFrameHeight / 2;

	auto motorRotor = make_shared<CComponent>(rotorX, rotorY);
	motorRotor->Circle(littlePulleyRadius);
	motorRotor->SetImage(L"images/pulley2.png");
	motorRotor->SetCanMove(true);
	machine->AddComponent(motorRotor);

	int midPointX = miniPulley0X + (rotorX - miniPulley0X) / 2;
	int midPointY = miniPulley0Y + (rotorY - miniPulley0Y) / 2;

	double distance = Distance(miniPulley0X, miniPulley0Y, rotorX, rotorY);
	double angle = Angle(miniPulley0X, miniPulley0Y, rotorX, rotorY);

	double offset = cos(PI / 4) * littlePulleyRadius;
	
	auto line = make_shared<CComponent>(rotorX - offset, rotorY + offset);
	
	// Rectangle(-size / 2, size / 2, size, size);
	line->Rectangle(0,0 , 2, distance);
	line->SetPhase(-angle );
	//line->SetCanMove(true);
	line->SetColor(Color::Black);
	machine->AddComponent(line);

	

	return machine;
}


/// Make machine of type 2 here!
std::shared_ptr<CMachineActual> CMachinesFactory::CreateMachine2()
{
	auto machine = make_shared<CMachineActual>();
	auto house = make_shared<CComponent>(490, 273);
	house->Circle(100);
	house->SetColor(Color(68, 114, 196));
	house->SetImage(L"images/electric-wheel.png");
	machine->AddComponent(house);
	return machine;
}






