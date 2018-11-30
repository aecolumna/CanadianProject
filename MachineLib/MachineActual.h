#pragma once

#include <vector>
#include <memory>


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

	void SetMotor(std::shared_ptr<CMotor> motor) { mMotor = motor; }
	std::shared_ptr<CMotor>& GetMotor() { return mMotor; }

private:
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
	double mSpeed = 1.0;
	CNewMachine* mNewMachine = nullptr;
	int mMachineNumber = 1;

	std::vector<std::shared_ptr<CComponent>> mComponents;
	std::vector<std::shared_ptr<CComponent>> mDependencies;
	std::shared_ptr<CMotor> mMotor;
	
	
	
};

