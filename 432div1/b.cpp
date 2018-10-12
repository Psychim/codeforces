#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int maxa=1e6+1;
ll x,y;
int n,a[maxn];
ll cost[maxa];
bool isprime[maxa];
int _max=0;
vector<int> prime;
int main(){
    scanf("%d%I64d%I64d",&n,&x,&y);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        _max=max(a[i],_max);
    }
    sort(a,a+n);
    ll res=n*y,cur;
    memset(isprime,1,sizeof isprime);
    for(int i=2;i<maxa;i++){
        if(isprime[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<maxa;j++){
            isprime[i*prime[j]]=false;
        }
    }
    //printf("%d\n",prime.size());
    memset(cost,0,sizeof cost);
    for(int u=0;u<prime.size();u++){
        int i=prime[u];
        for(int d=1;d<=x/y&&d<i;d++){

        }
        //printf("%d %I64d\n",prime[u],cost[prime[u]]);
        res=min(res,cost[prime[u]]);
    }
    printf("%I64d\n",res);
}
