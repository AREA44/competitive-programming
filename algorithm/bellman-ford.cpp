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
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;
const int base = 1e9 + 7;
const int MaxN = 1e3;

vector<vii> AdjList;
int V, E, u, v, w, s;

void graphDirected(){
    scanf("%d %d %d", &V, &E, &s);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        AdjList[u].push_back(ii(v, w));
    }
}

void BellmanFord(int s){
    vi dist(V, inf); dist[s] = 0;
    for (int i = 0; i < V - 1; i++){
        for (int u = 0; u < V; u++){
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++){
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second)
                hasNegativeCycle = true;
        }
    }
    printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");
    if (!hasNegativeCycle){
        for (int i = 0; i < V; i++)
            printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
    }
}

int main(){
    graphDirected();
    BellmanFord(s);
    return 0;
}
