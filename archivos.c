/*
            CURSO MASTERMIND

        TAREA: Buscador De Conocimiento
        
    Funcionamiento: Se trata de una aplicacion para el guardado y la ordenacion de archivos
                    segun su extension,con las caracteristicas de Año\extension\titulo\contenido
                    permitiendo eliminar y modificar los archivos*/

//Inclusiones a librerias propias
#include "archivos.h"
#include "menus.h"
//Inclusiones a librerias externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcion para Mostrar archivos segun su extension
void MostrarArchivosPorExtension(struct Archivo *archivos, int numArchivos, const char *extension) {
    LimpiarConsola();//Borrar datos de la consola
    printf("Archivos con extension '%s':\n", extension);

    for (int indiceArchivo = 0; indiceArchivo < numArchivos; indiceArchivo++) {
        if (strcmp(archivos[indiceArchivo].extension, extension) == 0) {
            printf("\nTitulo: %s\n", archivos[indiceArchivo].titulo);
            printf("Extension: %s\n", archivos[indiceArchivo].extension);
            printf("Contenido: %s\n", archivos[indiceArchivo].contenido);
            printf("Ano de creacion: %d\n", archivos[indiceArchivo].anoCreacion);
        }
    }
//Pausar y preguntar
PausaParaContinuar(archivos, &numArchivos);
}


//Funcion para Mostrar archivos diferentes a las extensiones predefinidas
void MostrarArchivosPorExtensionPersonalizada(struct Archivo *archivos, int numArchivos) {
  LimpiarConsola();//Borrar datos de la consola
  printf("Archivos personalizados:\n"); // Imprime el mensaje de que se van a mostrar archivos personalizados

    for (int indiceArchivo = 0; indiceArchivo < numArchivos; indiceArchivo++) {
        // Comprueba si la extensión no es una de las predefinidas
        if (strcmp(archivos[indiceArchivo].extension, "") != 0 &&
            strcmp(archivos[indiceArchivo].extension, "txt") != 0 &&
            strcmp(archivos[indiceArchivo].extension, "pdf") != 0 &&
            strcmp(archivos[indiceArchivo].extension, "jpg") != 0 &&
            strcmp(archivos[indiceArchivo].extension, "doc") != 0) {
            printf("\nTitulo: %s\n", archivos[indiceArchivo].titulo); // Imprime el título del archivo
            printf("Extension: %s\n", archivos[indiceArchivo].extension); // Imprime la extensión del archivo
            printf("Contenido: %s\n", archivos[indiceArchivo].contenido); // Imprime el contenido del archivo
            printf("Ano de creacion: %d\n", archivos[indiceArchivo].anoCreacion); // Imprime el año de creación del archivo
        }
}
//Pausar y preguntar
PausaParaContinuar(archivos, &numArchivos);
}

