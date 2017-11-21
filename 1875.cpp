#include <bits/stdc++.h>
using namespace std;

int main() {

	int C, P, i, R, G, B;
	char X, Y;

	scanf( "%d", &C );
	while( C-- ) {

		scanf( "%d", &P );

		R=G=B=0;

		while( P-- ){

			getchar();
			scanf( "%c %c", &X, &Y );

			if( X=='R' ){ // Red
				if( Y=='B' ) R+=1;
				else		 R+=2;
			}else if( X=='G' ){ // Green
				if( Y=='R' ) G+=1;
				else		 G+=2;
			}else{ // Blue
				if( Y=='G' ) B+=1;
				else		 B+=2;
			}
		}

		if( R==G && R==B && G==B ){
			printf( "trempate\n" );
		}else if((R==G&&R>B&&G>B)||(R==B&&R>G&&B>G)||(G==B&&G>R&&B>R)){
			printf( "empate\n" );
		}else if( R>G && R>B ){
			printf( "red\n" );
		}else if( G>R && G>B ){
			printf( "green\n" );
		}else if( B>R && B>G ){
			printf( "blue\n" );
		}
	}

	return 0;
}
