/**
 * \file Machine.h
 *
 * \author Charles Owen
 *
 * Class that represents a machine.
 *
 * You are not allowed to change this class in any way!
 */

#pragma once

#include <vector>
#include <memory>

class CMachineStandin;

/**
 * Class that represents a machine.
 *
 * This uses a standin class to provide a way to develop
 * the adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CMachine
{
public:
    /// Constructor
    CMachine();

    /// Destructor
    virtual ~CMachine() {}

    /// Copy constructor/disabled
    CMachine(const CMachine &) = delete;

    /// Assignment operator/disabled
    void operator=(const CMachine &) = delete;

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    virtual void SetLocation(int x, int y);

    /**
    * Draw the machine at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    virtual void DrawMachine(Gdiplus::Graphics *graphics);

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    virtual void SetMachineFrame(int frame);

	/**
	 * Set the expected frame rate in frames per second
	 * \param rate Frame rate in frames per second
	 */
	virtual void SetFrameRate(double rate);

    /**
    * Set  the bend angle
    * \param speed Speed from 0 to 1, where 1 is full speed
    */
    virtual void SetSpeed(double speed);

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine);

    /**
     * Get the current machine number
     * \return Machine number integer
     */
    virtual int GetMachineNumber();


private:
    /**
     * A stand-in machine class. 
     *
     * This draws simple stand-in graphics
     * so you can see where the machine will be and what its state
     * is. This makes it easy to develop code that uses the
     * machine before you have the machine working.
     *
     * And no, you may not change this to point to your
     * machine implementation!
     */
    std::shared_ptr<CMachineStandin> mStandin;
};

