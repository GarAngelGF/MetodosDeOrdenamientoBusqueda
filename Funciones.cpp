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
    uniform_int_distribution<> distrib(1, 100);
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


ResultadosOrdenamiento ordenamientoBurbuja(const int arreglo[], int tamano) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    int* ptrArreglo = arregloCopia.data();
    ResultadosOrdenamiento res = {0.0, 0, 0};

    clock_t inicio = clock();
    for (int i = 0; i < tamano - 1; ++i) {
        for (int j = 0; j < tamano - i - 1; ++j) {
            res.comparaciones++; // Se cuenta la comparación
            if (*(ptrArreglo + j) > *(ptrArreglo + j + 1)) {
                swap(*(ptrArreglo + j), *(ptrArreglo + j + 1));
                res.intercambios++; // Se cuenta el intercambio
            }
        }
    }
    clock_t fin = clock();
    res.tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "\n--- Ordenamiento Burbuja ---" << endl;
    cout << "Arreglo ordenado: ";
    mostrarArreglo(ptrArreglo, tamano);
    return res;
}

ResultadosOrdenamiento ordenamientoSeleccion(const int arreglo[], int tamano) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    int* ptrArreglo = arregloCopia.data();
    ResultadosOrdenamiento res = {0.0, 0, 0};

    clock_t inicio = clock();
    for (int i = 0; i < tamano - 1; ++i) {
        int* min_idx_ptr = ptrArreglo + i;
        for (int j = i + 1; j < tamano; ++j) {
            res.comparaciones++; // Se cuenta la comparación
            if (*(ptrArreglo + j) < *min_idx_ptr) {
                min_idx_ptr = ptrArreglo + j;
            }
        }
        if (min_idx_ptr != (ptrArreglo + i)) { // Solo intercambia si encontró un mínimo diferente
            swap(*(ptrArreglo + i), *min_idx_ptr);
            res.intercambios++; // Se cuenta el intercambio
        }
    }
    clock_t fin = clock();
    res.tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "\n--- Ordenamiento por Seleccion ---" << endl;
    cout << "Arreglo ordenado: ";
    mostrarArreglo(ptrArreglo, tamano);
    return res;
}

ResultadosOrdenamiento ordenamientoInsercion(const int arreglo[], int tamano) {
    vector<int> arregloCopia(arreglo, arreglo + tamano);
    int* ptrArreglo = arregloCopia.data();
    ResultadosOrdenamiento res = {0.0, 0, 0};

    clock_t inicio = clock();
    for (int i = 1; i < tamano; ++i) {
        int key = *(ptrArreglo + i);
        int j = i - 1;
        while (j >= 0 && (++res.comparaciones, *(ptrArreglo + j) > key)) {
            *(ptrArreglo + j + 1) = *(ptrArreglo + j);
            res.intercambios++; // Esto es un desplazamiento, no un swap completo, pero se cuenta como movimiento
            j = j - 1;
        }
        *(ptrArreglo + j + 1) = key;
        res.intercambios++; // Colocación final de la llave
    }
    clock_t fin = clock();
    res.tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "\n--- Ordenamiento por Insercion ---" << endl;
    cout << "Arreglo ordenado: ";
    mostrarArreglo(ptrArreglo, tamano);
    return res;
}

void mostrarResultados(
    double tiempoSecuencial, double tiempoBinario,
    const ResultadosOrdenamiento& resBurbuja,
    const ResultadosOrdenamiento& resSeleccion,
    const ResultadosOrdenamiento& resInsercion,
    int tamano) {
    cout << "\n\n========================================================================" << endl;
    cout << "                    RESUMEN DE TIEMPOS Y OPERACIONES" << endl;
    cout << "========================================================================" << endl;
    cout << " Tamano del arreglo: " << tamano << " elementos." << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << left << setw(22) << " Metodo" << " | "
         << left << setw(18) << " Tiempo (segundos)" << " | "
         << left << setw(15) << " Comparaciones" << " | "
         << left << setw(15) << " Intercambios" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << left << setw(22) << " Busqueda Secuencial" << " | "
         << left << setw(18) << fixed << setprecision(8) << tiempoSecuencial << " | "
         << left << setw(15) << "N/A" << " | "
         << left << setw(15) << "N/A" << endl;
    cout << left << setw(22) << " Busqueda Binaria" << " | "
         << left << setw(18) << fixed << setprecision(8) << tiempoBinario << " | "
         << left << setw(15) << "N/A" << " | "
         << left << setw(15) << "N/A" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << left << setw(22) << " Ordenamiento Burbuja" << " | "
         << left << setw(18) << fixed << setprecision(8) << resBurbuja.tiempo << " | "
         << left << setw(15) << resBurbuja.comparaciones << " | "
         << left << setw(15) << resBurbuja.intercambios << endl;
    cout << left << setw(22) << " Ordenamiento Seleccion" << " | "
         << left << setw(18) << fixed << setprecision(8) << resSeleccion.tiempo << " | "
         << left << setw(15) << resSeleccion.comparaciones << " | "
         << left << setw(15) << resSeleccion.intercambios << endl;
    cout << left << setw(22) << " Ordenamiento Insercion" << " | "
         << left << setw(18) << fixed << setprecision(8) << resInsercion.tiempo << " | "
         << left << setw(15) << resInsercion.comparaciones << " | "
         << left << setw(15) << resInsercion.intercambios << endl;
    cout << "------------------------------------------------------------------------" << endl;
}
