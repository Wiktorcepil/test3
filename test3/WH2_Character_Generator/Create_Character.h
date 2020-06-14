#pragma once 

class Create_Character
{
	//konstruktor Create_Charakter							inte zamiast int z oczywistych wzgledow technicznych
public: Create_Character(int ww, int us, int k, int odp, int zr, int inte, int sw, int ogd, int a, int zyw, int s, int wt, int sz, int mag, int po, int pp);
		
		int raceid=1; //indetygikator rasy. 1 human, 2 elf, 3 halfling, 4 dwarf
		int stat_roll; // do losowania statystyk typu PP
private: int stat_numb;
		

};

