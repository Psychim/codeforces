#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
int a[maxn];
int d[maxn][32];
int n;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void RMQ_init(){
    for(int i=0;i<n;i++) d[i][0]=a[i];     //³õÊ¼»¯
    for(int j=1;(1<<j)<=n;j++)              //Ã¶¾Ù2^j
        for(int i=0;i+(1<<j)-1<n;i++)
            d[i][j]=gcd(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R){
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return gcd(d[L][k],d[R-(1<<k)+1][k]);
}
int cnt;
int tmp;
int res=0x3f3f3f3f;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]>1) cnt++;
    }
    RMQ_init();
    if(RMQ(0,n-1)>1){
        puts("-1");
        return 0;
    }
    for(int i=0;i<n;i++){
        tmp=0;
        int l=i,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(RMQ(i,mid)==1){
                r=mid;
            }
            else l=mid+1;
        }
        //printf("%d\n",l);
        if(RMQ(i,l)!=1)
            continue;
        tmp=l-i;
        if(a[l]==1)
            tmp+=cnt;
        else tmp+=cnt-1;
        res=min(tmp,res);
    }
    printf("%d",res);
}
