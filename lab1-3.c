#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

void combinatoria(int n, int k);

//arcg: cantidad de parámetros contando el nombre del ejecutable que es el primer parámetro.
//argv[]: Un arreglo que contiene todos los parámetros recibidos.
//Lo hago para recibir los valores desde la consola!!!


main(int argc, char *argv[])
{
	int n, k;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	n = atoi(argv[1]); // Se convierten los datos ingresados a variable tipo entero.
	k = atoi(argv[2]);
	if(k <0 || n<0) //Condición para que los valores de n y k sean positivos!
	{
		printf("Los valores de n y de k deben ser positivos\n");
		return 0;
	}
	if (k>n)
	{
		printf("El valor de n tiene que ser mayor que el de k.\n"); // Si se ingresan mal los datos, el programa lo acusará y se cerrará.
		return 0;
	}
	if (argc != 3) //Como argc es la cantidad de parámetros, si lee más de 3 estará malo (porque solo necesitamos n y k)
		printf("Para ejecutar use: ./Ejecutar [valor n] [valor k] \n"); // Si se ingresan más de dos argumentos en la terminal, el programa lo acusará y se cerrará.
	else
	{
		
		combinatoria(n,k); //Se manda los datos ingresados.
	}
	
	
	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC); // %f es porque es un flotante!!!

	return 0; 
}

void combinatoria(int n, int k)
{
	int i;
	mpf_t facn, fack, facdif, denominador, combinatoriaFinal, dif; // mpz_t son variables del tipo entero
	mpf_init (denominador); // mpz_init lo uso para inicializar la variable en 0.
	mpf_init (combinatoriaFinal);
	mpf_init_set_ui(facn,1); // mpz_init_set_ui lo uso para inicializar la variable en 1.
	mpf_init_set_ui(fack,1);
	i=1;
	while(i<=n)
	{
		mpf_mul_ui(facn,facn,i); // Para sacar el factorial de n, facn=facn*i
		i++;
	}
	i=1;
	
	while(i<=k)
	{
		mpf_mul_ui(fack,fack,i);
		i++;
	}
	gmp_printf("%i! = %Ff \n", n, facn); //Esto dirá: n! = facn pero con los valores de la varible.
	gmp_printf("%i! = %Ff \n", k, fack);
	mpf_init_set_ui(facdif,1);
	i=1;
	while(i<=(n-k))
	{
		mpf_mul_ui(facdif,facdif,i); // Para sacar el factorial de la diferencia, facdif=facdif*i
		i++;
	}
	gmp_printf("(n-k)! = %Ff \n", facdif);
	mpf_mul(denominador,facdif,fack); // Multiplicación para el denominador (n-k)! * k! 
	gmp_printf("k!(n-k)! = %Ff \n", denominador); // Se imprime la multiplicación de (n-k)! * k!
	mpf_div(combinatoriaFinal,facn,denominador);
	gmp_printf("El resultado de la combinatoria es = %Ff \n", combinatoriaFinal);
	
	 
	mpf_clear(facn);
	mpf_clear(fack);
	mpf_clear(facdif);
	mpf_clear(denominador);
	mpf_clear(combinatoriaFinal);
	mpf_clear(dif);

}