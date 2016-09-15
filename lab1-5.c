//Programa para calcular el valor de una combinatoria según la fórmula de Stirling

#include <gmp.h>
#include <stdio.h>
#include <time.h>



int main(){
	
	clock_t inicio, fin;
	
	//mpz_t para inicializar las variable enteras
	mpz_t n;                    //valor que tomara el n en la combinatoria
	mpz_t r;                    //valor que tomara el r en la combinatoria

	// mpf_t para inicializar las variables float
	mpf_set_default_prec(30000);  //funcion para definir el largo de una cadena float
	mpf_t n2;                   //valor que tomara n float
	mpf_t r2;                   //valor que tomara r float
	mpf_t e;                    //valor que tomara e 
	mpf_t pi;                   //valor que tomara pi
	mpf_t rest;                 //resta de n y r
    mpf_t mult;                 //variable que guarda la multiplicacion entre la raiz y (n/e)^n
    mpf_t mult_2;               //variable que guarda la multiplicacion entre la raiz y (r/e)^r
    mpf_t mult_3;               //variable que guarda la multiplicacion entre la raiz y ((n-r)/e)^(n-r), al final, se usa la misma variable para guardar la multiplicacion de r! y (n-r)!
    mpf_t i;                    //indice
    mpf_t mult_sq_n;            //guarda la multiplicacion de 2*n*pi
    mpf_t mult_sq_r;            //guarda la multiplicacion de 2*r*pi
    mpf_t mult_sq_rest;         //guarda la multiplicacion de 2*(n-r)*pi
	mpf_t resultado;            
	mpf_t aux_n;                //variable con el resultado de (n/e)^n
	mpf_t aux_r;                //variable con el resultado de (r/e)^r
	mpf_t aux_rest;             //variable con el resultado de ((n-r)/e)^(n-r)
	mpf_t aux_subs_1;           //variable que guarda n/e
	mpf_t aux_subs_2;           //variable que guarda r/e
	mpf_t aux_subs_3;           //variable que guarda n-r/e


	// mpz_init para inicializar las variables en 0.
	mpz_init(n);                 
	mpz_init(r);
	mpf_init(n2);
	mpf_init(r2);
	mpf_init(e);
	mpf_init(pi);
	mpf_init(rest);
	mpf_init(mult_sq_n);
	mpf_init(mult_sq_r);
	mpf_init(mult_sq_rest);
	mpf_init(mult);
	mpf_init(aux_rest);
	mpf_init(resultado);
	mpf_init(mult_3);
	mpf_init(mult_2);
	mpf_init(aux_n);
	mpf_init(aux_r);
	mpf_init(aux_subs_1);
	mpf_init(aux_subs_2);
	mpf_init(aux_subs_3);
	mpf_init(i);
	
	printf("\nIngrese numero n\n");	
	gmp_scanf("%Zd",n);                     
	printf("\nIngrese numero r\n");
	gmp_scanf("%Zd",r);
	
	mpf_set_z(n2,n);
	mpf_set_z(r2,r);
	mpf_set_str(e,"2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746639193200305992181741359662904357290033429526059563073813232862794349076323382988075319525101901157383418793070215408914993488416750924476146066808226480016847741185374234544243710753907774499206955170276183860626133138458300075204493382656029760673711320070932870912744374704723069697720931014169283681902551510865746377211125238978442505695369677078544996996794686445490598793163688923009879312773617821542499922957635148220826989519366803318252886939849646510582093923",10);
	mpf_set_str(pi,"3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931",10);
	
	
	inicio=clock();
	
	if (mpf_cmp(n2,r2) == 0){                     // validación para n = r
		
		printf("\nEl resultado es : 1 \n");
		return 0;
	}
	if (mpf_cmp(n2,r2) < 0){                      // validación para n < r
		
		printf("\nERROR r no puede ser mayor a n \n");
		return 0;
	}
	
	mpf_sub(rest,n2,r2);                          // n-r
	mpf_set_ui(aux_n,1);
	mpf_set_ui(aux_r,1);
	mpf_set_ui(aux_rest,1);
	mpf_set_ui(aux_subs_1,1);
	mpf_set_ui(aux_subs_2,1);
	mpf_set_ui(aux_subs_3,1);
	mpf_set_ui(resultado,1);
	mpf_set_ui(mult,1);
	mpf_mul_ui(mult_sq_n,pi,2);                   //mult_sq_n = pi*2
	mpf_mul(mult_sq_n,mult_sq_n,n2);              //mult_sq_n = n*pi*2
	mpf_mul_ui(mult_sq_r,pi,2); 
	mpf_mul(mult_sq_r,mult_sq_r,r2);
	mpf_mul_ui(mult_sq_rest,pi,2);
	mpf_mul(mult_sq_rest,mult_sq_rest,rest);
	mpf_sqrt(mult_sq_n,mult_sq_n);                //raiz de mult_sq_n = n*pi*2
	mpf_sqrt(mult_sq_r,mult_sq_r);                //raiz de mult_sq_r = r*pi*2
	mpf_sqrt(mult_sq_rest,mult_sq_rest);          //raiz de mult_sq_rest = rest*pi*2
	mpf_div(aux_subs_1,n2,e);                     //aux_subs_1= n/e
	mpf_div(aux_subs_2,r2,e);
	mpf_div(aux_subs_3,rest,e);
	mpf_add_ui(n2,n2,1);
	mpf_add_ui(r2,r2,1);
	mpf_add_ui(rest,rest,1);
	
	
	
	for (mpf_set_ui(i,1); mpf_cmp(n2,i) != 0; mpf_add_ui(i,i,1)){       //ciclo que realiza (n/e)^n
		mpf_mul(aux_n,aux_n,aux_subs_1);	
	}
	mpf_mul(mult,mult_sq_n,aux_n);                                      //mult guarda la multiplicacion entre la raiz de n*pi*2  y (n/e)^n
	
	for (mpf_set_ui(i,1); mpf_cmp(r2,i) != 0; mpf_add_ui(i,i,1)){       //ciclo que realiza (r/e)^r
		mpf_mul(aux_r,aux_r,aux_subs_2);	                            
	}
	mpf_mul(mult_2,mult_sq_r,aux_r);                                    //mult_2 guarda la multiplicacion entre la raiz de r*pi*2  y (r/e)^r
	
	for (mpf_set_ui(i,1); mpf_cmp(rest,i) != 0; mpf_add_ui(i,i,1)){     //ciclo que realiza ((n-r)/e)^(n-r)
		mpf_mul(aux_rest,aux_rest,aux_subs_3);	
	}
	mpf_mul(mult_3,mult_sq_rest,aux_rest);                              //mult_3 guarda la multiplicacion entre la raiz de (n-r)*pi*2  y ((n-r)/e)^(n-r)
	
	
	mpf_mul(mult_3,mult_3,mult_2);                                      //mult_3 = r! * (n-r)!
	mpf_div(resultado,mult,mult_3);                                     //resultado = n!/ r! * (n-r)!

		
	printf("El C(n,r) es :");
	gmp_printf("%.10Ff \n",resultado);
	
	fin=clock();
		
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC);
	
	//liberar el espacio ocupado por las variables flotantes
	mpz_clear(n);
	mpz_clear(r);
	mpf_clear(mult);
	mpf_clear(rest);
	mpf_clear(e);
	mpf_clear(pi);
	mpf_clear(resultado);
	mpf_clear(aux_n);
	mpf_clear(aux_r);
	mpf_clear(aux_subs_1);
	mpf_clear(aux_subs_2);
	mpf_clear(aux_subs_3);
	mpf_clear(i);
	mpf_clear(n2);
	mpf_clear(r2);
	mpf_clear(mult_sq_n);
	mpf_clear(mult_sq_r);
	mpf_clear(mult_sq_rest);
	mpf_clear(aux_rest);
	mpf_clear(mult_2);
	mpf_clear(mult_3);
	
	return 0;
	
}



