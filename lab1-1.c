//Programa que resuelve factoriales
#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

int factorial(int n);


main()
{
	int n, k, facn,fack,dif,facdif, fac;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	printf("\nIntroduce un valor para n: ");
	scanf("%i", &n); //%i el i es porque es un entero!!!
	printf("\nIntroduce un valor para k: ");
	scanf("%i", &k); //%i el i es porque es un entero!!!

	dif=n-k;
	printf("\nEl valor de la dif es: %i \n", dif);
	facn=factorial(n);
	fack=factorial(k);
	facdif=factorial(dif); 	
	printf("\nEl valor de la factorial de n es: %i \n", facn);
	printf("\nEl valor de la factorial de k es: %i \n", fack);
	printf("\nEl valor de la factorial de dif es: %i \n", facdif);

	fac= facn / (fack*facdif); 
	printf("\nEl valor del calculo de la combinatoria es: %i \n", fac);
	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC); // %f es porque es un flotante!!!

	return 0; 
}

int factorial(int n){
	int fac=1;
	while(n>1)
	{
		fac=fac*n;
		printf("%i\n", fac);
		n=n-1;
	}
	return fac; 
}