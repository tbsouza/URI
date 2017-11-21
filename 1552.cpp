#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair< int, int >
#define pdd pair<double, double>
#define PQ priority_queue
#define MV 300000
#define F first
#define S second

vector< pair< double, pii > > aresta;
// (distancia, (x, y))
int lider[505], N, i, j, C, tam, X, Y;
vector< pii > pos;
double d, soma;


int findset( int A ){

	if( A != lider[A] )
		lider[A] = findset( lider[A] );

	return lider[A];
}

void uni( int X, int Y, double d ){

	int A = findset(X);
	int B = findset(Y);

	if( A!=B ){

		lider[A] = B;
		soma += d;
	}
}

int main(){

	scanf( "%d", &C );
	while( C-- ){

		scanf( "%d", &N );
		for( i=1; i<=N; ++i ){

			scanf( "%d%d", &X, &Y );

			pos.pb( mp(X,Y) );

			lider[i] = i;
		}

		for( i=0; i<N; ++i )
			for( j=(i+1); j<N; ++j ){

				X = pos[j].F - pos[i].F;
				Y = pos[j].S - pos[i].S;

				d = sqrt( (X*X) + (Y*Y) );

				aresta.pb( mp(d, mp(i+1, j+1)) );
		}

		sort( aresta.begin(), aresta.end() );

		tam = aresta.size();
		soma = 0;

		for( i=0; i<tam; ++i ){

			d = aresta[i].F;
			X = aresta[i].S.F;
			Y = aresta[i].S.S;

			uni( X, Y, d );
		}

		printf( "%.2lf\n", (soma/100.0) );

		aresta.clear();
		pos.clear();

	}

	return 0;
}
