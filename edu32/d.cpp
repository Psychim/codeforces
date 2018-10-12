#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int k;
int n;
ll res;
ll a(ll a,ll b){
    ll res=1;
    for(ll i=0;i<b;i++){
        res*=a-i;
    }
    return res;
}
ll c(ll a,ll b){
    if(b==0) return 1;
    ll up=1,down=1;
    for(ll i=1;i<=b;i++){
        up*=(a-i+1);
        down*=i;
    }
    return up/down;
}
ll crossper(ll n){
    ll res=0;
    for(int i=n;i>=0;i-=2){
        res+=c(n,i)*a(i,i);
    }
    for(int i=n-1;i>=0;i-=2){
        res-=c(n,i)*a(i,i);
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&k);
    res=1;
    ll up=n;
    ll down=1;
    for(int i=2;i<=k;i++){
        up*=n-i+1;
        down*=i;
        res+=up/down*crossper(i);
    }
    printf("%I64d",res);
}
