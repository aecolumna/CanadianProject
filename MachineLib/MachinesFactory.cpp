#include "stdafx.h"
#include "MachinesFactory.h"
#include "MachineActual.h"
#include <memory>
#include "Component.h"

using namespace std;
using namespace Gdiplus;

CMachinesFactory::CMachinesFactory()
{
}

CMachinesFactory::~CMachinesFactory()
{
}

/// Make machine of type 1 here!
std::shared_ptr<CMachineActual> CMachinesFactory::CreateMachine1()
{
	auto machine = make_shared<CMachineActual>();

	auto base = make_shared<CComponent>();
	int widthBase = 550, heightBase = 40, xBase = 230, yBase = 510;
	base->Rectangle(xBase, yBase, widthBase, heightBase);
	base->SetImage(L"images/base.png");
	machine->AddComponent(base);

	auto bluePost = make_shared<CComponent>();
	bluePost->SetColor(Color(25, 0, 144)); //blue
	int postHeight = 130;
	int postWidth = 25;
	bluePost->Rectangle(xBase + 60, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(bluePost);

	Color red = Color(178, 17, 23);

	auto redPost1 = make_shared<CComponent>();
	redPost1->SetColor(red); 
	int firstPostX = xBase + 180;
	redPost1->Rectangle(firstPostX, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(redPost1);


	int postSpacing = 70;
	auto redPost2 = make_shared<CComponent>();
	redPost2->SetColor(red);
	firstPostX += postSpacing;
	redPost2->Rectangle(firstPostX, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(redPost2);

	auto redPost3 = make_shared<CComponent>();
	redPost3->SetColor(red);
	firstPostX += postSpacing;
	redPost3->Rectangle(firstPostX, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(redPost3);

	auto redPost4 = make_shared<CComponent>();
	redPost4->SetColor(red);
	firstPostX += postSpacing;
	redPost4->Rectangle(firstPostX, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(redPost4);

	auto redPost5 = make_shared<CComponent>();
	redPost5->SetColor(red);
	firstPostX += postSpacing;
	redPost5->Rectangle(firstPostX, yBase - heightBase, postWidth, postHeight);
	machine->AddComponent(redPost5);

	auto pulley1 = make_shared<CComponent>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley1->Circle(40);
	pulley1->SetColor(Color(68, 114, 196));
	pulley1->SetImage(L"images/pulley.png");
	pulley1->SetCanMove(true);
	machine->AddComponent(pulley1);

	int littlePulleyRadius = 15;

	auto pulley1b = make_shared<CComponent>(xBase + 60 + (postWidth / 2), yBase - heightBase - postHeight);
	pulley1b->Circle(littlePulleyRadius);
	pulley1b->SetImage(L"images/pulley2.png");
	pulley1b->SetCanMove(true);
	machine->AddComponent(pulley1b);

	int machineFrameHeight = 70;
	int machineFrameWidth = 70;
	auto motorFrame = make_shared<CComponent>();
	motorFrame->Rectangle(xBase + 120 - postWidth, yBase - heightBase, machineFrameHeight, machineFrameWidth);
	motorFrame->SetImage(L"images/motor2.png");
	machine->AddComponent(motorFrame);

	auto motorRotor = make_shared<CComponent>(xBase + 120 - postWidth + machineFrameWidth/2, yBase - heightBase - machineFrameHeight/2);
	motorRotor->Circle(littlePulleyRadius);
	motorRotor->SetImage(L"images/pulley2.png");
	motorRotor->SetCanMove(true);
	machine->AddComponent(motorRotor);






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






