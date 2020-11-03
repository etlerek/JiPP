#include <iostream>
#include <conio.h>

using namespace std;

void zmiana (int &a, int *b)
{
    int temp;

    temp = a;
    a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    cout << "Podaj pierwszy argument: ";
    cin >> a;
    cout << "Podaj drugi argument: ";
    cin >> b;
    zmiana(a , &b);
    cout << "\nPierwszy argument po zamianie = " << a << "\nDrugi argument po zamianie = " << b << endl;

    getch();

    return 0;
}