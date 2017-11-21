#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct tree{
	int Chave;
	struct tree* Left;
	struct tree* Right;
}Tree;

queue<Tree*> Que;
bool flag;

void Insert( Tree** pTree, int iChave ){

	if( (*pTree)==NULL ){

		(*pTree) = (Tree*)malloc( sizeof(Tree));

		if( (*pTree) ){
			(*pTree)->Chave = iChave;
			(*pTree)->Left = NULL;
			(*pTree)->Right = NULL;
		}
	}
	else{
		if( iChave < (*pTree)->Chave )
			Insert( &(*pTree)->Left, iChave );
		else
			Insert( &(*pTree)->Right, iChave );
	}
}

void Search( Tree** pTree ){

	Tree* pN=NULL;

	if( pTree != NULL ){

		Que.push( (*pTree) );
		while( !( Que.empty() ) ){

			pN =  Que.front();
			Que.pop();

			if( (pN->Left) != NULL )
				Que.push( pN->Left );
			if( (pN->Right) != NULL )
				Que.push( pN->Right );

			if( flag ) printf( " " );
			printf( "%d", pN->Chave );
			flag=true;
		}
	}
}

int main(){

	int N, j=0, T, X;

	scanf( "%d", &N );
	while( N-- ){

		Tree* pTree=NULL;

		scanf( "%d", &T );
		while( T-- ){

			scanf( "%d", &X );
			Insert( &pTree, X );
		}

		flag=false;
		printf("Case %d:\n", ++j );
		Search( &pTree );
		printf( "\n\n" );
	}

	return 0;
}
