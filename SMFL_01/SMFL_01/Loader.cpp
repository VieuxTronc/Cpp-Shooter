#include "pch.h"
#include "Loader.h"

Loader* Loader::s_pInstance = nullptr;

Loader::Loader()
{
}

Loader::~Loader()
{
}

Loader* Loader::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Loader();
	}

	return s_pInstance;
}

string Loader::LoadDataFromFile(string _file, string _tag)
{
	string line;
	ifstream file(_file);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.find(_tag) != string::npos)
			{
				unsigned firstDelimiter = line.find("\"");
				unsigned lastDelimiter = line.find_last_of("\"");
				string content = line.substr(firstDelimiter + 1, lastDelimiter - 1 - firstDelimiter);
				return content; 
			}
		}
		file.close();
	}

	else return "";
}
