#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;

#define DFS_WHITE -1 //    UNVISITED
#define DFS_BLACK 1  //    VISITED

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

vi dfs_num,dfs_low,dfs_parent;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;   // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {        // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;       // special case, count children of root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u])     // for articulation point
                articulation_vertex[u] = true;      // store this information first
            if (dfs_low[v.first] > dfs_num[u])      // for bridge
                printf("  Edge (%d, %d) is a bridge.\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // update dfs_low[u]
        }
        else if (v.first != dfs_parent[u])          // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);     // update dfs_low[u]
    }
}


int main(){
    printf("Articulation Points & Bridges (the input graph must be UNDIRECTED)\n");
    graphUndirected();
    dfsNumberCounter = 0; dfs_num.assign(V+4, DFS_WHITE); dfs_low.assign(V+4, 0);
    dfs_parent.assign(V+4, -1); articulation_vertex.assign(V+4, 0);
    printf(" Bridges:\n");
    for (int i = 0; i < V; i++)
    if (dfs_num[i] == DFS_WHITE) {
        dfsRoot = i; rootChildren = 0;
        articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = (rootChildren > 1);  // special case
    }
    printf(" Articulation Points:\n");
    for (int i = 0; i < V; i++)
    if (articulation_vertex[i])
        printf("  Vertex %d.\n", i);
    printf("\n");
    return 0;
}
