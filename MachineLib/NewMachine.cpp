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

	const int LineSize = 16;
	const int LineSpacing = 25;

	Pen pen(Color(139, 69, 19), (REAL)2);
	const int StandinWidth = 700;
	const int StandinHeight = 400;

	//graphics->DrawRectangle(&pen, (REAL)(mX - StandinWidth / 2), (REAL)(mY - StandinHeight), (REAL)(StandinWidth), (REAL)(StandinHeight));

	const int OuterRadius = 90;
	const int InnerRadius = 80;
	const int NumTeeth = 20;

	const int GearX = 0;
	const int GearY = -StandinHeight / 2;

	Pen pen2(Color::Green, 2);

	int x = mX + GearX;
	int y = mY + GearY;

	//for (int i = 0; i < NumTeeth; i++)
	//{
	//	double angle1 = i * 2 * M_PI / NumTeeth;
	//	double angle2 = (i + 0.5) * 2 * M_PI / NumTeeth;
	//	double angle3 = (i + 1.0) * 2 * M_PI / NumTeeth;

	//	graphics->DrawLine(&pen2, (REAL)(x + OuterRadius * cos(angle1)), (REAL)(y + OuterRadius * sin(angle1)),
	//		(REAL)(x + OuterRadius * cos(angle2)), (REAL)(y + OuterRadius * sin(angle2)));
	//	graphics->DrawLine(&pen2, (REAL)(x + OuterRadius * cos(angle2)), (REAL)(y + OuterRadius * sin(angle2)),
	//		(REAL)(x + InnerRadius * cos(angle2)), (REAL)(y + InnerRadius * sin(angle2)));
	//	graphics->DrawLine(&pen2, (REAL)(x + InnerRadius * cos(angle2)), (REAL)(y + InnerRadius * sin(angle2)),
	//		(REAL)(x + InnerRadius * cos(angle3)), (REAL)(y + InnerRadius * sin(angle3)));
	//	graphics->DrawLine(&pen2, (REAL)(x + InnerRadius * cos(angle3)), (REAL)(y + InnerRadius * sin(angle3)),
	//		(REAL)(x + OuterRadius * cos(angle3)), (REAL)(y + OuterRadius * sin(angle3)));

	//}


	y = mY - LineSize * 3;
	//CenteredString(graphics, L"This is Andres' New Machine!", mX, y, LineSize);
	y -= LineSpacing;

	{
		wstringstream str;
		//str << L"Machine: " << mMachine << ends;
		//CenteredString(graphics, str.str(), mX, y, LineSize);
		y -= LineSpacing;
	}

	{
		wstringstream str;
		str << L"Frame: " << mMachineFrame << ends;
		CenteredString(graphics, str.str(), mX, y, LineSize);
		y -= LineSpacing;
	}


	{
		wstringstream str;
		str << L"Speed: " << mSpeed;
		CenteredString(graphics, str.str(), mX, y, LineSize);
		y -= LineSpacing;
	}

}


void CNewMachine::SetMachineNumber(int machine)
{
	if (machine == mMachineNumber) 
		return;
		
	mMachineNumber = machine;

	CMachinesFactory factory;

	std::shared_ptr<CMachineActual> machineActual;

	if (mMachineNumber == 1 || mMachineNumber != 2)
		machineActual = factory.CreateMachine1();
		
	else if (mMachineNumber == 2)
		machineActual = factory.CreateMachine2();
		

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
}

void CNewMachine::SetMachineActual(std::shared_ptr<CMachineActual> machine)
{
	mMachine = machine;
}
