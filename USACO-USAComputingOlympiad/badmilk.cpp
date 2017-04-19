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

int N, M, D, S, p, m, t, answer, cnt;
bool goodmilk[104],badmilk[104],checkpeople[104];
vi milk[104];
vii people[104];

bool cmp(ii a, ii b) { return a.second < b.second; }

int main() {
	freopen("badmilk.in","r",stdin);
	freopen("badmilk.out","w",stdout);
	cin >> N >> M >> D >> S;
	for (int i = 1; i <= D; ++i) {
		cin >> p >> m >> t;
		people[p].push_back(ii(m, t));
		milk[m].push_back(p);
	}
	for (int i = 1; i <= S; ++i) {
		cin >> p >> t;
		cnt = 0;
		while (cnt < people[p].size()) {
			if (goodmilk[people[p][cnt].first] ==false){
				if (people[p][cnt].second < t)
					badmilk[people[p][cnt].first] = true;
				else {
					if (badmilk[people[p][cnt].first] == false)
						goodmilk[people[p][cnt].first] = true;
				}
			}
			cnt++;
		}
		for (int j = 1; j <= M; ++j) {
			if (badmilk[j] == false) goodmilk[j] = true;
			badmilk[j] = false;
		}
	}
	for (int i = 1; i <= M; ++i) {
		if (goodmilk[i] == false) {
			for (int j = 0; j < milk[i].size(); ++j) {
				if (checkpeople[milk[i][j]] == false) {
					++answer;
					checkpeople[milk[i][j]] = true;
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}
