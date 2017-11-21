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
#define MV 65
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

void uni( int a, int b, int dis ){

 	int A = findset(a);
    int B = findset(b);

 	if( A != B ){

        lider[A] = B;
        soma += dis;
    }
}

int main(){

    int n, m, d, i;
    int dis, a, b;

    scanf( "%d%d", &n, &m );

	for( i=0; i<n; ++i )
	    lider[i] = i;
	//cada um eh seu proprio lider

	for( i=0; i<m; ++i ){

	    scanf( "%d%d%d", &a, &b, &d );

	    adj.pb( mp( d, mp(a,b) ) );
	}

	sort( adj.begin(), adj.end() );

	soma=0;

	for( i=0; i<m; ++i ){

	 	// pair< int, pari<int, int> >
	    dis = adj[i].F; // First
	    a = adj[i].S.F; // Second-First
	    b = adj[i].S.S; // Second-Second

		uni( a, b, dis );
	}

	printf( "%d\n", soma );

    return 0;
}
