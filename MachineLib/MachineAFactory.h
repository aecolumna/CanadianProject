#pragma once
#include <memory>

class CMachineActual;

class CMachineAFactory
{
public:
	CMachineAFactory();

	virtual ~CMachineAFactory();
	std::shared_ptr<CMachineActual> CreateMachine1();
	std::shared_ptr<CMachineActual> CreateMachine2();
	
};

