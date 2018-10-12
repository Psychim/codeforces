#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
const int maxd=2001;
int n;
struct Item{
    int t,d,p,i;
    Item(int a=0,int b=0,int c=0,int dd=0){t=a;d=b;p=c;i=dd;}
    bool operator<(Item a){
        return d-t<a.d-a.t||(d-t==a.d-a.t&&t<a.t);
    }
};
Item item[maxn];
int dp[maxn][maxd];
bool vis[maxn][maxd];
vector<int> ress;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t,d,p;
        scanf("%d%d%d",&t,&d,&p);
        item[i]=Item(t,d,p,i);
    }
    sort(item,item+n);
    memset(dp,0,sizeof dp);
    memset(vis,0,sizeof vis);
    for(int i=n;i>=1;i--){
        for(int t=maxd-1;t>=0;t--){
            if(t>=item[i].d-item[i].t){
                dp[i][t]=dp[i+1][t];
            }
            else{
                int choose=dp[i+1][t+item[i].t]+item[i].p;
                int notchoose=dp[i+1][t];
                if(choose>notchoose){
                    vis[i][t]=1;
                    dp[i][t]=choose;
                }
                else dp[i][t]=notchoose;
            }
        }
    }
    int resp=dp[1][0];
    int resn=0;
    int trace=0;
    for(int i=1;i<=n;i++){
        if(vis[i][trace]){
            ress.push_back(item[i].i);
            trace=trace+item[i].t;
            resn++;
        }
    }
    printf("%d\n",resp);
    printf("%d\n",resn);
    for(int i=0;i<ress.size();i++){
        printf("%d ",ress[i]);
    }
    puts("");
}
