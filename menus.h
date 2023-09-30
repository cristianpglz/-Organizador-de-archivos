/*
            CURSO MASTERMIND

        TAREA: Buscador De Conocimiento
        
    Funcionamiento: Se trata de una aplicacion para el guardado y la ordenacion de archivos
                    segun su extension,con las caracteristicas de Año\extension\titulo\contenido
                    permitiendo eliminar y modificar los archivos*/

#ifndef MENUS_H
//Definiciones
#define MENUS_H

//Inclusiones a librerias propias
#include "archivos.h"

//Estructura de los Menus
void MenuInicial(struct Archivo *archivos, int *numArchivos);
void MenuAgregarArchivos(struct Archivo *archivos, int *numArchivos);
void MenuVerArchivos(struct Archivo *archivos, int *numArchivos);
void MenuModificarEliminarArchivos(struct Archivo *archivos, int *numArchivos);

#endif
