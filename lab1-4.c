#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

void combinatoria(mpf_t n, mpf_t k);

//arcg: cantidad de parámetros contando el nombre del ejecutable que es el primer parámetro.
//argv[]: Un arreglo que contiene todos los parámetros recibidos.
//Lo hago para recibir los valores desde la consola!!!

main(int argc, char *argv[])
{
	mpf_t n, k;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	mpf_init_set_str(n, argv[1],10);
	mpf_init_set_str(k, argv[2],10);
	if( mpf_cmp_ui(n,0)<0|| mpf_cmp_ui(k,0)<0) //Condición para que los valores de n y k sean positivos!
	{
		printf("Los valores de n y de k deben ser positivos\n");
		return 0;
	}
	if (mpf_cmp(n,k)<0)
	{
		printf("El valor de n tiene que ser mayor que el de k.\n"); // Si se ingresan mal los datos, el programa lo acusará y se cerrará.
		return 0;
	}
	if (argc != 3) //Como argc es la cantidad de parámetros, si lee más de 3 estará malo (porque solo necesitamos n y k)
		printf("Para ejecutar use: ./Ejecutar [valor n] [valor k] \n"); // Si se ingresan más de dos argumentos en la terminal, el programa lo acusará y se cerrará.
	else
	{
		combinatoria(n,k);
	}
	
	
	fin=clock();
	mpf_clear(n);
	mpf_clear(k);
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC); // %f es porque es un flotante!!!
	return 0; 
}

void combinatoria(mpf_t n, mpf_t k){
	mpf_t numerador, denominador,div,combinatoria; //Se declaran variables flotantes	
	mpf_init_set(numerador,n); //Se asigna al valor del numerado, el valor de n;
	mpf_init_set(denominador,k);//En el denominador se deja el valor de k;
	mpf_init_set_ui(div, 1);//iniciamos div con valor 1
	mpf_init_set_ui(combinatoria,1);//iniciamos combinatoria con valor 1

	while(mpf_cmp_ui(denominador,1)>0) //hacemos un ciclo hasta que el valor del denominador sea 1
	{
		mpf_div(div,numerador,denominador); //comenzamos dividiendo numerador sobre denominador y lo guardamos en div
		mpf_mul(combinatoria,combinatoria,div);//luego el valor de div lo vamos multiplicando y lo guardamos en combinatoria
		mpf_sub_ui(numerador,numerador,1);//restamos 1 al valor de numerador
		mpf_sub_ui(denominador,denominador,1);//restamos 1 al valor de denomiandor
	}
	mpf_div(div,numerador,denominador); 
	mpf_mul(combinatoria,combinatoria,div); //Se multiplica la ultima vez cuando el valor de denominador es 1
	gmp_printf("el resultado de la combinatoria aproximada es: %Ff\n",combinatoria);

	//Liberamos el espacio de memoria de las variables
	
	mpf_clear(numerador);
	mpf_clear(denominador);
	mpf_clear(div );
	mpf_clear(combinatoria);

}