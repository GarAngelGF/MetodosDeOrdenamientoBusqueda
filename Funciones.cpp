#include "Funciones.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <vector>
#include <iomanip>

using namespace std;

void llenarArreglo(int arreglo[], int tamano) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000);
    for (int i = 0; i < tamano; ++i) {
        *(arreglo + i) = distrib(gen);
    }
}

void mostrarArreglo(const int arreglo[], int tamano) {
    cout << "[ ";
    for (int i = 0; i < tamano; ++i) {
        cout << arreglo[i] << (i == tamano - 1 ? "" : ", ");
    }
    cout << " ]" << endl;
}
double busquedaSecuencial(const int arreglo[], int tamano, int valor) {
    clock_t inicio = clock();

    bool encontrado = false;
    for (int i = 0; i < tamano; ++i) {
        if (*(arreglo + i) == valor) {
            encontrado = true;
            cout << "\n[Busqueda Secuencial] Valor " << valor << " encontrado en la posicion " << i << "." << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "\n[Busqueda Secuencial] Valor " << valor << " no encontrado." << endl;
    }

    clock_t fin = clock();
    return double(fin - inicio) / CLOCKS_PER_SEC;
}

double busquedaBinaria(const int arreglo[], int tamano, int valor) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    sort(arregloCopia.begin(), arregloCopia.end());

    clock_t inicio = clock();

    int izquierda = 0, derecha = tamano - 1;
    bool encontrado = false;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arregloCopia[medio] == valor) {
            cout << "\n[Busqueda Binaria] Valor " << valor << " encontrado en la posicion " << medio << " (del arreglo ordenado)." << endl;
            encontrado = true;
            break;
        }
        if (arregloCopia[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    if (!encontrado) {
        cout << "\n[Busqueda Binaria] Valor " << valor << " no encontrado." << endl;
    }

    clock_t fin = clock();
    return double(fin - inicio) / CLOCKS_PER_SEC;
}


double ordenamientoBurbuja(const int arreglo[], int tamano) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    int* ptrArreglo = arregloCopia.data();
    clock_t inicio = clock();
    for (int i = 0; i < tamano - 1; ++i) {
        for (int j = 0; j < tamano - i - 1; ++j) {
            if (*(ptrArreglo + j) > *(ptrArreglo + j + 1)) {
                swap(*(ptrArreglo + j), *(ptrArreglo + j + 1));
            }
        }
    }
    clock_t fin = clock();
    cout << "\n--- Ordenamiento Burbuja ---" << endl;
    cout << "Arreglo ordenado: ";
    mostrarArreglo(ptrArreglo, tamano);
    return double(fin - inicio) / CLOCKS_PER_SEC;
}

double ordenamientoSeleccion(const int arreglo[], int tamano) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    int* ptrArreglo = arregloCopia.data();
    clock_t inicio = clock();
    for (int i = 0; i < tamano - 1; ++i) {
        int* min_idx = ptrArreglo + i;
        for (int j = i + 1; j < tamano; ++j) {
            if (*(ptrArreglo + j) < *min_idx) min_idx = ptrArreglo + j;
        }
        swap(*(ptrArreglo + i), *min_idx);
    }
    clock_t fin = clock();
    cout << "\n--- Ordenamiento por Seleccion ---" << endl;
    cout << "Arreglo ordenado: ";
    mostrarArreglo(ptrArreglo, tamano);
    return double(fin - inicio) / CLOCKS_PER_SEC;
}

double ordenamientoInsercion(const int arreglo[], int tamano) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    int* ptrArreglo = arregloCopia.data();
    clock_t inicio = clock();
    for (int i = 1; i < tamano; ++i) {
        int key = *(ptrArreglo + i);
        int j = i - 1;
        while (j >= 0 && *(ptrArreglo + j) > key) {
            *(ptrArreglo + j + 1) = *(ptrArreglo + j);
            j = j - 1;
        }
        *(ptrArreglo + j + 1) = key;
    }
    clock_t fin = clock();
    cout << "\n--- Ordenamiento por Insercion ---" << endl;
    cout << "Arreglo ordenado: ";
    mostrarArreglo(ptrArreglo, tamano);
    return double(fin - inicio) / CLOCKS_PER_SEC;
}

void mostrarResultados(
    double tiempoSecuencial, double tiempoBinario,
    double tiempoBurbuja, double tiempoSeleccion, double tiempoInsercion,
    int tamano) {
    cout << "\n\n==========================================" << endl;
    cout << "      RESUMEN DE TIEMPOS DE EJECUCION" << endl;
    cout << "==========================================" << endl;
    cout << " Tamano del arreglo: " << tamano << " elementos." << endl;
    cout << "------------------------------------------" << endl;
    cout << " Metodo               | Tiempo (segundos)" << endl;
    cout << "------------------------------------------" << endl;
    cout << " Busqueda Secuencial  | " << fixed << setprecision(8) << tiempoSecuencial << endl;
    cout << " Busqueda Binaria     | " << fixed << setprecision(8) << tiempoBinario << endl;
    cout << "------------------------------------------" << endl;
    cout << " Ordenamiento Burbuja | " << fixed << setprecision(8) << tiempoBurbuja << endl;
    cout << " Ordenamiento Seleccion| " << fixed << setprecision(8) << tiempoSeleccion << endl;
    cout << " Ordenamiento Insercion| " << fixed << setprecision(8) << tiempoInsercion << endl;
    cout << "------------------------------------------" << endl;
}
