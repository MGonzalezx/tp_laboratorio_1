/*
 * Menu.c
 *
 *  Created on: 1 nov. 2021
 *      Author: MartinGonzalez
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
	printf("1. ALTAS");
	printf("\n2. MODIFICAR");
	printf("\n3. BAJAS.");
	printf("\n4. INFORMAR");
	printf("\n5. SALIR");

}



/** \brief Pregunta al usuario por una opcion del menu principal y la devuelve.
 *
 * \param void
 * \return int Retorna la opcion del menu que selecciona el usuario
 *
 */
int menuPrincipal(void)
{
    int opcion;
    printf("\n");
    menuPrincipal_print();
    PedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 5);
    fflush(stdin);
    return opcion;
}

/** \brief Imprime el menu de edicion de un cliente en pantalla.
 *
 * \param void
 * \return void
 *
 */

void menuEditarEmpleado_print(void)
{

	printf("\n1. Editar Nombre.");
	printf("\n2. Editar Apellido.");
	printf("\n3. Editar Salario.");
	printf("\n4. Editar Sector.");
	printf("\n5. Nada, salir.");
	printf("Elija una opcion: ");
}

/** \brief Pregunta al usuario por una opcion del menu de edicion de un cliente y la devuelve.
 *
 * \param void
 * \return int
 *
 */

int menuEditarEmpleado(void)
{
    int opcion;
    printf("\n");
    menuEditarEmpleado_print();
    PedirEntero(&opcion, "\n¿Que desea modificar? ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 5);
    return opcion;
}

void menuInformarEmpleado_print(void)
{

	printf("\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.");
	printf("\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.");
	printf("\n3. Nada, salir.");
	printf("Elija una opcion: ");
}

/** \brief Pregunta al usuario por una opcion del menu de edicion de un cliente y la devuelve.
 *
 * \param void
 * \return int
 *
 */

int menuInformarEmpleado(void)
{
    int opcion;
    printf("\n");
    menuInformarEmpleado_print();
    PedirEntero(&opcion, "\n¿Que desea ver? ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 3);
    return opcion;
}
