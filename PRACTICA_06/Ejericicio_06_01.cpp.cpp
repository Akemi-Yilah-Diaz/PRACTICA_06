/* 
// Materia: Programación I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creación: 08/10/2024
// Número de ejercicio: 1
// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fila
n.
Por ejemplo, si la matriz que da el usuario es:
4 7 1 3 5
2 0 6 9 7
3 1 2 6 4
Entonces el programa debe escribir la matriz:
3 1 2 6 4
2 0 6 9 7
4 7 1 3 5
*/
#include <iostream>
using namespace std;

int main() 
{
    int filas, columnas;
    cout << "Introduce el número de filas";
    cin >> filas;
    cout << "Introduce el número de columnas";
    cin >> columnas;

    int matriz[100][100];  

    cout << "Introduce numeros de la matriz fila por fila" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) 
        {
            cin >> matriz[i][j];  
        }
    }

    for (int j = 0; j < columnas; j++) 
    {
        int temp = matriz[0][j];
        matriz[0][j] = matriz[filas-1][j];
        matriz[filas-1][j] = temp;
    }


    cout << "el orden de la matriz sera" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "\t";  
        }
        cout << endl;
    }

    return 0;
}
