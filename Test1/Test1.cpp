#include "pch.h"
#include "..\Oppo_Prac1\data.h"
#include "..\Oppo_Prac1\zanyatia.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TestCore {
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(Test1)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "2005.. " };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(Test2)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "\n" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(Test3)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "500.02.29 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(Test4)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "0.05.2 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestRead5)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "1.08.32 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestRead6)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "1.06.31 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(Test7)
		{
			Zanyatia Aud;
			std::string TextError = "Ошибка при чтении аудитории.";
			try {
				std::string textToCheck = "2015.12.22  ";
				std::istringstream istStr(textToCheck);
				Aud.LoadTxt(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(Test8)
		{
			Zanyatia Prepod;
			std::string TextError = "Ошибка при чтении преподавателя.";
			try {
				std::string textToCheck = "2015.12.22 214  ";
				std::istringstream istStr(textToCheck);
				Prepod.LoadTxt(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(CorrectDate)
		{
			Data date(666, 3, 31);
			Assert::IsTrue(!date.CheckDate());
			date.SetDate(2006, 3, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(1950, 3, 31);
			Assert::IsTrue(!date.CheckDate());
			date.SetDate(2003, 1, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 3, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 5, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 7, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 8, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 10, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 12, 31);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 4, 30);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 6, 30);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 9, 30);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 11, 30);
			Assert::IsTrue(date.CheckDate());
			date.SetDate(2003, 2, 28);
			Assert::IsTrue(date.CheckDate());
		}
	};
}