#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "queue"
#include "stack"
#include "deque"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;

#define DFS_WHITE -1 //    unvisited
#define DFS_BLACK 1  //    visited

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

int s;
void bfs(int s){
    vi d(V+4, inf); d[s] = 0;         // distance to source is 0 (default)
    queue<int> q; q.push(s);          // start from source
    int layer = -1;                   // for our output printing purpose
    while (!q.empty()) {
        int u = q.front(); q.pop();   // queue: layer by layer!
        if (d[u] != layer) printf("\n Layer %d: ", d[u]);
        layer = d[u];
        printf(" visit %d ", u);
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];      // for each neighbors of u
            if (d[v.first] == inf) {
                d[v.first] = d[u] + 1; // v unvisited + reachable
                q.push(v.first);       // enqueue v for next step
            }
        }
    }
}

int main(){
    printf("Standard BFS Demo (the input graph must be UNDIRECTED)\n");
    graphUndirected();
    s = 5; bfs(s);
    printf("\n");
    return 0;
}
