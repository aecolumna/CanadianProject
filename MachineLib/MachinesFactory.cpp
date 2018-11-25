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

	auto house = make_shared<CComponent>(490, 273);
	house->Circle(100);
	house->SetColor(Color(68, 114, 196));
	house->SetImage(L"images/pulley.png");
	machine->AddComponent(house);
	return machine;
}


/// Make machine of type 2 here!
std::shared_ptr<CMachineActual> CMachinesFactory::CreateMachine2()
{
	auto machine = make_shared<CMachineActual>();
	return machine;
}






