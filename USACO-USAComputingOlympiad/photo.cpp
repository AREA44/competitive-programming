/*USACO 2011 December Contest, Gold Division
 *Problem 1. Cow Photography*/
 
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
const int MaxN = 1e5;

int N, Cow[MaxN + 4];
int pos;
map<int, int> mii[14];

bool cmp(int a, int b){
	int Count = 0;
	for (int i = 1; i <= 5; ++i){
		Count += mii[i][a] < mii[i][b];
	}
	return Count>2;
}

int main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	scanf("%d", &N);
	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &pos);
			mii[i][pos] = j;
			Cow[j] = pos;
		}
	}
	sort(Cow + 1, Cow + N + 1, cmp);
	for (int i = 1; i <= N; ++i)
		printf("%d\n", Cow[i]);
	return 0;
}
