#include<stdio.h>
#include<stdlib.h>
#include<cmath>

int main(){

	double R1, X1, Y1, R2, X2, Y2, Euc;

	while( scanf("%lf %lf %lf %lf %lf %lf", &R1, &X1, &Y1, &R2, &X2, &Y2)!= EOF){

		// Distancia entre os dois centros
		Euc = sqrt( pow(X1-X2, 2) + pow(Y1-Y2,2) );

		if( Euc >= R1 )
			printf( "MORTO\n" );
		else if( (R1-Euc) >= R2 )
			printf( "RICO\n" );
		else
			printf( "MORTO\n" );
	}
	return 0;
}
