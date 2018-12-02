#pragma once

#include <vector>
#include <memory>
#include "WavPlayer.h"
#include "NewMachine.h"

class CNewMachine;
class CComponent;
class CMotor;

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

	void AddComponent(std::shared_ptr<CComponent> component);
	void AddDependency(std::shared_ptr<CComponent> component) { mDependencies.push_back(component); }


	CWavPlayer* GetWavPlayer() { return mNewMachine->GetWavPlayer(); }

	void SetSpeed(double speed) { mSpeed = speed;  }

	void ShowDialogBox();

	void SetLocation(int x, int y) { mX = x; mY = y; }

	void SetFrameRate(double rate) { mFrameRate = rate; }

private:
	int mX = 0;
	int mY = 0;
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	double mSpeed = 1.0;
	CNewMachine* mNewMachine = nullptr;
	int mMachineNumber = 1;
	double mFrameRate = 1;
	int mFrame = 0;

	std::vector<std::shared_ptr<CComponent>> mComponents;
	std::vector<std::shared_ptr<CComponent>> mDependencies;
	
	
};

