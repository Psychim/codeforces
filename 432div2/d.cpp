#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int maxa=1e6+1;
ll x,y;
int n,a[maxn];
ll cnt[2*maxa];
ll sum[2*maxa];
int main(){
    scanf("%d%I64d%I64d",&n,&x,&y);
    memset(cnt,0,sizeof cnt);
    memset(sum,0,sizeof sum);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        cnt[a[i]]++;
        sum[a[i]]+=a[i];
    }
    for(int i=1;i<2*maxa;i++){
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];
    }
    ll res=n*y,cur;
    for(int i=2;i<maxa;i++){
        int dis=(int)min((i-1)*1LL,x/y);
        cur=0;
        for(int j=i;cur<res&&j<2*maxa;j+=i){
            cur+=(cnt[j-dis-1]-cnt[j-i])*x;
            cur+=((cnt[j]-cnt[j-dis-1])*j-(sum[j]-sum[j-dis-1]))*y;
        }
        res=min(res,cur);
    }
    printf("%I64d\n",res);
}
