#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const ll maxl=1e9+10;
int n;
ll a,b,c,d,start,len;
int cnt[2][maxn];
ll minsc[maxn];
ll sc[maxn];
ll t[maxn];
void moveToNext(int &l,int &r,ll &lt){
    if(r==n) lt=t[l+1]+1;
    else if(t[l+1]+1-lt<t[r+1]+1-lt-len){
        lt=t[l+1]+1;
    }
    else lt=t[r+1]+1-len;
    while(l<=n&&t[l]<lt) l++;
    while(r<=n&&t[r+1]<lt+len) r++;
}
int main(){
    scanf("%d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d,&start,&len);
    for(int i=1;i<=n;i++){
        int q;
        scanf("%I64d%d",t+i,q);
        cnt[q][i]++;
    }
    sc[0]=start;
    for(int i=1;i<=n;i++){
        cnt[0][i]+=cnt[0][i-1];
        cnt[1][i]+=cnt[1][i-1];
        sc[i]=start+cnt[0][i]*a-cnt[1][i]*b;
    }
    minsc[n+1]=minsc[n]=a*cnt[1][n]-b*cnt[0][n]+start;
    for(int i=n-1;i>=0;i--){
        minsc[i]=min(minsc[i+1],start+a*cnt[1][i]-b*cnt[0][i]);
    }
    ll lt=0;
    ll res=-1;
    int l=0,r=0;
    while(r<=n&&t[r+1]<lt+len) r++;
    for(;l<n&&res==-1;){
        ll delta=(cnt[1][r]-cnt[1][max(0,l-1)])*(c-a)+(cnt[0][r]-cnt[1][max(0,l-1)])*(b-d);
        if(delta+minsc[r+1]<0){
            moveToNext(l,r,lt);
        }
        else{

        }
    }
}
