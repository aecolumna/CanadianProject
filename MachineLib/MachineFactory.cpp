/**
 * \file MachineFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "stdafx.h"
#include "MachineFactory.h"
#include "Machine.h"
#include "NewMachine.h"
#include "MachineDlg.h"
#include "MachinesFactory.h"
#include "MachineActual.h"


using namespace std;

/**
 * Constructor
 */
CMachineFactory::CMachineFactory()
{
}


/**
 * Destructor
 */
CMachineFactory::~CMachineFactory()
{
}


/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachine> CMachineFactory::CreateMachine()
{
    auto machine = make_shared<CNewMachine>();
	CMachineDlg dlg(machine);
	if(dlg.DoModal() == IDOK){} // Sets Machine Number

	int machineNumber = machine->GetMachineNumber();
	CMachinesFactory factory;

	std::shared_ptr<CMachineActual> machineActual;
	
	// place Factory for different machine here!
	if ( machineNumber == 1 || machineNumber != 2)
	{
		machineActual = factory.CreateMachine1();
	}
	else if (machineNumber == 2)
	{
		machineActual = factory.CreateMachine2();
	}

	machine->SetMachineActual(machineActual);
	machineActual->SetNewMachine(machine.get()); 
	
	return machine;
}

