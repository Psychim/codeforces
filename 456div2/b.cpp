#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
    scanf("%I64d%I64d",&n,&k);
    ll i=1;
    while(i*2<=n)
        i<<=1;
    ll res=0;
    if(k==1){
        res=n;
    }
    else{
        res=i*2-1;
    }
    printf("%I64d",res);
}
