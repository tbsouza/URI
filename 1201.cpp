#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int Chave; // Conteudo
    struct tree* Left;// Ponteiro Esq
    struct tree* Right;// Ponteiro Dir
}Tree;

Tree* pTree=NULL;
bool flag;

void PRE( Tree** pTree ){
//PREFIXA: 1-Raiz 2-Esq 3-Dir

    if( (*pTree) != NULL ){

        if( flag ) printf( " " );
        printf( "%d", (*pTree)->Chave );
        flag=true;

        PRE( &(*pTree)->Left );
        PRE( &(*pTree)->Right );
    }
}

void IN( Tree** pTree ){
//INFIXA (em ordem): 1-Esq 2-Raiz 3-Dir

    if( (*pTree) != NULL ){

        IN( &(*pTree)->Left );

        if( flag ) printf( " " );
        printf( "%d", (*pTree)->Chave );
        flag=true;

        IN( &(*pTree)->Right );
    }
}

void POST( Tree** pTree ){
//POSFIXA: 1-Esq 2-Dir 3-Raiz

    if( (*pTree) != NULL ){

        POST( &(*pTree)->Left );
        POST( &(*pTree)->Right );

        if( flag ) printf( " " );
        printf( "%d", ((*pTree)->Chave) );
        flag=true;
    }
}

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

void Search( Tree** pTree, int iChave ){

    if( (*pTree) == NULL ){
        printf( "%d nao existe\n", iChave );
        return;
    }
    else{
        if( iChave == (*pTree)->Chave ){
            printf( "%d existe\n", iChave );
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

Tree* Menor( Tree** pTree ){

    Tree* pAux = (*pTree);

    if( pAux->Right == NULL ){// Encontrou o menor
        (*pTree) = (*pTree)->Left;
        return pAux;
    }
    else{ // Continua a busca
        return Menor( &(*pTree)->Right );
    }
}

void Remove( Tree** pTree, int iChave ){

    Tree* pN;

    if( (*pTree)==NULL )// ?rvore nula
        return;
    if( iChave == (*pTree)->Chave ){
        pN = (*pTree);

        if( (*pTree)->Left==NULL )//N? nao tem filho a Esq
            (*pTree) = (*pTree)->Right;
        else if( (*pTree)->Right==NULL )//N? nao tem filho a Dir
            (*pTree) = (*pTree)->Left;
        else{ // N? tem ambos os filhos

            pN = Menor( &(*pTree)->Left );
            (*pTree)->Chave = pN->Chave;
        }

        pN=NULL;
        return;
    }
    else if( iChave < (*pTree)->Chave ){
        Remove( &(*pTree)->Left, iChave );
        return;
    }
    else{
        Remove( &(*pTree)->Right, iChave );
        return;
    }
}

int main(){

    int j, i, C;
    char S[30];

    while( scanf( "%s", S ) != EOF ){

        getchar();
        if( S[0]=='I' && S[1]=='\0' ){
            scanf( "%d", &C ); //Elemento a ser inserido
            Insert( &pTree, C );
        }
        else if( S[0]=='I' && S[1]!='\0' ){
            flag=false;
            IN( &pTree );
            printf( "\n" );
        }
        else if( S[0]=='P' && S[1]=='\0' ){
            scanf( "%d", &C ); //Elemento a ser procurado
            Search( &pTree, C );
        }
        else if( S[0]=='P' && S[1]=='R' ){
            flag=false;
            PRE( &pTree );
            printf( "\n" );
        }
        else if( S[0]=='R' ){
            scanf( "%d", &C ); //Elemento a ser removido
            Remove( &pTree, C );
        }
        else{
            flag=false;
            POST( &pTree );
            printf( "\n" );
        }
    }

    return 0;
}
