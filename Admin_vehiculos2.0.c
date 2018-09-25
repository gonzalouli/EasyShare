#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define MAX_LINEA 140
//include "principal.h"

typedef struct{
    char Id_mat[8];
    char Id_usuario[5];
    char Num_plazas[2];
    char Desc_veh[50];
}vehiculos;

FILE *archivo;
FILE *temporal;
FILE *incide;

void ver_vehiculos(vehiculos *v);
void editar_vehiculos(vehiculos *v);
void anadir_vehiculos(vehiculos *v);
void eliminar_vehiculos(vehiculos *v);

int main(){

vehiculos *v;


///variables locales
int mod;

do{


puts("----------------------------------");
puts("Bienvenido Administrador,¿Que operacion desea realizar?");
puts("1.Ver vehiculos");
puts("2.Editar vehiculos");
puts("3.Añadir vehiculos");
puts("4.Eliminar vehiculos");
puts("5.Salir");


///elección
scanf("%d",&mod);
getchar();

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
system("clear");




return 0;


}


void ver_vehiculos(vehiculos *v){
char caracter;
archivo=fopen("vehiculos.txt","r");
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

system("clear");
char *linea;
linea=(char*)malloc(MAX_LINEA);
memset(linea,'\0',MAX_LINEA);
archivo=fopen("vehiculos.txt","a");

int i;
int num;
char c;

puts("Cuantos vehiculos quiere introducir?");
scanf("%d",&num);





for(i=1;i<=num;i++){
///ESCRIBIR LOS DATOS DE FICHERO EN LA ESTRUCTURA
printf("\nVehiculo nº %d \n",i); ///primero se inicializa el vehiculo en la struct y luego se mueve al fichero
getchar();
printf("\nId de la Matricula (7 caracteres) : ");
fgets(v->Id_mat,7,stdin);
 __fpurge(stdin);

printf("\nId del usuario (4 caracteres) : ");
fgets(v->Id_usuario,4,stdin);
__fpurge(stdin);

printf("\nNumero de plazas: ");
fgets(v->Num_plazas,2,stdin);
__fpurge(stdin);

printf("\nDescripcion del vehiculo: ");
fgets(v->Desc_veh,50,stdin);
__fpurge(stdin);

printf("%s\n",v->Id_mat);
printf("%s\n",v->Id_usuario);
printf("%s\n",v->Num_plazas);
printf("%s\n",v->Desc_veh);



puts("Desea guardar los cambios S/N?");
scanf("%c",&c);
__fpurge(stdin);

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


void editar_vehiculos(vehiculos *v){

  {		char *linea;
		char c;
        archivo=fopen("vehiculos.txt", "r");
        temporal=fopen("temporal.txt", "w");
        if (archivo==NULL)
            printf("El fichero %s no existe o está bloqueado.", "archivo.txt");
        else
            {
            fflush(stdin);
            system("cls");
            getchar();
            printf("Que vehiculo deseas modificar? (Matricula) : ");
            fgets(v->Id_mat, 7, stdin);
            getchar();
            printf("**********************************************************\n");
            printf("Introduzca La nueva matricula: ");
            fflush(stdin);
            getchar();
            fgets(v->Id_mat, 7, stdin);
            printf("Introduzca el nuevo Id_Usuario del vehiculo: ");
            fflush(stdin);
            getchar();
            fgets(v->Id_usuario, 5, stdin);
            printf("Introduzca el numero de plazas del vehiculo: ");
            fflush(stdin);
            getchar();
            fgets(v->Num_plazas, 2, stdin);
            printf("Realice una breve descripcion del vehiculo: ");
            fflush(stdin);
            getchar();
            fgets(v->Desc_veh, 50, stdin);

			puts("Pulse S para guardar los cambios");
			fflush(stdin);
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
                    rename("vehiculos.txt", "vehiculos.bkp.txt");
                    rename("temporal.txt", "vehiculos.txt");
                    remove("temporal.txt");
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

}


void eliminar_vehiculos(vehiculos *v){
	archivo=fopen("vehiculos.txt","w");
	rewind(archivo);
	int encontrado=0;
	char *linea;
	char cadena[7];	
	char *mat;
	printf("\n¿Qué vehiculo desea eliminar del archivo? Introduzca su Id de matricula: ");
	
	fgets(cadena,7,stdin);
	
	linea=(char*)malloc(140);
	
	while(feof(archivo)==0 || encontrado==1){ 
		
		mat=fgets(linea,7, archivo);

		if(strncmp(cadena,mat,7)){
					puts("Vehiculo encontrado");
					encontrado=1;
			fputs("\0",archivo);
				}
	}
	
	

	
	
	
}

