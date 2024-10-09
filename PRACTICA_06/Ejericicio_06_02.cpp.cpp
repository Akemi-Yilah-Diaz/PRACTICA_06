/* 
// Materia: Programación I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creación: 08/10/2024
// Número de ejercicio: 2
// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
• La suma de la última columna
• El producto total de la última fila
• Obtener el mayor valor y su posición
• Obtener la desviación estándar de todos los elementos de la matriz
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    int filas, columnas, A, B;
    cout << "Introduce el número de filas: "; cin >> filas;
    cout << "Introduce el número de columnas: "; cin >> columnas;
    cout << "Introduce el valor mínimo (A): "; cin >> A;
    cout << "Introduce el valor máximo (B): "; cin >> B;

    int matriz[100][100];
    srand(time(0));

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = A + rand() % (B - A + 1);

    cout << "Matriz generada:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }

    int sumaUltimaCol = 0, prodUltimaFila = 1, maxValor = matriz[0][0], posFilaMax = 0, posColMax = 0;
    double sumaElementos = 0, sumaCuadrados = 0;

    for (int i = 0; i < filas; i++) 
    {
        sumaUltimaCol += matriz[i][columnas - 1];
        for (int j = 0; j < columnas; j++) 
        {
            sumaElementos += matriz[i][j];
            sumaCuadrados += matriz[i][j] * matriz[i][j];
            if (matriz[i][j] > maxValor)
            {
                maxValor = matriz[i][j];
                posFilaMax = i;
                posColMax = j;
            }
        }
    }

    for (int j = 0; j < columnas; j++)
        prodUltimaFila *= matriz[filas - 1][j];

    double media = sumaElementos / (filas * columnas);
    double varianza = (sumaCuadrados / (filas * columnas)) - (media * media);
    double desviacionEstandar = sqrt(varianza);

    cout << "Suma de la última columna " << sumaUltimaCol << endl;
    cout << "Producto total de la última fila " << prodUltimaFila << endl;
    cout << "El mayor valor es " << maxValor << endl;
    cout << "Desviación estándar de todos los elementos" << desviacionEstandar << endl;

    return 0;
}
