/**
 * \file MusicMachineFactory.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once

#include "ActorFactory.h"


/**
 * CMusicMachineFactory  machine that creates dynamic machine
 */
class CMusicMachineFactory : public CActorFactory
{
public:
	CMusicMachineFactory();
	virtual ~CMusicMachineFactory();

	std::shared_ptr<CActor> Create();
	std::shared_ptr<CActor> Create(int x);
};

