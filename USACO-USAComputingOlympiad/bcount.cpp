// ConsoleApplication.cpp : main project file.

#include "iostream"
#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "string"
#include "string.h"
#include "vector"
#include "map"
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int A[100004], B[100004], C[100004];
int N, Q, a, b, id;

int main() {
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) {
		cin >> id;
		if (id == 1) A[i] = A[i - 1] + 1, B[i] = B[i - 1], C[i] = C[i - 1];
		else if(id==2) A[i] = A[i - 1], B[i] = B[i - 1] +1, C[i] = C[i - 1];
		else A[i] = A[i - 1], B[i] = B[i - 1], C[i] = C[i - 1] +1;
	}
	for (int i = 1; i <= Q; ++i) {
		cin >> a >> b;
		cout << A[b] - A[a - 1] << " " << B[b] - B[a - 1] << " " << C[b] - C[a - 1] << endl;
	}
	return 0;
}
