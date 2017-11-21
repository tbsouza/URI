#include <bits/stdc++.h>
using namespace std;

#define MAX 101
#define add push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define S second
#define F first

int vis[MAX];
double dist[MAX];
vector< pair<int, double> > adj[MAX];

void djk( int ini ){

	int v, sz, i, u;
	double w, m;

	priority_queue< pair< double, int > > pq;

	pq.push( mp( 1.000000, ini ) );
	dist[ini] = 1.000000;

	while( !pq.empty() ){

		v = pq.top().S; // 1o ini
		pq.pop();

		if( !vis[v] ){

			vis[v] = 1;

			sz = adj[v].size();

			for( i=0; i<sz; ++i ){

				u = adj[v][i].F;
				w = adj[v][i].S;
				m = dist[v]*w;

				if( m > dist[u] ){
					dist[u] = m;
					pq.push( mp(dist[u], u) );
				}
			}
		}
	}
}

int main(){

	int N, M, a, b, w, i;

	while( scanf("%d", &N), N ){

		scanf("%d", &M);

		for( i=1; i<=N; ++i ){
			adj[i].clear();
			vis[i] = 0;
			dist[i] = -INF;
		}

		for( i=0; i<M; ++i ){
			scanf("%d%d%d", &a, &b, &w );

			adj[a].add( mp(b, (w*1.000000)/100.000000) );
			adj[b].add( mp(a, (w*1.000000)/100.000000) );
		}

		djk(1);

		printf("%.6lf percent\n", dist[N]*100.000000 );
	}

	return 0;
}
