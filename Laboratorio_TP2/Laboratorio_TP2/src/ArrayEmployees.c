/*
 * ArrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: MartinGonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define FALSE 0
#define TRUE 1




static int ultimoID()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}


int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = TRUE;
            list[i].id= 0;
        }
    }
    return retorno;
}

int searchFreeSpaceEmployee(Employee* list, int len)
{
    int index = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        index = -2;
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}




int cargar_Employee(Employee* list, int len)
{
    int index = searchFreeSpaceEmployee(list, len);
    int retorno = 0;
    float salarioCorrecto = 0;
    int sectorCorrecto = 0;
    getchar();
    if(index >=0)
    {

        char buffer[1024];

        Employee myEmployee;

        myEmployee.id = ultimoID();

        printf("\nID: %d", myEmployee.id);

        printf("\nIngrese Nombre: ");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>51 || !esSoloLetras(buffer))
        {
            printf("Reingrese Nombre: ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(myEmployee.name, buffer);

        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>51 || !esSoloLetras(buffer))
        {
            printf("Reingrese Apellido: ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(myEmployee.lastName, buffer);

        printf("Ingrese Salario: ");
        while(!salarioCorrecto)
        {
            fflush(stdin);
            gets(buffer);
            if(esNumerico(buffer))
            {
                myEmployee.salary = atoi(buffer);

                if(myEmployee.salary <= 0 || myEmployee.salary > 1000)
                {
                    printf("Error! Reingresar sueldo entre 1 y 1000: \n");
                }
                else
                {
                    salarioCorrecto = 1;
                }
            }
            else
            {
                printf("Error! Ingresar salario Numerico: ");
            }
        }

        printf("Ingrese Sector: ");
        while(!sectorCorrecto)
        {
            fflush(stdin);
            gets(buffer);
            if(esNumerico(buffer))
            {
                myEmployee.sector = atoi(buffer);

                if(myEmployee.sector <= 0 || myEmployee.sector > 50)
                {
                    printf("Error! Reingresar sueldo entre 1 y 50: \n");
                }
                else
                {
                    sectorCorrecto = 1;
                }
            }
            else
            {
                printf("Error! Ingresar sector Numerico: ");
            }

        }
        addEmployee(list, len, myEmployee.id, myEmployee.name, myEmployee.lastName, myEmployee.salary, myEmployee.sector);
        retorno = 1;
    }
    /*else
    {
        printf("\nERROR indice invalido u ocupado.\n");
    }*/

    return retorno;

}

int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector)
{
    int index;
    if(list != NULL && len > 0)
    {
        index = searchFreeSpaceEmployee(list, len);
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

void mostrar_Un_Employee(Employee unEmployee)
{

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
                mostrar_Un_Employee(list[i]);
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
    char opcion;
    int id;
    int retorno = -1;
    if(list != NULL && len > 0)
    {

        printf("Ingrese ID del Employee a dar de baja: ");
        scanf("%d", &id);
        for(i=0; i<len; i++)
        {
            if(id==list[i].id)
            {
                printf("\nID encontrado: \n");
                /*printf("%s  %10s  %12s  %7s  %14s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
                mostrar_Un_Employee(list[i]);*/
                printf("Nombre: %s\n", list[i].name);
                printf("Apellido: %s\n", list[i].lastName);
                printf("Salario: %.2f\n", list[i].salary);
                printf("sector: %d\n", list[i].sector);

                printf("\n Seguro desea dar de baja? s=si n=no\n ");
                scanf("%s", &opcion);
                if(opcion=='s')
                {
                    list[i].id=0;
                    list[i].isEmpty = FALSE;
                    retorno = 0;

                }
                else
                {
                    printf("\nEl Employee no fue eliminado!\n");
                }

                break;
            }
        }

    }
    return retorno;
}
int sortEmployeesByLastName(Employee* list, int len, int order)
{
    int indice;
    int j;
    Employee auxiliar;
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
                }
                if(order == 1)
                {
                    while(j >= 0 && strcmp(auxiliar.lastName, list[j].lastName) > 0)
                    {
                        list[j + 1] = list[j];
                        j--;
                    }
                }
                list[j + 1] = auxiliar;
            }
        }
        printEmployees(list, len);
        return 0;
    }
    return -1;
}

int sortEmployeesBySector(Employee* list, int len, int order)
{
    int indice;
    int j;
    Employee auxiliar;
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
                    while(j >= 0 && auxiliar.sector < list[j].sector && list[j].isEmpty == FALSE)
                    {
                        list[j + 1] = list[j];
                        j--;
                    }
                }
                if(order == 1)
                {
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
        return 0;
    }
    return -1;
}


