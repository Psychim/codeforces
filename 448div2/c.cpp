#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll mod=1e9+7;
int a[maxn];
int bin[71];
int cnt[71];
int n;
ll dp[2][1<<19];
int p[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
ll fp[maxn];
int main(){
    scanf("%d",&n);
    //n=100000;
    for(int i=1;i<=70;i++){
        for(int j=0;j<19;j++){
            int cnt=0,tmp=i;
            while(tmp%p[j]==0){
                tmp/=p[j];
                cnt^=1;
            }
            bin[i]+=cnt<<j;
        }
    }
    fp[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        //a[i]=i%70+1;
        cnt[a[i]]++;
        fp[i]=fp[i-1]*2%mod;
    }
    dp[0][0]=1;
    for(int i=1;i<=70;i++){
        memset(dp[i&1],0,sizeof dp[i&1]);
        if(cnt[i]){
            for(int j=0;j<(1<<19);j++){
                dp[i&1][j]+=dp[i&1^1][j^bin[i]]*(fp[cnt[i]-1]%mod)%mod;
                dp[i&1][j]%=mod;
                dp[i&1][j]+=dp[i&1^1][j]*(fp[cnt[i]-1]%mod)%mod;
                dp[i&1][j]%=mod;
            }
        }
        else{
            for(int j=0;j<(1<<19);j++){
                dp[i&1][j]=dp[i&1^1][j];
            }
        }
    }
    printf("%I64d",(dp[70&1][0]-1+mod)%mod);
}
