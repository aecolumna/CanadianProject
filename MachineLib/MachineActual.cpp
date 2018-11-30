#include "stdafx.h"
#include "MachineActual.h"
#include "NewMachine.h"
#include "Component.h"
#include <string>
#include "Motor.h"

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


	double angle = GetNewMachine()->GetMachineFrame() * .2;

	angle *= GetNewMachine()->GetSpeed();

	auto DependencyVectorSize = mDependencies.size();

	// Fix since last element doesnt have its sink set!
	//for (int i = 0; i < DependencyVectorSize - 1; i++)
	//{
	//	mDependencies[i]->UpdateRotation(angle);
	//}
	for (auto comp : mDependencies)
	{
		comp->UpdateRotation(angle);
			
	}

	for (auto comp : mComponents)
	{
		comp->Draw(graphics, angle);
	}
}

void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
}




