#ifdef WIN32
#define clrscr() system("cls");
#define FF() fflush(stdin);
#else
#define clrscr() system("clear");
#define FF() flush_in();
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#include "inicio.h"

#include"admin.c"



int main(int argc, char** argv)
{

while(1)
    {
    // Menu Id usuarios
    //
    // Si usuario es ADMIN
    administrador();
    //
    }
}

void flush_in()
{
char ch;
while((ch = fgetc(stdin)) != EOF && ch != '\n' );
}

