#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,p,x;
ll fp(ll a,ll n,ll p){
    ll res=1;
    while(n){
        if(n&1)
            res=res*a%p;
        a=a*a%p;
        n>>=1;
    }
    return res;
}
ll cnt;
int main(){
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&x);
    ll bigmod=p*(p-1);
    ll tmp=(p-1)*fp(p-1,p-2,p)%bigmod;
    for(ll i=0;i<p-1;i++){
        ll ai=fp(a,i,p);
        ll j=fp(ai,p-2,p)*b%p;
        ll n=(i*p%bigmod+j*tmp%bigmod)%bigmod;
        if(n%p*fp(a,n%(p-1),p)%p==b){
            cnt+=x/bigmod;
            if(n<=x%bigmod)
                cnt++;
        }
    }
    printf("%I64d",cnt);
}
