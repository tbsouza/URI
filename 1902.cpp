#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

vector<int> adj[MAX];
int vis[MAX], t=0;

void dfs( int u ){

    vis[u]=1;

    int sz = adj[u].size();

    for( int i=0; i<sz; ++i){

        int v = adj[u][i];

        if( vis[v]==0 ) dfs(v);
        else if( vis[v]==1 ) t++;
    }

    vis[u] = 2;
}

int main(){

    map<string, int> mp;
    char A[11], B[11];
    int id=0, i;

    while( scanf("%s%s", A, B) != EOF ){

        if( !mp.count(A) ){
            mp[A] = id;
            ++id;
        }

        if( !mp.count(B) ){
            mp[B] = id;
            ++id;
        }

        adj[mp[A]].push_back(mp[B]);
    }
    for(i=0; i<id; ++i)
        vis[i] = 0; // not visited

    for(i=0; i<id; ++i){
        if( vis[i]==0 ){
            dfs(i);
        }
    }

    printf( "%d\n", t );

    return 0;

}
