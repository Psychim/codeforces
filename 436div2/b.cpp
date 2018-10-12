#include<bits/stdc++.h>
using namespace std;
const int maxn=220;
int n;
char s[maxn];
bool vis[maxn];
int res,pre;
int main(){
    scanf("%d%s",&n,s);
    res=0;
    pre=0;
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            res=max(res,pre);
            memset(vis,0,sizeof vis);
            pre=0;
        }
        else{
            if(!vis[s[i]-'a']) pre++;
            vis[s[i]-'a']=1;
        }
    }
    res=max(res,pre);
    printf("%d\n",res);
}
