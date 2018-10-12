#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxq=1e5+10;
const int maxx=1e6+1;
const int maxy=maxx+20;
int q;
int x;
int y;
bool isp[maxx];
vector<int> p;
int fact[maxx];
ll c[maxy][20];
ll inv[20];
ll tmp;
ll cnt;
ll res;
ll extgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll fastpow(ll a,ll b){
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
int main(){
    scanf("%d",&q);
    memset(isp,1,sizeof isp);
    for(int i=2;i<maxx;i++){
        if(isp[i]){
            p.push_back(i);
            fact[i]=i;
        }
        for(int j=0;j<p.size()&&p[j]*1LL*i<=maxx*1ll;j++){
            isp[p[j]*i]=0;
            if(!fact[p[j]*i]) fact[p[j]*i]=p[j];
        }
    }
    for(int i=1;i<20;i++){
        extgcd(i,mod,inv[i],tmp);
        while(inv[i]<0) inv[i]+=mod;
    }
    for(int i=1;i<maxy;i++){
        c[i][0]=1;
        for(int j=1;j<20;j++){
            c[i][j]=c[i][j-1]*(i-j+1)%mod*inv[j]%mod;
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        res=1;
        while(fact[x]){
            tmp=fact[x];
            cnt=0;
            while(x%tmp==0){
                cnt++;
                x/=tmp;
            }
            res=(res*c[y+cnt-1][cnt])%mod;
        }
        res=res*fastpow(2,y-1)%mod;
        printf("%I64d\n",res);
    }
}
