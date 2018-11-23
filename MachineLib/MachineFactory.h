/**
 * \file MachineFactory.h
 *
 * \author Charles Owen
 *
 * Machine factory class. Creates Machine objects
 */

#pragma once

#include <memory>

class CMachine;


/**
 * Machine factory class. Creates Machine objects
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CMachineFactory
{
public:
    CMachineFactory();
    ~CMachineFactory();

    std::shared_ptr<CMachine> CreateMachine();
};

