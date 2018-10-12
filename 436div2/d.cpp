#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int a[maxn];
int res;
int vis[maxn];
int cnt[maxn];
int main(){
    scanf("%d",&n);
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        cnt[a[i]]++;
    }
    res=0;
    memset(vis,0,sizeof vis);
    int next=1;
    for(int i=0;i<n;i++){
        while(cnt[next])next++;
        if(cnt[a[i]]==1) continue;
        if(next>a[i]&&!vis[a[i]]){
            vis[a[i]]=1;
        }
        else {
            res++;
            cnt[a[i]]--;
            a[i]=next;
            cnt[next]++;
        }
    }
    printf("%d\n",res);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    puts("");
}
