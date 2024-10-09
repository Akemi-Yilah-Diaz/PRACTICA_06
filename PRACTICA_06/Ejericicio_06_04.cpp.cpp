/* 
// Materia: Programación I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creación: 08/10/2024
// Número de ejercicio: 4
// Problema planteado:Generar la matriz para un orden nxn
Sea n=5
1 2 3 4 5
3 4 5 6 7
5 6 7 8 9
7 8 9 10 11
9 10 11 12 13
*/
#include <iostream>
using namespace std;

void llenarMatriz(int** matriz, int filas, int columnas)
{
    int impar = 1;
    int par = 2;

    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++)
        {
            if (j % 2 == 0) {
                matriz[i][j] = impar;
                impar += 2;
            } else {
                matriz[i][j] = par;
                par += 2;
            }
        }
    }
}

void mostrarMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int filas, columnas;
    
    cout << "Introduce el número de filas ";
    cin >> filas;
    cout << "Introduce el número de columnas ";
    cin >> columnas;

    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++)
        matriz[i] = new int[columnas];

    llenarMatriz(matriz, filas, columnas);
    mostrarMatriz(matriz, filas, columnas);
    
    for (int i = 0; i < filas; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}
