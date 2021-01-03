#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <conio.h>

using namespace std;
int i = 0;

bool compare(const pair<int, double> x, const pair<int, double> y)
{
  return x.second > y.second;
}

class Employee
{
public:
    int id; // identyfikator pracownika
    string name;
    string surname;
    string departmentid; //identyfikator działu w którym pracuje dane osoba
    string position;     //stanowisko na którym pracuje dana osoba

    void print()
    {
        cout << "ID pracownika: " << id << "\n Imie i nazwisko:" << name << " " << surname << "\n Departament i pozycja: " << departmentid << " - " << position << "\n";
    }
};

class HRMS
{
private:
    map<int, Employee> pracownik;
    map<string, vector<int>> pracownik_depid;
    map<int, double> pracownik_salary;

public:
    void add(Employee employee, string departmentid, double salary) //ampersant przed employee moze byc potrzebny
    {
        employee.departmentid = departmentid;
        employee.id = i;
        i++;
        pracownik[employee.id] = employee;

        pracownik_depid[departmentid].push_back(employee.id);

        pracownik_salary[employee.id] = salary;
    }

    void changeSalary(int pracownik_id, double salary)
    {
        pracownik_salary[pracownik_id] = salary;
    }

    void printDepartment(string departmentid)
    {
        cout << "\nPosortowano po departamencie: " << departmentid << endl;
        vector<int> vect = pracownik_depid[departmentid];
        for (int id : vect)
        {
            pracownik[id].print();
        }
    }

    void printSalaries()
    {
        for (map<int, Employee>::iterator it = pracownik.begin(); it != pracownik.end(); ++it)
        {
            it->second.print();
            cout << " Wynagrodzenie: " << pracownik_salary[it->first] << "zl" << endl;
        }
    }

    void printSalariesSorted()
    {
        list<pair<int, double>> sortuj;

        for (map<int, double>::iterator it = pracownik_salary.begin(); it != pracownik_salary.end(); ++it)
        {
            sortuj.push_back(make_pair(it->first, it->second));
        }
        sortuj.sort(compare);

        cout << "\nPosortowano po wynagrodzeniu: " << endl;
        for (list<pair<int, double>>::iterator it = sortuj.begin(); it != sortuj.end(); ++it)
        {
            pracownik[it->first].print();
            cout << " Wynagrodzenie: " << pracownik_salary[it->first] << "zl" << endl;
        }
    }
};

main()
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
