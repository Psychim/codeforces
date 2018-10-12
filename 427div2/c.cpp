#include<bits/stdc++.h>
using namespace std;
const int maxx=110;
const int maxc=11;
const int maxi=1e6;
int n,q,c;
int v[maxi][maxc];
int add[maxi];
int query(int l,int t,int b,int r,int i,int ll,int tt,int bb,int rr,int key){
    if(ll<=l&&tt<=t&&bb>=b&&rr>=r){
        int sum=0;
        for(int j=0;j<=c;j++)
            sum+=v[i][j]*((j+key%(c+1))%(c+1));
        //printf("%d %d %d %d %d: %d\n",l,t,b,r,i,sum);
        return sum;
    }
    int c1=4*i+1,c2=4*i+2,c3=4*i+3,c4=4*i+4;
    int midh=(l+r)/2,midv=(t+b)/2;
    int sum=0;
    if(ll<=midh&&tt<=midv)
        sum+=query(l,t,midv,midh,c1,ll,tt,bb,rr,key);
    if(rr>midh&&tt<=midv)
        sum+=query(midh+1,t,midv,r,c2,ll,tt,bb,rr,key);
    if(ll<=midh&&bb>midv)
        sum+=query(l,midv+1,b,midh,c3,ll,tt,bb,rr,key);
    if(rr>midh&&bb>midv)
        sum+=query(midh+1,midv+1,b,r,c4,ll,tt,bb,rr,key);
    return sum;
}
void addstar(int l,int t,int b,int r,int i,int x,int y,int key){
    //printf("%d %d %d %d %d\n",l,t,b,r,i);
    if(x==l&&x==r&&y==t&&y==b){
        v[i][key]++;
        return;
    }
    int c1=4*i+1,c2=4*i+2,c3=4*i+3,c4=4*i+4;
    int midh=(l+r)/2,midv=(t+b)/2;
    if(x<=midh&&y<=midv)
        addstar(l,t,midv,midh,c1,x,y,key);
    else if(x>midh&&y<=midv)
        addstar(midh+1,t,midv,r,c2,x,y,key);
    else if(x<=midh&&y>midv)
        addstar(l,midv+1,b,midh,c3,x,y,key);
    else if(x>midh&&y>midv)
        addstar(midh+1,midv+1,b,r,c4,x,y,key);
    for(int j=0;j<=c;j++){
        v[i][j]=v[c1][j]+v[c2][j]+v[c3][j]+v[c4][j];
    }
}
int main(){
    scanf("%d%d%d",&n,&q,&c);
    memset(v,0,sizeof v);
    for(int i=0;i<n;i++){
        int x,y,s;
        scanf("%d%d%d",&x,&y,&s);
        addstar(1,1,100,100,0,x,y,s);
    }
    for(int i=0;i<q;i++){
        int t,x1,y1,x2,y2;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        printf("%d\n",query(1,1,100,100,0,x1,y1,y2,x2,t));
    }
}
