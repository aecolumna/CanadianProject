/**
 * \file MachineStandin.cpp
 *
 * \author Charles Owen
 *
 * This file may not be changed.
 */

#include "stdafx.h"
#include "MachineStandin.h"
#include <sstream>

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 */
CMachineStandin::CMachineStandin()
{
}


/**
 * Destructor
 */
CMachineStandin::~CMachineStandin()
{
}


/**
* Draw the machine at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CMachineStandin::DrawMachine(Gdiplus::Graphics *graphics)
{
    const int LineSize = 16;
    const int LineSpacing = 25;

    Pen pen(Color(139, 69, 19), (REAL)2);
	const int StandinWidth = 300;
	const int StandinHeight = 200;

	graphics->DrawRectangle(&pen, (REAL)(mX - StandinWidth/2), (REAL)(mY - StandinHeight), (REAL)(StandinWidth), (REAL)(StandinHeight));

	const int OuterRadius = 90;
	const int InnerRadius = 80;
	const int NumTeeth = 20;

	const int GearX = 0;
	const int GearY = -StandinHeight / 2;

	Pen pen2(Color::Green, 2);

	int x = mX + GearX;
	int y = mY + GearY;

	for (int i = 0; i < NumTeeth; i++) 
	{
		double angle1 = i * 2 * M_PI / NumTeeth;
		double angle2 = (i + 0.5) * 2 * M_PI / NumTeeth;
		double angle3 = (i + 1.0) * 2 * M_PI / NumTeeth;

		graphics->DrawLine(&pen2, (REAL)(x + OuterRadius * cos(angle1)), (REAL)(y + OuterRadius * sin(angle1)),
			(REAL)(x + OuterRadius * cos(angle2)), (REAL)(y + OuterRadius * sin(angle2)));
		graphics->DrawLine(&pen2, (REAL)(x + OuterRadius * cos(angle2)), (REAL)(y + OuterRadius * sin(angle2)),
			(REAL)(x + InnerRadius * cos(angle2)), (REAL)(y + InnerRadius * sin(angle2)));
		graphics->DrawLine(&pen2, (REAL)(x + InnerRadius * cos(angle2)), (REAL)(y + InnerRadius * sin(angle2)),
			(REAL)(x + InnerRadius * cos(angle3)), (REAL)(y + InnerRadius * sin(angle3)));
		graphics->DrawLine(&pen2, (REAL)(x + InnerRadius * cos(angle3)), (REAL)(y + InnerRadius * sin(angle3)),
			(REAL)(x + OuterRadius * cos(angle3)), (REAL)(y + OuterRadius * sin(angle3)));

	}


    y = mY - LineSize * 3;
    CenteredString(graphics, L"Machine go here!", mX, y, LineSize);
    y -= LineSpacing;

    {
        wstringstream str;
        str << L"Machine: " << mMachine << ends;
        CenteredString(graphics, str.str(), mX, y, LineSize);
        y -= LineSpacing;
    }

    {
        wstringstream str;
        str << L"Frame: " << mFrame << ends;
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


/**
 * Draw a centered string
 *
 * \param graphics Graphics object
 * \param str String to draw
 * \param x X location of bottom center of string
 * \param y Y location of bottom center of string
 * \param dy String height
 */
void CMachineStandin::CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy)
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