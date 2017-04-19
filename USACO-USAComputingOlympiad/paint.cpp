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

int a,b,c,d;

int main() {
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a > b) swap(a, b);
	if (c > d) swap(c, d);
	if (a > d || b < c) cout << (b - a) + (d - c) << endl;
	else cout << max(b, d) - min(a, c) << endl;
	return 0;
}
