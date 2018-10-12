#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=2e5+10;
int n,m;
vector<int> g[maxn];
int c;
int s;
vector<int> stk;
void dfs(int u){

}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&c);
        for(int j=0;j<c;j++){
            int x;
            scanf("%d",&x);
            g[i].push_back(x);
        }
    }
    cin>>s;
    dfs(s);
}
