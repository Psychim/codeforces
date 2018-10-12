#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int n;
vector<int> g[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
