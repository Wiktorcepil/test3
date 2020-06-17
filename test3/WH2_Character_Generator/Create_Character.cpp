#include "Create_Character.h"
#include "Character_class.h"
#include <cstdlib> // srand() rand()
#include <ctime> // time()
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

//duze litery to tylko nazwy
std::string stats_names[16] = { "WW", "US", "K", "ODP", "ZR", "INT", "SW", "OGD", "A", "ZYW", "S", "WT", "SZ", "MAG", "PO", "PP" };


void Print_Character(int stat_numb_print, std::vector <int> stats_print) //funkcja wypisuje statystyki postaci, powstawala dla przejrzystosci kodu
{
	for (stat_numb_print = 0; stat_numb_print < stats_print.size(); stat_numb_print++) // wypisywanie statystyk stworzonej postaci na ekran
	{
		std::cout << stats_names[stat_numb_print] << ": " << stats_print[stat_numb_print] << "		" << stats_names[stat_numb_print + 1] << ": " << stats_print[stat_numb_print + 1] << std::endl; //to do jeszce jedna kolumna z +n z profesji
		stat_numb_print++;
	}
}



//bazowe wartosci statystyk dla poszczegolny ras wprowadzamy poprzez zmienne oznaczone malymi literami

/////////////////////KONSTRUKTOR//////////////////////////////
Create_Character::Create_Character(int ww, int us, int k, int odp, int zr, int inte, int sw, int ogd, int a, int zyw, int s, int wt, int sz, int mag, int po, int pp, char raceid)
{			
	srand(time(NULL));
		/////////////////////////// STL //////////////////////////////
		//std::vector<int> stats = { ww, us, k, odp, zr, inte, sw, ogd, a, zyw, s, wt, sz, mag, po, pp}; 
	std::vector <int> stats = { ww, us, k, odp, zr, inte, sw, ogd };		//od teraz kazda wartosc statystyki bierzemy z tego wektora
																	//TO SA FAKTYCZNE STATYSTYKI POSTACI! SA ONE W WEKTORZE STATS
		/////////////////////////// zakresowa petla for //////////////////////////////
	for (auto& v : stats)
	{
		v += (rand() % 10 + 1);
		v += (rand() % 10 + 1);
	}

	stats.push_back(a);
	stats.push_back(zyw);
	stats.push_back(stats[2] / 10); //  ustawianie S, tak samo dla wszystkich ras		s = k/10
	stats.push_back(stats[3] / 10); //  ustawianie WT, tak samo dla wszystkich ras		wt = odp/10
	stats.push_back(sz);
	stats.push_back(mag);
	stats.push_back(po); 
	stats.push_back(pp);
	
	
	if (raceid == 1 || 2)
	{
		stat_roll = (rand() % 10 + 1); // rzut na pp czlowieka i elfa
		if (stat_roll > 4)
		{
			stats[15]++;
			//stats[15] = stats[15] + 1; // najnizsza wartosc pp dla czlowieka to 2, jesli rzuci 5 lub wiecej uzyskuje maksymalna wartosc pp dla czlowieka czyli 3, algorytm dziala podobnie dla elfa -1
		}

		stat_roll = (rand() % 10 + 1); // rzut na zyw czlowieka i elfa
		if (stat_roll < 4)
		{
			stats[9] = 10 ; 
		}
		if (stat_roll > 3 && stat_roll < 7)
		{
			stats[9] = 11;
		}
		if (stat_roll == 10)
		{
			stats[9] = 13;
		}
		if (stat_roll > 6 && stat_roll < 10) //dla rzutu 7-9
		{
			stats[9] = 12;
		}
		if (raceid == 2) //elf ma -1 do zyw wzgledem czlowieka.
		{
			stats[9]--;
		}
	}

	//to do dodawanie bonusowych statystyk ze zdolnosci do zdolnosci postaci (do elementow wektora stats[]) 
	if (raceid == 1) 
	{
		std::cout << "TO CZLOWIEK!" << std::endl;		// komunikat informujacy o stworzeniu czlowieka
	}
	if (raceid == 2)
	{
		std::cout << "TO ELF!" << std::endl;			// komunikat informujacy o stworzeniu elfa
	}

	// to do losowanie i wypisawanie imienia z utworzonej bazy imion
	// to do wypisanie profesji z utworzeonej bazy profesji Z PLIKU Character_class

	profession_roll(); // rzut na profesje postaci Character_class
	
	Print_Character(stat_numb, stats); //wywolanie funkcji wypisujacej statystyki postaci

	// to do wypiswywanie zdolnosci wynikajacych z profesji i z rasy
}
