#include "stdafx.h"
#include "NewMachine.h"
#include "MachineActual.h"
#include "MachineDlg.h"
#include "MachinesFactory.h"
#include <string>
#include <sstream>
#include "Polygon.h"
#include "Component.h"


using namespace std;
using namespace Gdiplus;

CNewMachine::CNewMachine()
{
	SetMachineNumber(1);
}


CNewMachine::~CNewMachine()
{
}


/**
* Draw the machine at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CNewMachine::DrawMachine(Gdiplus::Graphics * graphics)
{
	
	// call individual draw on every single component
	mMachine->DrawMachine(graphics);

}

void CNewMachine::SetMachineFrame(int frame)
{
	mMachineFrame = frame; 
}


void CNewMachine::SetMachineNumber(int machine)
{
	if (machine == mMachineNumber) 
		return;
		
	mMachineNumber = machine;

	CMachinesFactory factory;

	std::shared_ptr<CMachineActual> machineActual;

	if (mMachineNumber == 1 || mMachineNumber != 2)
		machineActual = factory.CreateMachine1(this);
		
	else if (mMachineNumber == 2)
		machineActual = factory.CreateMachine2(this);
		

	SetMachineActual(machineActual);
	machineActual->SetNewMachine(this);

}

/**
 * Draw a centered string
 *
 * \param graphics Graphics object
 * \param str String to draw
 * \param x X location of bottom center of string
 * \param y Y location of bottom center of string
 * \param dy String height
 */
void CNewMachine::CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy)
{
	y -= dy;

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, (REAL)dy);

	SolidBrush black(Color(0, 0, 0));
	RectF rect;
	graphics->MeasureString(str.c_str(), -1, &font, PointF((REAL)x, (REAL)y), &rect);
	graphics->DrawString(str.c_str(),  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF((REAL)(x - rect.Width / 2), (REAL)y),   // Where to draw (top left corner)
		&black);    // The brush to draw the text with
}

void CNewMachine::SetLocation(int x, int y)
{
	mX = x;
	mY = y;
	mPos = Gdiplus::Point(x, y);
	if (mMachine)
	{
		mMachine->SetLocation(x, y);
	}
}

void CNewMachine::SetMachineActual(std::shared_ptr<CMachineActual> machine)
{
	mMachine = machine;
}
