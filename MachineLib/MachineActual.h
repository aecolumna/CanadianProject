/**
 * \file MachineActual.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once

#include <vector>
#include <memory>
#include "WavPlayer.h"
#include "NewMachine.h"

class CNewMachine;
class CComponent;
class CMotor;


/**
 * Machine actual
 */
class AFX_EXT_CLASS CMachineActual
{
public:
	CMachineActual();
	CMachineActual(int num);
	CMachineActual(const CMachineActual&) = delete;
	void operator=(const CMachineActual&) = delete;
	virtual ~CMachineActual();

	void DrawMachine(Gdiplus::Graphics * graphics);

	/**
	 * Set new machine
	 * \param newMachine newMachine pointer
	 */
	void SetNewMachine(CNewMachine* newMachine) { mNewMachine = newMachine; }
	/**
	 * Get new machine
	 * \return newMachine
	 */
	CNewMachine* GetNewMachine() { return mNewMachine; }

	/**
	 * Set machine
	 * \return machine number
	 */
	int GetMachineNumber() { return mMachineNumber; }
	/**
	 * Set new machine number
	 * \param num newMachine number
	 */
	void SetMachineNumber(int num) { mMachineNumber = num; }

	void AddComponent(std::shared_ptr<CComponent> component);
	/**
	 * Add Dependency
	 * \param component component to be added
	 */
	void AddDependency(std::shared_ptr<CComponent> component) { mDependencies.push_back(component); }

	/**
	 * Get wav plater
	 * \return Pointer to wav player
	 */
	CWavPlayer* GetWavPlayer() { return mNewMachine->GetWavPlayer(); }

	/**
	 * Set speed
	 * \param speed Speed of the machine
	 */
	void SetSpeed(double speed) { mSpeed = speed;  }

	void ShowDialogBox();

	/**
	 * Set location
	 * \param x newMachine pointer
	 * \param y location y
	 */
	void SetLocation(int x, int y) { mX = x; mY = y; }

	/**
	 * Set frame rate
	 * \param rate rate of the frames!
	 */
	void SetFrameRate(double rate) { mFrameRate = rate; }

private:
	/// X position of machine
	int mX = 0;
	/// Y position of machine
	int mY = 0;
	/// Positino of machine in Gdi Point object
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	/// speed of machine
	double mSpeed = 1.0;
	/// Pointer to new machine that owns this actual machine
	CNewMachine* mNewMachine = nullptr;
	/// machine number
	int mMachineNumber = 1;
	/// frame rate of our project
	double mFrameRate = 1;
	/// frame we are currently at.
	int mFrame = 0;

	/// Components of machine
	std::vector<std::shared_ptr<CComponent>> mComponents;
	/// dependencies of machine
	std::vector<std::shared_ptr<CComponent>> mDependencies;
	
	
};

