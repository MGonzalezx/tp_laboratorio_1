/*
 ============================================================================
 Name        : TP_Laboratio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#define CANTIDADEMPLEADOS 1000

int main(void) {

	setbuf(stdout, NULL);//disable buffer
	    int option = 0;
	    int inicializado = 0;
	    int i;
	    int opcionInformar = 0;
	    int orden;


	    Employee listadoMainEmpleados[CANTIDADEMPLEADOS];
	    initEmployees(listadoMainEmpleados, CANTIDADEMPLEADOS);



	    do{
	    	printf("\t ¡¡¡BIENVENIDO!!!\n");
	    	option = menuPrincipal();
	        switch(option)
	        {
	            case 1:
	            	i = CargarEmployee(listadoMainEmpleados, CANTIDADEMPLEADOS);
					inicializado = 1;
					   switch(i)
					   {
						   case -1:
							printf("No hay espacio disponible!!!\n");
							printf("\n-------------------------------\n");
						   break;
						   default:
							printf("\n-------------------------------\n");
							printf("Empleado registrado con exito!!!\n");
							printf("\n-------------------------------\n");
						   break;
					   }
						printf("\nPresione Enter para continuar\n");
						getchar();
	                break;
	            case 2:
	            	if(inicializado == 1)
					{
						 i =ModificarEmployee(listadoMainEmpleados, CANTIDADEMPLEADOS);
						   switch(i)
						   {
							   case -1:
								printf("¡¡¡No se modifico nada ya que ah cancelado la modificacion o el ID ingresado no existe!!!\n");
							   break;
							   default:
								printf("¡¡¡Producto Modificado con exito!!!\n");
							   break;
						   }
					}else{
						printf("Debe ingresar un cliente primero");
					}

					printf("\nPresione Enter para continuar\n");
					getchar();
	            	break;
	            case 3:
	            	if(inicializado == 1)
						{
							i = removeEmployee(listadoMainEmpleados, CANTIDADEMPLEADOS);
						   switch(i)
						   {
							   case -1:
								printf("\n¡¡¡NO EXISTE ESE ID!!!\n");
								printf("\n-------------------------------\n");
							   break;
							   default:
								printf("\n¡¡¡Cliente eliminado con exito!!!\n");
								printf("\n-------------------------------\n");
							   break;
						   }
						}else{
							printf("Debe ingresar un cliente primero");
						}
						printf("\nPresione Enter para continuar\n");
						getchar();
					break;
	            case 4:
	            	if(inicializado == 1)
	            	{
	            	do{
	            		opcionInformar = menuInformarEmpleado();
	            		switch(opcionInformar)
	            		{
	            		case 1:
	            			printf("¿En que orden quiere mostrar a la lista? 1 ascendente - 0 descendente: ");
	            			scanf("%d", &orden);
	            			sortEmployees(listadoMainEmpleados, CANTIDADEMPLEADOS, orden);
	            			break;
	            		case 2:
	            			printf("La suma total de todos los salarios es: \n");
							printf("%.2f\n",SumarSalarios(listadoMainEmpleados, CANTIDADEMPLEADOS));
							printf("El promedio de los salarios es: \n");
							printf("%.2f\n", PromedioSalarios(listadoMainEmpleados, CANTIDADEMPLEADOS));
							printf("La cantidad de empleados que superan el sueldo promedio es: \n");
							printf("%d\n", CantidadSalariosSuperandoPromedio(listadoMainEmpleados, CANTIDADEMPLEADOS));

							break;

	            		}

	            	}while(opcionInformar != 3);
	            	}else{
						printf("Debe ingresar un cliente primero");
					}

						printf("\nPresione Enter para continuar\n");
						getchar();
					break;
	            case 5:

					break;

	        }
	    }while(option != 5);

	    printf("Gracias por usar la aplicacion\n");
	return EXIT_SUCCESS;
}
