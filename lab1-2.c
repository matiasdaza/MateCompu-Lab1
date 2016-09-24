#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

void CombSimplificada(int n, int k);

main(int argc, char *argv[])
{
	int n, k;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	n = atoi(argv[1]); // Se convierten los datos ingresados a variable tipo entero.
	k = atoi(argv[2]);
	if(k<0 || n<0) //Condición para que los valores de n y k sean positivos!
	{
		printf("Los valores de n y de k deben ser positivos\n");
		return 0;
	}
	if (k > n) // Como es un arreglo uno se guarda en la posición 1 y el otro en la 2.Si se ingresan mal los datos, el programa lo acusará y se cerrará.
	{
		printf("El valor de n tiene que ser mayor que el de k.\n"); // Si se ingresan mal los datos, el programa lo acusará y se cerrará.
		return 0;
	}
	if (argc != 3) //Como argc es la cantidad de parámetros, si lee más de 3 estará malo (porque solo necesitamos n y k)
		printf("Para ejecutar use: ./Ejecutar [valor n] [valor k] \n"); // Si se ingresan más de dos argumentos en la terminal, el programa lo acusará y se cerrará.
	else
	{
		
		CombSimplificada(n,k); //Se manda los datos ingresados.
	}
	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC); // %f es porque es un flotante!!!

	return 0;
}

void CombSimplificada(int n, int k)
{
	int i=1, dif, sw=0;
	mpz_t facn, fack, facdif, denominador, combinatoriaFinal; // mpz_t son variables del tipo entero
	mpz_init_set_ui(denominador,1); // mpz_init lo uso para inicializar la variable en 0.
	mpz_init (combinatoriaFinal);
	mpz_init_set_ui(facn,1); // mpz_init_set_ui lo uso para inicializar la variable en 1.
	mpz_init_set_ui(fack,1);
	dif=n-k;
	if(k>dif && k!=dif)
	{
		while(k<n)
		{
			mpz_mul_ui(facn,facn,n); // Para sacar el factorial de n, facn=facn*n, para simplificar al encontrar n=k
			n=n-1;
		}
		sw=1; //Se utiliza este switch para diferenciar que k se simplifica con n
	}
	if(sw!=1 && k<dif && k!=dif)
	{
		
		while(dif<n)
		{
			mpz_mul_ui(facn,facn,n); // Para sacar el factorial de n, facn=facn*n, para simplificar al encontrar n=k
			n=n-1;
		}
		sw=2; //Se utiliza este switch para diferenciar que dif se simplifica con n
	}
	if(k==dif){
		while(dif<n)
		{
			mpz_mul_ui(facn,facn,n); // Para sacar el factorial de n, facn=facn*n, para simplificar al encontrar n=k
			n=n-1;
		}
		dif=1;

	}
	if(sw==1)
		k=1; //como k se simplifica con n, k queda con valor 1;
	if(sw==2)
		dif=1;	//como k se simplifica con n, dif queda con valor 1;

	
	i=1;	
	while(i<=k)
	{
		mpz_mul_ui(fack,fack,i);
		i++;
	}
	mpz_init_set_ui(facdif,1);
	i=1;
	while(i<=dif)
	{
		mpz_mul_ui(facdif,facdif,i); // Para sacar el factorial de la diferencia, facdif=facdif*i
		i++;
	}

	gmp_printf("\n%Zd\n",fack);
	gmp_printf("\n%Zd\n",facdif);

	mpz_mul(denominador, fack, facdif);
	
	gmp_printf("\nEl numerador simplificado es = %Zd \n",facn); //Esto dirá: n! = facn pero con los valores de la varible.
	gmp_printf("El denominador simplificado es = %Zd \n", denominador);

	mpz_cdiv_q(combinatoriaFinal,facn,denominador);
	gmp_printf("El resultado de la combinatoria es = %Zd \n", combinatoriaFinal); 
	mpz_clear(facn);
	mpz_clear(fack);
	mpz_clear(facdif);
	mpz_clear(denominador);
	mpz_clear(combinatoriaFinal);

}
