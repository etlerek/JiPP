#include <iostream>
#include <time.h>
#include <conio.h>
#include "matrix.cpp"

using  namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int wiersze = 4;
    int kolumny = 5;
    
    /////konstrukcja macierzy/////
    Matrix test( kolumny , wiersze );
    Matrix kwadrat( kolumny );
    Matrix dodawana( kolumny , wiersze);
    Matrix odejmowana( kolumny , wiersze);
    Matrix mnozona( kolumny );

    /////Usawianie wartosci macierzy za pomoca set innymi wartosciami niz 0/////

    for(int i = 1; i <= wiersze; i++)
    {
        for(int j = 1; j <= kolumny; j++)
        {
            test.set( i, j, rand()%10);
            dodawana.set( i, j, rand()%10);
            odejmowana.set( i, j, rand()%10);
        }
    }

    for(int i = 1; i <= kolumny; i++)
    {
        for(int j = 1; j <= kolumny; j++)
        {
            mnozona.set( i, j, rand()%10);
            kwadrat.set( i, j, rand()%10);
        }
    }
      
    ////wyswietla macierz test i wypisuje kolumny i wiersze////
    cout << "macierz test:\n";
    test.print();
    cout << "ilosc wierszy:" << test.rows() << endl;
    cout << "ilosc kolumn:" << test.cols() << endl;

    ////wyswietla macierz kwadrat i wypisuje kolumny i wiersze////
    cout << "\nmacierz kwadrat:\n";
    kwadrat.print();
    cout << "ilosc wierszy:" << kwadrat.rows() << endl;
    cout << "ilosc kolumn:" << kwadrat.cols() << endl;

    cout << endl;
    ////pobiera przykladowa wartisc z danej komorki macierzy test oraz kwadrat i wyswietla ta wartosc////
    cout << "wartosc wskazanej komorki macierzy test: " << test.get(2 , 3) << endl;
    cout << "wartosc wskazanej komorki macierzy kwadrat: " << kwadrat.get(3 , 1) << endl;

    ////dodaje macierz test do macierzy dodawana i wyswietla wynik////
    cout << "\nmacierz dodawana:\n";
    test.add(dodawana).print();

    ////odejmuje od macierzy test macierz odejmowana i wyswietla wynik////
    cout << "\nmacierz odejmowania:\n";
    test.subtract(odejmowana).print();

    ////mnoży i wyswietla wynik/////
    cout << "\nMnozone macierze:\n" << "macierz1:\n";
    mnozona.print();
    cout << "macierz2:\n";
    kwadrat.print();
    cout << "\nwynik mnozenia macierz1 x macierz2:\n";
    kwadrat.multiply(mnozona).print();

    //////UWAGA! aby plik zapisał się prawidłowo należy podać swoją nazwę użytkownika w ścieżce poniżej, lub //////
    //////       jeżeli chcemy żeby plik nie zapisywał się na pulpicie to podać własną ścieżkę               //////

    #define sciezka "C:\\Users\\**tutaj prosze podac nazwe uzytkownika**\\Desktop\\Lab3\\"
    
    //////zapis do pliku///////
    test.store("macierz.txt", sciezka );

    //////konstrukcja macierzy z pliku//////
    cout << "\nMacierz skonstruowana z pliku.txt:\n";
    Matrix z_pliku( sciezka "z_pliku.txt");
    z_pliku.print();

    getch();
    return 0;
}
