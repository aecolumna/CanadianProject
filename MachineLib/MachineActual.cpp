#include "stdafx.h"
#include "MachineActual.h"
#include "NewMachine.h"
#include "Component.h"
#include <string>
#include "Motor.h"
#include "WavPlayer.h"

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
	mFrame = GetNewMachine()->GetMachineFrame();
	double angle = GetNewMachine()->GetMachineFrame() * .2;

	angle *= GetNewMachine()->GetSpeed();

	auto DependencyVectorSize = mDependencies.size();


	for (auto comp : mDependencies)
	{
		comp->UpdateRotation(angle);
			
	}

	for (auto comp : mComponents)
	{
		comp->Draw(graphics);
	}
}

void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
}

void CMachineActual::ShowDialogBox()
{

}




