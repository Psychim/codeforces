#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
vector<int> g[maxn];
int n,q;
//树链剖分
int dep[maxn];  //深度
int son[maxn];  //重儿子
int top[maxn];  //重链顶部结点
int sz[maxn];   //子树大小
int father[maxn];
int w[maxn];    //MST映射成的一维数组中，每个结点的下标
int nw;
int seq[maxn];   //MST映射成的一维数组
bool vis[maxn];
//dfs1求sz,dep,efather,echild,son
void dfs1(int u){
    vis[u]=true;
    sz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]) continue;
        dep[v]=dep[u]+1;
        father[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])
            son[u]=v;
    }
}
void dfs1(){
    memset(son,0,sizeof son);
    memset(vis,0,sizeof vis);
    dep[1]=1;
    father[1]=0;
    sz[0]=0;
    dfs1(1);
}
//dfs2求w，seq，top
void dfs2(int u){
    if(son[u]){
        w[son[u]]=nw;
        seq[nw++]=son[u];
        top[son[u]]=top[u];
        dfs2(son[u]);
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(father[u]==v||v==son[u]) continue;
        w[v]=nw;
        seq[nw++]=v;
        top[v]=v;
        dfs2(v);
    }
}
void dfs2(){
    nw=1;
    top[1]=1;
    w[1]=0;
    seq[0]=1;
    dfs2(1);
}
int v[(1<<18)-2];
int setv[(1<<18)-2];
void pushdown(int l,int r,int i){
    if(setv[i]!=-1){
        int mid=(l+r)/2;
        int li=2*i+1,ri=2*i+2;
        setv[li]=setv[ri]=setv[i];
        v[li]=setv[i]*(mid-l+1);
        v[ri]=setv[i]*(r-mid);
        setv[i]=-1;
    }
}
void stset(int l,int r,int i,int a,int b,int key){
    if(a<=l&&b>=r){
        v[i]=key*(r-l+1);
        setv[i]=key;
//        printf("set(%d,%d)=%d\n",l,r,v[i]);
        return;
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    pushdown(l,r,i);
    if(a<=mid)
        stset(l,mid,li,a,b,key);
    if(b>mid)
        stset(mid+1,r,ri,a,b,key);
    v[i]=v[li]+v[ri];
//    printf("set(%d,%d)=%d\n",l,r,v[i]);
}
int stquery(int l,int r,int i,int a,int b){
    if(a<=l&&b>=r)
        return v[i];
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    int res=0;
    pushdown(l,r,i);
    if(a<=mid)
        res+=stquery(l,mid,li,a,b);
    if(b>mid)
        res+=stquery(mid+1,r,ri,a,b);
    return res;
}
void setkey(int u,int v,int key){
//    printf("setkey:%d %d\n",u,v);
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            stset(0,nw-1,0,w[top[u]],w[u],key);
//            printf("set:%d %d\n",top[u],u);
            u=father[top[u]];
        }
        else{
            stset(0,nw-1,0,w[top[v]],w[v],key);
//            printf("set:%d %d\n",top[v],v);
            v=father[top[v]];
        }
    }
    if(dep[u]<dep[v]){
        stset(0,nw-1,0,w[u],w[v],key);
//        printf("set:%d %d\n",u,v);
    }
    else{
        stset(0,nw-1,0,w[v],w[u],key);
//        printf("set:%d %d\n",v,u);
    }
}
int query(int u,int v){
//    printf("query(%d,%d)\n",u,v);
    int res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            res+=stquery(0,nw-1,0,w[top[u]],w[u]);
//            printf("query:%d %d %d\n",top[u],u,res);
            u=father[top[u]];
        }
        else{
            res+=stquery(0,nw-1,0,w[top[v]],w[v]);
//            printf("query:%d %d %d\n",top[v],v,res);
            v=father[top[v]];
        }
    }
    if(dep[u]<dep[v])
        res+=stquery(0,nw-1,0,w[u],w[v])
//        ,printf("query:%d %d %d\n",v,u,res)
        ;
    else res+=stquery(0,nw-1,0,w[v],w[u])
//        ,printf("query:%d %d %d\n",v,u,res)
        ;
    return res;
}

int main(){
    scanf("%d%d",&n,&q);
    int p;
    for(int i=2;i<=n;i++){
        scanf("%d",&p);
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs1();
    dfs2();
//    for(int i=0;i<nw;i++)
//        printf("%d ",seq[i]);
//    puts("");
    int res=0;
    while(q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        stset(0,nw-1,0,0,nw-1,0);
        setkey(a,b,1);
        res=query(c,b);
        res=max(query(c,a),res);
        stset(0,nw-1,0,0,nw-1,0);
        setkey(a,c,1);
        res=max(res,query(b,a));
        res=max(res,query(b,c));
        stset(0,nw-1,0,0,nw-1,0);
        setkey(b,c,1);
        res=max(res,query(a,b));
        res=max(res,query(a,c));
        printf("%d\n",res);
    }
}
