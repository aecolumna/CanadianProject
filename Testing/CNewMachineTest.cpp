#include "stdafx.h"
#include "CppUnitTest.h"

#include <cmath>
#include "NewMachine.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(CNewMachineTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestAll)
		{
			CNewMachine newMachine;

			Assert::IsTrue(newMachine.GetMachineNumber() == 1);
			Assert::IsTrue(newMachine.GetLocation().X == 0);
			Assert::IsTrue(newMachine.GetLocation().Y == 0);
			Assert::IsTrue(newMachine.GetMachineFrame() == 0);
			Assert::AreEqual(1.0, newMachine.GetFrameRate(), 0.00001);
			Assert::AreEqual(1.0, newMachine.GetSpeed(), 0.00001);

			newMachine.SetMachineFrame(5);
			Assert::IsTrue(newMachine.GetMachineFrame() == 5);

			newMachine.SetLocation(4, 2);
			Assert::IsTrue(newMachine.GetLocation().X == 4);
			Assert::IsTrue(newMachine.GetLocation().Y == 2);

			newMachine.SetFrameRate(6);
			Assert::AreEqual(6.0, newMachine.GetFrameRate(), 0.00001);

			newMachine.SetSpeed(8.0);
			Assert::AreEqual(8.0, newMachine.GetSpeed(), 0.00001);




		}

	};
}