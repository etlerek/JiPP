#include <iostream>
#include <conio.h>

using namespace std;

void zmiana(int &x, int &y)
{
    swap(x,y);
}

void test(int &testx, int &testy)
{
    int temp;

    temp = testx;
    testx = testy;
    testy = temp;
}

int main()
{
    int x, y, testx, testy;
    cout << "Podaj pierwszy argument: ";
    cin >> x;
    cout << "Podaj drugi argument: ";
    cin >> y;

    testx = x;
    testy = y;

    zmiana(x, y);
    test(testx , testy);

    cout << "\nPierwszy argument testowy po zamianie = " << testx << "\nDrugi argument testowy po zamianie = " << testy << endl;
    cout << "\nPierwszy argument po zamianie = " << x << "\nDrugi argument po zamianie = " << y << endl;

    if(x==testx && y==testy)
    {
         cout << "\nFunkcja swap dziala poprawnie";
    }
    else
    {
        cout << "\nFunkcja swap dziala niepoprawnie";
    }
    
 
    getch();

    return 0;
}