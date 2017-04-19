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

int n,m;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1),rank.assign(N, 0),p.assign(N, 0);
    numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {p[y] = x; setSize[x] += setSize[y];}
            else{
                p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
  	int numDisjointSets() { return numSets;}
  	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
    scanf("%d%d", &n, &m);
    UnionFind Set(n+4);
    int u, v;
    while (m--){
        scanf("%d%d", &u, &v);
        Set.unionSet(u, v);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ",Set.findSet(i));
    printf("\n");
    return 0;
}
