#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int n;
int a[maxn];
int dp[maxn][maxn][3][3];
int main(){
    cin>>n;
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        dp[i][i][a[i]][a[i]]=1;
        for(int j=i+1;j<=n;j++){
            if(a[j]==1){
                dp[i][j][1][1]=dp[i][j-1][1][1]+1;
                dp[i][j][2][1]=max(dp[i][j-1][2][1]+1,dp[i][j-1][2][2]+1);
                dp[i][j][1][2]=dp[i][j-1][1][2];
                dp[i][j][2][2]=dp[i][j-1][2][2];
            }
            else{
                dp[i][j][1][1]=dp[i][j-1][1][1];
                dp[i][j][2][1]=dp[i][j-1][2][1];
                dp[i][j][1][2]=max(dp[i][j-1][1][1]+1,dp[i][j-1][1][2]+1);
                dp[i][j][2][2]=dp[i][j-1][2][2]+1;
            }
        }
    }
    int best=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            best=max(best,dp[1][l-1][1][1]+dp[l][r][1][1]+dp[r+1][n][1][1]);
            best=max(best,dp[1][l-1][1][1]+dp[l][r][1][1]+dp[r+1][n][1][2]);
            best=max(best,dp[1][l-1][1][1]+dp[l][r][1][1]+dp[r+1][n][2][2]);
            best=max(best,dp[1][l-1][1][1]+dp[l][r][2][1]+dp[r+1][n][2][2]);
            best=max(best,dp[1][l-1][1][1]+dp[l][r][2][2]+dp[r+1][n][2][2]);
            best=max(best,dp[1][l-1][1][2]+dp[l][r][2][2]+dp[r+1][n][2][2]);
            best=max(best,dp[1][l-1][2][2]+dp[l][r][2][2]+dp[r+1][n][2][2]);
        }
    }
    cout<<best;
}
