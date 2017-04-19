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
using namespace std;

#define MaxN 10000004
typedef long long int64;
typedef vector<int> vi;
const long long inf = 1e9 + 7;
const long long inf_div = 5e8 + 4;
const long long base = 1e8 + 3;

vi Prime;

int main(){
	Prime.push_back(0);
	Prime.push_back(2);
	int p=3;
	while(p<=10000){
		bool ok=true;
		for(int i=1;i<Prime.size();i++){
			if(p%Prime[i]==0){
				ok=false;
				break;
			}
			if(Prime[i]>sqrt(p))
				break;
		}
		if(ok==true)
			Prime.push_back(p);
		p++;
	}
	for(int i=1;i<Prime.size();i++)
		printf("%d ",Prime[i]);
    return 0;
}
