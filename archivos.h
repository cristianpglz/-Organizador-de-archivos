/*
            CURSO MASTERMIND

        TAREA: Buscador De Conocimiento
        
    Funcionamiento: Se trata de una aplicacion para el guardado y la ordenacion de archivos
                    segun su extension,con las caracteristicas de Año\extension\titulo\contenido
                    permitiendo eliminar y modificar los archivos*/

#ifndef ARCHIVOS_H
//Definiciones
#define ARCHIVOS_H
#define MAX_ARCHIVOS 100

//Organizar archivo
struct Archivo {
    char titulo[100];
    char extension[10];
    char contenido[1000];
    int anoCreacion;
};

//Estructura para el funcionamiento de los datos y archivos
void MostrarArchivosPorExtension(struct Archivo *archivos, int numArchivos, const char *extension);
void MostrarArchivosPorExtensionPersonalizada(struct Archivo *archivos, int numArchivos);
void ModificarArchivo(struct Archivo *archivos, int *numArchivos);
void EliminarArchivo(struct Archivo *archivos, int *numArchivos);
void CargarDatosDesdeArchivo(struct Archivo *archivos, int *numArchivos);
void GuardarDatosEnArchivo(struct Archivo *archivos, int *numArchivos);
int ObtenerIndiceExtension(const char *extension);
void PausaParaContinuar(struct Archivo *archivos, int *numArchivos);
void LimpiarConsola();

#endif
