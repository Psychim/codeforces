#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
int n;
int r;
int a[maxn];
int seq[maxn];
int low[maxn],high[maxn];
vector<int> t[maxn];
int m;
int p;
int q;
int res;
int minv[maxn*4];
int mind[maxn*4];
int maxd[maxn*4];
int d[maxn];
int seqn;
void dfs(int u,int p){
    seq[++seqn]=u;
    d[u]=d[p]+1;
    low[u]=seqn;
    for(int i=0;i<t[u].size();i++){
        if(t[u][i]==p)continue;
        dfs(t[u][i],u);
    }
    high[u]=seqn;
}
void build(int i,int l,int r){
    if(l==r){
        minv[i]=a[seq[l]];
        mind[i]=maxd[i]=d[seq[l]];
        return;
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    build(li,l,mid);
    build(ri,mid+1,r);
    minv[i]=min(minv[li],minv[ri]);
    mind[i]=min(mind[li],mind[ri]);
    maxd[i]=max(maxd[li],maxd[ri]);
}
int query(int i,int l,int r,int a,int b,int bound){
    if(mind[i]>bound||l>r) return inf;
    if(a>r||b<l) return inf;
    if(a<=l&&b>=r&&maxd[i]<=bound){
        return minv[i];
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    return min(query(li,l,mid,a,b,bound),query(ri,mid+1,r,a,b,bound));
}
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        t[x].push_back(y);
        t[y].push_back(x);
    }
    seqn=0;
    dfs(r,0);
    build(0,1,n);
    scanf("%d",&m);
    res=0;
    while(m--){
        scanf("%d%d",&p,&q);
        p=(p+res)%n+1;
        q=(q+res)%n;
        res=0;
        printf("%d\n",res=query(0,1,n,low[p],high[p],d[p]+q));
    }
}
