/*
 * Biblioteca.c
 *
 *  Created on: 10 jun. 2021
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

/** \brief Pide al usuario un numero positivo en forma de string.
 *
 * \param arrayLetras[] char Array donde se recibe el string.
 * \param tamanio int Dimension del array.
 * \param mensaje[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje a mostrar en caso de que los datos recibidos no sean validos.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int pedirStringDeNumerosPositivo(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                if(comprobarStringNumericoPositivo(arrayAuxiliar, (strlen(arrayAuxiliar) + 1)) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);
        strncpy(arrayLetras, arrayAuxiliar, strlen(arrayAuxiliar) + 1);
        return 0;
    }
    return 1;
}

/** \brief Pide al usuario un string de caracteres alfabeticos unicamente.
 *
 * \param arrayLetras[] char Array donde se recibe el string.
 * \param tamanio int Dimension del array.
 * \param mensaje[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje a mostrar en caso de que los datos recibidos no sean validos.
 * \return int Retorna 0 si se realizo o 1 en caso de puntero NULL.
 *
 */
int pedirStringSoloLetras(char arrayLetras[], int tamanio, char mensaje[], char mensajeError[])
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    if(arrayLetras != NULL && tamanio > 0)
    {
        printf("%s", mensaje);
        do
        {
            error = 0;
            fflush(stdin);
            fgets(arrayAuxiliar, (tamanio + 1), stdin);
            if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
            {
                error = 1;
            } else
            {
                arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
                if(comprobarStringSoloLetras(arrayAuxiliar, strlen(arrayAuxiliar) + 1) != 1)
                {
                    error = 1;
                }
            }
            if(error == 1)
            {
                printf("%s", mensajeError);
            }
        }while(error == 1);

        strncpy(arrayLetras, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
        return 0;
    }
    return 1;
}

/** \brief Comprueba si el string recibido tiene solo caracteres numericos positivos.
 *
 * \param cadenaNumerica[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarStringNumericoPositivo(char cadenaNumerica[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        retorno = 1;
        if(strlen(cadenaNumerica) == 0 || strlen(cadenaNumerica) >= tamanio)
        {
            retorno = 0;
        } else
        {
            for(indice = 0; indice < tamanio; indice++)
            {
                if(cadenaNumerica[indice] == '\0')
                {
                    break;
                }
                if(isdigit(cadenaNumerica[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
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

/** \brief  Comprueba si el string recibido tiene unicamente caracteres alfabeticos.
 *
 * \param stringLetras[] char Array a evaluar.
 * \param tamanio int Dimesion del array.
 * \return int Retorna 1 si el string es correcto, 0 si no lo es o -1 en caso de puntero NULL.
 *
 */
int comprobarStringSoloLetras(char stringLetras[], int tamanio)
{
    int retorno = -1;
    int indice;
    if(stringLetras != NULL && tamanio > 0)
    {
        retorno = 1;
        if(strlen(stringLetras) == 0 || strlen(stringLetras) >= tamanio)
        {
            retorno = 0;
        } else
        {
            for(indice = 0; indice < tamanio; indice++)
            {
                if(stringLetras[indice] == '\0')
                {
                    break;
                }
                if(isalpha(stringLetras[indice]) == 0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Solicita al usuario una respuesta SI o NO y la devuelve en un unico caracter.
 *
 * \param mensaje[] char Mensaje a mostrar.
 * \return char Devuelve 'n' para NO y 's' para SI.
 *
 */
char pedirRespuestaSN(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    do
    {
        fflush(stdin);
        respuesta = getchar();
        respuesta = tolower(respuesta);
        if(respuesta != 's' && respuesta != 'n')
        {
            printf("\nRespuesta invalida. Ingrese s(para si) o n (para no): ");
        }
    } while(respuesta != 's' && respuesta != 'n');
    return respuesta;
}
