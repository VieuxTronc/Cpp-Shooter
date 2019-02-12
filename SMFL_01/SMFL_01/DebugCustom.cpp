#include "pch.h"
#include "DebugCustom.h"
#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

DebugCustom* DebugCustom::s_pInstance = nullptr;

DebugCustom::DebugCustom()
{
}


DebugCustom::~DebugCustom()
{
}

DebugCustom* DebugCustom::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new DebugCustom();
	}

	return s_pInstance;
}

void DebugCustom::Log(std::string _msg)
{
	cout << GRN "[LOG] - " RESET << _msg << endl;
}

void DebugCustom::Warning(std::string _msg)
{
	cout << YEL "[LOG] - " RESET << _msg << endl;
}

void DebugCustom::Error(std::string _msg)
{
	cout << RED "[LOG] - " RESET << _msg << endl;
}

