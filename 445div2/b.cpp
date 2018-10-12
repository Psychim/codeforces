#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int n;
int dis[maxn];
int res;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    res=0;
    for(int i=n-1;i>=0;i--){
        if(!dis[a[i]]){
            dis[a[i]]=n-i;
        }
    }
    for(int i=0;i<n;i++){
        if(dis[res]<dis[a[i]]){
            res=a[i];
        }
    }
    printf("%d",res);
}
