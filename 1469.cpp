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
#define MV 505
#define mp make_pair

int vis[MV];
vector<int> adj[MV];
int pos[MV];
int id[MV];
int N, M, I, i, j, X, Y, menor;
char C;

void dfs( int ini ){

	vis[ ini ] = 1;

	int tam = adj[ ini ].size();

	for( int i=0; i<tam; ++i ){

		int v = adj[ ini ][ i ];

		if( vis[ v ] == 0 ){

			if( id[ v ] < menor )
				menor = id[ v ];

			dfs( v );
		}
	}
}

int main(){

	memset( vis, 0, sizeof(vis) );

	while( scanf( "%d%d%d", &N, &M, &I ) != EOF ){

		// Idades
		for( i=1; i<=N; ++i ){
			scanf( "%d", &id[i] );
			pos[i] = i;
		}

		// Lista de Adj
		for( i=1; i<=M; ++i ){
			scanf( "%d%d", &X, &Y );

			adj[ Y ].pb( X );
		}

		for( i=1; i<=I; ++i ){

			scanf( " %c", &C );

			if( C=='P' ){ // Pergunta

				scanf( "%d", &X );

				if( adj[ pos[X] ].size() == 0 )
					printf( "*\n" );
				else{

					memset( vis, 0, sizeof(vis) );

					menor=999;
					dfs( pos[X] );

					printf( "%d\n", menor );
				}

			}else{ // Troca

				scanf( "%d%d", &X, &Y );

				swap( id[pos[X]], id[pos[Y]] );
				swap( pos[X], pos[Y] );
			}
		}

		for( i=1; i<=N; ++i )
			adj[i].clear();
	}

	return 0;
}
