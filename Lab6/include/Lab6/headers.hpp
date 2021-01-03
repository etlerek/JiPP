#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

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
