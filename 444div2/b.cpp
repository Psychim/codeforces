#include<bits/stdc++.h>
using namespace std;
const int maxn=3;
int n;
bool cube[maxn][10];
bool vis[maxn];
bool make(int x){
    if(!x) return true;
    int y;
    y=x%10;
    bool ok=false;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        if(cube[i][y]){
            ok|=make(x/10);
        }
        vis[i]=false;
    }
    return ok;
}
int main(){
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            scanf("%d",&x);
            cube[i][x]=true;
        }
    }
    int res;
    for(res=0;;res++){
        if(!make(res+1))
            break;
    }
    printf("%d",res);
}
