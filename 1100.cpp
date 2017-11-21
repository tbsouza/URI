#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int bfs( int x, int y, int dis );

#define pb push_back
#define p push
#define mp make_pair
#define F first
#define S second
#define pii pair< int, int >

int vis[10][10];
int x2, y2;

int bfs( int x, int y, int dis ){

	queue< pair< pii, int > > q;
	int nx, ny, nd;

	q.push( mp( mp(x,y), dis ) );

	while( !q.empty() ){

		pair< pii, int > p = q.front();
		q.pop();

		nx = p.F.F;
		ny = p.F.S;
		nd = p.S;

		if( vis[nx][ny] == 0 ){

			vis[nx][ny] = 1;

			if( (nx==x2) && (ny==y2) )
				return nd;
			else{

				if( nx+2<=8 && ny+1<=8 )
					q.p( mp( mp( nx+2,ny+1 ), nd+1 ) );

				if( nx+2<=8 && ny-1>=1 )
					q.p( mp( mp( nx+2,ny-1 ), nd+1 ) );

				if( nx+1<=8 && ny-2>=1 )
					q.p( mp( mp( nx+1,ny-2 ), nd+1 ) );

				if( nx-1>=1 && ny-2>=1 )
					q.p( mp( mp( nx-1,ny-2 ), nd+1 ) );

				if( nx-2>=1 && ny-1>=1 )
					q.p( mp( mp( nx-2,ny-1 ), nd+1 ) );

				if( nx-2>=1 && ny+1<=8 )
					q.p( mp( mp( nx-2,ny+1 ), nd+1 ) );

				if( nx-1>=1 && ny+2<=8 )
					q.p( mp( mp( nx-1,ny+2 ), nd+1 ) );

				if( nx+1<=8 && ny+2<=8 )
					q.p( mp( mp( nx+1,ny+2 ), nd+1 ) );

			}
		}
	}
}

int main(){

	string str1, str2;

	while( cin >> str1 >> str2 ){

		for( int i=0; i<10; ++i )
			for( int j=0; j<10; ++j )
				vis[i][j] = 0;

		x2 = str2[0] - 'a' + 1;
		y2 = str2[1] - '0';

		int T = bfs( str1[0] - 'a' + 1, str1[1] - '0', 0 );

		cout <<"To get from "<<str1<<" to "<<str2<<" takes "<<T<<" knight moves."<< endl;
	}

	return 0;
}
