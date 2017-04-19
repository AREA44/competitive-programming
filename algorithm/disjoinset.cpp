#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "deque"
#include "assert.h"
using namespace std;

typedef vector<int> vi;

vi pset(1004);

void initSet(int _size) { pset.resize(_size); for (int i = 0; i < _size;i++) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int V, E;

int main(){
    scanf("%d%d", &V, &E);
    initSet(V);
    int p, q;
    for (int i = 0; i<E; i++){
       scanf("%d%d",&p,&q);
       unionSet(p, q);
    }
    for (int i = 0; i<V; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i<V; i++) printf("%d ", findSet(i));
    printf("\n");
    return 0;
}
