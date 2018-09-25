//Modulo Gestion ADMIN VEHICULOS.C
#include "estructuras.h"
#include "auxiliar.h"
#include "ficheros.h"
#include "admin_vehiculos.h"

void admin_vehiculos ()
{

vehiculos *v;


///variables locales
int mod;

do{

clrscr();
puts("----------------------------------------------------------------");
puts("Bienvenido Administrador, inque la operacion que desea realizar:");
puts("1.Ver vehiculos");
puts("2.Editar vehiculos");
puts("3.Anadir vehiculos");
puts("4.Eliminar vehiculos");
puts("5.Salir");


///elección
scanf("%d",&mod);
FF();

v=(vehiculos*)malloc(sizeof(vehiculos));


switch(mod){

case 1: ver_vehiculos(v);
    break;

case 2: editar_vehiculos(v);
    break;

case 3: anadir_vehiculos(v);
    break;

case 4: eliminar_vehiculos(v);
    break;


case 5: break;

default: puts("Introduzca una opcion correcta");

}}while(mod!=5);
clrscr();


}


void ver_vehiculos(vehiculos *v){
char caracter;
archivo=fopen(FILE5,"r");
 if (archivo==NULL)
 puts("No se ha podido leer el archvio");
 else
 {
    caracter = fgetc (archivo);
    while (feof(archivo)==0)
    {
        printf("%c",caracter);
        caracter= fgetc (archivo);
        }
        }
    fclose (archivo);

}


