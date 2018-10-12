#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
int l,r;
int cnt[maxn];
int dp1[maxn];
int dp2[maxn];
int last[maxn];
int next[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&l,&r);
        cnt[l]++;
        cnt[r+1]--;
    }
    for(int i=1;i<=m;i++){
        cnt[i]+=cnt[i-1];
    }
    memset(last,0,sizeof last);
    memset(next,0,sizeof next);
    for(int i=1;i<=m;i++){
        last[cnt[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(last[i]==0) last[i]=last[i-1];
    }
    for(int i=m;i>=1;i--){
        next[cnt[i]]=i;
    }
    for(int i=n;i>=1;i--){
        if(next[i]==0) next[i]=next[i-1];
    }
    dp1[0]=0;
    for(int i=1;i<=m;i++){
        dp[i]=dp[last[i]]+1;
    }
    dp2[0]=0;
    for(int i=m;i>=1;i--){
        dp[]
    }
}
