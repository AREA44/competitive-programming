// Russian Code Cup WarmUp Round 2016
// "A" Secret Code
// http://www.russiancodecup.ru/en/championship/round/52/problem/A/

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "string"
#include "math.h"
using namespace std;

string s[1000004];
int n,a,b,cnts[46],_cnt[46];

int main(){
  cin>>s[0]>>n;
  for(int j=0;j<s[0].size();j++){
    if('0'<=s[0][j] && s[0][j]<='9') cnts[s[0][j]-'0']++;
    if('A'<=s[0][j] && s[0][j]<='Z') cnts[s[0][j]-'A'+10]++;
  }
  for(int i=1;i<=n;i++){
    cin>>s[i];a=0,b=0;
    for(int j=0;j<36;j++) _cnt[j]=cnts[j];
    for(int j=0;j<s[0].size();j++){
      if(s[i][j]==s[0][j]){
        if('0'<=s[i][j] && s[i][j]<='9') _cnt[s[i][j]-'0']--;
        if('A'<=s[i][j] && s[i][j]<='Z') _cnt[s[i][j]-'A'+10]--;
        a++;
      }
    }
    for(int j=0;j<s[0].size();j++){
      if(s[i][j]!=s[0][j]){
        if('0'<=s[i][j] && s[i][j]<='9' && _cnt[s[i][j]-'0']>0){
          _cnt[s[i][j]-'0']--;
          b++;
        }
        if('A'<=s[i][j] && s[i][j]<='Z' && _cnt[s[i][j]-'A'+10]>0){
          _cnt[s[i][j]-'A'+10]--;
          b++;
        }
      }
    }
    cout<<a<<" "<<b<<endl;
  }
  return 0;
}
