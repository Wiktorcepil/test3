#pragma once
#include <string>

//				WW US K ODP ZR INT SW OGD A ¯YW SW OGD A ¯YW S WT SZ MAG PO PP
int profession_quantity = 3; //ilosc klas postaci, uzywane do losowania profesji poczatkowej postaci AKTUALIZOWAC PRZY DODANIU NOWYCH KLAS!!!
class Character_profession
{
private: std::string stats_profession[16] = { "","","","","","","","","","","","","","","","" };
};

class Fighter : public Character_profession
{
	
};

class Hunter : public Character_profession
{

};

class Rouge : public Character_profession
{

};

int profession_roll();