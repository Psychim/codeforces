#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxx=1e9+10;
const ll mod=1e9+7;
ll x;
ll y;
ll res;
map<ll,ll> f;
vector<ll> factor;
map<ll,ll> mu;
vector<bool> isprime;
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
        for(ll i=1;i*i<=d;i++){
            if(d%i==0){
                factor.push_back(i);
                if(d/i!=i)
                    factor.push_back(d/i);
            }
        }
        sort(factor.begin(),factor.end());
        for(int i=0;i<factor.size();i++){
            isprime.push_back(true);
            mu[factor[i]]=1;
        }
        isprime[0]=false;
        for(int i=1;i<factor.size();i++){
            ll z=factor[i];
            if(isprime[i]){
                mu[z]=-1;
                for(int j=i+1;j<factor.size();j++){
                    if(factor[j]%z==0){
                        isprime[j]=false;
                        if(factor[j]/z%z){
                            mu[factor[j]]*=-1;
                        }
                        else mu[factor[j]]=0;
                    }
                }
            }
        }
        for(int i=0;i<factor.size();i++){
            res=(res+mu[d/factor[i]]*fp(2,factor[i]-1)+mod)%mod;
        }
    }
    printf("%I64d\n",res);
}
