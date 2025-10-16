#ifndef METODOSDEORDENAMIENTOBUSQUEDA_FUNCIONES_H
#define METODOSDEORDENAMIENTOBUSQUEDA_FUNCIONES_H

struct ResultadosOrdenamiento {
    double tiempo;
    long long comparaciones;
    long long intercambios;
};

void llenarArreglo(int arreglo[],int tamano);
void mostrarArreglo(const int arreglo[], int tamano);
double busquedaSecuencial(const int arreglo[], int tamano,int valor);
double busquedaBinaria(const int arreglo[], int tamano, int valor);
ResultadosOrdenamiento ordenamientoBurbuja(const int arreglo[], int tamano);
ResultadosOrdenamiento ordenamientoSeleccion(const int arreglo[], int tamano);
ResultadosOrdenamiento ordenamientoInsercion(const int arreglo[], int tamano);
void mostrarResultados( double tiempoSecuencial, double tiempoBinario,const ResultadosOrdenamiento& resBurbuja,const ResultadosOrdenamiento& resSeleccion,const ResultadosOrdenamiento& resInsercion,int tamano);

#endif