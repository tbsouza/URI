#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 105

int vis[MAX];         // visitados
vector<int> adj[MAX]; // lista adjacencia

void DFS( int u ){

	int sz, i, v;

	vis[u] = 1;

	sz = adj[u].size();

	for( i=0; i<sz; ++i ){

		v = adj[u][i];

		if( !vis[v] ) DFS(v);
	}

	vis[u] = 2;
}

int main(){

	int N, M, X, Y, T, i, j, conex;

	scanf( "%d", &T );
	for( i=1; i<=T; ++i ){

		scanf( "%d%d", &N, &M ); //N - vertices, M- arestas

		// limpa vetor visitados e lista adj
		for( j=1; j<=N; ++j  ){
			vis[j] = 0;
			adj[j].clear();
		}

		// criando lista de adjacencia
		for( j=1; j<=M; ++j ){
			scanf( "%d%d", &X, &Y );
			adj[X].push_back(Y);
			adj[Y].push_back(X);
		}

		conex = 0;

		for( j=1; j<=N; ++j ){
			if( !vis[j] ){
				DFS(j);
				conex++;
			}
		}

		if( conex==1 ) printf( "Caso #%d: a promessa foi cumprida\n", i );
		else printf( "Caso #%d: ainda falta(m) %d estrada(s)\n", i, conex-1 );
	}

	return 0;
}
