/*
 ============================================================================
 Name        : Laboratorio_TP1.c
 Author      : Martin Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Biblioteca.h"

int main(void) {

	 setbuf(stdout, NULL);



	    float primerNumero = 0;
	    float segundoNumero = 0;
	    float suma;
	    float resta;
	    float multiplicacion;
	    float division;
	    long int factorialA;
	    long int factorialB;
	    int opcion;

	    printf("                            ---------------------\n"
	           "                              ***CALCULADORA***\n"
	           "                            ---------------------\n"
	           "Instrucciones: \n\n"
	           "La calculadora tiene las siguientes opciones que lo seguiran a lo largo del \n"
	           "proceso: \n\n");


	    do
	    {

	        printf("\n1.Ingresar 1er operando (A=%.4f)\n\n", primerNumero);
	        printf("2.Ingresar 2do operando (B=%.4f)\n\n", segundoNumero);
	        printf("3.Calcular todas las operaciones (suma, resta, multiplicacion, \n\n"
	               "division, factorial de los dos numeros ingresados). \n\n"
	               "4.Informar resultados. \n\n"
	               "5.Salir de la calculadora. \n\n"
	               "Elija una de las siguientes opciones dadas con las teclas del 1 al 5. \n\n");
	        scanf("%d", &opcion);
	        switch(opcion)
	        {
	        case 1:
	            printf("|------------------------------------|\n"
	                   "   Ingrese su primer operando: ");
	            scanf("%f", &primerNumero);
	            printf("|------------------------------------|");
	            break;
	        case 2:
	            printf("|------------------------------------|\n"
	                   "   Ingrese su segundo operando: ");
	            scanf("%f", &segundoNumero);
	            printf("|------------------------------------|");
	            break;
	        case 3:
	            suma = sumar(primerNumero, segundoNumero);
	            resta = restar(primerNumero, segundoNumero);
	            multiplicacion = multiplicaciones(primerNumero, segundoNumero);
	            division = divisiones(primerNumero, segundoNumero);
	            factorialA = calcularFactorial(primerNumero);
	            factorialB = calcularFactorial(segundoNumero);

	            printf(" |====================================================================|"
	                   "  \n  Tus operaciones fueron realizadas, presione 4 para ver el resultado. \n"
	                   " |====================================================================|");
	            break;
	        case 4:
	            printf("===================================================================");
	            printf("\nEl resultado de A+B es: %.4f \n",suma);
	            printf("\nEl resultado de A-B es: %.4f \n",resta);
	            printf("\nEl resultado de A/B es: %.4f \n\n",division);
	            if(segundoNumero == 0)
	            {
	                printf("^^                              ^^"
	                       "\n||No es posible dividir por cero||\n\n");
	            }
	            printf("El resultado de A*B es: %.4f \n",multiplicacion);

	            if(primerNumero < 0)
	            {   printf(
	                       "\n||No es posible hacer el factorial de un numero menor a cero||\n");
	            }else{
	            	printf("\nEl factorial de A es: %ld \n",factorialA);
	            }

	            if(segundoNumero < 0)
	            {
	                printf(
	                       "\n||No es posible hacer el factorial de un numero menor a cero||\n");
	            }else{
	            	printf("\nEl factorial de B es: %ld \n",factorialB);
	            }
	            printf("===================================================================");
	            break;
	        case 5:
	         printf("                         ---------------------------\n"
	           "                           ***TENGA UN BUEN DIA***\n"
	           "                         ---------------------------\n");
	            break;
	        default:
	            printf("Opcion incorrecta, por favor elejir teclas del 1 al 5 \n\n");
	        }

	    }
	    while( opcion != 5);
	return EXIT_SUCCESS;
}
