#pragma once

#include "Vehicule.h"

class FormulaOne : public Vehicule
{
public:
	float wheel;
	FormulaOne();
	~FormulaOne();
	void Print(); //On peut mettre virtual aussi devant cette fonction pour donner de la visibilité mais ça la rend dispo au classes filles
	float operator +(float _val)
	{
		wheel += _val;
	};

private:

};

