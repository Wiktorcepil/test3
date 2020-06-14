#include "Create_Character.h"
#include <cstdlib> // srand() rand()
#include <ctime> // time()
#include <iostream>
#include <string>

//duze litery to tylko nazwy
std::string stats_names[16] = { "WW", "US", "K", "ODP", "ZR", "INT", "SW", "OGD", "A", "ZYW", "S", "WT", "SZ", "MAG", "PO", "PP" };
//bazowe wartosci statystyk dla poszczegolny raz wprowadzamy poprzez zmienne oznaczone malymi literami
	Create_Character::Create_Character(int ww, int us, int k, int odp, int zr, int inte, int sw, int ogd, int a, int zyw, int s, int wt, int sz, int mag, int po, int pp)
	{
							
	srand(time(NULL));
	//				0	1	2	3	4	5		6	7	8	9	10	11	12	13	14	15
	int stats[16] = {ww, us, k, odp, zr, inte, sw, ogd, a, zyw, s, wt, sz, mag, po, pp}; //od teraz kazda wartosc statystyki bierzemy z tej tablicy!
																						//TO SA FAKTYCZNE STATYSTYKI POSTACI!
	
	for (stat_numb = 0; stat_numb < 8; stat_numb++)
	{
		stats[stat_numb] = stats[stat_numb] + (rand() % 10 + 1);
		stats[stat_numb] = stats[stat_numb] + (rand() % 10 + 1);
	}

	stats[10] = stats[2] / 10;		 //  ustawianie S, tak samo dla wszystkich ras		s = k/10
	stats[11] = stats[3] / 10;	 //  ustawianie WT, tak samo dla wszystkich ras			wt = odp/10

	
	raceid = 1; //przykladowo ustawiony raceid na 1 DO TESTOW
	if (raceid == 1) // pp for human
	{
		stat_roll = (rand() % 10 + 1); // rzut na PP czlowieka
		if (stat_roll > 4)
		{
			stats[15]++;

		}
		
	}
	/* if (raceid == 2) //pp for elf
{
	stats[8] = { WW, US, K, ODP, ZR, INT, SW, OGD };
}

if (raceid == 3) //pp for halflinga
{
	stats[8] = { WW, US, K, ODP, ZR, INT, SW, OGD };
}

if (raceid == 4) //pp for dwarf
{
	stats[8] = { WW, US, K, ODP, ZR, INT, SW, OGD };
}
*/
	// dodawanie bonusowych statystyk ze zdolnosci do zdolnosci postaci (do elementow tablicy stats[]) 
	std::cout << "ETSE HOMO!" << std::endl;		// komunikat informujacy o stworzeniu czlowieka

	// to do losowanie i wypisawanie imienia z utworzonej bazy imion
	// to do wypisanie profesji z utworzeonej bazy profesji
	for (stat_numb = 0; stat_numb < 16; stat_numb++) // wypisywanie statystyk stworzonej postaci na ekran
	{
		std::cout<< stats_names[stat_numb] << ": " << stats[stat_numb] << "		" << stats_names[stat_numb + 1] << ": " << stats[stat_numb + 1] << std::endl; //to do jeszce jedna kolumna z +n z profesji
		stat_numb++;
	}
	// to do wypiswywanie zdolnosci wynikajacych z profesji i z rasy
	// to do wypisywanie ekwipunku danej profesji
	Create_Character:: ~Create_Character();
}