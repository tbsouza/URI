#include<bits/stdc++.h>
using namespace std;

#define MAX 4001
#define TAM 1001

map< string, bool > vis;
map< string, bool >::iterator it;
map< string, vector< string > > adj;

int BFS( string ini, string fim ){

    int t, sz, i;
    string v, u;
    queue< pair< string, int > > q;

    q.push( make_pair( ini, 0 ) );

    while( !q.empty() ){

        v = q.front().first;
        t = q.front().second;
        q.pop();

        if( v == fim ) return t;

        if( !vis[v] ){

            vis[v] = true;

            sz = adj[v].size();

            for( i=0; i<sz; ++i ){

                u =  adj[v][i];

                q.push( make_pair( u, t+1 ) );
            }
        }
    }

    return 0;
}

int main(){

    char p[TAM], a[TAM], b[TAM];
    int pts, ligas, i, tot;

    scanf( "%d%d", &pts, &ligas );
    getchar();

    for( i=0; i<ligas; ++i ){

         scanf( "%s%s", a, b );

         adj[ a ].push_back( b );
         adj[ b ].push_back( a );

         vis[ a ] = false;
         vis[ b ] = false;
    }

    tot = BFS( "Entrada", "*" );

    for( it=vis.begin(); it!=vis.end(); ++it )
         (it->second) = false;

    tot += BFS( "*", "Saida" );

    printf( "%d\n", tot );

    return 0;
}
