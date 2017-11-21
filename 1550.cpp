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
#define mp make_pair

int T, A, B;
int vis[200000];
int res = 0;

int inv( int num ){

	int i = 0;

	while( num > 0 ){

		i *= 10;

		i += num%10;

		num /= 10;
	}

	return i;
}

void bfs(){

	queue< pair<int,int> > q;

	q.push( mp( A, 0 ) );

	while( !q.empty() ){

		pair<int,int> t = q.front(); q.pop();

		int u = t.first;
		int d = t.second;

		if( vis[ u ] == 0 && u < 11000 ){

			vis[u] = 1;

			int I = inv( u );

			if( (I==B) || ((u+1)==B) ){

				res = d+1;
				return;
			}

			q.push( mp(u+1,d+1) );
			q.push( mp(I, d+1) );
		}
	}
}

int main(){

	scanf( "%d", &T );

	while( T-- ){

		memset( vis, 0, sizeof(vis) );

		scanf( "%d%d", &A, &B );

		bfs();

		printf( "%d\n", res );

	}

	return 0;
}
