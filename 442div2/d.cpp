#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f;
int n,m,k;
int dp[maxn][maxn];
char graph[maxn][maxn];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
struct pos{
    int r,c;
    pos(int pr=0,int pc=0):r(pr),c(pc){}
};
queue<pos> q;
int x1,y_1,x2,y2;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%c",&graph[i][j]);
        }
        getchar();
    }
    scanf("%d%d%d%d",&x1,&y_1,&x2,&y2);
    q.push(pos(x1,y_1));
    memset(dp,0x3f,sizeof dp);
    dp[x1][y_1]=0;
    while(q.size()){
        pos p=q.front();q.pop();
        int x=p.r,y=p.c;
        if(x==x2&&y==y2) break;
        //printf("consider %d %d\n",x,y);
        for(int j=0;j<4;j++){
            for(int i=1;i<=k&&x+dx[j]*i>0&&x+dx[j]*i<=n&&y+dy[j]*i>0&&y+dy[j]*i<=m;i++){
                if(graph[x+dx[j]*i][y+dy[j]*i]=='#'||dp[x+dx[j]*i][y+dy[j]*i]<=dp[x][y]) break;
                if(dp[x+dx[j]*i][y+dy[j]*i]==inf){
                    dp[x+dx[j]*i][y+dy[j]*i]=dp[x][y]+1;
                    q.push(pos(x+dx[j]*i,y+dy[j]*i));
                    //printf("%d %d=%d\n",x-i,y,dp[x-i][y]);
                }
            }
        }
    }
    printf("%d",dp[x2][y2]==inf?-1:dp[x2][y2]);
}
