#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int n;
int a[maxn];
int d[maxn][32];
ll res;
void RMQ_init(){
    for(int i=1;i<=n;i++) d[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            d[i][j]=d[i][j-1]|d[i+(1<<j-1)][j-1];
}
int RMQ(int L,int R){
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return d[L][k]|d[R-(1<<k)+1][k];
}
void work(int l,int r){
    if(l>=r) return;
    int large=l;
    for(int i=l;i<=r;i++){
        if(a[large]<a[i]) large=i;
    }
    work(l,large-1);
    work(large+1,r);
    for(int head=large;head>=l;head--){
        int ll=large,rr=r;
        while(ll<rr){
            int mid=(ll+rr)/2;
            int x=RMQ(head,mid);
            if(x>a[large])
                rr=mid;
            else ll=mid+1;
        }
        //printf("work(%d,%d):large(%d) %d %d\n",l,r,a[large],head,ll);
        res+=r-ll;
        if(RMQ(head,ll)>a[large])
            res++;
    }
}
int main(){
    scanf("%d",&n);
    res=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    RMQ_init();
    work(1,n);
    printf("%I64d\n",res);
}
