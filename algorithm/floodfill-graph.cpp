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
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define DFS_WHITE -1 // unvisited
#define DFS_BLACK 1  // visited

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
void floodfill(int u, int color) {
    dfs_num[u] = color;                            // not just a generic DFS_BLACK
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            floodfill(v.first, color);
    }
}

int main(){
    printf("Flood Fill Demo (the input graph must be UNDIRECTED)\n");
    numCC = 0;
    dfs_num.assign(V+4, DFS_WHITE);
    for (int i = 0; i < V; i++)
    if (dfs_num[i] == DFS_WHITE)
        floodfill(i, ++numCC);
    for (int i = 0; i < V; i++)
        printf(" Vertex %d has color %d.\n", i, dfs_num[i]);
    printf("\n");
    return 0;
}
