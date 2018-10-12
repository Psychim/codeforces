#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m;
char c[maxn];
vector<int> head;
vector<int> g[maxn];
int indeg[maxn];
queue<int> q;
int topo[maxn];
int tn;
int cnts[maxn][26];
void calindeg(){
    memset(indeg,0,sizeof indeg);
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            indeg[g[i][j]]++;
        }
    }
}
int main(){
    scanf("%d %d\n",&n,&m);
    scanf("%s",c+1);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    calindeg();
    for(int i=1;i<=n;i++){
        if(!indeg[i]){
            head.push_back(i);
            q.push(i);
        }
    }
    for(tn=0;q.size();tn++){
        int u=q.front();
        q.pop();
        topo[tn]=u;
        for(int j=0;j<g[u].size();j++){
            if(!--indeg[g[u][j]])
                q.push(g[u][j]);
        }
    }
    if(tn<n){
        puts("-1");
        return 0;
    }
    memset(cnts,0,sizeof cnts);
    for(int i=tn-1;i>=0;i--){
        int u=topo[i];
        if(!g[u].size()){
            cnts[u][c[u]-'a']=1;
        }
        else{
            for(int j=0;j<g[u].size();j++){
                int v=g[u][j];
                for(int k=0;k<26;k++){
                    cnts[u][k]=max(cnts[u][k],cnts[v][k]);
                }
            }
            cnts[u][c[u]-'a']++;
        }
    }
    int best=0;
    for(int i=0;i<head.size();i++){
        int u=head[i];
        for(int k=0;k<26;k++){
            best=max(cnts[u][k],best);
        }
    }
    printf("%d",best);
}
