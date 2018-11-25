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
 * Create a NewMachine object
 * Then calls factory that calls 
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachine> CMachineFactory::CreateMachine()
{
    auto machine = make_shared<CNewMachine>();

	CMachinesFactory factory;
	auto machineActual = factory.CreateMachine1(); // by default, we create machine1
	
	machine->SetMachineActual(machineActual);
	machineActual->SetNewMachine(machine.get()); 
	
	return machine;
}

