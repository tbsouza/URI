#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define pb push_back
#define MV 200005
#define mp make_pair
#define S second
#define F first
#define pi pair< int, int >

vector< pair< int, pi > > adj;
int lider[MV], soma;

int findset( int A ){

	if( A != lider[A] )
		lider[A] = findset( lider[A] );

	return lider[A];
}

void uni( int a, int b ){

	lider[a] = b;
}

int main(){

	int n, m, x, y, d, i;

	while( scanf( "%d%d", &n, &m ), n||m ){

		for( i=0; i<m; ++i ){

			scanf( "%d%d%d", &x, &y, &d );

			adj.pb( mp( d, mp(x,y) ) );
		}

		for( i=0; i<n; ++i )
			lider[i] = i;

		sort( adj.begin(), adj.end() );

		soma = 0;

		for( i=0; i<m; ++i ){

			int dis = adj[i].F;
			int a = adj[i].S.F;
			int b = adj[i].S.S;

			int A = findset(a);
			int B = findset(b);

			if( A != B )
				uni( A, B );
			else
				soma +=	dis;
		}

		printf( "%d\n", soma );

		adj.clear();
	}

	return 0;
}
