#include "stdafx.h"
#include "MachineActual.h"
#include "NewMachine.h"
#include "Component.h"
#include <string>

using namespace std;
using namespace Gdiplus;

CMachineActual::CMachineActual()
{
	
}

CMachineActual::CMachineActual(int num)
{
	SetMachineNumber(num);
}


CMachineActual::~CMachineActual()
{
}

void CMachineActual::DrawMachine(Gdiplus::Graphics * graphics)
{


	double angle = GetNewMachine()->GetMachineFrame();
	for (auto comp : mComponents)
	{
		comp->Draw(graphics, angle);		
	}
}

void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
}




