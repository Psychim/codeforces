#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int maxb=1e9+10;
const int inf=0x3f3f3f3f;
int n,b;
struct Node{
    int index,cost;
    Node(int pi=0,int pc=0){
        index=pi;cost=pc;
    }
    bool operator<(Node a){
        return cost<a.cost;
    }
};
Node p[maxn];
int d[maxn];
int x[maxn];
int s[maxn];
vector<int> child[maxn];
using namespace std;
int dp[maxn][maxn][maxn];
bool vis[maxn];
void dfs(int u){
    dp[u][0][0]=0;
    dp[u][0][1]=d[u];
    s[u]=1;
    for(int i=0;i<child[u].size();i++){
        int v=child[u][i];
        dfs(v);
        s[u]+=s[v];
    }
    for(int i=0;i<child[u].size();i++){
        int v=child[u][i];
        for(int j=0;j<s[v];j++){

        }
    }
}
void dfs2(int u,int siz){
    if(siz<1) return;
    vis[u]=1;
    //printf("%d ",u);
    while(siz>1){
        int j=pre[u][siz];
        int v=con[u][siz];
        dfs2(v,siz-j);
        siz=j;
    }
}
int main(){
    scanf("%d%d",&n,&b);
    scanf("%d%d",&p[0].cost,d+1);
    p[0].index=1;
    for(int i=2;i<=n;i++){
        scanf("%d%d%d",&p[i-1].cost,d+i,x+i);
        p[i-1].index=i;
        child[x[i]].push_back(i);
    }
    memset(dp,0x3f,sizeof dp);
    memset(pre,0,sizeof pre);
    memset(con,0,sizeof con);
    dfs(1);
    sort(p,p+n);
    int res=0;
    for(int i=0;i<n;i++){
        if(dp[1][i]>b) break;
        int tmp=i;
        memset(vis,0,sizeof vis);
        dfs2(1,i);
        int remain=b-dp[1][i];
        for(int j=0;j<n&&p[j].cost<=remain;j++){
            if(!vis[p[j].index]){
                remain-=p[j].cost;
                tmp++;
                //printf("%d ",p[j].index);
            }
        }
        //puts("");
        res=max(res,tmp);
    }
    printf("%d\n",res);
}
