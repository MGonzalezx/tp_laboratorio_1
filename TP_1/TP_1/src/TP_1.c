/*
 ============================================================================
 Name        : TP_1.c
 Author      : MartinGonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Funciones.h"

int main(void) {
	setbuf(stdout, NULL);//disable buffer
	int opcion;
	float primerOperando;
	float segundoOperando;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	int primerOperandoEntero;
	int segundoOperandoEntero;
	long int factorialPrimerOperando;
	long int factorialSegundoOperando;
	/* Banderas */
	int primerOperandoIngresado = 0;
	int segundoOperandoIngresado = 0;
	int cambioDeOperando = 0;
	int divisionPorCero = 0;
	int calculosRealizados = 0;
	int posibleFactorizarPrimerOperando;
	int posibleFactorizarSegundoOperando;


	printf("                            ---------------------\n"
		   "                              ***CALCULADORA***\n"
		   "                            ---------------------\n"
		   "Instrucciones: \n\n"
		   "La calculadora tiene las siguientes opciones que lo seguiran a lo largo del proceso: \n\n");



	do
	{
		if(primerOperandoIngresado == 0){
			printf("1) Ingresar primer operando\n\n");
		} else {
			printf("1) Ingresar primer operando (Valor actual = %.3f)\n\n", primerOperando);
		}
		if(segundoOperandoIngresado == 0){
			printf("2) Ingresar segundo operando\n");
		} else {
			printf("2) Ingresar segundo operando (Valor actual = %.3f)\n", segundoOperando);
		}
		opcion = menuPrincipal();

		switch(opcion)
		{
			case 1:
				 printf("|------------------------------------|\n");
						 primerOperando = PedirNumero("\nIngrese el primer operando: ");
						printf("\nPrimer operando: %.3f\n\n", primerOperando);
						primerOperandoIngresado = 1;
						cambioDeOperando = 1;
						posibleFactorizarPrimerOperando = ComprobarFactorizacion(primerOperando);
				printf("|------------------------------------|\n\n");

				break;
			case 2:
				 printf("|------------------------------------|\n");
						 segundoOperando = PedirNumero("\nIngrese el segundo operando: ");
						printf("\nSegundo operando: %.3f\n\n", segundoOperando);
						segundoOperandoIngresado = 1;
						cambioDeOperando = 1;
						posibleFactorizarSegundoOperando = ComprobarFactorizacion(segundoOperando);
				printf("|------------------------------------|\n\n");

				break;
			case 3:
				 if(primerOperandoIngresado == 1 && segundoOperandoIngresado == 1){
					suma = Sumar(primerOperando, segundoOperando);
					resta = Restar(primerOperando, segundoOperando);
				if(segundoOperando == 0){
					divisionPorCero = 1;
				} else {
					division = Divisiones(primerOperando, segundoOperando);
				}
					multiplicacion = Multiplicaciones(primerOperando, segundoOperando);
				if(posibleFactorizarPrimerOperando == 1){
					primerOperandoEntero = primerOperando;
					factorialPrimerOperando = CalcularFactorial(primerOperandoEntero);
				}
				if(posibleFactorizarSegundoOperando == 1){
					segundoOperandoEntero = segundoOperando;
					factorialSegundoOperando = CalcularFactorial(segundoOperandoEntero);
				}
					calculosRealizados = 1;
					cambioDeOperando = 0;
					 printf("|------------------------------------|\n");
					printf("\nLos calculos se han completado.\n");
					 printf("\n|------------------------------------|\n\n");
				} else {
					 printf("|---------------------------------------------------------------|\n");
					printf("\nFalta ingresar algun operando, los calculos no se han realizado.\n");
					 printf("\n|---------------------------------------------------------------|\n\n");
				}

				printf("\nPresione Enter para continuar\n");
				getchar();
				break;
			case 4:
				if(calculosRealizados == 1 && cambioDeOperando == 0){


					printf("\nResultados:\n");
					printf("a) El resultado de %.3f + %.3f es: %.3f\n", primerOperando, segundoOperando, suma);

					printf("b) El resultado de %.3f - %.3f es: %.3f\n", primerOperando, segundoOperando, resta);

				if(divisionPorCero == 0){

					printf("c) El resultado de %.3f / %.3f es: %.3f\n", primerOperando, segundoOperando, division);

				} else{

					printf("c) No es posible dividir un numero por cero.\n");

				}

					printf("c) El resultado de %.3f * %.3f es: %.3f \n", primerOperando, segundoOperando, multiplicacion);

				if(posibleFactorizarPrimerOperando == 1){

					printf("d) El factorial de %.0f es: %ld y ",primerOperando, factorialPrimerOperando);

				} else{

					printf("d) No es posible factorizar el primer operando y ");

				}
				if(posibleFactorizarSegundoOperando == 1){

					printf("el factorial de %.0f es: %ld\n", segundoOperando, factorialSegundoOperando);

				} else{

					printf("no es posible factorizar el segundo operando\n");

				}
				} else {
					if(calculosRealizados == 0){
						printf("\n|--------------------------------------------|\n");
						printf("\nLos calculos aun no han sido realizados.\n");
						printf("\n|--------------------------------------------|\n");
					} else {
						if(cambioDeOperando == 1){
							printf("\n|------------------------------------------------------------------|\n");
							printf("\nUn operando ha sido cambiado. Debe realizar los calculos nuevamente.\n");
							printf("\n|------------------------------------------------------------------|\n");
						}
					}
				}

				printf("\nPresione Enter para continuar\n");
				getchar();


				break;
			case 5:
				 printf("                         ---------------------------\n"
					   "                           ***TENGA UN BUEN DIA***\n"
					   "                         ---------------------------\n");
				break;

		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
