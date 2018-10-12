#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int d,r;
int n;
int x,y,rs;
int res;
int main(){
    scanf("%d%d",&r,&d);
    scanf("%d",&n);
    res=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&rs);
        int dd=x*x+y*y;
        if(rs>r) continue;
        if(r==d){
            if(dd<=(r-rs)*(r-rs))
                res++;
        }
        if(dd>=(r-d+rs)*(r-d+rs)&&dd<=(r-rs)*(r-rs))
            res++;
    }
    printf("%d\n",res);
}
