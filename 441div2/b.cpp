#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int maxm=1e6;
int k,n,m;
int a[maxn];
int cnt[maxm];
bool ok;
int b;
int main(){
    scanf("%d%d%d",&n,&k,&m);
    ok=false;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        cnt[a[i]%m]++;
    }
    for(int i=0;i<m;i++){
        if(cnt[i]>=k){
            ok=true;
            b=i;
            break;
        }
    }
    if(ok){
        printf("Yes\n");
        for(int i=0;i<n&&k;i++){
            if(a[i]%m==b){
                printf("%d ",a[i]);
                k--;
            }
        }
        puts("");
    }
    else puts("No");
}
