#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define pb push_back
#define mp make_pair

int G, vis[MAX];
vector< int > adj[MAX];
set< int > elm; // elementos

void bfs( int ini ){

	int v, d, sz, i, u;
	queue< pair<int, int> > q;

	q.push( mp(ini, 0) );

	while( !q.empty() ){

		v = q.front().first;
		d = q.front().second;
		q.pop();

		if( d<=G ){
			elm.insert(v) ;
		}

		if( !vis[v] ){

			vis[v] = 1;

			sz = adj[v].size();

			for( i=0; i<sz; ++i ){
				q.push( mp( adj[v][i], d+1 ) );
			}
		}
	}
}

int main(){

	map< string, int > p; // pessoas
	map< string, int >::iterator it;
	int N, i, k=0;
	char A[22], B[22];

	scanf( "%d%d", &N, &G );
	getchar();

	for( i=0; i<N; ++i ){

		scanf( "%s%s", A, B );

		if( !p.count(A) ){
			vis[k]=0;
			p[A] = k;
			k++;
		}

		if( !p.count(B) ){
			vis[k]=0;
			p[B] = k;
			k++;
		}

		adj[ p[A] ].pb( p[B] );
		adj[ p[B] ].pb( p[A] );
	}

	bfs( p[ "Rerisson" ] );

	if( elm.count( p["Rerisson"] ) ){
		elm.erase( p["Rerisson"] );
	}

	printf( "%d\n", elm.size() );

	for( it=p.begin(); it!=p.end(); ++it ){

		if( elm.count( (*it).second ) ){
			cout << (*it).first << endl;
		}
	}

	return 0;
}
