#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e6+10;
const int mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const int iinf=0x3f3f3f3f;
int l,r;
ll t;
bool notp[maxn];
int prime[maxn];
int cntp;
int minp[maxn];
int main(){
    scanf("%I64d%d%d",&t,&l,&r);
    memset(f,0x3f,sizeof f);
    f[1]=0;
    f[2]=1;
    memset(notp,0,sizeof notp);
    memset(minp,0x3f,sizeof minp);
    cntp=0;
    for(int i=2;i<=r;i++){
        if(!notp[i]){
            prime[cntp++]=i;
            minp[i]=i;
        }
        for(int j=0;j<cntp&&prime[j]*i<=r;j++){
            notp[prime[j]*i]=true;
            minp[prime[j]*i]=min(minp[prime[j]*i],prime[j]);
        }
    }
    ll res=0;
    ll tpow=1;
    for(int i=0;i<=r-l;i++){
        ll f=minp[l+i]
        res=(res+tpow*%mod)%mod;
        tpow=tpow*t%mod;
    }
    printf("%I64d\n",res);
}
