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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;
const double pi = acos(-1);
const int base = 1e9;
const int MaxN = 5e4+4;

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
vi dist(V+4, inf);
void dijkstra(int s){
    dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > P;
    P.push(ii(0, s));
    while (!P.empty()) {
        ii front = P.top(); P.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                P.push(ii(dist[v.first], v.first));
            }
        }
    }
}

int main(){
    printf("Standard Dijkstra (the input graph must be UNDIRECTED)\n");
    graphUndirected();
    scanf("%d",&s);
    dijkstra(s);
    for (int i = 0; i < V; i++)
        printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
    return 0;
}
