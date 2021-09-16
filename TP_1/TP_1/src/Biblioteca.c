/*
 * Biblioteca.c
 *
 *  Created on: 16 sep. 2021
 *      Author: MartinGonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"

/** \brief Solicita un numero entero al usuario.
 *
 * \param pEntero int* Puntero donde se recibe el numero.
 * \param mensaje[] char Es el mensaje mostrado al solicitar el numero.
 * \param mensajeError[] char Es el mensaje mostrado en caso de ingreso invalido o fuera del rango.
 * \param minimo int  El numero minimo aceptado inclusive.
 * \param maximo int El numero maximo aceptado inclusive.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int pedirEntero(int* pEntero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    char array[13];
    int numero;
    int error;
    if(pEntero != NULL)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(array, 13, stdin);
            if(array[(strlen(array) - 1)] != '\n')
            {
                error = 1;
            } else
            {
                /**Devuelve 1 si ES NUMERICA y 0 si NO ES */
                if(comprobarArrayNumericaEntero(array, (strlen(array) - 1)) == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atoi(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    } else
                    {
                        *pEntero = numero;
                    }
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        } while(error == 1);
        return 0;
    }
    return 1;
}

/** \brief Comprueba si el string recibido forma un numero entero.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarArrayNumericaEntero(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(isdigit(cadenaNumerica[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

