#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=110;
int g[maxn][maxn];
struct Operation{
    int dir,num,cnt;
    Operation(int a=0,int b=0,int c=0){dir=a,num=b,cnt=c;}
};
Operation ope[maxn*maxn];
int opecnt;
int n,m;
int res;
void calcol(){
    for(int i=0;i<m;i++){
        int least=g[0][i];
        for(int j=1;j<n;j++){
            least=min(least,g[j][i]);
        }
        if(least){
            res+=least;
            ope[opecnt++]=Operation(0,i+1,least);
            for(int j=0;j<n;j++)
                g[j][i]-=least;
        }
    }
}
void calrow(){
    for(int i=0;i<n;i++){
        int least=g[i][0];
        for(int j=1;j<m;j++){
            least=min(least,g[i][j]);
        }
        if(least){
            res+=least;
            ope[opecnt++]=Operation(1,i+1,least);

            for(int j=0;j<m;j++)
                g[i][j]-=least;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    res=0;
    opecnt=0;
    if(n<m){
        calrow();
        calcol();
    }
    else{
        calcol();
        calrow();
    }
    bool ok=true;
    for(int i=0;i<n&&ok;i++){
        for(int j=0;j<m&&ok;j++){
            if(g[i][j])
                ok=false;
        }
    }
    if(ok){
        printf("%d\n",res);
        for(int i=0;i<opecnt;i++){
            for(int j=0;j<ope[i].cnt;j++){
                if(ope[i].dir){
                    printf("row ");
                }
                else printf("col ");
                printf("%d\n",ope[i].num);
            }
        }
    }
    else printf("-1\n");
}
