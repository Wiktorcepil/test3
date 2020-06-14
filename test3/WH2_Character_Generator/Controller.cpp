#include "Controller.h"
#include "Create_Character.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//				WW US K ODP ZR INT SW OGD A ¯YW SW OGD A ¯Yw S WT SZ MAG PO PP

void Controller()
{
	char controller;
//	int character_numb;
//	std::vector <int> humans;
	while (true)
	{
		
		cin >> controller; //zapytanie kontrolera, wprowadzenie wartosci w kontroler
		if (controller == '1')
		{
			Create_Character human1(20, 20, 20, 20, 20, 20, 20, 20, 1, 0, 0, 0, 4, 0, 0, 2);
			
		}

		//create elf raceid == 2
		//Create_Character elf(20, 30, 20, 20, 30, 20, 20, 20, 1, 0, 0, 0, 5, 0, 0, 1);

		//create halfling raceid == 3
		///Create_Character(10, 30, 10, 10, 30, 20, 20, 30, 1, 0, 0, 0, 3, 0, 0, 0);

		//create dwarf raceid == 4
		///Create_Character(30, 20, 20, 30, 10, 20, 20, 10, 1, 0, 0, 0, 4, 0, 0, 0);

		if (controller == 'q') // wylaczanie programu przy wprowadzeniu q z klawiatury
		{
			controller = '0'; // zerowanie kontrolera
			cout << "czy napewno chcesz opuscic program? Wpisz q ponownie jesli tak" << endl;
			cin >> controller;
			if (controller == 'q')
			{
				cout << "opuszczanie programu" << endl;
				exit(1);
			}
		} 

		controller = '0'; // zerowanie kontrolera
	}
}