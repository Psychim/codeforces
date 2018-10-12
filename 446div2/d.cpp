#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=30;
ll a[maxn];
int n;
int order[maxn];
ll b[maxn];
bool verify(ll suba[],ll subb[],int subn){
    for(int i=1<<(subn-1);i<(1<<n)-1&&i<=((1<<subn)-1);i++){
        ll asum=0,bsum=0;
        for(int j=0;j<subn;j++){
            if(i&(1<<j)){
                asum+=suba[j];
                bsum+=subb[j];
            }
        }
        if(asum==bsum) return false;
    }
    return true;
}
bool dfs(int i){
    if(i==n) return true;
    for(int j=i;j<n;j++){
        swap(b[i],b[j]);
//        for(int k=0;k<=i;k++)
//            printf("%I64d ",b[k]);
//        puts("");
        if(verify(a,b,i+1)){
            if(dfs(i+1)) return true;
        }
        swap(b[i],b[j]);
    }
    return false;
}
int main(){
    srand(time(0));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
        //a[i]=i;
        b[i]=a[i];
    }
    if(dfs(0)){
        for(int i=0;i<n;i++){
            printf("%I64d%c",b[i],i==n-1?'\b':' ');
        }
    }
    else puts("-1");
}
