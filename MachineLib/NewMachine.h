#pragma once

#include "Machine.h"
#include "WavPlayer.h"

// forward declaration
class CMachineActual;
class CMachineDlg;


class AFX_EXT_CLASS CNewMachine : public CMachine
{
public:
	CNewMachine();

	CNewMachine(const CNewMachine&) = delete;
	void operator=(const CNewMachine&) = delete;
	virtual ~CNewMachine();

	virtual void DrawMachine(Gdiplus::Graphics *graphics) override;

	/// Setter/Getter for mMachineFrame
	virtual void SetMachineFrame(int frame) override { mMachineFrame = frame; }
	int GetMachineFrame() const { return mMachineFrame; }

	/// Setter/Getter for mSpeed
	virtual void SetSpeed(double speed) { mSpeed = speed; }
	virtual double GetSpeed() const { return mSpeed; }

	/// Setter/Getter for MachineNumber
	virtual void SetMachineNumber(int machine) override;
	virtual int GetMachineNumber() override { return mMachineNumber; }

	void CenteredString(Gdiplus::Graphics * graphics, const std::wstring & str, int x, int y, int dy);

	/// Setter/Getter for mX, mY
	virtual void SetLocation(int x, int y) override; // declared in cpp file
	Gdiplus::Point GetLocation() const { return mPos; }

	/// Setter/Getter for mFrameRate
	virtual void SetFrameRate(double rate) { mFrameRate = rate; }
	double GetFrameRate() const { return mFrameRate; }

	void SetMachineActual(std::shared_ptr<CMachineActual> machine);
	std::shared_ptr<CMachineActual> GetMachineActual() { return mMachine; }

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

	CWavPlayer mWavPlayer;


};

