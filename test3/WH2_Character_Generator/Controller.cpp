#include "Controller.h"
#include "Create_Character.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>

using namespace std;
//				WW US K ODP ZR INT SW OGD A ŻYW SW OGD A ŻYw S WT SZ MAG PO PP raceid

void Controller()
{
	while (true)
	{
		char controller;
		
		cin >> controller; //zapytanie kontrolera, wprowadzenie wartosci w kontroler

		if (controller == '1') //tworzenie czlowieka
		{
			Create_Character human1(20, 20, 20, 20, 20, 20, 20, 20, 1, 0, 0, 0, 4, 0, 0, 2, 1);	
		}

		if (controller == '2') //tworzenie elfa
		{
			Create_Character elf(20, 30, 20, 20, 30, 20, 20, 20, 1, 0, 0, 0, 5, 0, 0, 1, 2);
		}

		if (controller == 'q') // wylaczanie programu przy wprowadzeniu q z klawiatury
		{
			controller = '0'; // zerowanie kontrolera
			cout << "czy napewno chcesz opuscic program? Wpisz q ponownie jesli tak" << endl;
			cin >> controller;
			if (controller == 'q')
			{
				cout << "opuszczanie programu" << endl;
				exit(1); //wychodzenie z programu
			}
		} 

		controller = '0'; // zerowanie kontrolera przed ponownym zapytaniem
	}
}
