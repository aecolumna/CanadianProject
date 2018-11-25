#include "stdafx.h"
#include "MachineActual.h"
#include "NewMachine.h"
#include <string>

using namespace std;
using namespace Gdiplus;

CMachineActual::CMachineActual()
{
	
}

CMachineActual::CMachineActual(int num)
{
	SetMachineNumber(num);
}


CMachineActual::~CMachineActual()
{
}

void CMachineActual::DrawMachine(Gdiplus::Graphics * graphics)
{
}



