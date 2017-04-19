/* USACO 2013 December Contest, Gold
 * Problem 1. Vacation Planning (gold) */
 
// nhatnguyendrgs (c) 2015

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
const int base = 1e6;
const int MaxN = 1e2;

int N, M, K, Q,u,v,d,center[204];
vector<vii> Adj,rAdj;

int dist[204][20004];
void dijkstra(int id){
	for (int i = 1; i <= N; ++i)
		dist[id][i] = inf;
	dist[id][center[id]] = 0;
	priority_queue<ii, vii > P;
	P.push(ii(0, center[id]));
	while (!P.empty()){
		ii front = P.top(); P.pop();
		int di = -front.first, ui = front.second;
		if (di > dist[id][ui]) continue;
		for (int j = 0; j < Adj[ui].size(); ++j){
			ii vi = Adj[ui][j];
			if (dist[id][vi.first]>di + vi.second){
				dist[id][vi.first] = di + vi.second;
				P.push(ii(-dist[id][vi.first], vi.first));
			}
		}
	}
}

int rdist[204][20004];
void rdijkstra(int id){
	for (int i = 1; i <= N; ++i)
		rdist[id][i] = inf;
	rdist[id][center[id]] = 0;
	priority_queue<ii, vii > P;
	P.push(ii(0, center[id]));
	while (!P.empty()){
		ii front = P.top(); P.pop();
		int di = -front.first, ui = front.second;
		if (di > rdist[id][ui]) continue;
		for (int j = 0; j < rAdj[ui].size(); ++j){
			ii vi = rAdj[ui][j];
			if (rdist[id][vi.first] > di + vi.second){
				rdist[id][vi.first] = di + vi.second;
				P.push(ii(-rdist[id][vi.first], vi.first));
			}
		}
	}
}

int main(){
	freopen("vacationgold.in","r",stdin);
    	freopen("vacationgold.out","w",stdout);
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	Adj.assign(N + 4, vii()); rAdj.assign(N + 4, vii());
	for (int i = 1; i <= M; ++i){
		scanf("%d%d%d", &u, &v, &d);
		Adj[u].push_back(ii(v, d));
		rAdj[v].push_back(ii(u, d));
	}
	for (int i = 1; i <= K; ++i){
		scanf("%d", &center[i]);
		dijkstra(i);
		rdijkstra(i);
	}
	long long answer = 0;
	int duv, cnt = 0;
	for (int i = 1; i <= Q; ++i){
		scanf("%d%d", &u, &v);
		duv = inf;
		for (int j = 1; j <= K; ++j)
			duv = min(duv, rdist[j][u] + dist[j][v]);
		if (duv < inf){
			cnt++;
			answer += duv;
		}
	}
	printf("%d\n%lld\n", cnt, answer);
	return 0;
}
