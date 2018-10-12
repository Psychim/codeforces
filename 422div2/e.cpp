#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
const int maxx=40;
int wa[maxn];
int wb[maxn];
int wv[maxn];
int tws[maxn];

char s[maxn],t[maxn];
int r[maxn];

int sa[maxn];
int rk[maxn];
int ht[maxn];

int d[maxn][32];

int dp[maxx][maxn];

int n,m,x;
void RMQ_init(int*b,int n){
    for(int i=0;i<n;i++) d[i][0]=b[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            d[i][j]=min(d[i][j-1],d[i+(1<<j-1)][j-1]);
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
    //wa，wb是排好序的关键字数组

    int i,j,p,*x=wa,*y=wb,*t;
    memset(tws,0,sizeof tws);
    //ws[i]表示第i个字符的末序号
    for(int i=0;i<n;i++)
        tws[x[i]=r[i]]++;
    for(int i=1;i<m;i++)
        tws[i]+=tws[i-1];
    //sa是排好序的后缀数组
    for(int i=n-1;i>=0;i--)
        sa[--tws[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p){
        //y是按第一关键字排好序的后缀
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;   //后j个，第一关键字均为0
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
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++){
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }
    for(int i=0;i<n;i++){
        rk[sa[i]]=i;
    }
    for(int i=0;i<n;i++){
        if(!rk[i])
            ht[rk[i]]=0;
        else if(!i||ht[rk[i-1]]<=1){
            int j=sa[rk[i]-1];
            int cnt;
            for(cnt=0;cnt<min(n-j,n-i)&&r[j+cnt]==r[i+cnt];cnt++);
            ht[rk[i]]=cnt;
        }
        else{
            int j=sa[rk[i]-1];
            int cnt;
            for(cnt=ht[rk[i-1]]-1;cnt<min(n-j,n-i)&&r[j+cnt]==r[i+cnt];cnt++);
            ht[rk[i]]=cnt;
        }
    }
    RMQ_init(ht,n);
}
int main(){
    scanf("%d",&n);
    scanf("%s",s);
//    for(int i=0;i<n;i++)
//        s[i]='v';
//    s[n]=0;
    scanf("%d",&m);
    scanf("%s",t);
//    for(int i=0;i<m;i++)
//        t[i]='v';
//    t[m]=0;
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        r[i]=s[i]-'a'+1;
    }
    r[n]='z'-'a'+2;
    for(int i=0;i<m;i++){
        r[n+1+i]=t[i]-'a'+1;
    }
    r[n+m+1]=0;
    da(n+m+2,28);
//    for(int i=0;i<n+m+1;i++){
//        printf("(%d,%d):",sa[i],ht[i]);
//        for(int j=sa[i];j<n+m+1;j++)
//            printf("%c",r[j]+'a');
//        puts("");
//    }
    memset(dp,-1,sizeof dp);
    for(int k=0;k<=x;k++){
        for(int i=1;i<=n;i++){
            if(dp[k][i]==m-1){
                puts("YES");
                return 0;
            }
            if(s[i-1]==t[dp[k][i-1]+1]){
                int mv=RMQ(rk[i-1],rk[n+1+dp[k][i-1]+1],n+m+1);
                //printf("%d\n",mv);
                dp[k+1][i+mv-1]=max(dp[k+1][i+mv-1],dp[k][i-1]+mv);
            }
            dp[k][i]=max(dp[k][i],dp[k][i-1]);
            //printf("dp[%d][%d]=%d\n",i+1,k,dp[i+1][k]);
        }
    }
    puts("NO");
}
