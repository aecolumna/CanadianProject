/**
 * \file ActorFactory.h
 *
 * \author Charles B. Owen
 *
 * \brief Abstract base class for actor factories.
 */

#pragma once

#include <memory>
#include "Actor.h"

/** 
 * \brief Abstract base class for actor factories. 
 */
class CActorFactory
{
public:
    virtual ~CActorFactory();

    /** \brief Create the actor 
     * \returns New actor object */
    virtual std::shared_ptr<CActor> Create() = 0;

protected:
    CActorFactory();
};

