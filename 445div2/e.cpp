#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e6+10;
int n;
int k;
ll res;
ll dp[maxn];
ll h[maxn];
ll  a[maxn];
ll suma[maxn];
int main(){
    scanf("%d%d",&n,&k);
    a[1]=1;
    for(int i=2;i<=n-k;i++){
        a[i]=i*a[i-1]%mod;
    }

}
