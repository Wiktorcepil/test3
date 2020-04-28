#include <iostream>
#include <random>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h>

char switch_operator = 'a';
int progress = 0;
int cost;
int bonusy = 0;
int bonusy_wprowadzane = 0;
int roll_outcomes[1000];
int n = 0;
using namespace std;
int staty;
int roll;
int roll_srednia;

void instrukcja_bonusy(void){
	cout << "TWOJA ZRECZNOSC = " << staty << "\n" << endl;
	cout << "Teraz wprowadz POJEDYNCZO bonusy jako wartosci dodatnie i minusy jako wartosci ujemne." << endl;
	cout << "Nacisnij c gdy skonczysz wpisywac wartosci." << endl;
	cout << "Nacisnij z aby cofnac wprowadzenie ostatniej wartosci \nWcisnij n aby wprowadzic wartosc i n po wprowadzeniu jej by dodac kolejna." << endl;
	Sleep(500);
	cout << "\nco chcesz zrobic?" << endl;
}


void wprowadzanie_bonusow(void) {
	while (switch_operator != 'c')						//wprowadzanie bonusow
	{
		instrukcja_bonusy();
		Sleep(500);
		switch_operator = 'a';
		switch_operator = _getch();

		switch (switch_operator)
		{
		case 'n':
		{
			system("cls");
			cout << "wprowadz wartosc bonusu/minusa" << endl;
			cin >> bonusy_wprowadzane;
			bonusy += bonusy_wprowadzane;
			system("cls");
			cout << "suma bonusow i minusow wynosi:   " << bonusy << endl;
			Sleep(500);
			cout << "Twoja calkowita zdolnosc wynosi:   " << staty + bonusy << endl;

			break;
		}
		case 'z':
		{
			system("cls");
			cout << "usunieto ostatni modyfikator" << endl;
			bonusy -= bonusy_wprowadzane;
			cout << "suma bonusow i minusow wynosi:   " << bonusy << endl;
			Sleep(500);
			cout << "Twoja calkowita zdolnosc wynosi:   " << staty + bonusy << endl;
			bonusy_wprowadzane = 0;
			break;
		}
		}
	}
}
						/////////////CRITICAL ROLL///////////////////
void critical_roll(void)
{
	if (roll = 1)
	{
		cout << "WOW! Idzie Ci niesamowicie! Udalo Ci sie dzisiaj zrobic naprawde dobra robote. Postep znacznie wzrasta" << endl;
		progress += roll = rand() % 10 + 1;
		Sleep(3000);
	}
}
						/////////////BAD ROLL///////////////////
void failure_roll(int r)
{
	if (roll == r)
	{
		cout << "UPS! Uszkodziles przedmiot, postep nieznacznie spada. Badz ostrozniejszy! \nzakoncz program naciskajac q, albo uzyj punktu szczescia naciskajac n, albo kontynuuj wytwarzanie naciskajac c." << endl;
		Sleep(500);
		switch_operator = _getch();

		switch (switch_operator)
		{
			case 'q':
			{

				cout << "\nPorzucanie przedmiotu." << endl;
				Sleep(1000);
				exit(1);

			}
			case 'n':
			{
				cout << "\nWykorzystano punkt szczescia aby przerzucic kosci" << endl;
				Sleep(1000);
				n -= 1;
				roll_srednia -= roll_outcomes[n];
				break;

			}
			case 'c':
			{
				cout << "\nWykonujesz przedmiot dalej, nie zwazajac na swoje niedbalstwo" << endl;
				Sleep(1000);
				cout << "PFFFF...\n" << endl;
				Sleep(1000);
				progress -= roll = rand() % 10 + 1;
				break;

			}
		}
	}
}

						//////CRITICAL FAILURE ROLL////////////
void critical_failure_roll(void) 
{
	if (roll == 100)
	{
		cout << "OJ! Wyglada na to, ze twoj przedmiot sie zepsul. Jaka szkoda... \nzakoncz program naciskajac q, albo uzyj punktu szczescia naciskajac n." << endl;
		Sleep(500);
		switch_operator = _getch();

		switch (switch_operator)
		{
		case 'q':
		{

			cout << "\nPorzucanie przedmiotu." << endl;
			Sleep(1000);
			exit(1);

		}
		case 'n':
		{
			cout << "\nWykorzystano punkt szczescia aby przerzucic kosci" << endl;
			Sleep(1000);
			n -= 1;
			roll_srednia -= roll_outcomes[n];
			break;

		}

		}
	}
}
									//WYKONYWANIE PRZEDMIOTU//
void wykonywanie_przedmiotu(void)
{
	//roll random 1-100

	while (n != 1000)
	{
		roll = rand() % 100 + 1;
		roll_outcomes[n] = roll; //wpisywanie rolli do tablicy
		cout << "numer rzutu:" << n << "wynik rzutu:"<< roll <<endl;

		if (roll == 100) critical_failure_roll();
		failure_roll(99);
		failure_roll(98);
		failure_roll(97);
		failure_roll(96);
		

		roll_srednia += roll_outcomes[n];
		int rem_progress; // remember progress
		rem_progress = progress;
		progress += (staty + bonusy - roll_outcomes[n] + 1);
		
		if (progress < 0)
		{
			progress -= ((staty + bonusy) - roll_outcomes[n] + 1);
		}
	
		if (progress >= cost)
		{	
			
			
			roll_srednia = roll_srednia / n;
			
			cout << "roll_srednia: " << roll_srednia << "    progress: " << progress << endl;
			cout << "\nPrzedmiot wykonany!" << endl;
			cout << "srednia wartosc rzutow " << roll_srednia << endl;
			if (n % 2 == 0)
			{
				cout << "tworzyles przedmiot przez " << n * 8 << " godzin. Czyli przez " << n / 2 << " dni" << endl;
			}
			else
			{
				cout << "tworzyles przedmiot przez " << n * 8 << " godzin. Czyli przez " << n / 2 << ",5 dnia" << endl;
			}
			system("pause");
			exit(1);
		}
		
		n++;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{

	srand(time(NULL));
	//wartosc do wykucia broni w %
	cout << "Wprowadz wartosc liczbowa potrzebna do wykonania przedmiotu. Zostanie ona wyrazona w %" << endl;

	cin >> cost;
	Sleep(800);
	system("cls");

	//Zapytanie o statystyki postaci
	cout << "Wprowadz wartosc zrecznosci. \n(w nastepnych krokach wprowadzisz pozostale bonusy.)" << endl;
	cin >> staty;

	while ((staty < 0) || (staty > 101))					//Wprowadzanie statystyki przy pomocy petli
	{
		cout << "wprowadziles nieprawidlowa wartosc zrecznosci! \nwprowadz poprawna!" << endl;
		cin >> staty;
	}
	system("cls");

	switch_operator = 'a';
	wprowadzanie_bonusow();

	
	wykonywanie_przedmiotu();	

	system("pause");
	return 0;
}
