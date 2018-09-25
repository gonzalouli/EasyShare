//Modulo Gestion ADMIN USUARIOS.C
#include "estructuras.h"
#include "auxiliar.h"
#include "ficheros.h"
#include "admin_usuarios.h"

char c, caracter, *linea, *linea2, *lineastotales;
int contador, num=-1, encontrado=0;

void admin_usuarios()
{

usuario *user=(usuario *)malloc(sizeof(usuario));
incid *inc=(incid *)malloc(sizeof(incid));

clrscr();

do  {
    printf("**********************************************************\n");
    printf("ADMINISTRADOR seleccione una opcion:\n");
    printf("1. Editar un usuario existente.\n");
    printf("2. Dar de Alta un usuario nuevo.\n");
    printf("3. Listar Usuarios.\n");
    printf("0. Salir del menu de administracion.\n");
    FF();
    scanf("%d", &num);
    }while (num<0 || num>3);

switch (num)
{
    case 1: //EDITAR REGISTRO EXISTENTE
        {
        editar_usuarios(user);
        break;
        }


    case 2: //CREAR UN REGISTRO NUEVO
        {
        alta_usuarios(user);
        break;
        }

    case 3: //LISTAR REGISTROS
        {
        listar_usuarios(user);
        break;
        }

    case 0:
        {
          break;
        }
    }
}

void editar_usuarios (usuario *user)
{
        archivo=fopen(FILE1, "r");
        if (archivo==NULL)
            printf("El fichero %s no existe o está bloqueado.", FILE1);
        else
            {
            FF();
            clrscr();
            //Modificacion de registros
            printf("Que registro deseas modificar? (xxxx) : ");
            fgets(user->Id_usuario, 5, stdin);
            printf("**********************************************************\n");
            printf("Introduzca nuevo nombre del usuario: ");
            FF();
            fgets(user->Nombre_usuario, 20, stdin);
            printf("Introduzca nueva Localidad: ");
            FF();
            fgets(user->Localidad, 20, stdin);
            printf("Introduzca el nuevo Perfil (A)dministrador) o (U)suario: ");
            FF();
            c=getchar();

            if (c=='A' || c=='a')
                strcpy(user->Perfil_usuario, tipo_usuario[0]);
            else
                strcpy(user->Perfil_usuario, tipo_usuario[1]);

            printf("* %s *\n", user->Perfil_usuario);
            printf("Introduzca el nuevo usuario de acceso: ");
            FF();
            fgets(user->User, 6, stdin);
            printf("Introduzca la nueva password: ");
            FF();
            fgets(user->Login, 9, stdin);
            printf("Nuevo estado (A)ctivo o (B)loqueado: ");
            FF();
            c=getchar();

            if (c=='A' || c=='a')
                strcpy(user->Estado, tipo_estado[0]);
            else
                strcpy(user->Estado, tipo_estado[1]);

            printf("* %s *\n", user->Estado);
            printf("Pulse (s) para guardar cambios.\n");
            FF();
            c=getchar();

            if (c=='s' || c=='S')
                {
                    rewind(archivo);
                    linea=(char*)malloc(MAX_LINEA);
                    memset(linea,'\0',MAX_LINEA);
                    temporal=fopen(FILE2, "w");
                    if (temporal==NULL)
                        printf("El fichero %s está bloqueado.", FILE2);
                    else
                        {
                            while(feof(archivo)==0)
                            {
                                fgets(linea, MAX_LINEA, archivo);
                                strtok(linea, "\n");
                                if (strncmp(linea, strtok(user->Id_usuario, "\n"), 4)==0)
                                    {
                                    encontrado=1;
                                    strcpy(linea, strtok(user->Id_usuario,"\n"));
                                    strcat(linea,"-");
                                    strcat(linea, strtok(user->Nombre_usuario, "\n"));
                                    strcat(linea,"-");
                                    strcat(linea, strtok(user->Localidad, "\n"));
                                    strcat(linea,"-");
                                    strcat(linea, strtok(user->Perfil_usuario, "\n"));
                                    strcat(linea,"-");
                                    strcat(linea, strtok(user->User, "\n"));
                                    strcat(linea,"-");
                                    strcat(linea, strtok(user->Login, "\n"));
                                    strcat(linea,"-");
                                    strcat(linea, strtok(user->Estado, "\0\n"));
                                    fprintf(temporal, linea, "\n");
                                    memset(linea,'\0',MAX_LINEA);
                                    }
                                else
                                    {
                                    fprintf(temporal, linea);
                                    memset(linea,'\0',MAX_LINEA);
                                    }
                            }
                            fclose(archivo);
                            fclose(temporal);

                            remove(FILE3);

                            if( rename(FILE1, FILE3) == 0 )
                                //printf( "renombrado: %s\n", FILE6);
                            else
                                printf( "\nNo pudo ser renombrado $s.\n", FILE1 );

                            if( rename(FILE2, FILE1) == 0 )
                                //printf( "renombrado: %s\n", FILE5);
                            else
                                printf( "\nNo pudo ser renombrado %s.\n", FILE2 );

                            remove(FILE2);

                            printf("Datos guardados.");
                            getchar();
                        }
                }
                else
                    {
                    printf("Cambios no guardados.");
                    getchar();
                    }
            fclose(archivo);
            fclose(temporal);
        }
}

