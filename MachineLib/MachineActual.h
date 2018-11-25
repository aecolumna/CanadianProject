#pragma once
class CNewMachine;

class AFX_EXT_CLASS CMachineActual
{
public:
	CMachineActual();
	CMachineActual(int num);
	CMachineActual(const CMachineActual&) = delete;
	void operator=(const CMachineActual&) = delete;
	virtual ~CMachineActual();

	void DrawMachine(Gdiplus::Graphics * graphics);

	void SetNewMachine(CNewMachine* newMachine) { mNewMachine = newMachine; }
	CNewMachine* GetNewMachine() { return mNewMachine; }

	int GetMachineNumber() { return mMachineNumber; }
	void SetMachineNumber(int num) { mMachineNumber = num; }


private:
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
	double mSpeed = 1.0;
	CNewMachine* mNewMachine = nullptr;
	int mMachineNumber = 1;
	
};

