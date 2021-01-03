#include <iostream>
#include <time.h>
#include <conio.h>

using  namespace std;

int main(int argc, char *argv[])
{
    HRMS dane;
    Employee osoba;

    osoba.name = "Max";
    osoba.surname = "Bury";
    osoba.position = "Kucharz";
    dane.add(osoba, "Kuchnia", 4200.00);

    osoba.name = "Marek";
    osoba.surname = "Mitchel";
    osoba.position = "Szef";
    dane.add(osoba, "Kuchnia", 9999.99);

    osoba.name = "Marcin";
    osoba.surname = "Najman";
    osoba.position = "Klepacz kurczakow";
    dane.add(osoba, "Kuchnia", 4.20);

    osoba.name = "Jakub";
    osoba.surname = "Michalski";
    osoba.position = "Pakowacz";
    dane.add(osoba, "Serwis", 2137.00);

    osoba.name = "Ola";
    osoba.surname = "Michalska";
    osoba.position = "Pomocniczka pakowacza";
    dane.add(osoba, "Serwis", 21.37);

    osoba.name = "Bartek";
    osoba.surname = "Guty";
    osoba.position = "Podaj Majster";
    dane.add(osoba, "Serwis", 1.01);

    osoba.name = "Michal";
    osoba.surname = "Gniwek";
    osoba.position = "Sprzedawca";
    dane.add(osoba, "Obsluga", 154.76);

    osoba.name = "Wiktor";
    osoba.surname = "Kudzia";
    osoba.position = "Sprzedawca";
    dane.add(osoba, "Obsluga", 372.76);

    osoba.name = "Miroslaw";
    osoba.surname = "Zelent";
    osoba.position = "Kelner";
    dane.add(osoba, "Obsluga", 554.45);

    osoba.name = "Lukasz";
    osoba.surname = "Rekin";
    osoba.position = "Kelner";
    dane.add(osoba, "Obsluga", 554.45);

    dane.printDepartment("Kuchnia");
    dane.printDepartment("Serwis");
    dane.printDepartment("Obsluga");

    cout << "\n";
    dane.printSalaries();
    dane.printSalariesSorted();
    
    getch();
    return 0;
}
