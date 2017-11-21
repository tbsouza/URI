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
#define MV 80

int vis[ MV ];
vector< int > adj[ MV ];
map< int, int > mp;
map< int, int >::iterator it;

void dfs( int ini ){

	vis[ ini ] = mp[ ini ] = 1;

	int tam = adj[ ini ].size();

	for( int i=0; i<tam; ++i ){

		int u = adj[ini][i];

		if( vis[u] == 0 )
			dfs( u );
	}
}

int main(){

	int N, V, E, i, total, j, cont=0;
	char x, y, z;
	int letx, lety;

	scanf( "%d", &N );
	while( N-- ){

		total=0;
		memset( vis, 0, sizeof(vis) );

		scanf( "%d%d", &V, &E );
		getchar();

		for( i=0; i<E; ++i ){

			scanf( "%c%c%c", &x, &z, &y );
			getchar();

			letx = x - 96;
			lety = y - 96;

			// ambos adjacentes
			adj[ letx ].pb( lety );
			adj[ lety ].pb( letx );
		}

		printf( "Case #%d:\n", ++cont );

		for( i=1; i<=V; ++i ){

			if( vis[i] == 0 ){
				dfs( i );
				total++;

				for( it=mp.begin(); it!=mp.end(); ++it )
					printf( "%c,", (char)((it->first)+96) );

				mp.clear();

				printf( "\n" );
			}
		}

		printf( "%d connected components\n\n", total );

		for( i=1; i<=V; ++i ) adj[i].clear();

	}

	return 0;
}
