#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t[maxn];
int n;
int td[maxn];
int dcnt;
bool verify(int d){
    memset(td,0,sizeof td);
    dcnt=1;
    td[0]=1;
    for(int i=1;i<=n;i++){
        if(td[t[i]]){
            td[i]=td[t[i]];
            td[t[i]]=0;
        }
        else{
            td[i]=++dcnt;
        }
    }
    return dcnt<=d;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",t+i);
    }
    int l=1;
    int r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(verify(mid))
            r=mid;
        else l=mid+1;
    }
    printf("%d",l);
}
