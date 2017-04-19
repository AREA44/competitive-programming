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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MaxN = 1e3 +4;
const int Log_2_MaxN = log2(MaxN)+4;

class RMQ {
private:
    int _A[MaxN], SpT[MaxN][Log_2_MaxN];
public:
    RMQ(int n, int A[]) {       // constructor as well as pre-processing routine
        for (int i = 0; i < n; i++) {
            _A[i] = A[i];
            SpT[i][0] = i;      // RMQ of sub array starting at index i + length 2^0=1
        }
        // the two nested loops below have overall time complexity = O(n log n)
        for (int j = 1; (1<<j) <= n; j++)                           // for each j s.t. 2^j <= n, O(log n)
            for (int i = 0; i + (1<<j) - 1 < n; i++)                // for each valid i, O(n)
                if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])   // RMQ
                    SpT[i][j] = SpT[i][j-1];                        // start at index i of length 2^(j-1)
                else                                                // start at index i+2^(j-1) of length 2^(j-1)
                    SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
        }

    int rmq(int i, int j) {
        int k = (int)floor(log((double)j-i+1) / log(2.0));          // 2^k <= (j-i+1)
        if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
        else return SpT[j-(1<<k)+1][k];
    }
};

vector<vi> children;
int L[2*MaxN], E[2*MaxN], H[MaxN], idx;
void dfs(int cur, int depth) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for (int i = 0; i < children[cur].size(); i++) {
        dfs(children[cur][i], depth+1);
        E[idx] = cur;                               // backtrack to current node
        L[idx++] = depth;
    }
}

void buildRMQ() {
    idx = 0;
    memset(H, -1, sizeof H);
    dfs(0, 0);
}

int lca(int u,int v,RMQ st){
    if(H[u]>H[v]) swap(u,v);
    return E[st.rmq(H[u],H[v])];
}

int V,u,v;

int main() {
    scanf("%d",&V);
    children.assign(14, vi());
    for(int i=1;i<V;i++){
        scanf("%d%d",&u,&v);
        children[u].push_back(v);
    }
    // children[0].push_back(1); children[0].push_back(7);
    // children[1].push_back(2); children[1].push_back(3); children[1].push_back(6);
    // children[3].push_back(4); children[3].push_back(5);
    // children[7].push_back(8); children[7].push_back(9);

    buildRMQ();
    for (int i = 0; i < 2*10-1; i++) printf("%d ", H[i]);printf("\n");
    for (int i = 0; i < 2*10-1; i++) printf("%d ", E[i]);printf("\n");
    for (int i = 0; i < 2*10-1; i++) printf("%d ", L[i]);printf("\n");

    RMQ st(MaxN,L);
    while(1){
        scanf("%d%d",&u,&v);
        if (u==0&&v==0) break;
        else printf("%d\n",lca(u,v,st));
    }
    return 0;
}
