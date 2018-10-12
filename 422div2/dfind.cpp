#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e6+10;
const ll mod=1e9+7;

ll f[maxn];
int n;
int main(){
    scanf("%d",&n);
    f[0]=0;
    f[1]=0;
    f[2]=1;
    printf("1:0 2:1 ");
    for(int i=3;i<n;i++){
        f[i]=i*1LL*(i-1)/2%mod;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j) continue;
            f[i]=min(f[i],(f[i/j]+i*1LL*(j-1)/2%mod)%mod);
        }
        printf("%d:%I64d ",i,f[i]);
    }
}
