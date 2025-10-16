#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    cout << "Programa de ordenamientos y metodos de busqueda" << endl;

    int tamano;
    cout << "Introduce el tamano del arreglo: ";
    cin >> tamano;

    if (tamano <= 0) {
        cout << "El tamano debe ser un numero positivo." << endl;
        return 1;
    }

    int* miArreglo = new int[tamano];

    llenarArreglo(miArreglo, tamano);
    cout << "\nArreglo generado aleatoriamente:" << endl;
    mostrarArreglo(miArreglo, tamano);

    int valorABuscar;
    cout << "\nIntroduce el valor a buscar: ";
    cin >> valorABuscar;

    double tiempoSec = busquedaSecuencial(miArreglo, tamano, valorABuscar);
    double tiempoBin = busquedaBinaria(miArreglo, tamano, valorABuscar);

    ResultadosOrdenamiento resBur = ordenamientoBurbuja(miArreglo, tamano);
    ResultadosOrdenamiento resSel = ordenamientoSeleccion(miArreglo, tamano);
    ResultadosOrdenamiento resIns = ordenamientoInsercion(miArreglo, tamano);

    mostrarResultados(tiempoSec, tiempoBin, resBur, resSel, resIns, tamano);

    delete[] miArreglo;

    return 0;
}