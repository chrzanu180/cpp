#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h> //do obslugi _getch() w menu

#define N 3

using namespace std;

struct Osoba
{
	char nazwisko[10];
	char imie[10];

};


struct Konto
{
	Osoba klient;
	int numer;
	float wklad;

};

void wczytaj(Konto tab[], int n);
void wypisz(Konto tab[], int n);
void sortowanie_nazwisko(Konto tab[], int n);
void sortowanie_nazwisko(Konto tab[], int n);
void wklad_powyzej(Konto tab[], int n);
void menu();
void b2menu();

int main()
{
	menu();
	return 0;
}

//wpisywanie do tablicy z pliku
void wczytaj(Konto tab[], int n)
{
	ifstream konta;     // tworzenie pliku do odczytu
	konta.open("konto.txt", ios_base::in);       //otwarcie pliku do odczytu

	for (int i = 0; i<n; i++)
	{
		konta >> tab[i].klient.nazwisko >> tab[i].klient.imie >> tab[i].numer >> tab[i].wklad;      //wczytywanie danych !!!

																									//cout<<tab[i].klient.imie<<" "<<tab[i].klient.nazwisko<<" "<<tab[i].numer<<" "<<tab[i].wklad<<endl;
	}
	konta.close();
}

void wypisz(Konto tab[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << tab[i].klient.nazwisko << " " << tab[i].klient.imie << " " << tab[i].numer << " " << tab[i].wklad << endl;
	}
}

void sortowanie_nazwisko(Konto tab[], int n)
{
	Konto temp;     //zmienna pomocnicza

	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j<n - 1 - i; j++)
			if (strcmp(tab[j].klient.nazwisko, tab[j + 1].klient.nazwisko)>0)   //porownywanie lancuchow
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}

	//wczytywanie z kodu do pliku !!!
	ofstream posortowane;
	posortowane.open("alfabetycznie.txt", ios_base::out);       //plik sam sie utworzy

	for (int i = 0; i<n; i++)
	{
		posortowane << tab[i].klient.nazwisko << " " << tab[i].klient.imie << " " << tab[i].numer << " " << tab[i].wklad << endl;
	}

	posortowane.close();        //musi byc ??
}

void wklad_powyzej(Konto tab[], int n)
{
	float x;
	cout << "podaj wklad: ";
	cin >> x;
	cout << "klienci z wkladem wyzszym niz podany \n";
	for (int i = 0; i<n; i++)
	{
		if (tab[i].wklad>x)
		{
			cout << tab[i].klient.nazwisko << " " << tab[i].klient.imie << endl;
		}
	}
}

void wyplata(Konto tab[], int n)
{
	int nr, ile, y, x = 0;
	system("cls");
	cout << "Podaj numer konta: " << endl;
	cin >> nr;

	for (int i = 0; i < N; i++) {
		if (nr == tab[i].numer) {
			x = tab[i].numer;
			y = i;
		}
	}

	if (x == 0) {
		cout << "Bledny numer konta!";
	}
	else {
		cout << "ile chcesz wyplacic?" << endl;
		cin >> ile;
		cout << endl;
		cout << "Na koncie " << tab[y].numer << " bylo " << tab[y].wklad << endl;
		tab[y].wklad = tab[y].wklad - ile;
		cout << "Obecnie jest " << tab[y].wklad << "\n\n";
		wypisz(tab, n);
	}


	//zapisywanie do nowego pliku
	/*
	ofstream kontomod;
	kontomod.open("konto-mod.txt", ios_base::out);       //plik sam sie utworzy

	for (int i = 0; i<n; i++)
	{
	kontomod << tab[i].klient.nazwisko << " " << tab[i].klient.imie << " " << tab[i].numer << " " << tab[i].wklad << endl;
	}

	kontomod.close();
	*/

}

void b2menu() {//powrot do menu i czyszczenie ekranu
	cout << "\nWcisnij dowolny przycisk, aby wrocic do menu";
	_getch();
	system("cls");
}

void menu() {
	Konto tablica[N];


	while (true) {
		char option;
		cout << "\nCo chcesz zrobic?\n\n";
		cout << "1.Wczytaj ponownie dane \n2.Wypisz elementy\n3.Sortowanie alfabetyczne i zapis do alfabetycznie.txt\n";
		cout << "4.Wyplata z konta\n5.Wyswietlenie klietow z wkladem powyzej podanej wartosci\n";
		cout << "\n\n0. Zamknij program\n";


		option = _getch();

		switch (option)
		{
		case '1':
			wczytaj(tablica, N);
			cout << "Wczytano dane";
			break;
		case '2':
			cout << "Wypisz elementy\n";
			wypisz(tablica, N);
			break;
		case '3':
			sortowanie_nazwisko(tablica, N);
			cout << "Posortowano alfabetyczne\n";
			break;
		case '4':
			cout << "Wyplata srodkow\n";
			wyplata(tablica, N);
			break;
		case '5':
			cout << "Klienci z minimalnym wkladem\n";
			wklad_powyzej(tablica, N);
			break;

		case '0':
			cout << "\nPa pa...\n\n";
			exit(0);
		default:
			system("cls");
			cout << "\nNie ma takiej opcji!" << endl;


		}
		b2menu();

	}

}