/*
 * Menu.c
 *
 *  Created on: 16 sep. 2021
 *      Author: MartinGonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

/** \brief Imprime el menu principal en pantalla.
 *
 * \param void
 * \return void
 *
 */
void menuPrincipal_print(void)
{
    printf("1) Inicializar\n");
    printf("2) Cargar\n");
    printf("3) Mostrar\n");
    printf("4) Calcular Promedio\n");
    printf("5) Ordenar\n");
    printf("6) Salir\n");

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
    pedirEntero(&opcion, "\nIntroduzca una opcion: ", "\nError, opcion invalida. Introduzca una opcion valida: ", 1, 6);
    fflush(stdin);
    return opcion;
}

