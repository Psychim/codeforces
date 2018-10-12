#include<bits/stdc++.h>
using namespace std;
const int maxs=5010;
const int maxn=maxs;
char s[maxs];
struct subs{
    int begin,end;
    subs(int a=0,int b=0){begin=a;end=b;}
    bool operator<(subs a)const{
        if(begin<a.begin)
            return 1;
        else if(begin==a.begin&&end<a.end)
            return 1;
        return 0;
    }
    int len(){
        return end-begin;
    }
};
set<subs> subset[maxs];
set<subs>::iterator ite;
int len;
int wa[maxn];
int wb[maxn];
int wv[maxn];
int tws[maxn];

int r[maxn];

int sa[maxn];
int rk[maxn];
int ht[maxn];

int d[maxn][32];

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
    scanf("%s",s);
    len=strlen(s);
    int cnt=0;
    for(int i=0;s[i];i++){
        int j=i,k=i;
        while(j>=0&&s[k]&&s[j]==s[k]){
            subset[k-j+1].insert(subs(j,k+1));
            printf("palindrome: %d %d\n",j,k);
            j--;
            k++;
            cnt++;
        }
        j=i,k=i+1;
        while(j>=0&&s[k]&&s[j]==s[k]){
            subset[k-j+1].insert(subs(j,k+1));
            printf("palindrome: %d %d\n",j,k);
            j--;
            k++;
            cnt++;
        }
    }
    for(int i=0;i<len;i++)
        r[i]=s[i]-'a'+1;
    r[len]=0;
    da(len+1,28);
    printf("%d ",cnt);
    for(int i=2;i<=len;i++){
        if(!cnt){
            printf("0 ");
            continue;
        }
        for(int j=1;j<=len;j++){
            for(ite=subset[j].begin();ite!=subset[j].end();){
                int l=ite->begin,r=ite->end-1;
                int mid=(l+r)/2-l;
                if(l<r&&subset[mid+1].count(subs(l,mid+1))&&subset[mid+1].count(subs(r-mid,r+1))&&RMQ(l,r-mid,len+1)>=mid+1){
                    printf("%d-palindrome: %d %d\n",i,l,r);
                    ite++;
                }
                else{
                    printf("%d %d %d ",mid+1,subset[mid+1].count(subs(l,mid+1)),subset[mid+1].count(subs(r-mid,r+1)));
                    printf("RMQ(%d,%d):%d\n",l,r-mid,RMQ(l,r-mid,len+1));
                    cnt--;
                    ite++;
                    subset[j].erase(subs(l,r+1));
                    printf("not %d: %d %d\n",i,l,r);
                }
            }
        }
        printf("%d ",cnt);
    }
}
