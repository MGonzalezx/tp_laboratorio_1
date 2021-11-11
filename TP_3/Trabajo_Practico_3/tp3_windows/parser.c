#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Biblioteca.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Archivo data.csv abierto en modo lectura.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* pEmployee = NULL;
	Employee* pAuxEmployee = NULL;
	int cantidadDeDatosLeidos;
	char id[15];
	char nombre[128];
	char horasTrabajadas[15];
	char sueldo[15];
	int retorno = 1;
	FILE* archivoUltimoId;
	int lastId;
	int mayor;

	if(pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			if(cantidadDeDatosLeidos == 4 && isdigit(id[0]) != 0)
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(pEmployee != NULL)
				{
					ll_add(pArrayListEmployee, pEmployee);
				}
			}

		}

		archivoUltimoId = fopen("ultimo_id.txt","r");
		if(archivoUltimoId == NULL)
		{
			for(int i = 0; i <ll_len(pArrayListEmployee); i++ )
			{
				pAuxEmployee = ll_get(pArrayListEmployee, i);
				//printf("%d\n", pAuxEmployee->id);
				employee_getId(pAuxEmployee,&lastId);
				if( i == 0 || mayor < lastId)
				{

					mayor = lastId;
					//printf("%d\n", mayor);
				}
			}
			archivoUltimoId = fopen("ultimo_id.txt","w");
			if(archivoUltimoId != NULL)
			{
				fprintf(archivoUltimoId, "%d",mayor);


			}
		}
		fclose(archivoUltimoId);

		retorno = 0;
	}
	return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* Archivo data.bin abierto en modo lectura.
 * \param pArrayListEmployee LinkedList* LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee auxEmployee;
    Employee* pEmployee = NULL;
    int retorno = 1;
    int cont;
    if(pArrayListEmployee != NULL)
    {
    	while(!feof(pFile))
		{
			cont = fread(&auxEmployee,sizeof(Employee),1,pFile);

			if(cont == 1)
			{
				pEmployee = employee_new();
				if(pEmployee != NULL)
				{
					*pEmployee = auxEmployee;
					ll_add(pArrayListEmployee, pEmployee);

					retorno = 0;
				}
			}


		}
		fclose(pFile);
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Archivo data.csv abierto en modo lectura.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* pEmployee = NULL;
	//int cantidadDeDatosLeidos;
	int indice;
	int retorno = 1;

	if(pArrayListEmployee != NULL)
	{
		fprintf(pFile, "%s,%s,%s,%s\n", "Id", "Nombre", "HorasTrabajadas", "Sueldo");
		for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
		{
			pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
			fprintf(pFile, "%d,%s,%d,%d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* Archivo data.bin abierto en modo lectura.
 * \param pArrayListEmployee LinkedList* LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int parser_BinaryFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int retorno = 1;
    int indice;
    if(pArrayListEmployee != NULL)
    {
    	for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
		{
    		pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);

		}
    	retorno = 0;
    }

    return retorno;
}
