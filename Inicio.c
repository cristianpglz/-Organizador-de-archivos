/*
            CURSO MASTERMIND

        TAREA: Buscador De Conocimiento
        
    Funcionamiento: Se trata de una aplicacion para el guardado y la ordenacion de archivos
                    segun su extension,con las caracteristicas de Año\extension\titulo\contenido
                    permitiendo eliminar y modificar los archivos
*/

//Inclusiones a librerias propias
#include "archivos.h"
#include "menus.h"
//Inclusiones a librerias externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int numArchivos = 0;
    struct Archivo archivos[MAX_ARCHIVOS];

    // Cargar datos desde archivo al inicio del programa
    CargarDatosDesdeArchivo(archivos, &numArchivos);

    // Llamar al menú principal
    MenuInicial(archivos, &numArchivos);


    
    return 0;
}
