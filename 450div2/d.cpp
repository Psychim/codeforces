#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxx=1e9+10;
const ll mod=1e9+7;
ll x;
ll y;
ll res;
map<ll,ll> f;

ll fp(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void calf(ll d){
    if(f.count(d))
        return;
    ll res=(fp(2,d-1)+mod-f[1])%mod;
    for(ll i=2;i*i<=d;i++){
        if(d%i==0){
            calf(d/i);
            res=(res+mod-f[d/i])%mod;
            if(d/i!=i){
                calf(i);
                res=(res+mod-f[i])%mod;
            }
        }
    }
    f[d]=res;
}
int main(){
    scanf("%I64d%I64d",&x,&y);
    res=0;
    if(y%x==0){
        ll d=y/x;
        f[1]=1;
        calf(d);
        res=f[d];
    }
    printf("%I64d\n",res);
}
