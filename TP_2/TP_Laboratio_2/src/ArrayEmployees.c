/*
 * ArrayEmployees.c
 *
 *  Created on: 1 nov. 2021
 *      Author: MartinGonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "Biblioteca.h"
#include "Menu.h"

int initEmployees(Employee* list, int len)
{
	int i;
	int retorno = -1;
	for(i=0; i<len; i++)
	{
		list[i].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}


int BuscarEmployeeLibre(Employee* list, int len)
{
    int i;
    int index;
    index = -1; //Si no encuentra espacio disponible

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == TRUE)//Criterio de busqueda
        {
            index = i;
            break;
        }
    }

    return index;
}

int SiguienteId(Employee* list, int len)
{
    int retorno = 0;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                    if(list[i].id>retorno)
                    {
                         retorno=list[i].id;
                    }

            }
        }
    }

    return retorno+1;
}

int CargarEmployee(Employee* list, int len)
{
    int index = BuscarEmployeeLibre(list, len);
    int retorno = -1;
    float salario;
    int sector;
    if(index >=0)
    {

    	Employee myEmployee;

    	myEmployee.id = SiguienteId(list,len);

    	PedirAlfanumericaConEspacio(myEmployee.name, 51, "Ingrese el nombre del empleado: ", "Ah ocurrido un error, reingrese: ");
    	PedirAlfanumericaConEspacio(myEmployee.lastName, 51, "Ingrese el apellido del empleado: ", "Ah ocurrido un error, reingrese: ");
    	PedirFlotante(&salario, "Ingrese el salario del empleado: ", "Error, el salario minimo es 100 y el maximo 15000. Reingrese: ", 100, 15000);
    	PedirEntero(&sector, "Ingrese el Sector del empleado: ", "Error, los sectores son del 1 al 50. Reingrese: ", 1, 50);

    	myEmployee.salary = salario;
    	myEmployee.sector = sector;

        addEmployee(list, len, myEmployee.id, myEmployee.name, myEmployee.lastName, myEmployee.salary, myEmployee.sector);
        retorno = 0;
    }


    return retorno;

}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int index;
    if(list != NULL && len > 0)
    {
        index = BuscarEmployeeLibre(list, len);
        if(index > -1)
        {
            list[index].id = id;
            strcpy(list[index].name, name);
            strcpy(list[index].lastName, lastName);
            list[index].salary = salary;
            list[index].sector = sector;
            list[index].isEmpty = FALSE;
            return 0;
        }
    }
    return -1;
}

void MostrarUnEmployee(Employee unEmployee){

    printf("\n%-7d%-14s%-10s%-17.2f%-10d\n ", unEmployee.id, unEmployee.name, unEmployee.lastName, unEmployee.salary, unEmployee.sector);

}

int printEmployees(Employee* list, int len)
{
    int retorno = -1;
    int i;
    printf("%s  %10s  %12s  %7s  %14s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
            	MostrarUnEmployee(list[i]);
            }
        }
    }
    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index;
    if(list != NULL && len > 0)
    {
        for(index = 0; index < len; index ++)
        {
            if(list[index].isEmpty == FALSE)
            {
                if(list[index].id == id)
                {
                    return index;
                }
            }
        }
    }
    return -1;
}

int removeEmployee(Employee* list, int len)
{

    int i;
    int id;
    char confirmar;
    int retorno = -1;
    if(list != NULL && len > 0)
    {

    	PedirEntero(&id, "Ingrese el ID del empleado a eliminar: ", "Error, ingrese un numero entre 1 y 1000", 1, 1000);
        for(i=0; i<len; i++)
        {
            if(id==list[i].id)
            {

            	MostrarUnEmployee(list[i]);
            	confirmar = PedirRespuestaSN("¿Esta seguro que desea eliminar el empleado? s=si n=no\n ");

				if(confirmar=='s')
				{
					list[i].isEmpty = TRUE;
					retorno = 0;
					break;

				}

                break;
            }
        }

    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int indice;
	int j;
	Employee auxiliar;
	int retorno = -1;
	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		for(indice = 1; indice < len; indice++)
		{
			if(list[indice].isEmpty == FALSE)
			{
				auxiliar = list[indice];
				j = indice - 1;
				if(order == 0)
				{
					while(j >= 0 && strcmp(auxiliar.lastName, list[j].lastName) < 0)
					{
						list[j + 1] = list[j];
						j--;
					}
					while(j >= 0 && auxiliar.sector < list[j].sector && list[j].isEmpty == FALSE)
					{
						list[j + 1] = list[j];
						j--;
					}
				}
				if(order == 1)
				{
					while(j >= 0 && strcmp(auxiliar.lastName, list[j].lastName) > 0)
					{
						list[j + 1] = list[j];
						j--;
					}
					while(j >= 0 && auxiliar.sector > list[j].sector)
					{
						list[j + 1] = list[j];
						j--;
					}
				}
				list[j + 1] = auxiliar;
			}
		}
		printEmployees(list, len);
		retorno = 0;
	}
	return retorno;
}

int ModificarEmployee(Employee* list, int len)
{
    int opcion;
    int id;
    int i;
    int retorno = -1;
    char nombre[51];
    char apellido[51];
    char confirmar;
    float salario;
    int sector;


    printEmployees(list, len);

	PedirEntero(&id, "Ingrese el ID del cliente a modificar: ", "Error, ingrese un numero entre 1 y 1000", 1, 1000);

	printf("\n-------------------------------\n");

    for(i=0; i<len; i++)
    {
        if(id == list[i].id)
        {

            printf(".ID del Empleado encontrado!!\n");

            do
            {
            	opcion = menuEditarEmpleado();
                switch(opcion)
                {
                case 1:
                	PedirAlfanumericaConEspacio(nombre, 51, "Ingrese el nuevo nombre del empleado: ", "Ah ocurrido un error, reingrese: ");
					confirmar = PedirRespuestaSN("¿Esta seguro que desea modificar? s=si n=no\n");

					if(confirmar=='s')
					{

						strcpy(list[i].name, nombre);
						retorno = 0;


					}
                    break;
                case 2:
                	PedirAlfanumericaConEspacio(apellido, 51, "Ingrese el nuevo apellido del empleado: ", "Ah ocurrido un error, reingrese: ");
					confirmar = PedirRespuestaSN("¿Esta seguro que desea modificar? s=si n=no\n");

					if(confirmar=='s')
					{

						strcpy(list[i].lastName, apellido);
						retorno = 0;


					}
                    break;
                case 3:
                	PedirFlotante(&salario, "Ingrese el nuevo salario del empleado: ", "Error, el salario minimo es 100 y el maximo 15000. Reingrese: ", 100, 15000);
					confirmar = PedirRespuestaSN("¿Esta seguro que desea modificar? s=si n=no\n");

					if(confirmar=='s')
					{

						list[i].salary = salario;
						retorno = 0;


					}
                    break;
                case 4:
                	PedirEntero(&sector, "Ingrese el nuevo Sector del empleado: ", "Error, los sectores son del 1 al 50. Reingrese: ", 1, 50);
					confirmar = PedirRespuestaSN("¿Esta seguro que desea modificar? s=si n=no\n");

					if(confirmar=='s')
					{

						list[i].sector = sector;
						retorno = 0;


					}
                    break;
                case 5:
                	break;
                }
            }
            while(opcion != 5);

           break;

        }
    }

    return retorno;

}

float SumarSalarios(Employee* list, int len)
{
	int index;
	float total = -1;
	if(list != NULL && len > 0)
	{
		total = 0;
		for(index = 0; index < len; index++)
		{
			if(list[index].isEmpty == FALSE)
			{
				total = total + list[index].salary;
			}
		}
	}
	return total;
}

float PromedioSalarios(Employee* list, int len)
{
	int index;
	float promedio = -1;
	int contadorSalarios = 0;
	float totalSalarios;
	if(list != NULL && len > 0)
	{
		promedio = 0;
		for(index = 0; index < len; index++)
		{
			if(list[index].isEmpty == FALSE)
			{
				contadorSalarios++;
			}
		}
		if(contadorSalarios > 0)
		{
			totalSalarios = SumarSalarios(list, len);
			promedio = totalSalarios / contadorSalarios;
		}
	}
	return promedio;
}

int CantidadSalariosSuperandoPromedio(Employee* list, int len)
{
	int index;
	    int contador = -1;
	    float promedio;
	    if(list != NULL && len > 0)
	    {
	        contador = 0;
	        promedio = PromedioSalarios(list, len);
	        for(index = 0; index < len; index++)
	        {
	            if(list[index].isEmpty == FALSE)
	            {
	                if(list[index].salary > promedio)
	                {
	                    contador++;
	                }
	            }
	        }
	    }
	    return contador;
}
