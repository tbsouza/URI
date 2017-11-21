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
#define MV 50005
#define F first
#define S second

vector< pair< int ,pii > > aresta;
int lider[40005], M, N, X, Y, D, i, soma;

int findset( int X ){

	if( X != lider[X] )
		lider[X] = findset( lider[X] );

	return lider[X];
}

void uni( int A, int B, int D ){

	int X = findset(A);
	int Y = findset(B);

	if( X!=Y ){

		lider[X] = Y;

		soma += D;
	}
}

int main(){

	while( scanf( "%d%d", &M, &N ), M||N ){

		for( i=0; i<N; ++i ){

			scanf( "%d%d%d", &X, &Y, &D );

			aresta.pb( mp(D, mp(X, Y)) );
		}

		for( i=0; i<M; ++i )
			lider[i] = i;

		sort( aresta.begin(), aresta.end() );

		soma=0;

		for( i=0; i<N; ++i ){

			uni(aresta[i].S.F, aresta[i].S.S, aresta[i].F);
			// X, Y, Dis
		}

		printf( "%d\n", soma );

		aresta.clear();
	}

	return 0;
}
