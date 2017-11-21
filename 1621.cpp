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
#define MV 5000
#define mp make_pair
#define rep(i,x) for(i=0;i<x;++i)
#define pi pair<int, int>
#define pii pair< pi, int >

int vis[MV][MV];
char adj[505][505];
int N, M, i, j, ni, nj;

void dfs( int i, int j, int dis ){

    int x, y, d;
    queue< pii > q;

    q.push( mp( mp( i,j ), dis) );

    while( !q.empty() ){

        pii p = q.front();
        q.pop();

        x = p.first.first;
        y = p.first.second;
        d = p.second;

        if( (vis[x][y]==-1) && (adj[x][y]!='#') ){

            vis[x][y] = d;

            if( (x+1<N) )
                q.push( mp( mp( x+1,y ), d+1) );

            if( (x-1>=0) )
                q.push( mp( mp( x-1,y ), d+1) );


            if( (y+1<M) )
                q.push( mp( mp( x,y+1 ), d+1) );

            if( (y-1>=0) )
                q.push( mp( mp( x,y-1 ), d+1) );
        }
    }
}

int main(){

	int maior, mi, mj;

    while( scanf( "%d%d", &N, &M ), N||M ){

        getchar();

        rep(i, N*4){ rep(j,M*4){
            vis[i][j] = -1;
        } }

        rep(i, N){ rep(j,M){
            scanf( "%c", &adj[i][j] );
        }  getchar(); }

        rep(i, N){ rep(j,M){

            if( adj[i][j] == '.' ){
                ni = i;
                nj = j;
                break;
            }
        } }

        dfs( ni, nj, 0);

        maior=0;

        rep(i, N){ rep(j,M){

        	if( vis[i][j] > maior ){
        		maior = vis[i][j];
        		mi = i;
        		mj = j;
        	}
		} }

        rep(i, N*4){ rep(j,M*4){
            vis[i][j] = -1;
        } }

		dfs( mi, mj, 0 );

        maior=0;

		rep(i, N){ rep(j,M){

        	if( vis[i][j] > maior )
                maior = vis[i][j];
		} }

        printf( "%d\n", maior );
    }

    return 0;
}
