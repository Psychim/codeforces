#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxm=1e5+10;
typedef long long ll;
int n;
int m;
ll c[maxn];
int x,y;
int father[maxn];
int mc[maxn];
bool vis[maxn];
int findset(int u){
    if(father[u]!=u)
        return father[u]=findset(father[u]);
    return u;
}
int unionset(int u,int v){
    u=findset(u);
    v=findset(v);
    father[u]=v;
    return v;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%I64d",c+i);
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        unionset(x,y);
    }
    memset(mc,0x3f,sizeof mc);
    for(int i=1;i<=n;i++){
        int u=findset(i);
        if(c[i]<=mc[u]){
            vis[u]=1;
            mc[u]=c[i];
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        if(vis[i])
            res+=mc[i];
    }
    printf("%I64d",res);
}
