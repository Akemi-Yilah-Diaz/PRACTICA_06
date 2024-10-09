/* 
// Materia: Programación I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creación: 08/10/2024
// Número de ejercicio: 3
// Problema planteado: En la segunda temporada de The Walking Dead, los personajes llegaron a una
cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos
vivientes no podían entrar en ella. Sin embargo, dentro de las instalaciones aun
existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
otros miembros del grupo decidieron ir a investigar las instalaciones con el fin de
determinar cuáles eran los lugares seguros. Para lograr su objetivo construyeron
un mapa basado en una matriz que indicaba las zonas seguras. Después de un
tiempo, tu grupo llega al mismo complejo y encuentra el mapa hecho por Rick.
Para mantener a salvo a tus amigos decides diseñar e implementar un programa
que te ayude a determinar las zonas seguras.
Tu trabajo es determinar los siguientes datos:
a) Mostrar la matriz que describe el área.
b) Mostrar el número de filas y columnas que no tienen un muerto viviente.
c) Determinar las coordenadas de los muertos vivientes en la matriz. Utilice
vectores paralelos para almacenar la posición de los muertos vivientes. Un
vector almacenara el índice de la fila y otro vector almacenara el índice de la
columna.
d) La cantidad de muertos vivientes que existen en toda la matriz.
e) Determinar si dos o más muertos vivientes se encuentran en la primera
columna. Si es así imprimir “no es posible entrar al complejo” de otro modo
imprimir “es posible entrar al complejo”.
NOTA 1.- INICIALIZE LA SIGUIENTE MATRIZ COMO CONSTANTE PARA PROBAR
SU PROGRAMA
x o x o
o o o o
o o x o
Las "o" describen lugares seguros mientras que las "x" describen los lugares
con un muerto viviente.
NOTA 2.- AYUDA --> PUEDE DECLARAR DOS VARIABLES GLOBALES
CONSTANTES PARA DETERMINAR EL TAMANO DE LA MATRIZ
NOTA 3.- CADA INCISO DEBE SER RESUELTO CON UNA FUNCION
ESTRICTAMENTE, EXCEPTO EL ULTIMO INCISO QUE NO REQUIERE DE UNA
FUNCION.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(char** matriz, int filas, int columnas) {
    vector<char> elementos = {'o', 'x'};
    srand(time(0));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = elementos[rand() % 2];
        }
    }
}

void mostrarMatriz(char** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void contarZonasSeguras(int filas, int columnas, int& filasSeguras, int& columnasSeguras, char** matriz) {
    filasSeguras = columnasSeguras = 0;
    for (int i = 0; i < filas; i++) {
        bool filaSegura = true;
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 'x') { filaSegura = false; break; }
        }
        if (filaSegura) filasSeguras++;
    }
    for (int j = 0; j < columnas; j++) {
        bool columnaSegura = true;
        for (int i = 0; i < filas; i++) {
            if (matriz[i][j] == 'x') { columnaSegura = false; break; }
        }
        if (columnaSegura) columnasSeguras++;
    }
}

void encontrarMuertosVivientes(vector<int>& filas, vector<int>& columnas, char** matriz, int filasTotales, int columnasTotales) {
    for (int i = 0; i < filasTotales; i++) {
        for (int j = 0; j < columnasTotales; j++) {
            if (matriz[i][j] == 'x') {
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }
}

int contarTotalMuertosVivientes(char** matriz, int filas, int columnas) {
    int contador = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 'x') contador++;
        }
    }
    return contador;
}

int main() {
    int filas, columnas;
    
    cout << "Introduce el número de filas";
    cin >> filas;
    cout << "Introduce el número de columnas ";
    cin >> columnas;

    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++)
        matriz[i] = new char[columnas];

    llenarMatriz(matriz, filas, columnas);
    mostrarMatriz(matriz, filas, columnas);
    
    int filasSeguras, columnasSeguras;
    contarZonasSeguras(filas, columnas, filasSeguras, columnasSeguras, matriz);
    cout << "Filas seguras " << filasSeguras << endl;
    cout << "Columnas seguras " << columnasSeguras << endl;

    vector<int> filasMuertos, columnasMuertos;
    encontrarMuertosVivientes(filasMuertos, columnasMuertos, matriz, filas, columnas);
    
    cout << "Coordenadas de los muertos vivientes" << endl;
    for (size_t i = 0; i < filasMuertos.size(); i++) {
        cout << "(" << filasMuertos[i] << ", " << columnasMuertos[i] << ")" << endl;
    }

    int totalMuertos = contarTotalMuertosVivientes(matriz, filas, columnas);
    cout << "Cantidad de zombies " << totalMuertos << endl;

    int muertosEnPrimeraColumna = 0;
    for (int i = 0; i < filas; i++) {
        if (matriz[i][0] == 'x') muertosEnPrimeraColumna++;
    }

    if (muertosEnPrimeraColumna >= 2)
        cout << "No es posible entrar al complejo" << endl;
    else
        cout << "Es posible entrar al complejo" << endl;

    for (int i = 0; i < filas; i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}
