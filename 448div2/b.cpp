#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll x;
int n;
ll k;
struct Node{
    ll a;
    int i;
    bool operator<(Node p){
        if(a!=p.a)return a<p.a;
        return i<p.i;
    }
};
Node p[maxn];
ll cntr[maxn],cntl[maxn];
ll res;
int main(){
    scanf("%d%I64d%I64d",&n,&x,&k);
    for(int i=0;i<n;i++){
        scanf("%I64d",&p[i].a);
        p[i].i=i;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        cntr[i]=p[i].a/x;
        cntl[i]=(p[i].a-1)/x;
    }
    int rl=0,rr=0;
    res=0;
    for(int l=0;l<n;l++){
        while(rl<n&&p[rl].a<p[l].a) rl++;
        while(rr<n&&p[rr].a<p[l].a) rr++;
        while(rl<n&&cntr[rl]-cntl[l]<k){
            rl++;
        }
        //printf("%d %d\n",rr,rl);
        if(cntr[rl]-cntl[l]!=k) continue;
        while(rr+1<n&&cntr[rr+1]-cntl[l]<=k){
            rr++;
        }
        if(cntr[rr]-cntl[l]!=k) continue;
        res+=(rr-rl+1);
    }
    printf("%I64d",res);
}
