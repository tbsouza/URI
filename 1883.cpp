#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
#define mp make_pair

char g[MAX][MAX], vis[MAX][MAX];
int N, M;

bool bfs( int i, int j ){

    int x, y;
    queue< pair<int,int> > q;

    q.push( mp( i,j ) );

    while( !q.empty() ){

        x = q.front().first;
        y = q.front().second;

        if( g[x][y]=='F' ) return false;

        if( g[x][y]=='S' ){

            while( !q.empty() ){

                x = q.front().first;
                y = q.front().second;

                if( g[x][y]=='F' ) return false;

                q.pop();
            }

            return true;
        }

        q.pop();

        if( (!vis[x][y]) && (g[x][y]!='#') ){

            vis[x][y] = 1; // visita

            q.push( mp( x+1,y ) );

            q.push( mp( x-1,y ) );

            q.push( mp( x,y+1 ) );

            q.push( mp( x,y-1 ) );
        }
    }
}

int main(){

    int T, i, j, Ei, Ej;

    scanf( "%d", &T );
    while( T-- ){

        scanf( "%d%d", &N, &M );

        for( i=0; i<=(N+1); ++i ){
            g[i][0] = g[i][N+1] = '#';
        }

        for(j=0; j<=(M+1); ++j){
            g[0][j] = g[0][M+1] = '#';
        }

/*
        for( i=0; i<=(N+1); ++i ){
            for(j=0; j<=(M+1); ++j){
                g[i][j] = '#';
            }
        }
*/
        for( i=1; i<=N; ++i ){

            getchar();

            for(j=1; j<=M; ++j){

                scanf( "%c", &g[i][j] );

                if( g[i][j]=='E' ){
                    Ei=i;
                    Ej=j;
                }

                vis[i][j] = 0;
            }
        }

        if( bfs( Ei, Ej ) ) printf( "Y\n" );
        else              printf( "N\n" );
    }

    return 0;
}
