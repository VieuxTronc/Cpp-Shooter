#pragma once
class Vehicule //La classe vehicule � au moins un membre virtuel elle est donc appel�e classe "Abstraite"
{
public:
	Vehicule();
	~Vehicule();
	//virtual void Print();
	virtual void Print() = 0; //Oblige l'utilisateur � surcharger Print(), impossible d'instancier la classe si une virtual est "pure"
	//void Print();
protected :
	//accessible uniquement par la classe et ses filles 
};

