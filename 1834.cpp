#include<bits/stdc++.h>
using namespace std;

struct ponto{

	int x, y;
};

struct segmento{

	struct ponto p1, p2;
};

double areaOrientada( ponto A, ponto B, ponto C ){

	return ((double)(A.x*B.y - A.y*B.x + A.y*C.x - A.x*C.y + B.x*C.y - B.y*C.x))/2;
}

double lado( segmento AB, ponto C ){

	return areaOrientada( AB.p1, AB.p2, C );
}

double dist( segmento AB ){

	return sqrt(((double)(AB.p1.x-AB.p2.x)*(AB.p1.x-AB.p2.x)+(AB.p1.y-AB.p2.y)*(AB.p1.y-AB.p2.y)));
}

int main(){

	segmento rod;
	int pnt, i, leste=0, popLeste=0, oeste=0, popOeste=0, mid=0, pop, res;
	ponto x;

	scanf( "%d%d%d%d%d", &rod.p1.x, &rod.p1.y, &rod.p2.x, &rod.p2.y, &pnt );

	for( i=0; i<pnt; ++i ){

		scanf( "%d%d%d", &x.x, &x.y, &pop );

		res = lado( rod, x );

		if( res<0 ){
			leste++;
			popLeste+=pop;
		}else if( res>0 ){
			oeste++;
			popOeste+=pop;
		}else{
			mid++;
		}
	}

	printf( "Relatorio Vogon #35987-2\nDistancia entre referencias: %.2lf anos-luz\n", dist( rod ) );
	printf( "Setor Oeste:\n- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", oeste, popOeste );
	printf( "Setor Leste:\n- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", leste, popLeste );
	printf( "Casualidades: %d planeta(s)\n", mid );

	return 0;
}
