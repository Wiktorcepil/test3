#include <iostream>
#include "Character_class.h"


Fighter :: Fighter()
{
	//stats_profession[0] = "+10";
	//stats_profession[9] = "+2";
	//stats_profession[2] = "+10";
	equipment.push_back("miecz");
	equipment.push_back("skorzany kaftan");
};

Hunter :: Hunter()
{
	//stats_profession[1] = "+10";
	//stats_profession[4] = "+15";
	equipment.push_back("luk");
	equipment.push_back("sztylet");
};

void profession_roll() 
{
	int profession_quantity = 2; //ilosc klas postaci, uzywane do losowania profesji poczatkowej postaci AKTUALIZOWAC PRZY DODANIU NOWYCH KLAS!!!

	if ((rand() % profession_quantity + 1) == 1)
	{
		Fighter fighter;
		//wypisuje ekwipunek fightera
			std::cout << "Wojownik\nEkwipunek:" << std::endl;
			for (int i = 0; i < fighter.equipment.size(); i++) // wypisywanie statystyk stworzonej postaci na ekran
			{
				std::cout << "-" << fighter.equipment[i]  << std::endl;
			}
	}
	else
	{
		Hunter hunter;
		 //wypisuje ekwipunek huntera
		std::cout << "Lowca\nEkwipunek:" << std::endl;
			for (int i = 0; i < hunter.equipment.size(); i++) // wypisywanie statystyk stworzonej postaci na ekran
			{
				std::cout << "-" << hunter.equipment[i] << std::endl;
			}
	}
}
