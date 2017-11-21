#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

typedef struct tree{
	int Chave;
	struct tree* Left;
	struct tree* Right;
}Tree;

Tree* pTree;
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

void PRE( Tree** pTree ){

	if( (*pTree) != NULL ){

		if( flag ) printf( " " );
		printf( "%d", (*pTree)->Chave );
		flag=true;

		PRE( &(*pTree)->Left );
		PRE( &(*pTree)->Right );
	}
}

void IN( Tree** pTree ){

	if( (*pTree) != NULL ){

		IN( &(*pTree)->Left );

		if( flag ) printf( " " );
		printf( "%d", (*pTree)->Chave );
		flag=true;

		IN( &(*pTree)->Right );
	}
}

void POST( Tree** pTree ){

	if( (*pTree) != NULL ){

		POST( &(*pTree)->Left );
		POST( &(*pTree)->Right );

		if( flag ) printf( " " );
		printf( "%d", (*pTree)->Chave );
		flag=true;
	}
}

int main(){

	int N, j=0, T, X;

	scanf( "%d", &N );
	while( N-- ){

		pTree=NULL;

		scanf( "%d", &T );
		while( T-- ){

			scanf( "%d", &X );
			Insert( &pTree, X );
		}

		printf("Case %d:\n", ++j );

		flag=false;
		printf( "Pre.: " );
		PRE( &pTree );

		flag=false;
		printf( "\nIn..: " );
		IN( &pTree );

		flag=false;
		printf( "\nPost: " );
		POST( &pTree );

		printf( "\n\n" );
	}

	return 0;
}
