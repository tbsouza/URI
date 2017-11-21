#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

#define MaxVertice 31000
#define pb push_back
#define sz size

vector<long long int> adj[MaxVertice]; // Lista de adjacencia
int vis[MaxVertice];     // Vetor de visitados
bool ciclo;

void dfs( long long int A ){

    long long int size, v;

    vis[A] = 1; // Visitando

    size = adj[A].sz();

    for( long long int i=0; i<size; ++i ){
        v = adj[A][i];

        if( vis[v] == 0  )
            dfs( v );
        else if( vis[v] == 1 )
            ciclo = true;

    }

    vis[ A ] = 2; // ja visitado
}

int main(){

    long long int N, A, B, i; // testes
    long long int M;
    int T;

    scanf( "%d", &T );
    while( T-- ){
        scanf( "%lli %lli", &N, &M );

        for( i=0; i<M; ++i ){
            scanf( "%lli %lli", &A, &B );

            adj[A].pb(B); // add B na lista de A
        }

        memset( vis, 0, sizeof(vis) ); // nao visitado

        ciclo = false;

		for( i=1; i<=N; ++i ){

			if( vis[i]==0 )
				dfs(i);
			if( ciclo ) break;
		}

			dfs( A );

        if( ciclo==true ) printf( "SIM\n" );
        else  printf( "NAO\n" );

        // Limpado a lista de adjacencia
        for( i=1; i<=N; ++i ) adj[i].clear();
    }

    return 0;
}
