#ifndef METODOSDEORDENAMIENTOBUSQUEDA_FUNCIONES_H
#define METODOSDEORDENAMIENTOBUSQUEDA_FUNCIONES_H


void llenarArreglo(int arreglo[],int tamano);
void mostrarArreglo(const int arreglo[], int tamano);
double busquedaSecuencial(const int arreglo[], int tamano,int valor);
double busquedaBinaria(const int arreglo[], int tamano, int valor);
double ordenamientoBurbuja(const int arreglo[], int tamano);
double ordenamientoSeleccion(const int arreglo[], int tamano);
double ordenamientoInsercion(const int arreglo[], int tamano);
void mostrarResultados( double tiempoSecuencial, double tiempoBinario,double tiempoBurbuja, double tiempoSeleccion, double tiempoInsercion,int tamano);


#endif