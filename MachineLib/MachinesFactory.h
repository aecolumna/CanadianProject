
/**
 * \file MachinesFactory.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once
#include <memory>
#include <sstream>
#include <string>

class CNewMachine;
class CMachineActual;
class CPulley;


/**
 * Class that creats machines
 */
class CMachinesFactory
{
public:
	CMachinesFactory();

	virtual ~CMachinesFactory();
	/**
	 * Create a post
	 * \param machine The machine
	 * \param x X location of post
	 * \param color Color of the post
	 */
	void CreatePost(std::shared_ptr<CMachineActual>& machine, int x, Gdiplus::Color color = Gdiplus::Color::Red);

	/**
	 * Create a bar
	 * \param machine Machine
	 * \param x X
	 * \param filename Image filename
	 */
	void CreateBar(std::shared_ptr<CMachineActual>& machine, int x, std::wstring filename);

	/**
	 * Create a pulley
	 * \param machine
	 * \param x
	 * \return pulley
	 */
	std::shared_ptr<CPulley> CreatePulley(std::shared_ptr<CMachineActual>& machine, int x);

	/**
	 * Make machine of type 1
	 * \param newMachine
	 * \return Machine Pointer
	 */
	std::shared_ptr<CMachineActual> CreateMachine1(CNewMachine* newMachine);

	/**
	 * Make machine of type 2
	 * \param newMachine
	 * \return Machine Pointer
	 */
	std::shared_ptr<CMachineActual> CreateMachine2(CNewMachine* newMachine);
	
};



