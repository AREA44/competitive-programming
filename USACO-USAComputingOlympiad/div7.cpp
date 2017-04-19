#include <bits/stdc++.h>
using namespace std;

int N,id[50004];
int mod[7][50004],answer;

int main(){
	freopen("div7.in","r",stdin);
	freopen("div7.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&id[i]);
		id[i]=(id[i]%7+id[i-1])%7;
		mod[id[i]][++mod[id[i]][0]]=i;
	}
	for(int i=0;i<=6;++i){
		if(mod[i][0]>1)
			answer=max(answer,mod[i][mod[i][0]]-mod[i][1]);
	}
	if(answer==0) printf("-1\n");
	else printf("%d\n",answer);
	return 0;
}
