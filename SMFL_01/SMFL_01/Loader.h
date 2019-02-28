#pragma once
class Loader
{
public:
	Loader();
	~Loader();

	static Loader* GetInstance();
	static string LoadDataFromFile(string _file, string _tag);

	const string PlayerConfig = "../data/Configs/PlayerConfig.txt";

private:
	static Loader* s_pInstance;
};

