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
int V, E, u, v, s;

void graphUndirected(){
    scanf("%d %d", &V, &E);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        AdjList[u].push_back(ii(v, 0));
        AdjList[v].push_back(ii(u, 0));
    }
}

vi p;
void printPath(int u) {
    if (u == s) { printf("%d", u); return; }
    printPath(p[u]);
    printf(" %d", u);
}

void bfs(int s){
    vi d(V + 4, inf); d[s] = 0;
    queue<int> q; q.push(s);
    p.assign(V + 4, -1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (d[v.first] == inf) {
                d[v.first] = d[u] + 1;
                p[v.first] = u;
                q.push(v.first);
            }
        }
    }
}

int main(){
    graphUndirected();
    s = 5, bfs(s);
    printPath(7);
    printf("\n");
    return 0;
}
