#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Menu.h"
#include "Biblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo = NULL;
	FILE* archivoUltimoId;
	int retorno = 1;
	int lastId;
	//int id;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			fclose(pArchivo);
			retorno = 0;
		}





	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se ubican los datos.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    int retorno = 1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
    	pArchivo=fopen(path, "rb");


        if(pArchivo !=NULL)
        {
        	parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        	fclose(pArchivo);
        	retorno = 0;
        }

    }
    return retorno;
}

/** \brief Alta de empleados.
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada a la cual se agrega el empleado.
 * \return int Devuelve 0 si se realizo, 2 si se cancelo la carga o 1 en caso de puntero NULL.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee = NULL;
	//Employee* auxEmployee = NULL;
	FILE* archivoUltimoId;
	char id[15];
	char nombre[128];
	char horasTrabajadas[15];
	char sueldo[15];
	char respuesta;
	int lastId;
	int retorno = 1;
	if(pArrayListEmployee != NULL)
	{

		//auxEmployee = (Employee *)ll_get(pArrayListEmployee, (ll_len(pArrayListEmployee)) - 1);
		//employee_getId(auxEmployee, &lastId);





		archivoUltimoId = fopen("ultimo_id.txt","r");
		if(archivoUltimoId != NULL)
		{
			//fgets(id,15, archivoUltimoId);
			fscanf(archivoUltimoId, "%d", &lastId);

			fclose(archivoUltimoId);
		}

		archivoUltimoId = fopen("ultimo_id.txt","w");
		if(archivoUltimoId != NULL)
		{
			lastId++;
			fprintf(archivoUltimoId, "%d",lastId);
			printf("%d", lastId);
			fclose(archivoUltimoId);

		}

		PedirStringCaracteresAlfabeticos(nombre, 128, "\nIntroduzca nombre: ", "\nError, nombre invalido. Introduzca nombre nuevamente: ");
		PedirStringDeNumerosPositivo(horasTrabajadas, 15, "\nIntroduzca horas trabajadas: ", "\nError, cantidad de horas invalida. Introduzca horas nuevamente: ");
		PedirStringDeNumerosPositivo(sueldo, 15, "\nIntroduzca sueldo: ", "\nError, sueldo invalido. Introduzca sueldo nuevamente: ");
		pEmployee = employee_newParametros(itoa(lastId, id,10), nombre, horasTrabajadas, sueldo);
		if(pEmployee != NULL)
		{
			printf("\n");
			employee_print(pEmployee);
			respuesta = PedirRespuestaSN("\n\nDesea agregar empleado?(s para si / n para no):\n");
			if(respuesta == 's')
			{
				ll_add(pArrayListEmployee, pEmployee);
				retorno = 0;

			} else
			{
				employee_delete(pEmployee);
				retorno = 2;

			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtiene el empleado.
 * \return int Devuelve 0 si se realizo, o 1 en caso de puntero NULL.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id_aBuscar;
    int id;
    Employee* pEmployee = NULL;
    int opcion;
    int indice;
    int idEncontrado = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int retorno = 1;
    if(pArrayListEmployee != NULL)
    {
        PedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
            employee_getId(pEmployee, &id);
            if(id == id_aBuscar)
            {
                idEncontrado = 1;
                printf("\nId encontrado.\n\n");
                break;
            }
        }
        if(idEncontrado == 1)
        {
            printf("%5s | %15s | %16s | %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
            employee_print(pEmployee);
            printf("\n");
            opcion = menuEditEmployee();
            switch(opcion)
            {
                case 1:
                	PedirStringCaracteresAlfabeticos(nombre, 128, "\nIntroduzca el nuevo nombre: ", "\nError, nombre invalido. Introduzca el nuevo nombre: ");
                    employee_setNombre(pEmployee, nombre);
                    printf("\nNombre modificado.\n");
                    employee_print(pEmployee);
                    retorno = 0;
                    break;
                case 2:
                    PedirEntero(&horasTrabajadas, "\nIntroduzca la nueva cantidad de horas trabajadas: ", "\nError cantidad invalida. Introduzca la cantidad nuevamente: ", 0, 400);
                    employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
                    printf("\nCantidad de horas modificada.\n");
                    employee_print(pEmployee);
                    retorno = 0;
                    break;
                case 3:
                    PedirEntero(&sueldo, "\nIntroduzca el nuevo sueldo: ", "\nError, sueldo invalido. Introduzca el sueldo nuevamente: ", 1000, 5000000);
                    employee_setSueldo(pEmployee, sueldo);
                    printf("\nSueldo modificado.\n");
                    employee_print(pEmployee);
                    retorno = 0;
                    break;
                case 4:

                	retorno = 2;
                    break;
            }
        }

    }
    return retorno;
}

/** \brief Baja de empleado
 *
* \param pArrayListEmployee LinkedList* Lista linkeada donde se obtiene el empleado.
 * \return Devuelve 0 si se realizo, 2 si se cancelo, 3 si no se encontro ID o 1 en caso de puntero NULL.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id_aBuscar;
    int id;
    Employee* pEmployee  = NULL;
    char respuesta;
    int indice;
    int idEncontrado = 0;
    int retorno = 1;
    if(pArrayListEmployee != NULL)
    {
    	PedirEntero(&id_aBuscar, "\nIntroduzca el id a buscar: ", "\nError, id invalido. Introduzca el id nuevamente: ", 0, 1000000);
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
            employee_getId(pEmployee, &id);
            if(id == id_aBuscar)
            {
                idEncontrado = 1;
                printf("\nId encontrado.\n\n");
                break;
            }
        }
        if(idEncontrado == 1)
        {
            printf("%5s | %15s | %16s | %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
            employee_print(pEmployee);
            respuesta = PedirRespuestaSN("\nDesea eliminar empleado?(s para si / n para no):\n");
            if(respuesta == 's')
            {
                employee_delete(pEmployee);
                ll_remove(pArrayListEmployee, indice);
                retorno = 0;//printf("\nEmpleado eliminado.\n");
            } else
            {
                retorno = 2;//printf("\nEmpleado no eliminado.\n");
            }
        } else
        {
            retorno = 3;//printf("\nId no encontrado.\n");
        }

    }
    return retorno;
}

/** \brief Listar empleados
 *
  * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int indice;
    int retorno = 1;
    if(pArrayListEmployee != NULL)
    {
        printf("%5s | %15s | %16s | %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
                pEmployee = (Employee *)ll_get(pArrayListEmployee, indice);
                employee_print(pEmployee);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
  * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = 1;
    LinkedList* pAuxListEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        pAuxListEmployee = ll_clone(pArrayListEmployee);
        opcion = menuSortEmployee();
        switch(opcion)
        {
            case 1:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararId, 0);
                printf("\nLista de empleados ordenada por Id(mayor a menor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 2:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararNombre, 1);
                printf("\nLista de empleados ordenada por nombre(A-Z).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 3:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararNombre, 0);
                printf("\nLista de empleados ordenada por nombre(Z-A).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 4:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararHorasTrabajadas, 1);
                printf("\nLista de empleados ordenada por cantidad de horas trabajadas(menor a mayor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 5:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararHorasTrabajadas, 0);
                printf("\nLista de empleados ordenada por cantidad de horas trabajadas(mayor a menor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 6:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararSueldo, 1);
                printf("\nLista de empleados ordenada por sueldo(menor a mayor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 7:
                printf("Ordenando...\n");
                ll_sort(pAuxListEmployee, employee_CompararSueldo, 0);
                printf("\nLista de empleados ordenada por sueldo(mayor a menor).\n\n");
                controller_ListEmployee(pAuxListEmployee);
                break;
            case 8:
                printf("\nLista no ordenada.\n");
                break;
        }
        ll_deleteLinkedList(pAuxListEmployee);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
  * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    //Employee* auxEmployee = NULL;
    //int indice;
    int retorno = 1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            retorno = parser_TextFromEmployee(pArchivo ,pArrayListEmployee);
        }
        fclose(pArchivo);
        //printf("Archivo guardado.\n");

        //retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Nombre y ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista linkeada donde se obtienen los empleados.
 * \return int Devuelve 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = NULL;
    //Employee* auxEmployee = NULL;
    //int indice;
    int retorno = 1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "wb");
        if(pArchivo != NULL)
        {
        	retorno = parser_BinaryFromEmployee(pArchivo, pArrayListEmployee);
        }
        fclose(pArchivo);

    }
    return retorno;
}

