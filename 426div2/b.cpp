#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int open[maxn];
char s[maxn];
bool isop[30];
int cnt[30];
bool yes;
int n,k;
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    memset(cnt,0,sizeof cnt);
    memset(isop,0,sizeof isop);
    for(int i=1;i<=n;i++)
        cnt[s[i]-'A']++;
    open[0]=0;
    yes=0;
    for(int i=1;!yes&&i<=n;i++){
        int j=s[i]-'A';
        open[i]=open[i-1];
        if(!isop[j]){
            isop[j]=1;
            if(++open[i]>k)
                yes=1;
        }
        if(--cnt[j]==0){
            isop[j]=0;
            --open[i];
        }
    }
    if(yes) puts("YES");
    else puts("NO");
}
