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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;

#define DFS_WHITE -1 //    UNVISITED
#define DFS_BLACK 1  //    VISITED

vector<vii> AdjList;
int V, E, u, v, w;

void graphDirected(){
    scanf("%d %d", &V, &E);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        AdjList[u].push_back(ii(v, w));
    }
}

vi dfs_num,dfs_low;
vi S, visited;                                      // additional global variables
int numSCC, dfsNumberCounter;
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;   // dfs_low[u] <= dfs_num[u]
    S.push_back(u);      // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
              if (dfs_num[v.first] == DFS_WHITE)
            tarjanSCC(v.first);
        if (visited[v.first])                       // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }
    if (dfs_low[u] == dfs_num[u]) {                 // if this is a root (start) of an SCC
        printf(" SCC %d:", ++numSCC);               // this part is done after recursion
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            printf(" %d", v);
            if (u == v) break;
        }
        printf("\n");
    }
}

int main(){
    printf("Strongly Connected Components (the input graph must be DIRECTED)\n");
    graphDAG();
    dfs_num.assign(V+4, DFS_WHITE); dfs_low.assign(V+4, 0); visited.assign(V+4, 0);
    dfsNumberCounter = numSCC = 0;
    for (int i = 0; i < V; i++)
    if (dfs_num[i] == DFS_WHITE) tarjanSCC(i);
    printf("\n");
    return 0;
}
