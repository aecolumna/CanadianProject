#include "stdafx.h"
#include "MusicMachineFactory.h"
#include "MachineDrawable.h"

using namespace std;
using namespace Gdiplus;

CMusicMachineFactory::CMusicMachineFactory()
{
}


CMusicMachineFactory::~CMusicMachineFactory()
{
}

std::shared_ptr<CActor> CMusicMachineFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Machine1");

	auto machine = make_shared<CMachineDrawable>();

	machine->SetPosition(Point(50, 100));
	
	actor->AddDrawable(machine);

	return actor;
}

std::shared_ptr<CActor> CMusicMachineFactory::Create(int x)
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Machine2");

	auto machine = make_shared<CMachineDrawable>(x);

	machine->SetPosition(Point(200, 50));

	actor->AddDrawable(machine);

	return actor;
}
