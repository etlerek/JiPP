#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;
template < class T >

void swap(T & a, T & b, int x)  ////// przekazuje inta aby kompilator nie wyrzucal bledu ///////
{
    b = (a*b)/(a=b);
}

int main()
{
    int a, b;
    cout << "Podaj pierwszy argument: ";
    cin >> a;
    cout << "Podaj drugi argument: ";
    cin >> b;

    swap(a, b);
    
    cout << "\nPierwszy argument po zamianie = " << a << "\nDrugi argument po zamianie = " << b << endl;
 
    getch();

    return 0;
}