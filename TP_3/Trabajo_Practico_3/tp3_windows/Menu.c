/*
 * Menu.c
 *
 *  Created on: 3 nov. 2021
 *      Author: RocioGonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Menu.h"

/** \brief Imprime el menu principal en pantalla.
 *
 * \param void
 * \return void
 *
 */
void menuPrincipal_print(void)
{
    printf("1) Cargar los datos de los empleados desde el archivo data.csv\n");
    printf("2) Cargar los datos de los empleados desde el archivo data.bin\n");
    printf("3) Alta de empleado\n");
    printf("4) Modificar datos de empleado\n");
    printf("5) Baja de empleado\n");
    printf("6) Listar empleados\n");
    printf("7) Ordenar empleados\n");
    printf("8) Guardar los datos de los empleados en el archivo data.csv\n");
    printf("9) Guardar los datos de los empleados en el archivo data.bin\n");
    printf("10) Salir\n");
}

/** \brief Imprime el menu de edicion de un empleado en pantalla.
 *
 * \param void
 * \return void
 *
 */
void menuEditEmployee_print(void)
{
    printf("1) Modificar nombre\n");
    printf("2) Modificar cantidad de horas trabajadas\n");
    printf("3) Modificar sueldo\n");
    printf("4) Salir\n");
}

/** \brief Imprime el menu para ordenar la lista de empleados en pantalla.
 *
 * \param void
 * \return void
 *
 */
void menuSortEmployee_print(void)
{
    printf("1) Ordenar por Id(mayor a menor)\n");
    printf("2) Ordenar por nombre(A-Z)\n");
    printf("3) Ordenar por nombre(Z-A)\n");
    printf("4) Ordenar por cantidad de horas trabajadas(menor a mayor)\n");
    printf("5) Ordenar por cantidad de horas trabajadas(mayor a menor)\n");
    printf("6) Ordenar por sueldo(menor a mayor)\n");
    printf("7) Ordenar por sueldo(mayor a menor)\n");
    printf("8) Salir\n");
}

/** \brief Pregunta al usuario por una opcion del menu principal y la devuelve.
 *
 * \param void
 * \return int
 *
 */
int menuPrincipal(void)
{
    int opcion;
    printf("\n");
    menuPrincipal_print();
    PedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 10);
    fflush(stdin);
    return opcion;
}

/** \brief Pregunta al usuario por una opcion del menu de edicion de un empleado y la devuelve.
 *
 * \param void
 * \return int
 *
 */
int menuEditEmployee(void)
{
    int opcion;
    printf("\n");
    menuEditEmployee_print();
    PedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 4);
    return opcion;
}

/** \brief Pregunta al usuario por una opcion del menu menu para ordenar la lista de empleados y devuelve la opcion.
 *
 * \param void
 * \return int
 *
 */
int menuSortEmployee(void)
{
    int opcion;
    printf("\n");
    menuSortEmployee_print();
    PedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 8);
    return opcion;
}
