#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
int n,m,q;
set<int> g[maxn];
map<int,vector<int> > res[maxn];
bool vis[maxn];
vector<int> path;
int ring;
bool dfs(int s,int u){
    //printf("dfs(%d)\n",u);
    vis[u]=true;
    path.push_back(u);
    if(!res[s].count(u))
        res[s][u]=path;
    for(set<int>::iterator ite=g[u].begin();ite!=g[u].end();ite++){
        int v=*ite;
        //printf("(%d,%d)\n",u,v);
        if(vis[v]){
            ring=v;
            path.pop_back();
            return false;
        }
        if(!dfs(s,v)&&ring){
            if(ring!=u){
                path.pop_back();
                return false;
            }
            else{
                ring=0;
                path.pop_back();
                return true;
            }
        }
    }
    path.pop_back();
    return true;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].insert(y);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        path.clear();
        ring=0;
        dfs(i,i);
    }
    while(q--){
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        if(!res[s].count(t)){
            puts("-1");
        }
        else{
            vector<int> path=res[s][t];
            int len=path.size();
            int node;
            if(k>len){
                node=-1;
            }
            else{
                node=path[k-1];
            }
            printf("%d\n",node);
        }
    }
}
