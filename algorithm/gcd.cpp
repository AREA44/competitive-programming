#include "iostream"
#include "stdio.h"
using namespace std;

long long gcd(long long a,long long b){
    if(a==0) return b;
    else return gcd(b%a,a);
}

long long a,b;

int main() {
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
