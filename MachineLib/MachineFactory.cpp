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
    return make_shared<CMachine>();
}

