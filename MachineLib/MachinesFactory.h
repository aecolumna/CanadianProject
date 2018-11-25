#pragma once
#include <memory>

class CMachineActual;

class CMachinesFactory
{
public:
	CMachinesFactory();

	virtual ~CMachinesFactory();
	std::shared_ptr<CMachineActual> CreateMachine1();
	std::shared_ptr<CMachineActual> CreateMachine2();
	
};

