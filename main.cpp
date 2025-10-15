#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    cout << "Programa de ordenamientos y metodos de busqueda" << endl;

    int tamano;
    cout << "Introduce el tamano del arreglo: ";
    cin >> tamano;

    // Crear el arreglo
    int* miArreglo = new int[tamano];

    llenarArreglo(miArreglo, tamano);
    cout << "\nArreglo generado aleatoriamente:" << endl;
    mostrarArreglo(miArreglo, tamano);

    int valorABuscar;
    cout << "\nIntroduce el valor a buscar: ";
    cin >> valorABuscar;

    // --- Ejecutar Búsquedas ---
    double tiempoSec = busquedaSecuencial(miArreglo, tamano, valorABuscar);
    double tiempoBin = busquedaBinaria(miArreglo, tamano, valorABuscar);

    // --- Ejecutar Ordenamientos ---
    double tiempoBur = ordenamientoBurbuja(miArreglo, tamano);
    double tiempoSel = ordenamientoSeleccion(miArreglo, tamano);
    double tiempoIns = ordenamientoInsercion(miArreglo, tamano);

    // --- Mostrar Resumen Final ---
    mostrarResultados(tiempoSec, tiempoBin, tiempoBur, tiempoSel, tiempoIns, tamano);

    // Liberar la memoria
    delete[] miArreglo;

    return 0;
}