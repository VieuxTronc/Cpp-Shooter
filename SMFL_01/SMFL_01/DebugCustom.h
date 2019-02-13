#pragma once

#include "pch.h"

class DebugCustom
{
public:
	DebugCustom();
	~DebugCustom();

	static DebugCustom* GetInstance(); 
	static void Log(std::string _msg); 
	static void Warning(std::string _msg); 
	static void Error(std::string _msg); 

private:
	static DebugCustom* s_pInstance; 
 };

