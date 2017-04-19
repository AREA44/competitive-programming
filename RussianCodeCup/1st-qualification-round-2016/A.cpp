#include "bits/stdc++.h"
using namespace std;

int t,n,a,b,c,d;

int main(){
  cin>>t;
  for(int _case=1;_case<=t;_case++){
    cin>>a>>b>>c>>d;
    if(a!=0 && b==0 && c==0 && d!=0) cout<<"impossible"<<endl;
    else if(abs(b-c)>=2) cout<<"impossible"<<endl;
    else{
      string mid,pre,back;
      if((b-c)==1){
        for(int i=1;i<=b;i++) mid+="01";
        for(int i=1;i<=a;i++) pre+="0";
        for(int i=1;i<=d;i++) back+="1";
      }
      else if((c-b)==1) {
        for(int i=1;i<=c;i++) mid+="10";
        for(int i=1;i<=a;i++) back+="0";
        for(int i=1;i<=d;i++) pre+="1";
      }
      else{
        if(b!=0){
          for(int i=1;i<=a;i++) mid+="0";
          for(int i=1;i<=b;i++) pre+="10";
          back="1";for(int i=1;i<=d;i++) back+="1";
        }
        else{
          if(d==0){
            mid="0";for(int i=1;i<=a;i++) pre+="0";
          }
          else {
            mid="1";for(int i=1;i<=d;i++) back+="1";
          }
        }
      }
      cout<<pre+mid+back<<endl;
    }
  }
  return 0;
}
