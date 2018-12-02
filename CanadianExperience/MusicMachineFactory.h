#pragma once

#include "ActorFactory.h"

class CMusicMachineFactory : public CActorFactory
{
public:
	CMusicMachineFactory();
	virtual ~CMusicMachineFactory();

	std::shared_ptr<CActor> Create();
	std::shared_ptr<CActor> Create(int x);
};

