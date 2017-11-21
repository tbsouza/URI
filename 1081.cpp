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
#define MV 30
#define mp make_pair
#define ii pair<int, int>
#define pii pair< ii, int >

vector< int > adj[ MV ];
int vis[ MV ];

void dfs( int ini, int dis ){

	vis[ ini ] = 1;

	int tam = adj[ini].size();

	for( int i=0; i<tam; ++i ){

		int u = adj[ini][i];

		for( int j=0; j<dis; ++j ) printf(" ");

		printf( "%d-%d", ini, u );

		if( vis[ u ] == 0 ){

			printf( " pathR(G,%d)\n", u );

			dfs( u, dis+2 );

		} else printf( "\n" );
	}
}

int main(){

	int N, V, E, i, x, y, c=0;

	scanf( "%d", &N );
	while( N-- ){

		memset( vis, 0, sizeof( vis ) );

		scanf( "%d%d", &V, &E );

		for( i=0; i<E; ++i ){

			scanf( "%d%d", &x, &y );

			adj[ x ].pb( y );
		} 

		printf( "Caso %d:\n", ++c );

		for( i=0; i<V; ++i )
			sort( adj[i].begin(), adj[i].end() );

		for( i=0; i<V; ++i ){

			if( (vis[i]==0) && (adj[i].size()!=0) ){

				dfs( i, 2 );

				printf( "\n" );
			}
		}

		for( i=0; i<V; ++i ) adj[i].clear();
	}

	return 0;
}
