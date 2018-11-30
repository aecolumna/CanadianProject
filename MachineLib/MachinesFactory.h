#pragma once
#include <memory>
#include <sstream>
#include <string>

class CMachineActual;
class CPulley;

class CMachinesFactory
{
public:
	CMachinesFactory();

	virtual ~CMachinesFactory();

	void CreatePost(std::shared_ptr<CMachineActual>& machine, int x, Gdiplus::Color color = Gdiplus::Color::Red);
	void CreateBar(std::shared_ptr<CMachineActual>& machine, int x, std::wstring filename);
	std::shared_ptr<CPulley> CreatePulley(std::shared_ptr<CMachineActual>& machine, int x);
	std::shared_ptr<CMachineActual> CreateMachine1();
	std::shared_ptr<CMachineActual> CreateMachine2();
	
};

