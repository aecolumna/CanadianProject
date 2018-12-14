/**
 * \file MachineActual.cpp
 *
 * \author Andres Columna
 */



#include "stdafx.h"
#include "MachineActual.h"
#include "NewMachine.h"
#include "Component.h"
#include <string>
#include "Motor.h"
#include "WavPlayer.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CMachineActual::CMachineActual()
{
	
}



/**
 * Constructor
 * \param num number of machine
 */
CMachineActual::CMachineActual(int num)
{
	SetMachineNumber(num);
}


/**
 * Destructor
 */
CMachineActual::~CMachineActual()
{
}


/**
 * Draw the machine
 * \param graphics objects in which we draw
 */
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


/**
 * Add Component
 * \param component 
 */
void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
}


/**
 * Show dialog box
 */
void CMachineActual::ShowDialogBox()
{

}




