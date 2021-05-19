/*
 * Biblioteca.c
 *
 *  Created on: 14 abr. 2021
 *      Author: MartinGonzalez
 */

#include "Biblioteca.h"
#include <stdio.h>


float sumar(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

float multiplicaciones (float primerNumero, float segundoNumero)
{
    float multiplicacion;
    multiplicacion = primerNumero * segundoNumero;
    return multiplicacion;
}

float restar (float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}
float divisiones(float primerNumero, float segundoNumero)
{
    float division;
    division = primerNumero / segundoNumero;

    return division;
}

int calcularFactorial(int numero)
{
    int factorial;
    int i;
    factorial = 1;

    for(i=1; i<=numero;i++)
	{
		factorial = factorial * i;
	}

    return factorial;
}




