#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int opcion;
    setbuf(stdout, NULL);//disable buffer
    LinkedList* listaEmpleados = ll_newLinkedList();
    int archivoDataCargado = 0;
    int retorno;
    do
    {
        printf("BIENVENIDO\n");
        opcion = menuPrincipal();

        switch(opcion)
        {
            case 1:
                if(archivoDataCargado == 0)
                {
                    retorno = controller_loadFromText("data.csv", listaEmpleados);
                    switch(retorno)
                    {
						case 0:
							printf("Archivo de texto cargado exitosamente.\n");
							archivoDataCargado = 1;
							break;
						case 1:
							printf("Error al cargar el archivo de texto.\n");
							break;
                    }

                } else
                {
                    printf("El archivo ya a sido cargado.\n");
                }
                printf("\nPresione Enter para continuar\n");
                getchar();

                break;
            case 2:
                if(archivoDataCargado == 0)
                {
                    retorno = controller_loadFromBinary("data.bin", listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("Archivo binario cargado exitosamente.\n");
							archivoDataCargado = 1;
							break;
						case 1:
							printf("Error al cargar el archivo binario.\n");
							break;
					}

                } else
                {
                    printf("El archivo ya a sido cargado.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 3:
                if(archivoDataCargado == 1)
                {
                    retorno = controller_addEmployee(listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("Empleado agregado\n");
							break;
						case 1:
							printf("Error al agregar el empleado.\n");
							break;
						case 2:
							printf("Se ah cancelado el ingreso del empleado.\n");
							break;
					}
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();
                break;
            case 4:
                if(archivoDataCargado == 1)
                {
                    printf("MODIFICAR EMPLEADO\n");
                    controller_editEmployee(listaEmpleados);
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 5:
                if(archivoDataCargado == 1)
                {
                    printf("BAJA EMPLEADO\n");
                    retorno = controller_removeEmployee(listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("\nEmpleado eliminado.\n");
							break;
						case 1:
							printf("Error al eliminar el empleado.\n");
							break;
						case 2:
							printf("\nEmpleado no eliminado.\n");
							break;
						case 3:
							printf("\nId no encontrado.\n");
							break;
					}
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 6:
                if(archivoDataCargado == 1)
                {
                    printf("LISTAR EMPLEADOS\n\n");
                    retorno = controller_ListEmployee(listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("\nExito al mostrar empleados\n");
							break;
						case 1:
							printf("Error al mostrar lista de empleados.\n");
							break;
					}
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 7:
                if(archivoDataCargado == 1)
                {
                    printf("ORDENAR EMPLEADOS\n");
                    retorno = controller_sortEmployee(listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("\nExito al ordenar lista empleados\n");
							break;
						case 1:
							printf("Error al ordenar lista de empleados.\n");
							break;
					}
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 8:
                if(archivoDataCargado == 1)
                {
                    retorno = controller_saveAsText("data.csv", listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("Archivo guardado.\n");
							break;
						case 1:
							printf("Error al guardar el archivo.\n");
							break;
					}
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 9:
                if(archivoDataCargado == 1)
                {
                    retorno = controller_saveAsBinary("data.bin", listaEmpleados);
                    switch(retorno)
					{
						case 0:
							printf("Archivo guardado.\n");
							break;
						case 1:
							printf("Error al guardar el archivo.\n");
							break;
					}
                } else
                {
                    printf("El archivo no ha sido cargado todavia.\n");
                }
                printf("\nPresione Enter para continuar\n");
				getchar();


                break;
            case 10:
                break;
        }
    }while(opcion != 10);

    printf("Gracias por usar la aplicacion\n");

    return 0;
}

