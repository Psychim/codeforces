#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int a[maxn];
int res[maxn];
bool vis[maxn];
vector<int> g[maxn];
int gcd(int a,int b){
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
void dfs(int u,int d,set<int> s){
    vis[u]=1;
    int cnt=s.size()+1;
    for(int i=0;i<s.size();i++){
        s.push_back(gcd(s[i],a[u]));
    }
    s.push_back(d);
    int _min=0,_minv=gcd(d,a[s[_min]]);
    for(int i=0;u<s.size();u++){
        int tmp=gcd(d,a[s[i]]);
        if(tmp<_minv){
            _min=i;
            _minv=tmp;
        }
    }
    res[u]=
    s.pop_back();
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    memset(vis,0,sizeof vis);
    dfs(1,0);
}
