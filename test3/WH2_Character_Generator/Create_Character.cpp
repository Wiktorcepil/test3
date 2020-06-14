#include "Create_Character.h"
#include <cstdlib> // srand() rand()
#include <ctime> // time()
#include <iostream>
#include <string>
#include <vector>

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
Create_Character::Create_Character(int ww, int us, int k, int odp, int zr, int inte, int sw, int ogd, int a, int zyw, int s, int wt, int sz, int mag, int po, int pp)
{			
	srand(time(NULL));
					///////////////////// NIE STL/////////////////
	//					0	1	2	3	4	5	 6	 7	  8	  9	 10	 11	 12	 13	  14  15
	/*int stats[16] = {ww, us, k, odp, zr, inte, sw, ogd, a, zyw, s, wt, sz, mag, po, pp}; //od teraz kazda wartosc statystyki bierzemy z tej tablicy!
																						//TO SA FAKTYCZNE STATYSTYKI POSTACI!
	for (stat_numb = 0; stat_numb < 8; stat_numb++)
	{
		stats[stat_numb] = stats[stat_numb] + (rand() % 10 + 1);
		stats[stat_numb] = stats[stat_numb] + (rand() % 10 + 1);			//bez uzycia zakresowej petli for
	}*/
	
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
	stats.push_back(zyw); //9
	stats.push_back(stats[2] / 10); //  ustawianie S, tak samo dla wszystkich ras		s = k/10
	stats.push_back(stats[3] / 10); //  ustawianie WT, tak samo dla wszystkich ras			wt = odp/10
	stats.push_back(sz);
	stats.push_back(mag);
	stats.push_back(po); 
	stats.push_back(pp);
	
	raceid = 1; //przykladowo ustawiony raceid na 1 DO TESTOW! W przyszlosci gdy dodane zostana nowe rasy nalezy dodac mozliwosc zmiany zmiennej raceid na ludzka, elfia, niziolkowa, krasnoludzka
	
	if (raceid == 1 || 2) // pp for human and elf
	{
		stat_roll = (rand() % 10 + 1); // rzut na PP czlowieka i elfa
		if (stat_roll > 4)
		{
			stats[15]++;
			//stats[15] = stats[15] + 1; // najnizsza wartosc pp dla czlowieka to 2, jesli rzuci 5 lub wiecej uzyskuje maksymalna wartosc pp dla czlowieka czyli 3, algorytm dziala podobnie dla elfa
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
		if (raceid == 2) //elf ma -1 do zyw wzgledem czlowieka. TO DO
		{
			stats[9]--;
		}
	}

	//if (raceid == 3) //pp for halflinga
	//if (raceid == 4) //pp for dwarf

	//to do dodawanie bonusowych statystyk ze zdolnosci do zdolnosci postaci (do elementow wektora stats[]) 
	if (raceid == 1) 
	{
		std::cout << "TO CZLOWIEK!" << std::endl;		// komunikat informujacy o stworzeniu czlowieka
	}
	if (raceid == 2)
	{
		std::cout << "TO ELF!" << std::endl;
	}
	// to do losowanie i wypisawanie imienia z utworzonej bazy imion
	// to do wypisanie profesji z utworzeonej bazy profesji

	Print_Character(stat_numb, stats); //wywolanie funkcji wypisujacej statystyki postaci

	// to do wypiswywanie zdolnosci wynikajacych z profesji i z rasy
	// to do wypisywanie ekwipunku danej profesji
	Create_Character:: ~Create_Character();
}
