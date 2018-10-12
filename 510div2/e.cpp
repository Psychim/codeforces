#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll mod=998244353;
int m,n;
ll g[maxn][maxn];
ll gcd(ll a,ll p,ll mod){
    ll res=1;
    while(p){
        if(p&1)
            res=res*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdfio(false);
    cin>>n>>m;

}
