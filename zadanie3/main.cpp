#include <iostream>
#include "matrix.cpp"

using  namespace std;

int main(int argc, char *argv[])
{
    int wiersze = 3;
    int kolumny = 9;
    
    /////konstrukcja macierzy/////
    Matrix test( kolumny , wiersze );
    Matrix kwadrat( kolumny );
    Matrix dodawana( kolumny , wiersze);
    Matrix odejmowana( kolumny , wiersze);

    ////ustawianie wartosci w danej komorce////
    test.set( 2, 3, 5);
    kwadrat.set(3 , 5, 8);
    dodawana.set(2, 3, 5);

    ////pobiera wartisc z danej komorki macierzy////
    cout << "wartosc wskazanej komorki macierzy zwyklej: " << test.get(2 , 3) << endl;
    cout << "wartosc wskazanej komorki macierzy kwadratowej: " << kwadrat.get(3 , 5) << endl;
    
    
    ////wyswietla macierz zwykla////
    cout << "macierz:\n";
    test.print();

    ////wyswietla macierz kwadratowa zwykla////
    cout << "\nmacierz kwadratowa:\n";
    kwadrat.print();

    cout << "\nmacierz dodawana:\n";
    test.add(dodawana).print();

    cout << "\nmacierz odejmowania:\n";
    test.subtract(odejmowana).print();

    return 0;
}