void alta_usuarios(usuario *user)
{

     archivo=fopen(FILE1, "r");
        if (archivo==NULL)
            printf("El fichero %s no existe o está bloqueado.", FILE1);
        else
            {
            //CONTADOR DE REGISTROS
            lineastotales=(char*)malloc(MAX_LINEA);
            linea=(char*)malloc(MAX_LINEA);
            memset(lineastotales,'\0',MAX_LINEA);
            memset(linea,'\0',MAX_LINEA);
            contador=0;
            while(feof(archivo)==0)
                {
                    fgets(lineastotales, MAX_LINEA, archivo);
                    contador=contador+1;
                }
            //INCLUIR RESTO DE CAMPOS
            FF();
            fclose(archivo);
            archivo=fopen(FILE1, "a");
            clrscr();
            printf("**********************************************************\n");
            printf("Registro: [%04i]\n", contador+1);
            printf("Introduzca nombre del usuario: ");
            FF();
            fgets(user->Nombre_usuario, 20, stdin);
            printf("Introduzca Localidad: ");
            FF();
            fgets(user->Localidad, 20, stdin);
            printf("Introduzca Perfil (A)dministrador) o (U)suario: ");
            FF();
            c=getchar();

            if (c=='A' || c=='a')
                strcpy(user->Perfil_usuario, tipo_usuario[0]);
            else
                strcpy(user->Perfil_usuario, tipo_usuario[1]);

            printf("* %s *\n", user->Perfil_usuario);
            printf("Introduzca usuario de acceso: ");
            FF();
            fgets(user->User, 6, stdin);
            printf("Introduzca password: ");
            FF();
            fgets(user->Login, 9, stdin);
            printf("Nuevo estado (A)ctivo o (B)loqueado: ");
            FF();
            c=getchar();

            if (c=='A' || c=='a')
                strcpy(user->Estado, tipo_estado[0]);
            else
                strcpy(user->Estado, tipo_estado[1]);

            printf("* %s *\n", user->Estado);
            printf("Pulse (s) para guardar cambios.\n");
            FF();
            c=getchar();
            if (c=='s' || c=='S')
            {
                linea=(char*)malloc(MAX_LINEA);

                strcpy(linea, strtok(user->Nombre_usuario, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(user->Localidad, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(user->Perfil_usuario, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(user->User, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(user->Login, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(user->Estado, "\n"));

                fprintf(archivo, "\n%04d-", (contador+1));
                fprintf(archivo, linea);
                memset(linea,'\0',MAX_LINEA);
                fclose(archivo);
                }
            else
                {
                printf("Registro no creado.");
                getchar();
                }
            }

}

void listar_usuarios (usuario *user)
{

        int res=0;
        int cont=1;
        char * f1, * f2, *pch, *id_cpy, *est_cpy;
        archivo=fopen(FILE1, "r");
        incide=fopen(FILE4, "r");
        linea=(char*)malloc(MAX_LINEA);
        linea2=(char*)malloc(MAX_LINEA);

        //temp=(char *)malloc(140);

        if (archivo==NULL || incide==NULL)
            printf("El fichero %s o %s no existe o está bloqueado.", FILE1, FILE4);
        else
            {
            //IMPRIMIR TODOS LOS REGISTROS POR PANTALLA
            clrscr();
            printf("ID-NOMBRE DEL USUARIO-LOCALIDAD-PERFIL-USER-PASSWORD-ESTADO-INCIDENCIAS(NO CERRADAS)\n\n");
            //strcpy(linea,"");
            while(!feof(archivo))
                {
                f1=fgets(linea, MAX_LINEA, archivo);
                strncpy(user->Id_usuario, f1, 4);
                strcat(user->Id_usuario, "\0");
                rewind(incide);

                if (linea!=NULL)
                    {
                    while(!feof(incide))
                        {
                        f2=fgets(linea2, MAX_LINEA, incide);
                        pch = strtok (f2,"-");

                        while ((pch = strtok (NULL, "-"))!=NULL)
                            {
                            cont++;
                            if (cont==3)
                                id_cpy=pch;
                            if (cont==5)
                                est_cpy=pch;
                            }

                        if (strncmp(user->Id_usuario, id_cpy, 4)==0 && strcmp(est_cpy, tipo_incidencia[1])!=0)
                            {
                                res++;
                            }
                        cont=1;
                        }
                    pch=strtok(linea, "\n");
                    if (pch!=NULL)
                        {
                        printf("%s-Incidencias:[%02d]\n", f1, res);
                        }
                    res=0;
                    }
                }
            printf("\n\nPulse una tecla para continuar.");
            getchar();
            }
        fclose(incide);
        fclose(archivo);

}
