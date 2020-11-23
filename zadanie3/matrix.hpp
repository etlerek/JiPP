#include <iostream>

using namespace std;

class Matrix
{
    private:
    double **macierz;
    int K;
    int W;

    public:
    Matrix(int k, int w);
    Matrix(int k);
    void set(int m, int n, double val);
    double get(int m, int n);
    Matrix add(Matrix m2);
    Matrix subtract(Matrix m2);
    Matrix multiply(Matrix m2);
    int cols();
    int rows();
    void print();
    void store(string filename, string path);
    Matrix(string path);
};
