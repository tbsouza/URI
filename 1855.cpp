#include <stdio.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

char m[101][101];
int vis[101][101], x, y;

void verify(){

	int a, b, i, sz=x*y, flag;

	a=b=0;

	for( i=0; i<sz; ++i ){

		if( (!vis[a][b]) && (a>=0&&a<y) && (b>=0&&b<x) ){

			vis[a][b] = 1; // visited

			if( m[a][b] == '*' ){
				printf( "*\n" );
				return;
			}else if( m[a][b] == '.' ){
				if( flag==1 ) b++;
				else if( flag==2 ) b--;
				else if( flag==3 ) a++;
				else a--;
			}else{
				if( m[a][b] == '>' ){
				    flag=1;
				    b++;
				}else if( m[a][b] == '<' ){
				    flag=2;
				    b--;
				}else if( m[a][b] == 'v' ){
					flag=3;
					a++;
				}else if( m[a][b] == '.' );
				else{
				 	flag=4;
				 	a--;
				}
			}
		}else{
			printf( "!\n" );
			return;
		}
	}

	printf( "!\n" );
	return;
}

int main(){

	int i, j;

	scanf("%d%d", &x, &y);
	getchar();

	for( i=0; i<y; ++i ){
		scanf( "%s", m[i] );
		for( j=0; j<x; ++j ) vis[x][y] = 0;
	}

	verify();

	return 0;
}
