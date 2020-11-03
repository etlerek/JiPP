#include <iostream>
#include <conio.h>

using namespace std;

void zmiana(int *x ,int *y)
{
    int temp;

    if( *y < *x)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

int main()
{
    int x, y;
    cout << "Podaj pierwszy argument: ";
    cin >> x;
    cout << "Podaj drugi argument: ";
    cin >> y;
    zmiana(&x , &y);
    cout << "\nPierwszy argument po zamianie = " << x << "\nDrugi argument po zamianie = " << y << endl;

    getch();

    return 0;
}