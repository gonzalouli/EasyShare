#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

FILE *archivo;
FILE *temporal;
FILE *incide;

char *tipo_usuario[]={"administrador", "usuario", NULL};
char *tipo_estado[]={"activo", "bloqueado", NULL};
char *tipo_incidencia[]={"Abierta", "Cerrada", "Validada", NULL};

typedef struct  {
                char Id_usuario[5];
                char Nombre_usuario[20];
                char Localidad[20];
                char Perfil_usuario[15];
                char User[6];
                char Login[8];
                char Estado[10];
}usuario;

typedef struct  {
                char Id_viaje[6];
                char Id_us_registra[4];
                char Id_us_incidencia[4];
                char Desc_indicencia[100];
                char Est_incidencia[10];
}incid;

typedef struct{
                char Id_mat[8];
                char Id_usuario[5];
                char Num_plazas[2];
                char Desc_veh[50];
}vehiculos;



#endif
