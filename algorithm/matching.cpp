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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MaxN 100001
#define inf 1000000009
#define inf_div 50000004
#define base 1000000009

vi G[MaxN];
int n, m, match[MaxN], dist[MaxN];

bool bfs() {
	queue< int > Q;
	for (int i = 1; i <= n; i++) {
		if (match[i] == NULL) {
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = inf;
	}
	dist[NULL] = inf;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		if (u != NULL) {
			for (int i = 0; i<G[u].size(); i++) {
				int v = G[u][i];
				if (dist[match[v]] == inf) {
					dist[match[v]] = dist[u] + 1;
					Q.push(match[v]);
				}
			}
		}
	}
	return (dist[NULL] != inf);
}

bool dfs(int u) {
	if (u != NULL) {
		for (int i = 0; i<G[u].size(); i++) {
			int v = G[u][i];
			if (dist[match[v]] == dist[u] + 1) {
				if (dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		dist[u] = inf;
		return false;
	}
	return true;
}

void hopcroft_karp() {
	int matching = 0;
	while (bfs())
	for (int i = 1; i <= n; i++)
	if (match[i] == NULL && dfs(i))
		matching++;
	printf("%d\n", matching);
	for (int i = 1; i <= n; i++)
	if (match[i] != 0)
		printf("%d %d\n", i, match[i] - n);
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	while (scanf("%d%d", &u, &v) != EOF){
		v += n;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	hopcroft_karp();
	return 0;
}
