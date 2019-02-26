#pragma once
class Loader
{
public:
	Loader();
	~Loader();

	static Loader* GetInstance();
	static void LoadDataFromFile(string _file, string _tag);

	const string PlayerConfig = "../data/test.txt";

private:
	static Loader* s_pInstance;
};

