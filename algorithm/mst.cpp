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

int V, E, u, v, w;
vector<vii> AdjList;
vector< pair<int, ii> > EdgeList;

void graphUndirected(){
    scanf("%d %d", &V, &E);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        EdgeList.push_back(make_pair(w, ii(u, v)));
        AdjList[u].push_back(ii(v, 0));
        AdjList[v].push_back(ii(u, 0));
    }
}

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1), rank.assign(N, 0), p.assign(N, 0);
        numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else{
                p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
void Kruskal(){
    sort(EdgeList.begin(), EdgeList.end());
    int mst_cost = 0;
    UnionFind UF(V + 4);
    for (int i = 0; i < E; i++) {
        pair<int, ii> front = EdgeList[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }
    printf("MST cost = %d (Kruskal's)\n", mst_cost);
}

vi taken;
priority_queue<ii> P;
void process(int vtx) {
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) P.push(ii(-v.second, -v.first));
    }
}
void Prim(){
    int mst_cost = 0;
    taken.assign(V+4, 0);
    process(0);
    while (!P.empty()) {
        ii front = P.top(); P.pop();
        u = -front.second, w = -front.first;
        if (!taken[u])
            mst_cost += w, process(u);
    }
    printf("MST cost = %d (Prim's)\n", mst_cost);
}

int main(){
    graphUndirected();
    Kruskal();
    Prim();
    return 0;
}
