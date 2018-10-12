#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxnk=1e6+10;
const ll mod=1e9+7;
ll dp[maxnk];
int a[maxnk];
struct Node{
    int v,p;
    bool operator<(Node a){
        return v<a.v;
    }
};
Node b[maxnk];
int iinb[maxnk];
ll minl,m;
int n,k;
ll l;
int main(){
    cin>>n>>l>>k;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        //a[i]=rand();
        //printf("%d ",a[i]);
        b[i].v=a[i];
        b[i].p=i;
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        iinb[b[i].p]=i;
    }
    minl=min((l/n)+(l%n?1:0),(ll)k);
    m=l/n;
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=n;i<n*k;i++){
        if(i%n&&b[(i-1)%n].v==b[i%n].v){
            dp[i]=dp[i-1];
        }
        else if(i%n==0){
            int j=i-n;
            dp[i]=0;
            while(j<i&&b[j%n].v==b[i%n].v)
                dp[i]=(dp[i]+dp[j++])%mod;
        }
        else{
            int j=i-n;
            dp[i]=dp[i-1];
            while(i-j>i%n&&b[j%n].v==b[i%n].v){
                dp[i]=(dp[i]+dp[j])%mod;
                j++;
            }
        }
    }
    ll res=0;
    for(int i=0;i<n*min(m,(ll)k);i++){
        int thisl=i/n;
        res=(res+(m-thisl)%mod*dp[i]%mod)%mod;
    }
    for(int i=0;i<l%n;i++){
        int j=iinb[i];
        for(int o=0;o<minl;o++){
            res=(res+dp[o*n+j])%mod;
        }
    }
    cout<<res<<endl;
}
