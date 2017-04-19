#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define DFS_WHITE -1 //	unvisited
#define DFS_BLACK 1  //	visited

vector<vii> AdjList;
int V, E, u, v, w;

void graphUndirected(){
    scanf("%d %d", &V, &E);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v,&w);
        AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
    }
}

vi dfs_num;
int numCC;
void dfs(int u) {                    // DFS for normal usage: as graph traversal algorithm
    printf(" %d", u);                // this vertex is visited
    dfs_num[u] = DFS_BLACK;          // important step: we mark this vertex as visited
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
        if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
            dfs(v.first);            // recursively visits unvisited neighbors v of vertex u
    }
}

int main(){
    printf("Standard DFS Demo (the input graph must be UNDIRECTED)\n");
    graphUndirected();
    numCC = 0;
    dfs_num.assign(V, DFS_WHITE);           // this sets all vertices' state to DFS_WHITE
    for (int i = 0; i < V; i++)             // for each vertex i in [0..V-1]
    if (dfs_num[i] == DFS_WHITE)            // if that vertex is not visited yet
        printf(" Component %d:", ++numCC), dfs(i), printf("\n");   // 3 lines here!
    printf(" There are %d connected components.\n", numCC);
    printf("\n");
    return 0;
}