//Funcion para Modificar Archivos
void ModificarArchivo(struct Archivo *archivos, int *numArchivos) {
    char titulo[100];
    printf("Ingrese el titulo del archivo que desea modificar: ");
    fflush(stdin);
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';  // Eliminar el carácter de nueva línea si está presente


    int encontrado = 0;
    for (int indiceArchivo = 0; indiceArchivo < *numArchivos; indiceArchivo++) {
        if (strcmp(archivos[indiceArchivo].titulo, titulo) == 0) {
            // Archivo encontrado, permite modificarlo
            LimpiarConsola();//Borrar datos de la consola


            // Modificar título
            char nuevoTitulo[100];
            printf("Nuevo titulo (deje en blanco para mantener el actual): ");
            fflush(stdin);// Eliminar el carácter de nueva línea si está presente primera opcipon
            fgets(nuevoTitulo, sizeof(nuevoTitulo), stdin);
            nuevoTitulo[strcspn(nuevoTitulo, "\n")] = '\0';  //Si sigue habiendo salto de linea esta opcion tambien la elimina

            if (nuevoTitulo[0] != '\0') {
                strcpy(archivos[indiceArchivo].titulo, nuevoTitulo);
            }

            // Modificar contenido
            char nuevoContenido[100];
            printf("Nuevo contenido (deje en blanco para mantener el actual):\n");
            fflush(stdin);// Eliminar el carácter de nueva línea si está presente primera opcipon
            fgets(nuevoContenido, sizeof(nuevoContenido), stdin);
            nuevoContenido[strcspn(nuevoContenido, "\n")] = '\0';//Si sigue habiendo salto de linea esta opcion tambien la elimina
            
            // Modificar año de creación
            char nuevoAno[4];
            printf("Nuevo ano de creacion (deje 0 para mantener el actual): ");
            fflush(stdin);// Eliminar el carácter de nueva línea si está presente primera opcipon
            fgets(nuevoAno, sizeof(nuevoAno), stdin);
            nuevoAno[strcspn(nuevoAno, "\n")] = '\0';//Si sigue habiendo salto de linea esta opcion tambien la elimina

            
            
            // Modificar extensión
            char nuevaExtension[10];
            printf("Nueva extension (deje en blanco para mantener el actual): ");
            fflush(stdin);// Eliminar el carácter de nueva línea si está presente primera opcipon
            fgets(nuevaExtension, sizeof(nuevaExtension), stdin);
            nuevaExtension[strcspn(nuevaExtension, "\n")] = '\0';//Si sigue habiendo salto de linea esta opcion tambien la elimina

            if (nuevaExtension[0] != '\0') {
                strcpy(archivos[indiceArchivo].extension, nuevaExtension);
            }
            LimpiarConsola();//Borrar datos de la consola
            printf("\nArchivo modificado exitosamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        LimpiarConsola();//Borrar datos de la consola
        printf("\nNo se encontro ningun archivo con el titulo especificado.\n");
    }
}


//Funcion para Eliminar Archivos
void EliminarArchivo(struct Archivo *archivos, int *numArchivos) {
    LimpiarConsola();//Borrar datos de la consola
    char titulo[100];
    printf("\nIngrese el titulo del archivo que desea eliminar: ");
    scanf(" %[^\n]", titulo);

  int encontrado = 0;
    for (int indiceArchivo = 0; indiceArchivo < *numArchivos; indiceArchivo++) {
        if (strcmp(archivos[indiceArchivo].titulo, titulo) == 0) {
            // Archivo encontrado, permite eliminarlo
            for (int movimientoIndex = indiceArchivo; movimientoIndex < *numArchivos - 1; movimientoIndex++) {
                // Elimina el archivo moviendo los siguientes hacia arriba en el arreglo
                strcpy(archivos[movimientoIndex].titulo, archivos[movimientoIndex + 1].titulo);
                strcpy(archivos[movimientoIndex].extension, archivos[movimientoIndex + 1].extension);
                strcpy(archivos[movimientoIndex].contenido, archivos[movimientoIndex + 1].contenido);
                archivos[movimientoIndex].anoCreacion = archivos[movimientoIndex + 1].anoCreacion;
            }
            (*numArchivos)--;
            LimpiarConsola();//Borrar datos de la consola
            printf("Archivo eliminado exitosamente.\n");

            encontrado = 1;
            break;
        }
    }
    //En caso de no encontrar archivos
    if (!encontrado) {
        LimpiarConsola();//Borrar datos de la consola
        printf("No se encontro ningun archivo con el titulo especificado.\n");
    }

    }


//Funcion para Cargar los datos dentro del archivo 
void CargarDatosDesdeArchivo(struct Archivo *archivos, int *numArchivos) {
    LimpiarConsola();//Borrar datos de la consola
    FILE *archivo = fopen("datos_almacenados.json", "rb"); // Abre el archivo "datos_almacenados.json" en modo lectura binaria
        if (archivo == NULL) {
            printf("No se pudo cargar los datos. No hay un archivo previo.\n"); // Si el archivo no se pudo abrir, imprime un mensaje y retorna
            return;
        }

        fread(numArchivos, sizeof(int), 1, archivo); // Lee el número de archivos guardado en el archivo
        fread(archivos, sizeof(struct Archivo), *numArchivos, archivo); // Lee la estructura de archivos desde el archivo

        fclose(archivo); // Cierra el archivo después de leer los datos

}


//Guarda los datos en el archivo
void GuardarDatosEnArchivo(struct Archivo *archivos, int *numArchivos) {
    LimpiarConsola();//Borrar datos de la consola
    FILE *archivo = fopen("datos_almacenados.json", "wb"); // Abre el archivo "datos_almacenados.json" en modo escritura binaria
        if (archivo == NULL) {
            printf("No se pudo guardar los datos.\n"); // Si el archivo no se pudo abrir, imprime un mensaje y retorna
            return;
        }

        fwrite(numArchivos, sizeof(int), 1, archivo); // Escribe el número de archivos en el archivo
        fwrite(archivos, sizeof(struct Archivo), *numArchivos, archivo); // Escribe la estructura de archivos en el archivo

        fclose(archivo); // Cierra el archivo después de escribir los datos

}


//Separa las extensiones predefinidar para su organizacion
int ObtenerIndiceExtension(const char *extension) {
    //Extensiones predefinidas
    if (strcmp(extension, "txt") == 0) {
        return 0;
    } else if (strcmp(extension, "pdf") == 0) {
        return 1;
    } else if (strcmp(extension, "jpg") == 0) {
        return 2;
    } else if (strcmp(extension, "doc") == 0) {
        return 3;
    } else {
        return 0;  // Extensión personalizada
    }
}


//Pausar donde sea necesario
void PausaParaContinuar(struct Archivo *archivos, int *numArchivos) {
    char respuesta;
    int continua = 1;

    while (continua) {
        printf("\nMenu inicial S/s Menu ver archivos N/n? (S/N): ");
        scanf(" %c", &respuesta);
        getchar();  // Consumir el carácter de nueva línea en el buffer

        if (respuesta == 'S' || respuesta == 's') {
            LimpiarConsola();//Borrar datos de la consola
            printf("Volviendo al menu inicial...\n");
            continua = 0;
        } 
        else if (respuesta == 'N' || respuesta == 'n') {
            LimpiarConsola();//Borrar datos de la consola
            printf("Volviendo al menu de ver archivos...\n");
            MenuVerArchivos(archivos, numArchivos);  // Llamar a la función que muestra los archivos
            continua = 0;
        } 
        else {
            LimpiarConsola();//Borrar datos de la consola
            printf("Opcion no valida. Por favor, ingrese S o N.\n");
        }
    }
}


//Limpiar la consola en cualquier Sistema
void LimpiarConsola() {
#ifdef _WIN32
    system("cls");  // Para Windows
#elif __linux__
    system("clear");  // Para Linux
#elif __APPLE__
    system("clear");  // Para macOS/iOS
#else
    // Sistema operativo no reconocido, no se limpia la consola
#endif
}

