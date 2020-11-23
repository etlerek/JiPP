#include <iostream>
#include <stdio.h>
#include <fstream>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix(int k, int w)
{
    if(k < 0 || w < 0)
        cout << "Blad nie mozna stworzyc takiej macierzy";
    else
    {
       K = k;
       W = w;
        macierz = new double* [w];
        for (int i=0; i < w; i++)
        {
            macierz[i] = new double [k];

            for(int j = 0; j < k; j++)
            {
                macierz[i][j] = 0;
            }
        }
    }
}

Matrix::Matrix(int k)
{
    if(k<0)
        cout << "Blad nie mozna stworzyc takiej macierzy";
    else
    {
        K = k;
        W = k;
        macierz = new double* [k];
        for(int i = 0; i < k; i++)
        {
            macierz[i] = new double [k];
            for(int j = 0; j < k; j++)
            {
                macierz[i][j] = 0; 
            }
        }
    }
}

void Matrix::set(int m, int n, double val)
{
    macierz[m - 1][n - 1] = val;
}

double Matrix::get(int m, int n)
{
    return macierz[m - 1][n - 1];
}

Matrix Matrix::add(Matrix m2)
{
    if (K == m2.K && W == m2.W)
    {
        Matrix suma(K,W);
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < W; j++)
            {
                suma.macierz[i][j] = macierz[i][j] + m2.macierz[i][j];
            }
        }

        return suma;
    }
    else
    {
        cout << "Nie da sie dodac tych macierzy\n";
        exit(0);
    }
}

Matrix Matrix::subtract(Matrix m2)
{
    if (K == m2.K && W == m2.W)
    {
        Matrix suma(K, W);

        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < W; j++)
            {
                suma.macierz[i][j] = macierz[i][j] - m2.macierz[i][j];
            }
        }

        return suma;
    }
    else
    {
        cout << "Nie da sie odjac tych macierzy\n";
        exit(0);
    }
}

Matrix Matrix::multiply(Matrix m2)
{
    if (K == m2.W)
    {
        Matrix iloczyn(K, W);

        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < W; j++)
            {
                for (int k = 0; k < K; k++)
                {
                    iloczyn.macierz[i][j] += macierz[i][k] * m2.macierz[k][j];       
                }             
            }
        }
        return iloczyn;
    }
    exit(0);
}

int Matrix::cols()
{
    return K;
}

int Matrix::rows()
{
    return W;
}

void Matrix::print()
{
    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < K; j++)
        {
            cout << macierz[i][j] << " ";
        }
    cout << endl;
    }
}

void Matrix::store(string filename, string path)
{
    fstream plik;
    plik.open(path + filename, ios::out);

    if (plik.good())
    {
        plik << " Kolumny: " << K;
        plik << " Wiersze: " << W;

        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < W; j++)
            {
                plik << " Macierz:" << endl << macierz[i][j] << " ";
            }
            cout << endl;
        }
        plik.close();
    }
    else
    {
        cout << "Error nie udalo sie otworzyc pliku";
    }   
}
/*
Matrix::Matrix(string path)
{
    fstream plik;
    plik.open(path, ios::in);

    if(plik.good())
    {

    }
    else
    {
        cout << "Error nie udalo sie otworzyc pliku";
    }
}

else
    {
        K = k;
        W = w;
        macierz = new double* [k];
        for(int i = 0; i < k; i++)
        {
            macierz[i] = new double [w];
        }

        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < w; j++)
            {
                macierz[i][j] = 0; 
            }
        }
        
    }
*/