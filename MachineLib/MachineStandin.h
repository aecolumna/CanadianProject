/**
 * \file MachineStandin.h
 *
 * \author Charles Owen
 *
 * This class is a stand-in class that will allow you to
 * develop the machine adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */

#pragma once

#include <vector>
#include <memory>


/**
 * This class is a stand-in class that will allow you to
 * develop the machine adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */
class CMachineStandin
{
public:
    CMachineStandin();
    virtual ~CMachineStandin();

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    void SetLocation(int x, int y) { mX = x; mY = y; }

    void DrawMachine(Gdiplus::Graphics *graphics);

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    void SetMachineFrame(int frame) { mFrame = frame; }

    /**
    * Set  the speed
    * \param speed of the machine from 0 to 1
    */
    void SetSpeed(double speed) { mSpeed = speed; }

    /**
    * Set the machine number
    * \param machine An integer number. Each integer makes a different machine
    */
    void SetMachine(int machine) { mMachine = machine; }

    /**
    * Get the current machine number
    * \return Machine number
    */
    virtual int GetMachine() { return mMachine; }

private:
    void CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy);

    int mX = 0;     ///< Machine X location
    int mY = 0;     ///< Machine Y location
    int mFrame = 0; ///< Current frame
    double mSpeed = 0;  ///< Bend angle
    int mMachine = 1;  ///< Machine number
};

