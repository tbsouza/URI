#include<bits/stdc++.h>
using namespace std;

#define add push
#define mp make_pair
#define MAX 100002

int vis[MAX];

bool dentro( int x ){
	return ( x>0 && x<=100000 );
}

int bfs( int O, int D ){

	queue< pair<int, int> > q;
	int v, t;

	q.add( mp(O,0) );

	while( !q.empty() ){

		v = q.front().first;

		if( v==D ) return q.front().second;

		t = q.front().second;
		q.pop();

		if( !vis[v] ){

			vis[v] = 1;

			if( dentro(v+1) && !vis[v+1] ) q.add( mp(v+1,t+1) );

			if( dentro(v-1) && !vis[v-1] ) q.add( mp(v-1,t+1) );

			if( dentro(v*2) && !vis[v*2] ) q.add( mp(v*2,t+1) );

			if( dentro(v*3) && !vis[v*3] ) q.add( mp(v*3,t+1) );

			if( v%2==0 ){
				if( dentro(v/2) && !vis[v/2] ) q.add( mp(v/2,t+1) );
			}
		}
	}

	return -1;
}

int main(){

	int O, D, K, X;

	while( scanf("%d%d%d", &O, &D, &K), O||D||K ){

		memset( vis, 0, sizeof(vis) );

		while( K-- ){
			scanf( "%d", &X );
			vis[X]=1;  // visited
		}

		printf( "%d\n", bfs(O, D) );
	}

	return 0;
}
