/*USACO 2013 February Contest, Silver
 *Problem 3. Milk Scheduling*/
 
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
#include "stack"
#include "deque"
#include "set"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;
const int MaxN = 1e4;
const int base = 1e9+7;

int N,M;
vector<vi> Adj;
long long times[MaxN+4],minitimes[MaxN+4];

long long getTimes(int i){
    if(minitimes[i]==-1){
        long long start=0;
        for(int j=0;j<Adj[i].size();j++){
            start=max(start,getTimes(Adj[i][j]));
        }
        minitimes[i]=start+times[i];

    }
    return minitimes[i];
}

int main(){
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>times[i];
        minitimes[i]=-1;
    }
    Adj.assign(N+4,vi());
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        Adj[a].push_back(b);
    }
    long long ans=0;
    for(int i=1;i<=N;i++){
        ans=max(ans,getTimes(i));
    }
    cout<<ans<<endl;
    return 0;
}
