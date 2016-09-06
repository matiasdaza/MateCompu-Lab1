//Programa que resuelve factoriales
#include <stdio.h>

int factorial(int n);


main(){
	int n, k, facn,fack,dif,facdif, fac;

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


	return 0; 
}

int factorial(int n){
	int fac=1;
	while(n>1
)	{
		fac=fac*n;
		n=n-1;
	}
	return fac; 
}