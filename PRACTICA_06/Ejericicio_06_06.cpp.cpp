/* 
// Materia: Programación I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creación: 08/10/2024
// Número de ejercicio: 6
// Problema planteado:Traspones una matriz de N x M
*/
#include <iostream>
using namespace std;

int main() {
    int filas, columnas;

    cout << "Introduce el número de filas y columnas de la matriz ";
    cin >> filas >> columnas;

    int matriz[filas][columnas], transpuesta[columnas][filas];

    cout << "Llena la matriz" << endl;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            cin >> matriz[i][j];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            transpuesta[j][i] = matriz[i][j];

    cout << "Matriz transpuesta" << endl;
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++)
            cout << transpuesta[i][j] << " ";
        cout << endl;
    }

    return 0;
}