void anadir_vehiculos(vehiculos *v){

clrscr();
char *linea;
linea=(char*)malloc(MAX_LINEA);
memset(linea,'\0',MAX_LINEA);
archivo=fopen(FILE5,"a");

int i;
int num;
char c;

puts("Cuantos vehiculos quiere introducir?");
scanf("%d",&num);
FF();



for(i=1;i<=num;i++){
///ESCRIBIR LOS DATOS DE FICHERO EN LA ESTRUCTURA
printf("\nVehiculo nº %d \n",i); ///primero se inicializa el vehiculo en la struct y luego se mueve al fichero
FF();
printf("\nId de la Matricula (7 caracteres) : ");
fgets(v->Id_mat,8,stdin);
FF();

printf("\nId del usuario (4 caracteres) : ");
fgets(v->Id_usuario,5,stdin);
FF();

printf("\nNumero de plazas: ");
fgets(v->Num_plazas,2,stdin);
FF();

printf("\nDescripcion del vehiculo: ");
fgets(v->Desc_veh,50,stdin);
FF();

///printf("%s\n",v->Id_mat);
///printf("%s\n",v->Id_usuario);
///printf("%s\n",v->Num_plazas);
///printf("%s\n",v->Desc_veh);



puts("Desea guardar los cambios S/N?");
scanf("%c",&c);
FF();

if(c=='S' || c=='s'){
                strcpy(linea, strtok(v->Id_mat,"\n"));
                strcat(linea,"-");
                strcat(linea, strtok(v->Id_usuario, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(v->Num_plazas, "\n"));
                strcat(linea,"-");
                strcat(linea, strtok(v->Desc_veh, "\0\n"));
fprintf(archivo,"%s",linea);
}else
puts("No se han guardado los cambios");
}
fclose(archivo);
}


void editar_vehiculos(vehiculos *v)
{
    	char *linea;
		char busqueda[7];
		char c;

        archivo=fopen(FILE5, "r");
        temporal=fopen(FILE2, "w");

        if (archivo==NULL)
            printf("El fichero %s no existe o está bloqueado.", "archivo.txt");
        else
            {

            clrscr()
			FF();
            printf("Que vehiculo deseas modificar? (Matricula) : ");
            scanf("%s",busqueda);
			FF();
            printf("**********************************************************\n");
            printf("Introduzca La nueva matricula: ");
            FF();
            fgets(v->Id_mat, 7, stdin);
            printf("Introduzca el nuevo Id_Usuario del vehiculo: ");
			FF();
            fgets(v->Id_usuario, 5, stdin);
            printf("Introduzca el numero de plazas del vehiculo: ");
            FF();
            fgets(v->Num_plazas, 2, stdin);
            printf("Realice una breve descripcion del vehiculo: ");
            FF();
            fgets(v->Desc_veh, 50, stdin);
			puts("Pulse S para guardar los cambios");
			FF();
			c=getchar();

            if (c=='s' || c=='S')
                {
                    rewind(archivo);
                    linea=(char*)malloc(MAX_LINEA);
                    memset(linea,'\0',MAX_LINEA);
                    if (temporal==NULL)
                        printf("El fichero %s está bloqueado.", "temporal.txt");
                    else
                        {
                        while(feof(archivo)==0)
                            {
                            fgets(linea, MAX_LINEA, archivo);
                            strtok(linea, "\n");
                            if (strncmp(linea, strtok(v->Id_usuario, "\n"), 7)==0)
                                {
                                strcpy(linea, strtok(v->Id_mat,"\n"));
                                strcat(linea,"-");
                                strcat(linea, strtok(v->Id_usuario, "\n"));
                                strcat(linea,"-");
                                strcat(linea, strtok(v->Num_plazas, "\n"));
                                strcat(linea,"-");
                                strcat(linea, strtok(v->Desc_veh, "\0\n"));
                                fprintf(temporal, linea, "\n");
                                memset(linea,'\0',MAX_LINEA);
                                }
                            else
                                {
                                fprintf(temporal, linea, "\n");
                                memset(linea,'\0',MAX_LINEA);
                                }
                            }
                        fclose(archivo);
                        fclose(temporal);
                        rename(FILE5, FILE6);
                        rename(FILE2, FILE5);
                        remove(FILE2);
                        printf("Datos guardados.");
                        FF();
                        }
                }
            else
                {
                printf("Cambios no guardados.");
                FF();
                }
            fclose(archivo);
            fclose(temporal);
        }

}


void eliminar_vehiculos(vehiculos *v)
{
clrscr();
int c1=0;
char *linea;
int encontrado=0;
char selec; //es un char
archivo=fopen(FILE5,"r"); //* solo lectura *
linea = (char*)malloc(MAX_LINEA);
///Lectura del la matricula que queremos borrar
printf("\nQue vehiculo desea eliminar? Introduzca su Id_Matricula: ");
FF();
fgets(v->Id_mat,8,stdin);
///busqueda de esa matricula en el archivo

while(feof(archivo)==0 && encontrado==0)
    {
	fgets(linea, MAX_LINEA, archivo);
	c1++;
	if(strncmp(linea,v->Id_mat,7)==0)
        encontrado=c1;
    }
if (encontrado!=0)
    {
    puts("Vehiculo encontrado!");
    printf("\nDesea borrar el vehiculo con matricula %s? S/N: ",v->Id_mat);
    FF();
    selec=getchar();
    if(selec == 's' || selec =='S')
        {
        rewind(archivo);
        temporal=fopen(FILE2,"w");
        c1=1;
        while(feof(archivo)==0)
            {
            fgets(linea,MAX_LINEA,archivo);
            if((c1!=encontrado))
                {
                fputs(linea, temporal);
                }
            c1++;
            }
        fclose(archivo);
        fclose(temporal);

        remove(FILE6);
        if( rename(FILE5, FILE6) == 0 )
            //printf( "renombrado: %s\n", FILE6);
        else
           printf( "\nNo pudo ser renombrado $s.\n", FILE5 );

        if( rename(FILE2, FILE5) == 0 )
            //printf( "renombrado: %s\n", FILE5);
        else
           printf( "\nNo pudo ser renombrado %s.\n", FILE2 );

        remove(FILE2);
        printf("\nVehiculo eliminado.");
        }
    }
else
    {
    puts("El vehiculo no consta en la base de datos");
    }
FF();
getchar();
fclose(temporal);
fclose(archivo);
}
