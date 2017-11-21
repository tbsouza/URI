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
#define S second
#define F first
#define PQ priority_queue
#define INF 0x3f3f3f3f
#define debug(x) cout << #x << "= " << x << endl
#define MV 505

int vis[MV], dist[MV];
int adj[MV][MV];
//   < vertice, distancia >

void djk( int ini, int N ){

	for( int i=1; i<=N; ++i ){
			// limpra para cada consulta
			dist[i] = INF;
			vis[i] = 0;
	}

	PQ< pii > pq;
	// < distancia, vertice >

	pq.push( mp(0, ini) );
	dist[ini] = 0;

	while( !pq.empty() ){

		int u = pq.top().S;
		pq.pop();

		if( vis[u] == 0 ){

			vis[u]=1;

			for( int i=1; i<=N; ++i ){

				if( adj[u][i] != -1 ){

					int peso = adj[u][i];

					if( dist[i] > dist[u] + peso ){

						dist[i] = dist[u] + peso;

						pq.push( mp(-dist[i], i) );
						// pois pode atualizar novamente
					}
				}
			}
		}
	}
}

int main(){

	int N, E, X, Y, H, i, d, K, j;

	while( scanf( "%d%d", &N, &E ), N||E ){

		for( i=1; i<=N; ++i )
			for( j=1; j<=N; ++j )
				adj[i][j]= -1;

		for( i=0; i<E; ++i ){

			scanf( "%d%d%d", &X, &Y, &H );
			// de X para Y com custo H

			if( adj[Y][X] != -1 ){
				adj[X][Y] = 0;
				adj[Y][X]=0;
			}
           	else
				adj[X][Y] = H;
		}

		scanf( "%d", &K );

		for( i=0; i<K; ++i ){

			scanf( "%d%d", &X, &Y );
			//   origem e destino

			djk( X, N );

			if( dist[Y] != INF )
				printf( "%d\n", dist[Y] );
			else
				printf( "Nao e possivel entregar a carta\n" );
		}

		printf( "\n" );
	}

	return 0;
}
