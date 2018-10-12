#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int q;
int pa[maxn];
vector<int> tree[maxn];
int w;
int seq[maxn];
int lft[maxn],rght[maxn];
int on[maxn*8];
int off[maxn*8];
int flag[maxn*8];
bool light[maxn];
char buf[4];
int com;
void dfs(int u){
    lft[u]=w;
    seq[w++]=u;
    for(int i=0;i<tree[u].size();i++){
        dfs(tree[u][i]);
    }
    rght[u]=w-1;
}
void build(int i,int l,int r){
    flag[i]=0;
    if(l==r){
        if(light[seq[l]]){
            on[i]=1;
        }
        else{
            on[i]=0;
        }
        off[i]=1-on[i];
        return;
    }
    int mid=(l+r)/2;
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    on[i]=on[2*i+1]+on[2*i+2];
    off[i]=off[2*i+1]+off[2*i+2];
}
void pushdown(int i){
    int li=2*i+1,ri=2*i+2;
    if(flag[i]%2){
        swap(on[li],off[li]);
        swap(on[ri],off[ri]);
        flag[li]++;
        flag[ri]++;
    }
    flag[i]=0;
}
void reset(int i,int l,int r,int a,int b){
    if(a<=l&&b>=r){
        flag[i]++;
        swap(on[i],off[i]);
        return;
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    pushdown(i);
    if(a<=mid)
        reset(li,l,mid,a,b);
    if(b>mid)
        reset(ri,mid+1,r,a,b);
    on[i]=on[li]+on[ri];
    off[i]=off[li]+off[ri];
}
int query(int i,int l,int r,int a,int b){
    if(a<=l&&b>=r){
        return on[i];
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    pushdown(i);
    int res=0;
    if(a<=mid)
        res+=query(li,l,mid,a,b);
    if(b>mid)
        res+=query(ri,mid+1,r,a,b);
    return res;
}
int main(){
    scanf("%d",&n);
    pa[1]=0;
    for(int i=2;i<=n;i++){
        int p;
        scanf("%d",&p);
        tree[p].push_back(i);
        pa[i]=p;
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        light[i]=x;
    }
    w=0;
    dfs(1);
    build(0,0,n-1);
    scanf("%d",&q);
    while(q--){
        scanf("%s %d",buf,&com);
        if(strcmp(buf,"pow")==0){
            reset(0,0,n-1,lft[com],rght[com]);
        }
        else{
            printf("%d\n",query(0,0,n-1,lft[com],rght[com]));
        }
    }
}
