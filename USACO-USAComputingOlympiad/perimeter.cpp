/*USACO 2013 February Contest, Silver
 *Problem 1. Perimeter*/
 
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
#include "set"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;
const int MaxN = 5e4;
const int base = 1e9+7;

int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

int N;
set<ii> object,visited;
int perimeter;

bool isOlated(int x,int y){
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if(object.count(ii(x+i,y+j))) return false;//object(ii(x+i,y+j))==false
    return true;
}

void floodfill(int x,int y){
    if(object.count(ii(x,y))){perimeter++;return;}
    if(visited.count(ii(x,y))) return;
    else visited.insert(ii(x,y));
    if (isOlated(x,y)) return;
    for(int d=0;d<4;d++) floodfill(x+dr[d],y+dc[d]);
}

int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        ii pos;
        cin>>pos.first>>pos.second;
        object.insert(pos);
    }
    ii start = *object.begin(); 
    int x = start.first-1,y = start.second;
    floodfill(x,y);
    cout<<perimeter<<endl;
    return 0;
}
