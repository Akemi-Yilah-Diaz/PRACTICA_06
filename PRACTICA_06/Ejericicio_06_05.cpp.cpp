/* 
// Materia: Programación I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creación: 08/10/2024
// Número de ejercicio: 5
// Problema planteado:Multiplique dos matrices una de N x M y la otra de M x N
*/
#include <iostream>
using namespace std;

int main() {
    int filasA, columnasA;

    cout << "Introduce el número de filas y columnas de la primera matriz (N x M): ";
    cin >> filasA >> columnasA;

    int filasB = columnasA; 
    int columnasB;
    cout << "Introduce el número de columnas de la segunda matriz (M x N): ";
    cin >> columnasB;

    int A[filasA][columnasA], B[filasB][columnasB], C[filasA][columnasB];

    cout << "Llena la primera matriz:" << endl;
    for (int i = 0; i < filasA; i++)
        for (int j = 0; j < columnasA; j++)
            cin >> A[i][j];

    cout << "Llena la segunda matriz:" << endl;
    for (int i = 0; i < filasB; i++)
        for (int j = 0; j < columnasB; j++)
            cin >> B[i][j];

    for (int i = 0; i < filasA; i++)
        for (int j = 0; j < columnasB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < columnasA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    cout << "Resultado de la multiplicación:" << endl;
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
