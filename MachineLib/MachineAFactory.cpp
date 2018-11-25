#include "stdafx.h"
#include "MachineAFactory.h"
#include "MachineActual.h"
#include <memory>

using namespace std;

CMachineAFactory::CMachineAFactory()
{
}


CMachineAFactory::~CMachineAFactory()
{
}

/// Make machine of type 1 here!
std::shared_ptr<CMachineActual> CMachineAFactory::CreateMachine1()
{
	auto machine = make_shared<CMachineActual>();
	return machine;
}


/// Make machine of type 2 here!
std::shared_ptr<CMachineActual> CMachineAFactory::CreateMachine2()
{
	auto machine = make_shared<CMachineActual>();
	return machine;
}






