#include <iostream>
#include <conio.h>

using namespace std;

int funkcja(int &a, int &b, int *suma)
{
    *suma = a+b;
    return a*b;
}

int main()
{
    int a, b, suma;
    cout << "Podaj pierwszy argument: ";
    cin >> a;
    cout << "Podaj drugi argument: ";
    cin >> b;
    funkcja(a , b, &suma);
    cout << "\nIloczyn = " << funkcja(a , b, &suma) << "\nSuma = " << suma;

    getch();
 
    return 0; 
}