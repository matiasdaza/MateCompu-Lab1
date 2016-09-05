//Programa que resuelve factoriales
#include <stdio.h>
#define PI 3.1416 // Define variable global PI con el valor 3.1416

main(){
	int n, k, facn=1,fack=1,dif,facdif=1, factorial;

	printf("\nIntroduce un valor para n: ");
	scanf("%i", &n); //%i el i es porque es un entero!!!
	printf("\nIntroduce un valor para k: ");
	scanf("%i", &k); //%i el i es porque es un entero!!!

	dif=n-k;
	printf("\nEl valor de la dif es: %i \n", dif);
	while(n>1)
	{
		facn=facn*n;
		n=n-1;
	}
	while(k>1)
	{
		fack=fack*k;
		k=k-1;
	}
	while(dif>1)
	{
		facdif=facdif*dif;
		dif=dif-1;
	}
	printf("\nEl valor de la factorial de n es: %i \n", facn);
	printf("\nEl valor de la factorial de k es: %i \n", fack);
	printf("\nEl valor de la factorial de dif es: %i \n", facdif);

	factorial= facn / (fack*facdif); 
	printf("\nEl valor de la factorial es: %i \n", factorial);


	return 0; 
}