int modificar_Employee(Employee list[], int len)
{
    Employee miEmployee;
    char buffer[1024];
    char opcion;
    int id;
    int i;
    int retorno = 0;
    printf("Ingrese un ID del Employee a buscar: ");
    scanf("%d", &id);

    for(i=0; i<len; i++)
    {
        printf("%d", list[i].id);
        if(id == list[i].id)
        {

            printf(".ID del Employee encontrado!!\n");





            do
            {
                printf("\n??Que cambios desea hacer?");
                printf("\na. Cambiar Nombre");
                printf("\nb. Cambiar Apellido ");
                printf("\nc. Cambiar Salario");
                printf("\nd. Cambiar Sector");
                printf("\nz. Ninguno, salir");
                printf("\nIngrese una opcion: \n");
                scanf("%s", &opcion);
                switch(opcion)
                {
                case 'a':
                    printf("\nIngrese el nuevo Nombre: ");
                    fflush(stdin);
                    gets(buffer);
                    while(strlen(buffer)>51)
                    {
                        printf("Reingrese Nombre: ");
                        fflush(stdin);
                        gets(buffer);
                    }
                    strcpy(miEmployee.name, buffer);

                    printf("??Esta seguro que desea modificar el Nombre? s=si n=no\n ");
                    scanf("%s", &opcion);
                    if(opcion=='s')
                    {
                        strcpy(list[i].name, miEmployee.name);
                        retorno = 1;

                    }
                    else
                    {
                        printf("El Nombre no fue modificado!!\n");
                    }
                    break;
                case 'b':
                    printf("\nIngrese el Apellido: ");
                    fflush(stdin);
                    gets(buffer);
                    while(strlen(buffer)>51)
                    {
                        printf("Reingrese Apellido: ");
                        fflush(stdin);
                        gets(buffer);
                    }
                    strcpy(miEmployee.lastName, buffer);

                    printf("??Esta seguro que desea modificar el Apellido? s=si n=no\n ");
                    scanf("%s", &opcion);
                    if(opcion=='s')
                    {
                        strcpy(list[i].lastName, miEmployee.lastName);
                        retorno = 1;

                    }
                    else
                    {
                        printf("El Apellido no fue modificado!!\n");
                    }
                    break;
                case 'c':
                    printf("\nIngrese el nuevo salario: ");


                        fflush(stdin);
                        gets(buffer);
                        if(esNumerico(buffer))
                        {
                            miEmployee.salary = atoi(buffer);

                            if(miEmployee.salary <= 0 || miEmployee.salary > 1000)
                            {
                                printf("Error! Reingresar sueldo entre 1 y 1000: \n");
                            }

                        }
                        else
                        {
                            printf("Error! Ingresar salario Numerico: ");
                        }


                    printf("??Esta seguro que desea modificar el salario? s=si n=no\n ");
                    scanf("%s", &opcion);
                    if(opcion=='s')
                    {
                        list[i].salary = miEmployee.salary;
                        retorno = 1;

                    }
                    else
                    {
                        printf("El salario no fue modificado!!\n");
                    }
                    break;
                case 'd':
                    printf("\nIngrese el nuevo sector: ");


                        fflush(stdin);
                        gets(buffer);
                        if(esNumerico(buffer))
                        {
                            miEmployee.sector = atoi(buffer);

                            if(miEmployee.sector <= 0 || miEmployee.sector > 50)
                            {
                                printf("Error! Reingresar sueldo entre 1 y 50: \n");
                            }

                        }
                        else
                        {
                            printf("Error! Ingresar sector Numerico: ");
                        }



                    printf("??Esta seguro que desea modificar el sector? s=si n=no\n ");
                    scanf("%s", &opcion);
                    if(opcion=='s')
                    {
                        list[i].sector = miEmployee.sector;
                        retorno = 1;

                    }
                    else
                    {
                        printf("El sector no fue modificado!!\n");
                    }
                    break;
                }
            }
            while(opcion !='z');

           break;

        }
    }

    return retorno;

}

int contarAltasEmployee(Employee* list, int len)
{
    int retorno = -1;
    int indice;
    if(list != NULL && len > 0)
    {
        retorno = 0;
        for(indice = 0; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                retorno++;
            }
        }
    }
    return retorno;
}

float sumar_Salarios(Employee* list, int len)
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

float promedio_Salarios(Employee* list, int len)
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
            totalSalarios = sumar_Salarios(list, len);
            promedio = totalSalarios / contadorSalarios;
        }
    }
    return promedio;


}

int cantidad_Salarios_Superando_Promedio(Employee* list, int len)
{
    int index;
    int contador = -1;
    float promedio;
    if(list != NULL && len > 0)
    {
        contador = 0;
        promedio = promedio_Salarios(list, len);
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

