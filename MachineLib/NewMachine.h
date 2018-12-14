/**
 * \file NewMachine.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once

#include "Machine.h"
#include "WavPlayer.h"

// forward declaration
class CMachineActual;
class CMachineDlg;


/**
 * Represents a new machine
 */
class AFX_EXT_CLASS CNewMachine : public CMachine
{
public:
	CNewMachine();

	CNewMachine(const CNewMachine&) = delete;
	void operator=(const CNewMachine&) = delete;
	virtual ~CNewMachine();
	/**
	* Draw the machine at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawMachine(Gdiplus::Graphics *graphics) override;

	/// Setter/Getter for mMachineFrame
	virtual void SetMachineFrame(int frame) override;
	/**
	 * Get Machine frame
	 * \return integer
	 */
	int GetMachineFrame() const { return mMachineFrame; }

	/**
	 * Set seed
	 * \param speed Speed
	 */
	virtual void SetSpeed(double speed) { mSpeed = speed;  }
	/**
	 * Get Speed
	 * \return Double with speed
	 */
	virtual double GetSpeed() const { return mSpeed; }

	/// Setter/Getter for MachineNumber
	virtual void SetMachineNumber(int machine) override;
	/**
	 * Get Machine Number
	 * \return int machine number
	 */
	virtual int GetMachineNumber() override { return mMachineNumber; }



	/// Setter/Getter for mX, mY
	virtual void SetLocation(int x, int y) override; // declared in cpp file

	/**
	 * Get Location
	 * \return location
	 */
	Gdiplus::Point GetLocation() const { return mPos; }

	/**
	 * Set Frame Rate
	 * \param rate double with rate
	 */
	virtual void SetFrameRate(double rate) { mFrameRate = rate; }
	/**
	 * Get frame rate
	 * \return frame rate
	 */
	double GetFrameRate() const { return mFrameRate; }

	/**
	* Set the actual machine
	* \param machine The Machine
	*/
	void SetMachineActual(std::shared_ptr<CMachineActual> machine);

	/**
	 * GetMachine
	 * \return pointer to machine actual
	 */
	std::shared_ptr<CMachineActual> GetMachineActual() { return mMachine; }

	/**
	 * GetWav player
	 * \return wav player reference x newMachine pointer
	 */
	CWavPlayer* GetWavPlayer() { return &mWavPlayer; }

private:
	/// pointer to Machine
	std::shared_ptr<CMachineActual> mMachine;

	/// Machine Number aka Machine Type
	int mMachineNumber = 1;

	/// speed at which the motor turns
	double mSpeed = 1;

	/// the frameRate
	double mFrameRate = 1;

	/// X location of Machine
	int mX = 0;

	/// Y location of Machine
	int mY = 0;

	/// Position, mX, mY;
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);

	/// Current Frame
	int mMachineFrame = 0;

	/// Wavplayer
	CWavPlayer mWavPlayer;


};

