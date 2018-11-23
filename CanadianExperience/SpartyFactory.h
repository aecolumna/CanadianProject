/**
 * \file SpartyFactory.h
 *
 * \author Charles B. Owen
 *
 * \brief Factory that builds the Sparty actor.
 */

#pragma once
#include "ActorFactory.h"


/**
 * \brief Factory that builds the Sparty actor.
 */
class CSpartyFactory :
    public CActorFactory
{
public:
    CSpartyFactory();
    virtual ~CSpartyFactory();

    std::shared_ptr<CActor> Create();

};

