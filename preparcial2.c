/*
 ============================================================================
 Name        : preparcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "avion.h"
#include "viaje.h"



int main(void)
{
	    setbuf(stdout, NULL);
	    eMarca marcas[TAM_MARCAS];
	    eAvion aviones[TAM_AVIONES];
	    eViaje viajes[TAM_VIAJES];

	    //var menu principal

	    int seguirPrincipal=0;
	    int seguirMarcas=0;
	    int seguirAviones=0;
	    int seguirViajes=0;

	    //var para marcas
	    int posicionMarcas;
	    int errorMarcas;
	    int idMarcas=1000;
	    int contadorInicialMarcas=0;

	    //var para aviones
	    int posicionAviones;
	    int errorAviones;
	    int idAviones=1000;
	    int contadorInicialAviones=0;

	    //var para viajes
	    int posicionViajes;
	    int errorViajes;
	    int idViajes=100;
	    int contadorInicialViajes=0;

	    //inicializadores
	    iniciarMarcas(marcas, TAM_MARCAS);
	    iniciarAviones(aviones, TAM_AVIONES);
	    iniciarViajes(viajes, TAM_VIAJES);

	    do
	    {
	        switch(MenuPrincipal())
	        {
	        case 1:
	            do
	            {
	                seguirMarcas=0;
	                switch(subMenuMarcas())
	                {

	                case 1:
	                    posicionMarcas = buscarMarcasVacia(marcas, TAM_MARCAS,&errorMarcas);
	                    if(errorMarcas!=-1)
	                    {
	                        altaMarcas(marcas, TAM_MARCAS,posicionMarcas,idMarcas);
	                        idMarcas++;
	                        printf("Alta exitosa\n");
	                        contadorInicialMarcas=1;
	                    }
	                    else
	                    {
	                        printf("No se encuentra lugar vacio\n");
	                    }
	                    break;
	                case 2:
	                    if(contadorInicialMarcas==1)
	                    {
	                        mostrarMarcas(marcas, TAM_MARCAS);
	                        if(bajaMarcas(marcas, TAM_MARCAS)!=-1)
	                        {
	                            printf("Baja exitosa\n");
	                        }
	                        else
	                        {
	                            printf("No se encontro..\n");
	                        }
	                    }
	                    else
	                    {
	                        printf("Debes cargar antes de dar de baja\n");
	                    }
	                    break;
	                case 3:
	                    if( mostrarMarcas(marcas, TAM_MARCAS)==-1)
	                    {
	                        printf("    No se cargo ninguna marca\n");
	                    }
	                    break;
	                case 4:
	                    seguirMarcas=1;
	                    break;
	                }
	                system("pause");
	            }
	            while(seguirMarcas==0);
	            break;
	        case 2:
	            do
	            {
	                seguirAviones=0;
	                switch(subMenuAviones())
	                {
	                case 1:
	                    if(contadorInicialAviones==0 || contadorInicialMarcas==0)
	                    {
	                        printf("Antes de cargar aviones deben cargarse marca y viajes\n");
	                    }
	                    else if(posicionAviones!=-1 || posicionMarcas!=-1)
	                    {
	                        posicionAviones = buscarAvionesVacio(aviones, TAM_AVIONES,&errorAviones);
	                        if(errorAviones!=-1)
	                        {
	                            altaAviones(aviones, TAM_AVIONES, marcas, TAM_MARCAS, viajes, TAM_VIAJES, posicionAviones, idAviones);
	                            idAviones++;
	                            printf("Alta exitosa\n");
	                            contadorInicialAviones=1;
	                        }
	                        else
	                        {
	                            printf("No se encuentra lugar vacio\n");
	                        }
	                    }
	                    break;
	                case 2:
	                    if(contadorInicialAviones==1)
	                    {
	                        mostrarAviones(aviones, TAM_AVIONES, marcas, viajes);
	                        if(bajaAviones(aviones,TAM_AVIONES)!=-1)
	                        {
	                            printf("Baja exitosa\n");
	                        }
	                        else
	                        {
	                            printf("No se encontro numero de id\n");
	                        }
	                    }
	                    else
	                    {
	                        printf("Debes cargar antes de dar de baja\n");
	                    }
	                    break;
	                case 3:
	                    if( mostrarAviones(aviones, TAM_AVIONES, marcas, viajes)==-1)
	                    {
	                        printf("    No se cargo ningun avion\n");
	                    }
	                    break;
	                case 4:
	                    if(contadorInicialAviones==1)
	                    {
	                        errorAviones = modificarAviones(aviones, TAM_AVIONES, marcas, viajes);
	                        if(errorAviones!=-1)
	                        {
	                            printf("Modificacion exitosa\n");
	                        }
	                        else
	                        {
	                            printf("No fue posible modificar\n");
	                        }
	                    }
	                    else
	                    {
	                        printf("Hay que cargar aviones antes de modificar\n");
	                    }
	                    break;
	                case 5:
	                    seguirAviones=1;
	                    break;
	                }
	                system("pause");
	            }
	            while(seguirAviones==0);
	            break;
	        case 3:
	            do
	            {
	                seguirViajes=0;
	                switch(subMenuViajes())
	                {
	                case 1:
	                    printf("DAR ALTA VIAJES\n");
	                    posicionViajes = buscarViajesVacio(viajes, TAM_VIAJES, &errorViajes);
	                    if(errorViajes!=-1)
	                    {
	                        altaViajes(viajes, TAM_VIAJES, posicionViajes, idViajes);
	                        idViajes++;
	                        printf("Alta exitosa\n");
	                        contadorInicialViajes=1;
	                    }
	                    else
	                    {
	                        printf("No se encuentra lugar vacio\n");
	                    }
	                    break;
	                case 2 :
	                    printf("LISTAR VIAJES\n");
	                    if( mostrarViajes(viajes, TAM_VIAJES)==-1)
	                    {
	                        printf("    No se cargo ningun viaje\n");
	                    }
	                    break;
	                case 3:
	                    seguirViajes=1;
	                    break;
	                }
	                system("pause");
	            }
	            while(seguirViajes==0);
	            break;
	        }
	    }
	    while(seguirPrincipal==0);

	    return 0;
	}
