#include "pch.h"
#include "FormulaOne.h"
#include <iostream>

FormulaOne::FormulaOne()
{
}

FormulaOne::~FormulaOne()
{
}

void FormulaOne::Print()
{
	//Vehicule::Print(); //On peut appeler la fonction mère si elle peut être utile avant d'executer notre code
	std::cout << "FormulaOne" << std::endl;
}
