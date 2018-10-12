#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
const int inf=0x3f3f3f3f;
int n,k,p;
int a[maxn];
int b[maxn];
bool comp(int x,int y){
    return abs(x-p)<abs(y-p);
}
int g[maxn][maxn];
int pre[maxn];
bool vis[maxn];
int up;
bool dfs(int i){
    //找未匹配边
    for(int j=0;j<n;j++){
        if(g[i][j]>up) continue;
        if(vis[j]) continue;    //跳过访问过的空位
        vis[j]=1;
        if(!pre[j]){    //未盖点
            pre[j]=i;       //当前边变成匹配边
            return true;
        }
        else{           //已盖点
            if(dfs(pre[j])){
                pre[j]=i;
                return true;
            }
        }
    }
    return false;
}
int hungry(){
    int _max=0;
    memset(pre,0,sizeof pre);
    for(int i=0;i<n;i++){  //枚举
        memset(vis,0,sizeof vis);
        if(dfs(i))
            _max++;
    }
    return _max;
}
int main(){
    scanf("%d%d%d",&n,&k,&p);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<k;i++)
        scanf("%d",b+i);
    sort(b,b+k,comp);
    int l=0,r=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=abs(a[i]-b[j])+abs(b[j]-p);
            r=max(g[i][j],r);
        }
    }
    while(l<r){
        int mid=(l+r)/2;
        up=mid;
        if(hungry()==n)
            r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}
