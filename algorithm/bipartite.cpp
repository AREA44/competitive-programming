#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "queue"
#include "stack"
#include "deque"
#include "set"
using namespace std;

int V, E, u, v;
vector<vii> AdjList;

void graphUndirected(){
	scanf("%d %d", &V, &E);
	AdjList.assign(V + 4, vii());
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &u, &v);
		AdjList[u].push_back(ii(v, 0));
		AdjList[v].push_back(ii(u, 0));
	}
}

bool isBipartite = true;
void bfs(int s){
	vi d(V + 4, inf); d[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if (d[v.first] == inf) {
				d[v.first] = d[u] + 1;
				q.push(v.first);
			}
			else if ((d[v.first] % 2) == (d[u] % 2)) isBipartite = false;
		}
	}
}

int main(){
	graphUndirected();
	bfs(5);
	printf("isBipartite? %s\n", isBipartite?"Yes":"No");
	return 0;
}
