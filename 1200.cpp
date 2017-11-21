//Problem com ?rvore Bin?ria
#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	char Chave; // Conteudo
	struct tree* Left;// Ponteiro Esq
	struct tree* Right;// Ponteiro Dir
}Tree;

Tree* pTree=NULL;
bool flag;

void PRE( Tree** pTree ){

	if( (*pTree) != NULL ){

		if( flag ) printf( " " );
		printf( "%c", (*pTree)->Chave );
		flag=true;

		PRE( &(*pTree)->Left );
		PRE( &(*pTree)->Right );
	}
}

void IN( Tree** pTree ){

	if( (*pTree) != NULL ){

		IN( &(*pTree)->Left );

		if( flag ) printf( " " );
		printf( "%c", (*pTree)->Chave );
		flag=true;

		IN( &(*pTree)->Right );
	}
}

void POST( Tree** pTree ){

	if( (*pTree) != NULL ){

		POST( &(*pTree)->Left );
		POST( &(*pTree)->Right );

		if( flag ) printf( " " );
		printf( "%c", ((*pTree)->Chave) );
		flag=true;
	}
}

void Insert( Tree** pTree, char iChave ){

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

void Search( Tree** pTree, char iChave ){

	if( (*pTree) == NULL ){
		printf( "%c nao existe\n", iChave );
		return;
	}
	else{
		if( iChave == (*pTree)->Chave ){
			printf( "%c existe\n", iChave );
			return;
		}
		else{
			if( iChave < (*pTree)->Chave ){
				Search( &(*pTree)->Left, iChave );
				return;
			}
			else{
				Search( &(*pTree)->Right, iChave );
				return;
			}
		}
	}
}

int main(){

	int j, i;
	char S[30], C;

	while( scanf( "%s", S ) != EOF ){

		getchar();
		if( S[0]=='I' && S[1]=='\0' ){

			scanf( "%c", &C );//Elemento a ser inserido
			Insert( &pTree, C );
		}
		else if( S[0]=='I' && S[1]!='\0' ){

			flag=false;
			IN( &pTree );
			printf( "\n" );
		}
		else if( S[0]=='P' && S[1]=='\0' ){

			scanf( "%c", &C );//Elemento a ser procurado
			Search( &pTree, C );
		}
		else if( S[0]=='P' && S[1]=='R' ){

			flag=false;
			PRE( &pTree );
			printf( "\n" );
		}
		else{

			flag=false;
			POST( &pTree );
			printf( "\n" );
		}
	}

	return 0;
}
