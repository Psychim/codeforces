#include<bits/stdc++.h>
using namespace std;
const int maxn=7e4+10;
const int maxs=10*maxn;
int n;
char phone[maxn][10];
int wa[maxs];
int wb[maxs];
int wv[maxs];
int tws[maxs];
int r[maxs];
int sa[maxs];
int rk[maxs];
int ht[maxs];
int d[maxs][32];
void RMQ_init(int*b,int n){
    for(int i=0;i<n;i++) d[i][0]=b[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            d[i][j]=min(d[i][j-1],d[i+(1<<j-1)][j-1]);
        }
    }
}
int RMQ(int L,int R,int n){
    if(L>R) swap(L,R);
    L++;
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return min(d[L][k],d[R-(1<<k)+1][k]);
}
int cmp(int*r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    memset(tws,0,sizeof tws);
    for(int i=0;i<n;i++)
        tws[x[i]=r[i]]++;
    for(int i=1;i<m;i++)
        tws[i]+=tws[i-1];
    for(int i=n-1;i>=0;i--)
        sa[--tws[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p){
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=j)
               y[p++]=sa[i]-j;
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];
        memset(tws,0,sizeof tws);
        for(i=0;i<n;i++)
            tws[wv[i]]++;
        for(i=1;i<m;i++)
            tws[i]+=tws[i-1];
        for(i=n-1;i>=0;i--)
            sa[--tws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(i=0;i<n;i++)
        rk[sa[i]]=i;
    for(i=0;i<n;i++){
        if(!rk[i])
            ht[rk[i]]=0;
        else if(!i||ht[rk[i-1]]<=1){
            j=sa[rk[i]-1];
            int cnt;
            for(cnt=ht[rk[i-1]]-1;cnt<min(n-j,n-i)&&r[j+cnt]==r[i+cnt];cnt++);
            ht[rk[i]]=cnt;
        }
    }
    RMQ_init(ht,n);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",phone[i]);
    }

}
