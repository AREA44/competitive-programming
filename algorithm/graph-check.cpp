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
#define DFS_BLACK 1  //    EXPLORED
#define DFS_GRAY 2   //    VISTED BUT NOT EXPLORED

vector<vii> AdjList;
int V, E, u, v, w;

void graphDAG(){
    scanf("%d %d", &V, &E);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        AdjList[u].push_back(ii(v, w));
    }
}

vi dfs_num,dfs_parent;
int numCC;
void graphCheck(int u) {                // DFS for checking graph edge properties
    dfs_num[u] = DFS_GRAY;              // color this as DFS_GRAY (temp) instead of DFS_BLACK
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {        // Tree Edge, DFS_GRAY to DFS_WHITE
            dfs_parent[v.first] = u;                // parent of this children is me
            graphCheck(v.first);
        }
        else if (dfs_num[v.first] == DFS_GRAY) {    // DFS_GRAY to DFS_GRAY
            if (v.first == dfs_parent[u])           // to differentiate these two cases
                printf("  Bidirectional (%d, %d) - (%d, %d)\n", u, v.first, v.first, u);
            else                                    // the most frequent application: check if the given graph is cyclic
                printf("  Back Edge (%d, %d) (Cycle)\n", u, v.first);
        }
        else if (dfs_num[v.first] == DFS_BLACK)     // DFS_GRAY to DFS_BLACK
            printf("  Forward/Cross Edge (%d, %d)\n", u, v.first);
    }
    dfs_num[u] = DFS_BLACK;                         // after recursion, color this as DFS_BLACK (DONE)
}

int main(){
    printf("Graph Edges Property Check (the input graph must be DAG)\n");
    graphDAG();
    numCC = 0;
    dfs_num.assign(V, DFS_WHITE); dfs_parent.assign(V, -1);
    for (int i = 0; i < V; i++)
    if (dfs_num[i] == DFS_WHITE)
        printf(" Component %d:\n", ++numCC), graphCheck(i);
    printf("\n");
    return 0;
}
