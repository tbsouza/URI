#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define pb push_back
#define MV 2100

vector< int > adj[ MV ];
int vis[ MV ];
int cont, N, M, P;

void dfs( int ini ){

	cont++;

	vis[ ini ] = 1;

	int tam = adj[ ini ].size();

	for( int j=0; j<tam; ++ j ){

		int u = adj[ ini ][ j ];

		if( vis[ u ] == 0 )
			dfs( u );
	}
}

bool verify(){

	int i;

	cont = 0;

	for( i=1; i<=N; ++i ){

		memset( vis, 0, sizeof(vis) );

		cont = 0;

		dfs( i );

		//printf( "Cont: %d\n", cont );

		if( cont != N )
			return false;
	}

	return true;
}

int main(){

	int x, y, i, j;

	while( scanf( "%d%d", &N, &M ), N||M ){

		memset( vis, 0, sizeof(vis) );

		// Montando lista de adjacencia
		for( i=0; i<M; ++i ){

			scanf( "%d%d%d", &x, &y, &P );

			adj[ x ].pb( y );

			if( P==2 ) adj[ y ].pb( x );
		}

		if( verify() == true ) printf( "1\n" );
		else				   printf( "0\n" );

		for( i=1; i<=N; ++i ) adj[i].clear();
	}

	return 0;
}
