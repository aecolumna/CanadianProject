/**
 * \file NewMachine.cpp
 *
 * \author Andres Columna
 */


#include "stdafx.h"
#include "NewMachine.h"
#include "MachineActual.h"
#include "MachineDlg.h"
#include "MachinesFactory.h"


#include <string>
#include <sstream>
#include "Polygon.h"
#include "Component.h"


using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CNewMachine::CNewMachine()
{
	SetMachineNumber(1);
}


/**
 * Destructor
 */
CNewMachine::~CNewMachine()
{
}


/**
* Draw the machine at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CNewMachine::DrawMachine(Gdiplus::Graphics * graphics)
{
	
	// call individual draw on every single component
	mMachine->DrawMachine(graphics);

}


/**
 * Set machine frame
 * \param frame 
 */
void CNewMachine::SetMachineFrame(int frame)
{
	mMachineFrame = frame; 
}


/**
 * SetMachineNumber
 * \param machine Number
 */
void CNewMachine::SetMachineNumber(int machine)
{
	if (machine == mMachineNumber) 
		return;
		
	mMachineNumber = machine;

	CMachinesFactory factory;

	std::shared_ptr<CMachineActual> machineActual;

	if (mMachineNumber == 1 || mMachineNumber != 2)
		machineActual = factory.CreateMachine1(this);
		
	else if (mMachineNumber == 2)
		machineActual = factory.CreateMachine2(this);
		

	SetMachineActual(machineActual);
	machineActual->SetNewMachine(this);

}



/**
 * Set location of our machine
 * \param x 
 * \param y 
 */
void CNewMachine::SetLocation(int x, int y)
{
	mX = x;
	mY = y;
	mPos = Gdiplus::Point(x, y);
	if (mMachine)
	{
		mMachine->SetLocation(x, y);
	}
}


/**
 * Set machine actual of our machine
 * \param machine 
 */
void CNewMachine::SetMachineActual(std::shared_ptr<CMachineActual> machine)
{
	mMachine = machine;
}
