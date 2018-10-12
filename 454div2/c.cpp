#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int cnt=0;
int n;
bool candidate[26];
bool vis[26];
int rest;
char act;
char s[maxn];
void cancel(int j){
    if(candidate[j])
        rest--;
    candidate[j]=false;
}
int main(){
    scanf("%d",&n);
    memset(candidate,1,sizeof candidate);
    rest=26;
    for(int i=0;i<n;i++){
        getchar();
        //printf("%d\n",rest);
        scanf("%c %s",&act,s);
        //printf("%c %s\n",act,s);
        if(i==n-1) continue;
        if(act=='!'){
            memset(vis,0,sizeof vis);
            if(rest==1)
                cnt++;
            for(int j=0;s[j];j++){
                vis[s[j]-'a']=true;
            }
            for(int j=0;j<26;j++){
                //printf("%d ",vis[j]);
                if(!vis[j]){
                    cancel(j);
                }
            }
           // puts("");
        }
        else if(act=='.'){
            for(int j=0;s[j];j++){
                cancel(s[j]-'a');
            }
        }
        else if(act=='?'){
            if(rest==1)
                cnt++;
            cancel(s[0]-'a');
        }
    }
    printf("%d",cnt);
}
