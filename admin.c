// Modulo ADMIN para gestion de usuarios

#include "admin.h"

#include "admin_usuarios.c"
#include "admin_vehiculos.c"
#include "admin_viajes.c"
#include "admin_incidencias.c"


void administrador()
{
    int opcion;
    do {
    clrscr();
    printf("*************************************************************\n");
    printf("Bienvenido ADMINISTRADOR\n\n");
    printf("1. Gestion de USUARIOS\n");
    printf("2. Gestion de VEHICULOS\n");
    printf("3. Gestion de VIAJES\n");
    printf("4. Gestion de INCIDENCIAS\n");
    printf("0. Salir del modulo ADMINISTRADOR\n\n");
    printf("Introduzca una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);} while (opcion<0 || opcion>4);

    switch (opcion)
    {
        case 1: admin_usuarios(); getchar(); break;
            /*1. Usuarios. Permitirá al administrador gestionar los usuarios del sistema
            pudiendo dar de alta, baja, modificar y listar usuarios. Al listar los usuarios
            se permitirá ver el número de incidencias que recaen sobre los mismos. El
            administrador será el único que podrá bloquear manualmente a un usuario
            debido a las incidencias registradas. No se tendrán en cuenta las
            incidencias ya cerradas.*/

        case 2: admin_vehiculos(); getchar(); break;
            /*2. Vehículos. Permitirá al administrador gestionar todos los vehículos del
            sistema pudiendo dar de alta, baja, modificar y listar vehículos. Se dará la
            posibilidad de, dado un vehículo concreto, mostrar la lista de todos los
            viajes realizados.*/

        case 3: admin_viajes (); getchar(); break;
            /*3. Viajes. Permitirá al administrador gestionar todos los viajes. Podrá
            publicar, eliminar, modificar y listar viajes.*/

        case 4: admin_incidencias (); getchar(); break;
            /*4. Incidencias. Permitirá al administrador gestionar todas las incidencias del
            sistema pudiendo crear, eliminar, modificar y listar las mismas. El sistema
            le dará la opción de validar las incidencias, una vez comprobada su
            veracidad. El administrador debe bloquear manualmente a un usuario con
            tres incidencias validadas.*/

        case 0: break; //No hace nada, y regresamos al menu principal//
    }
}

