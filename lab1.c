//Programa que resuelve factoriales
#include <stdio.h>
#define PI 3.1416 // Define variable global PI con el valor 3.1416

main(){
	int y;
	float x;

	x=PI;

	printf("\nEl valor de x es: %f \n",x); //%f el f es porq es flotante
	printf("\nIntroduce un valor para y: ");
	scanf("%i", &y); //%i el i es porque es un entero!!!
	printf("\nEl valor de y es: %i \n", y);

	return 0; 
}