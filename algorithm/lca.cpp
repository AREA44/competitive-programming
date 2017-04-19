#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
#include "set"
using namespace std;
typedef pair<int,int> ii;

int Test, N, m, Q, up[1004][1004], times, visited[1004];
vector<int> Adj[1004];
ii t[1004];

int Log(){
    int ans = 0;
    for (int i=N;i/2>0;i/=2) ans++;
    return ans;
}

void reset(){
    times = 0;
    m = Log();
    for (int i=1;i<=N;i++){
        Adj[i].clear();
        visited[i] = 0;
        t[i].first = t[i].second = 0;
    }
    for (int i=1;i<=N;i++){
        for (int j=0;j<=m;j++)
            up[i][j] = 0;
    }
}

void dfs(int u, int v){
    t[v].first = ++times;
    visited[v] = 1;
    up[v][0] = u;
    for (int i=1;i<=m;i++) up[v][i] = up[up[v][i-1]][i-1];
    for (int i=0;i<Adj[v].size();i++){
        int k = Adj[v][i];
        if (!visited[k])
        dfs(v, k);
    }
    t[v].second = ++times;
}

bool upper(int u, int v){
    return (t[u].first <= t[v].first and t[u].second >= t[v].second);
}

int lca(int u, int v){
    if (upper(u,v)) return u;
    if (upper(v,u)) return v;
    for (int i=m;i>=0;i--)
        if (up[u][i] > 0 && ! upper(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int main(){
    scanf("%d", &Test);
    for (int test = 1 ; test <= Test ; test++){
        printf("Case %d:\n", test);
        scanf("%d", &N);
        reset();
        for (int u=1;u<=N;u++){
            int v, sl;
            scanf("%d", &sl);
            while (sl--){
                scanf("%d", &v);
                Adj[u].push_back(v);
            }
        }
        dfs(0,1);
        scanf("%d", &Q);
        while (Q--){
            int u, v;
            scanf("%d%d", &u,&v);
            printf("%d\n", lca(u, v));
        }
    }
    return 0;
}
