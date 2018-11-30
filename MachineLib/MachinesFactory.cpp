#include "stdafx.h"
#include "MachinesFactory.h"
#include "MachineActual.h"
#include <memory>
#include "Component.h"
#include <cmath>
#include "Motor.h"
#include "Pulley.h"
#include "Shape.h"
#include "Cam.h"
#include "Roller.h"

using namespace std;
using namespace Gdiplus;

const double PI = 3.14159;

CMachinesFactory::CMachinesFactory()
{
}

CMachinesFactory::~CMachinesFactory()
{
}

// Constants
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
const int rotorX = xBase + 120 - postWidth + machineFrameWidth / 2;
const int rotorY = yBase - heightBase - machineFrameHeight / 2;
const int firstPostX = xBase + 180;
const int miniPulley0X = xBase + 60 + (postWidth / 2);
const int miniPulley0Y = yBase - heightBase - postHeight;
const int miniPulley1X = xBase + 60 + (postWidth / 2);
const int miniPulley1Y = yBase - heightBase - postHeight;

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

std::shared_ptr<CPulley> CMachinesFactory::CreatePulley(std::shared_ptr<CMachineActual>& machine, int x)
{
	auto pulley = make_shared<CPulley>(x, yBase - heightBase - postHeight, insidePulleyRadius);
	machine->AddComponent(pulley);
	return pulley;

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
	// Create Machine
	auto machine = make_shared<CMachineActual>();

	// Create Posts
	CreatePost(machine, xBase + 60, Color::Blue);
	CreatePost(machine, firstPostX + postSpacing * 0);
	CreatePost(machine, firstPostX + postSpacing * 1);
	CreatePost(machine, firstPostX + postSpacing * 2);
	CreatePost(machine, firstPostX + postSpacing * 3);
	CreatePost(machine, firstPostX + postSpacing * 4);

	// Create Motor Frame
	auto motorFrame = make_shared<CComponent>();
	motorFrame->Rectangle(xBase + 120 - postWidth, yBase - heightBase,
		machineFrameHeight, machineFrameWidth);
	motorFrame->SetImage(L"images/motor2.png");

	// Create Belts
	double distance = Distance(miniPulley0X, miniPulley0Y, rotorX, rotorY);
	double angle = Angle(miniPulley0X, miniPulley0Y, rotorX, rotorY);

	double offset = cos(PI / 4) * littlePulleyRadius;

	auto belt1 = make_shared<CComponent>(rotorX - offset, rotorY + offset);
	belt1->Rectangle(0, 0, 2, (int)distance);
	belt1->SetPhase(-angle);

	auto belt2 = make_shared<CComponent>(rotorX + offset, rotorY - offset);
	belt2->Rectangle(0, 0, 2, (int)distance);
	belt2->SetPhase(-angle / 2);
	
	distance = 4 * postSpacing + 3;
	auto belt3 = make_shared<CComponent>(firstPostX + postSpacing * 0 + insidePulleyRadius/2, yBase - heightBase - postHeight + insidePulleyRadius);
	belt3->Rectangle(0, 0, distance, 2);
	
	auto belt4 = make_shared<CComponent>(firstPostX + postSpacing * 0 + insidePulleyRadius / 2, yBase - heightBase - postHeight - insidePulleyRadius + 3);
	belt4->Rectangle(0, 0, distance, 2);


	//// End of Belts

	auto base = make_shared<CComponent>();
	base->Rectangle(xBase, yBase, widthBase, heightBase);
	base->SetImage(L"images/base.png");
	
	CreateBar(machine, firstPostX + postSpacing * 0, L"images/bar-cyan.png"); // first red bar
	CreateBar(machine, firstPostX + postSpacing * 1, L"images/bar-grn.png");
	CreateBar(machine, firstPostX + postSpacing * 2, L"images/bar-pur.png");
	CreateBar(machine, firstPostX + postSpacing * 3, L"images/bar-yel.png");
	CreateBar(machine, firstPostX + postSpacing * 4, L"images/bar-red.png");

	int pulleyY = yBase - heightBase - postHeight;
	int pulleyX = firstPostX + (postWidth / 2);

	shared_ptr<CPulley> pulley3 = make_shared<CPulley>(pulleyX , pulleyY, insidePulleyRadius);
	shared_ptr<CPulley> pulley4 = make_shared<CPulley>(pulleyX + postSpacing * 1 , pulleyY, insidePulleyRadius);
	shared_ptr<CPulley> pulley5 = make_shared<CPulley>(pulleyX + postSpacing * 2, pulleyY, insidePulleyRadius);
	shared_ptr<CPulley> pulley6 = make_shared<CPulley>(pulleyX + postSpacing * 3, pulleyY, insidePulleyRadius);
	shared_ptr<CPulley> pulley7 = make_shared<CPulley>(pulleyX + postSpacing * 4, pulleyY, insidePulleyRadius);
	
	int distanceBelt = firstPostX - (xBase + 60);

	auto belt5 = make_shared<CComponent>(miniPulley1X, miniPulley1Y - littlePulleyRadius + 2);
	belt5->Rectangle(0, 0, distanceBelt, 2);
	belt5->SetPhase(-.02);
	
	auto belt6 = make_shared<CComponent>(miniPulley1X, miniPulley1Y + littlePulleyRadius - 2);
	belt6->Rectangle(0, 0, distanceBelt, 2);
	belt6->SetPhase(0.02);
	

	auto miniPulley0 = make_shared<CPulley>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight, littlePulleyRadius);

	auto motorRotor = make_shared<CMotor>(rotorX, rotorY, littlePulleyRadius);
	motorRotor->GetSource()->SetSink(miniPulley0->GetSink());

	auto pulley0 = make_shared<CPulley>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight, 40);

	auto flag = make_shared<CShape>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight);
	int size = 150;
	flag->Rectangle(-size / 2, size / 2, size, size + 20);
	flag->SetImage(L"images/flag22.png");
	flag->SetCanMove(true);
	flag->SetRadius(littlePulleyRadius);

	auto cam1 = make_shared<CCam>(pulleyX, pulleyY);
	auto cam2 = make_shared<CCam>(pulleyX + postSpacing * 1, pulleyY);
	auto cam3 = make_shared<CCam>(pulleyX + postSpacing * 2, pulleyY);
	auto cam4 = make_shared<CCam>(pulleyX + postSpacing * 3, pulleyY);
	auto cam5 = make_shared<CCam>(pulleyX + postSpacing * 4, pulleyY);

	auto roller1 = make_shared<CRoller>(pulleyX, pulleyY - insidePulleyRadius + 10);
	auto roller2 = make_shared<CRoller>(pulleyX + postSpacing * 1, pulleyY - insidePulleyRadius + 10);
	auto roller3 = make_shared<CRoller>(pulleyX + postSpacing * 2, pulleyY - insidePulleyRadius + 10);
	auto roller4 = make_shared<CRoller>(pulleyX + postSpacing * 3, pulleyY - insidePulleyRadius + 10);
	auto roller5 = make_shared<CRoller>(pulleyX + postSpacing * 4, pulleyY - insidePulleyRadius + 10);

	// set up dependencies
	motorRotor->GetSource()->SetSink(pulley0->GetSink());
	pulley0->GetSource()->AddSink(miniPulley0->GetSink());
	miniPulley0->GetSource()->AddSink(pulley3->GetSink());
	miniPulley0->GetSource()->AddSink(pulley4->GetSink());
	miniPulley0->GetSource()->AddSink(pulley5->GetSink());
	miniPulley0->GetSource()->AddSink(pulley6->GetSink());
	miniPulley0->GetSource()->AddSink(pulley7->GetSink());
	miniPulley0->GetSource()->AddSink(flag->GetSink());
	pulley3->GetSource()->AddSink(cam1->GetSink());
	pulley4->GetSource()->AddSink(cam2->GetSink());
	pulley5->GetSource()->AddSink(cam3->GetSink());
	pulley6->GetSource()->AddSink(cam4->GetSink());
	pulley7->GetSource()->AddSink(cam5->GetSink());
	cam1->GetSource()->AddSink(roller1->GetSink());
	cam2->GetSource()->AddSink(roller2->GetSink());
	cam3->GetSource()->AddSink(roller3->GetSink());
	cam4->GetSource()->AddSink(roller4->GetSink());
	cam5->GetSource()->AddSink(roller5->GetSink());

	// The order in which they update sink from source
	machine->AddDependency(motorRotor);
	machine->AddDependency(miniPulley0);
	machine->AddDependency(pulley0);
	machine->AddDependency(pulley3);
	machine->AddDependency(pulley4);
	machine->AddDependency(pulley5);
	machine->AddDependency(pulley6);
	machine->AddDependency(pulley7);
	machine->AddDependency(flag);
	machine->AddDependency(cam1);
	machine->AddDependency(cam2);
	machine->AddDependency(cam3);
	machine->AddDependency(cam4);
	machine->AddDependency(cam5);
	machine->AddDependency(roller1);
	machine->AddDependency(roller2);
	machine->AddDependency(roller3);
	machine->AddDependency(roller4);
	machine->AddDependency(roller5);

	
	// Order in which Components are drawn
	machine->AddComponent(motorFrame);
	machine->AddComponent(belt1);
	machine->AddComponent(belt2);
	machine->AddComponent(motorRotor);
	machine->AddComponent(base);
	machine->AddComponent(flag);
	machine->AddComponent(pulley0);
	machine->AddComponent(belt3);
	machine->AddComponent(belt4);
	machine->AddComponent(belt5);
	machine->AddComponent(belt6);
	machine->AddComponent(miniPulley0);
	machine->AddComponent(pulley3);
	machine->AddComponent(pulley4);
	machine->AddComponent(pulley5);
	machine->AddComponent(pulley6);
	machine->AddComponent(pulley7);
	machine->AddComponent(cam1);
	machine->AddComponent(cam2);
	machine->AddComponent(cam3);
	machine->AddComponent(cam4);
	machine->AddComponent(cam5);
	machine->AddComponent(roller1);
	machine->AddComponent(roller2);
	machine->AddComponent(roller3);
	machine->AddComponent(roller4);
	machine->AddComponent(roller5);


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






