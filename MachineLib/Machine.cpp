/**
 * \file Machine.cpp
 *
 * \author Charles Owen
 *
 * You are not allowed to change this class in any way!
 *
 * This is a simple adapter class that routes all of the 
 * operations to the class CMachineStandin, which is a standin
 * for an actual machine in the system.
 */

#include "stdafx.h"
#include "Machine.h"
#include "MachineStandin.h"

using namespace Gdiplus;
using namespace std;


CMachine::CMachine() 
{
    mStandin = make_shared<CMachineStandin>();
}

void CMachine::SetLocation(int x, int y)
{
    mStandin->SetLocation(x, y);
}

void CMachine::DrawMachine(Gdiplus::Graphics *graphics)
{
    mStandin->DrawMachine(graphics);
}


void CMachine::SetMachineFrame(int frame) 
{
    mStandin->SetMachineFrame(frame);
}


void CMachine::SetSpeed(double speed) 
{
    mStandin->SetSpeed(speed);
}

void CMachine::SetFrameRate(double rate)
{

}


void CMachine::SetMachineNumber(int seed) 
{
    mStandin->SetMachine(seed);
}

int CMachine::GetMachineNumber()
{
    return mStandin->GetMachine();
}
