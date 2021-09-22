/*
 * Funciones.c
 *
 *  Created on: 16 sep. 2021
 *      Author: MartinGonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"
#include "Biblioteca.h"


/// Solicita un número entero al usuario.
///
/// @param texto Es el mensaje mostrado al solicitar el número.
/// @return retorna el número pedido
float PedirNumero(char texto[]){
    float numero;
    printf("%s", texto);
    setbuf(stdin, NULL);
    scanf("%f", &numero);
    return numero;
}

/// Calcula la suma de dos numeros
///
/// @param primerNumero primer número del cálculo
/// @param segundoNumero segundo número del cálculo
/// @return retorna el resultado de la suma
float Sumar(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

/// Calcula la multiplicación de dos numeros
///
/// @param primerNumero primer número del cálculo
/// @param segundoNumero segundo número del cálculo
/// @return retorna el resultado de la multiplicación
float Multiplicaciones (float primerNumero, float segundoNumero)
{
    float multiplicacion;
    multiplicacion = primerNumero * segundoNumero;
    return multiplicacion;
}


/// Calcula la resta de dos numeros
///
/// @param primerNumero primer número del cálculo
/// @param segundoNumero segundo número del cálculo
/// @return retorna el resultado de la resta
float Restar (float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

/// Calcula la división de dos numeros
///
/// @param primerNumero primer número del cálculo
/// @param segundoNumero segundo número del cálculo
/// @return retorna el resultado de la división

float Divisiones(float primerNumero, float segundoNumero)
{
    float division;
    division = primerNumero / segundoNumero;

    return division;
}

/// Calcula el factorial un número
///
/// @param numero número con el que vamos a trabajar
///
/// @return retorna el factorial del numero
long int CalcularFactorial(int numero){
    long int resultado;
    int i;
    resultado = 1;
    for(i = numero; i >= 1; i--){
        resultado = resultado * i;
    }
    return resultado;
}

/// brief Comprueba si es posible aplicar la factorizacion a un numero flotante
///
/// @param numero número con el que vamos a trabajar.
/// @return rotrna 0 si NO es posible aplicar la factorizacion y 1 si se puede
int ComprobarFactorizacion(float numero){
    int esEntero;
    esEntero = ComprobarEntero(numero);
    if(numero >= 0 && esEntero == 1){
        return 1;
    } else {
        return 0;
    }
}

/// Comprueba si un numero flotante es entero
///
/// @param numero número con el que vamos a trabajar
/// @return retorna 0 si NO lo es y 1 si lo es
int ComprobarEntero(float numero){
    int enteroDelNumero = numero;
    float resultado;
    resultado = numero - enteroDelNumero;
    if(resultado > 0 || resultado < 0){
        return 0;
    } else
        return 1;
}
