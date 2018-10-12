#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod =1e9+7;
const int maxn=510;
bool g[maxn][maxn];
int n;
ll dp[maxn][maxn][2];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=0;i<=n;i++){
        g[i][n]=g[i][0];
        g[n][i]=g[0][i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            if(i==1) dp[j][j+i][1]=dp[j][j+i][0]=1;
            else{
                for(int k=j+1;k<j+i;k++){
                    if(g[j][k]){
                        dp[j][j+i][1]+=dp[j][k][1]*dp[k][j+i][1];
                        dp[j][j+i][1]%=mod;
                    }
                    if(g[k][j+i]){
                        dp[j][j+i][0]+=dp[j][k][0]*dp[k][j+i][1];
                        dp[j][j+i][1]+=dp[j][k][0]*dp[k][j+i][1];
                        dp[j][j+i][0]%=mod;
                        dp[j][j+i][1]%=mod;
                    }
                }
            }
           // printf("dp[%d][%d]=%I64d\n",j,j+i,dp[j][j+i][1]);
        }
    }
    printf("%I64d",dp[0][n][0]);
}
