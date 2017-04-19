#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;

int n, x[MaxN],y[MaxN];
double S;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	x[0]=x[n];x[n+1]=x[1];
	for (int i = 1; i <= n; i++)
		S+=y[i]*(x[i-1]-x[i+1]);
	if(S>=0){
		printf("CCW\n");
		S/=2;
	}
	else{
		printf("CW\n");
		S=-S/2;
	}
	printf("%.9f\n",S);
	return 0;
}
