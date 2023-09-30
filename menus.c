/*
            CURSO MASTERMIND

        TAREA: Buscador De Conocimiento
        
    Funcionamiento: Se trata de una aplicacion para el guardado y la ordenacion de archivos
                    segun su extension,con las caracteristicas de Año\extension\titulo\contenido
                    permitiendo eliminar y modificar los archivos*/

//Inclusiones a librerias propias
#include "menus.h"
//Inclusiones a librerias externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

//Menu de comienzo
void MenuInicial(struct Archivo *archivos, int *numArchivos) {
    int opcion;
    do {
        printf("--LIBRERIA DE ARCHIVOS--\n");
        printf("\n1. Ingresar archivos\n");
        printf("2. Ver archivos\n");
        printf("3. Modificar o eliminar archivos\n");
        printf("4. Salir\n");
        printf("\nElija un numero: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                LimpiarConsola();//Borrar datos de la consola
                //Agregar archivos
                MenuAgregarArchivos(archivos, numArchivos);
                break;
            case 2:
                LimpiarConsola();//Borrar datos de la consola
                //Ver archivos
                MenuVerArchivos(archivos, numArchivos);
                break;
            case 3:
                LimpiarConsola();//Borrar datos de la consola
                //Modificar o Eliminar
                MenuModificarEliminarArchivos(archivos, numArchivos);
                break;
            case 4:
                LimpiarConsola();//Borrar datos de la consola
                // Guardar datos en archivo antes de finalizar el programa
                GuardarDatosEnArchivo(archivos, numArchivos);
                printf("Hasta Pronto!!\n");
                exit(0);
            default:
                LimpiarConsola();//Borrar datos de la consola
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);
}



//Menu para agregar archivos segun sus extensiones
void MenuAgregarArchivos(struct Archivo *archivos, int *numArchivos) {
 if (*numArchivos >= MAX_ARCHIVOS) {
        printf("\nLa lista de archivos esta llena. No se pueden agregar mas archivos.\n");
        return;
    }

    // Limpiar el búfer del teclado correctamente
    int salto;
    while ((salto = getchar()) != '\n' && salto != EOF);

    printf("Elija la extension del archivo:\n");
    printf("\n1. txt\n");
    printf("2. pdf\n");
    printf("3. jpg\n");
    printf("4. doc\n");
    printf("5. Otro\n");
    printf("6. Volver al menu inicial\n");
    printf("\nElija un numero: ");
    int opcion;
    if (scanf("%d", &opcion) != 1) {
        LimpiarConsola();
        printf("Opcion no valida. Ingrese un numero.\n");
        return;
    }

    switch (opcion) {
        //Agrega archivos segun la extension elegida
        case 1:
            LimpiarConsola();//Borrar datos de la consola
            strcpy(archivos[*numArchivos].extension, "txt");     
            break;
        case 2:
            LimpiarConsola();//Borrar datos de la consola
            strcpy(archivos[*numArchivos].extension, "pdf");
            break;
        case 3:
            LimpiarConsola();//Borrar datos de la consola
            strcpy(archivos[*numArchivos].extension, "jpg");
            break;
        case 4:
            LimpiarConsola();//Borrar datos de la consola
            strcpy(archivos[*numArchivos].extension, "doc");
            break;

        //Agrega archivos con extensiones diferentes a las anteriores
        case 5:
            LimpiarConsola();//Borrar datos de la consola
            printf("Ingrese la extension personalizada (sin punto): ");
            scanf("%9s", archivos[*numArchivos].extension);
            break;

        //Volver al menuInicial
        case 6:
            LimpiarConsola();//Borrar datos de la consola
            MenuInicial(archivos, numArchivos);

        //Reinicia el bucle si no es valida
        default:
            LimpiarConsola();//Borrar datos de la consola
            printf("Opcion no valida.\n");
            return;
    }
    //Ingresar Título
    printf("Ingrese el titulo: ");
    char caracterLeido;  // Variable para almacenar el carácter leído

    // Limpiar el búfer del teclado
    while ((caracterLeido = getchar()) != '\n' && caracterLeido != EOF);

    // Leer el título y verificar que no esté en blanco
    do {
        if (scanf("%99[^\n]", archivos[*numArchivos].titulo) != 1) {
            printf("Ingrese el titulo: ");
            // Limpiar el búfer del teclado
            while ((caracterLeido = getchar()) != '\n' && caracterLeido != EOF);
        } else {
            if (archivos[*numArchivos].titulo[0] == '\0') {
                printf("El titulo no puede estar en blanco. Por favor, ingrese un titulo.\n");
                // Limpiar el búfer del teclado
                while ((caracterLeido = getchar()) != '\n' && caracterLeido != EOF);
            } else {
                // Verificar si el título ya existe
                int tituloRepetido = 0;
                for (int i = 0; i < *numArchivos; i++) {
                    if (strcmp(archivos[i].titulo, archivos[*numArchivos].titulo) == 0) {
                        tituloRepetido = 1;
                        break;
                    }
                }

                if (tituloRepetido) {
                    printf("El titulo '%s' ya existe. Ingrese otro titulo.\n", archivos[*numArchivos].titulo);
                } else {
                    break;
                }
            }
        }
    } while (1);


    //Ingresar Contenido
    printf("Ingrese el contenido (hasta 1000 caracteres):\n");
    scanf(" %[^\n]", archivos[*numArchivos].contenido);

    //Ingresar año
    // Validar que el año contenga solo números y repita hasta que se ingresen 4 números.
    char anoInput[10];
    int numerosIngresados = 0;
     do {
        printf("Ingrese el ano de creacion (4 digitos numericos): ");
        if (scanf("%4d", &archivos[*numArchivos].anoCreacion) != 1) {
            LimpiarConsola(); // Borrar datos de la consola
            printf("Ano de creacion no valido. Debe contener solo numeros.\n");
            scanf("%*[^\n]");  // Limpiar el buffer de entrada
        } else {
            int salto;
            while ((salto = getchar()) != '\n' && salto != EOF);  // Limpiar el buffer de entrada
        }

        if (archivos[*numArchivos].anoCreacion < 1000 || archivos[*numArchivos].anoCreacion > 9999) {
            LimpiarConsola(); // Borrar datos de la consola
            printf("Ano de creacion debe contener exactamente 4 numeros.\n");
        }
    } while (archivos[*numArchivos].anoCreacion < 1000 || archivos[*numArchivos].anoCreacion > 9999);

    
    (*numArchivos)++; // Incrementa el contador de archivos
    LimpiarConsola();  // Borrar datos de la consola
}




//Menu para revisar archivos segun sus extensiones
void MenuVerArchivos(struct Archivo *archivos, int *numArchivos) {
    int opcion;
    printf("\n-- Menu Ver Archivos --\n");
    printf("\n1. Ver archivos .txt\n");
    printf("2. Ver archivos .pdf\n");
    printf("3. Ver archivos .jpg\n");
    printf("4. Ver archivos .doc\n");
    printf("5. Ver archivos personalizados\n");
    printf("6. Volver al menu principal\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        //Revisar archivos segun las extensiones
        case 1:
            LimpiarConsola();//Borrar datos de la consola
            MostrarArchivosPorExtension(archivos, *numArchivos, "txt");
            break;
        case 2:
            LimpiarConsola();//Borrar datos de la consola
            MostrarArchivosPorExtension(archivos, *numArchivos, "pdf");
            break;
        case 3:
            LimpiarConsola();//Borrar datos de la consola
            MostrarArchivosPorExtension(archivos, *numArchivos, "jpg");
            break;
        case 4:
            LimpiarConsola();//Borrar datos de la consola
            MostrarArchivosPorExtension(archivos, *numArchivos, "doc");
            break;

        //Revisar archivos con extensiones diferentes a las anteriores
        case 5:
            LimpiarConsola();//Borrar datos de la consola
            MostrarArchivosPorExtensionPersonalizada(archivos, *numArchivos);
            break;

        //Regresar al MenuInicial
        case 6:
            LimpiarConsola();//Borrar datos de la consola
            printf("Volviendo al Menu Principal...\n");
            break;

        //Repetir el bucle
        default:
            LimpiarConsola();//Borrar datos de la consola
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
    }
}


//Menu para modificar o eliminar archivos
void MenuModificarEliminarArchivos(struct Archivo *archivos, int *numArchivos) {
    int opcion;
    printf("\n-- Menu Modificar/Eliminar Archivos --\n");
    printf("\n1. Modificar un archivo\n");
    printf("2. Eliminar un archivo\n");
    printf("3. Volver al menu principal\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        //Modificar archivos
        case 1:
            LimpiarConsola();//Borrar datos de la consola
            ModificarArchivo(archivos, numArchivos);
            break;

        //Eliminar archivos
        case 2:
            LimpiarConsola();//Borrar datos de la consola
            EliminarArchivo(archivos, numArchivos);
            break;

        //Volver al MenuInicial
        case 3:
            LimpiarConsola();//Borrar datos de la consola
            printf("Volviendo al Menu Principal...\n");
            break;

        //Repetir bucle
        default:
            LimpiarConsola();//Borrar datos de la consola
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
    }
}



