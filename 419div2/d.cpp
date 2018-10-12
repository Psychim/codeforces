#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=200010;
const ll mod=1e9+7;
ll a[maxn];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
    }
    int ope=1;
    while(n>1){
        for(int i=0;i<n-1;i++){
            if(ope)
                a[i]=(a[i]+a[i+1])%mod;
            else a[i]=(a[i]-a[i+1]+mod)%mod;
            ope=1-ope;
        }
        n--;
    }
    printf("%I64d\n",a[0]);
}
