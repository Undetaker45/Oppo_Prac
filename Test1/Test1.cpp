// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "..\Oppo_Prac1\data.h"
#include "..\Oppo_Prac1\zanyatia.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TestCore {
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(TestData1)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "2007.. " };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestData2)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "\n" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestData3)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "666.02.29 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestData4)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "0.07. 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestRead1)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "1.08.32 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestRead2)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "1.06.31 124 Fedow" };
				Data date;  date.ReadDate(sin);
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestRead3)
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

		TEST_METHOD(TestRead4)
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
		
		TEST_METHOD(CorrectAud1)
		{
			Zanyatia aud;
			std::string TextError = "Ошибка в определении запрещенных символов в поле аудитории.";
			try {
				std::string textToCheck = "2015.12.22 !214 daty";
				std::istringstream istStr(textToCheck);
				aud.LoadTxt(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(CorrectAud2)
		{
			Zanyatia aud;
			std::string TextError = "Ошибка в определении запрещенных символов в поле аудитории.";
			try {
				std::string textToCheck = "2015.12.22 d214 daty";
				std::istringstream istStr(textToCheck);
				aud.LoadTxt(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(CorrectPrepod1)
		{
			Zanyatia Prepod;
			std::string TextError = "Ошибка в определении запрещенных символов в поле фамилии.";
			try {
				std::string textToCheck = "2015.12.22 D214 !daty";
				std::istringstream istStr(textToCheck);
				Prepod.LoadTxt(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(CorrectPrepod2)
		{
			Zanyatia Prepod;
			std::string TextError = "Ошибка в определении запрещенных символов в поле фамилии.";
			try {
				std::string textToCheck = "2015.12.22 D214 1daty";
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