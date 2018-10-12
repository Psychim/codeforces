#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m;
char g[maxn][maxn];
int l,r,t,b;
int main(){
    scanf("%d%d",&n,&m);
    l=maxn;
    r=0;
    t=maxn;
    b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            while(~scanf("%c",&g[i][j])&&(g[i][j]!='B'&&g[i][j]!='W'));
            //printf("%c",g[i][j]);
            if(g[i][j]=='B'){
                l=min(j,l);
                r=max(j,r);
                t=min(i,t);
                b=max(i,b);
            }
        }
    }
    if(l==maxn){
        puts("1");
    }
    else{
        bool ok=true;
        if(r-l>b-t){
            int delta=r-l-(b-t);
            if(b+delta<n)
                b+=delta;
            else if(t-delta>=0)
                t-=delta;
            else ok=false;
        }
        else{
            int delta=(b-t)-(r-l);
            if(r+delta<m)
                r+=delta;
            else if(l-delta>=0)
                l-=delta;
            else ok=false;
        }
        if(ok){
            int res=0;
            for(int i=t;i<=b;i++){
                for(int j=l;j<=r;j++){
                    if(g[i][j]=='W')
                        res++;
                }
            }
            printf("%d\n",res);
        }
        else puts("-1");
    }

}
