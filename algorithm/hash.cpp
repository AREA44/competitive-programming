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

const long long base = 1e8 + 3;

string a,b;
long long Pow[1000004],HashA[1000004],HashB[1000004];
int la,lb;

long long Get_Hash(long long hash[],int i)
{return(hash[i+lb-1]-hash[i-1]*Pow[lb]+base*base)%base;}

void Hash(){
    Pow[0]=1;
    for(int i=1;i<=lb;i++){
        HashB[i]=(HashB[i-1]*26 + b[i]-'a')%base;
        Pow[i]=(Pow[i-1]*26)%base;
    }
    for(int i=1;i<=la;i++) HashA[i]=(HashA[i-1]*26+a[i]-'a')%base;
    for (int i=1;i<=la-lb+1;i++)
        if(HashB[lb]==Get_Hash(HashA,i))
            printf("%d ",i);
}

int main(){
    cin>>a>>b;
    la=a.length();a=" "+a;
    lb=b.length();b=" "+b;
    Hash();
    return 0;
}
