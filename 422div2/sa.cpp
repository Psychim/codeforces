#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5;
const int maxm=27;
int wa[maxn];
int wb[maxn];
int wv[maxn];
int ws[maxm];

int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m){
    //wa，wb是排好序的关键字数组
    int i,j,p,*x=wa,*y=wb,*t;
    memset(ws,0,sizeof ws);
    //ws[i]表示第i个字符的末序号
    for(int i=0;i<n;i++)
        ws[x[i]=r[i]]++;
    for(int i=1;i<m;i++)
        ws[i]+=ws[i-1];
    //sa是排好序的后缀数组
    for(int i=n-1;i>=0;i--)
        sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j<<=1,m=p){
        //y是按第一关键字排好序的后缀
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;   //后j个，第一关键字均为0
        for(i=0;i<n;i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];
        memset(ws,0,sizeof ws);
        for(i=0;i<n;i++)
            ws[wv[i]]++;
        for(i=1;i<m;i++)
            ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--)
            sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
int main(){
    int r[8]={1,1,2,4,1,2,4,1};
    int sa[8];
    da(r,sa,8,5);
    for(int i=0;i<8;i++){
        printf("%d:", sa[i]);
        for(int j=sa[i];j<8;j++)
            printf("%d",r[j]);
        puts("");
    }
}
