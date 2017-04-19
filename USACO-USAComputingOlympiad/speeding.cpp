// ConsoleApplication.cpp : main project file.

#include "iostream"
#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "string"
#include "string.h"
#include "vector"
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N,M,road[104], bessie[104],start,finish,Next,speed,answer;

int main() {
	freopen("speeding.in","r",stdin);
	freopen("speeding.out","w",stdout);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		start = finish + 1;
		cin >> Next >> speed;
		finish += Next;
		for (int j = start; j <= finish; ++j)
			road[j] = speed;
	}
	finish = 0;
	for (int i = 1; i <= M; ++i) {
		start = finish + 1;
		cin >> Next >> speed;
		finish += Next;
		for (int j = start; j <= finish; ++j)
			bessie[j] = speed;
	}
	for (int i = 1; i <= 100; ++i) answer = max(answer, bessie[i] - road[i]);
	cout << answer << endl;
	return 0;
}
