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
#define PQ priority_queue
#define MV 6000

vector< pair< int, pii > > aresta;
int dis[105][105];
int lider[105], T, N, V, A, B, i, j;
int tam, X, Y, soma, D;

int findset( int A ){

	if( A != lider[A] )
		lider[A] = findset( lider[A] );

	return lider[A];
}

void uni( int X, int Y, int D ){

	int A = findset(X);
	int B = findset(Y);

	if( A!=B ){

		lider[A] = B;

		if( D==1 )
			soma++;
	}
}

int main(){

	scanf( "%d", &T );
	while( T-- ){

		scanf( "%d%d", &N, &V );

		for( i=0; i<N; ++i )
			for( j=0; j<N; ++j )
				dis[i][j] = 0;

		for( i=0; i<V; ++i ){

			scanf( "%d%d", &A, &B );

			dis[A][B] = 1;
			dis[B][A] = 1;
		}

		for( i=0; i<N; ++i )
			for( j=(i+1); j<N; ++j ){

				aresta.pb( mp(dis[i][j], mp(i, j)) );
			}

		tam = aresta.size();

		sort( aresta.begin(), aresta.end() );

		for( i=0; i<N; ++i )
			lider[i] = i;

		soma=0;

		for( i=0; i<tam; ++i ){

			D = aresta[i].first;
			X = aresta[i].second.first;
			Y = aresta[i].second.second;

			uni( X, Y, D );
		}

		printf( "%d\n", soma );

		aresta.clear();
	}

	return 0;
}
