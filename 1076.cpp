#include <stdio.h>
#include <stdlib.h>
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
#define MV 60

int cont;
int vis[ MV ];
vector< int > adj[ MV ];

void dfs( int u ){

	vis[ u ] = 1;
	cont++;

	int tam = adj[u].size();

	for( int i=0; i<tam; ++i ){

		int v = adj[u][i];

		if( vis[ v ] == 0 )
			dfs( v );
	}
}

int main(){

	int V, A, ini, T, i, X, Y;

	scanf( "%d", &T );
	while( T-- ){

		cont = 0;

		memset( vis, 0, sizeof( vis ) );

		scanf( "%d%d%d", &ini, &V, &A );

		for( i=0; i<A; ++i ){

				scanf( "%d%d", &X, &Y );

				adj[ X ].pb( Y );
				adj[ Y ].pb( X );
		}

		dfs( ini );

		printf( "%d\n", (cont-1)*2 );

		for( i=0; i<A; ++i ) adj[i].clear();

	}

	return 0;
}
