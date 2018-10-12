#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
char s[maxn];
char alpha[30];
bool good[30];
bool vis[maxn];
char q[maxn];
int qlen,slen;
int main(){
    scanf("%s",alpha);
    memset(good,0,sizeof good);
    for(int i=0;alpha[i];i++)
        good[alpha[i]-'a']=1;
    scanf("%s",s);
    slen=strlen(s);
    scanf("%d",&n);
    while(n--){
        scanf("%s",q);
        qlen=strlen(q);
        bool ok=true;
        int i,j;
        memset(vis,0,sizeof vis);
        for(i=0;ok&&i<qlen&&i<slen&&s[i]!='*';i++){
            if(s[i]=='?'){
                if(!good[q[i]-'a']) ok=false;
            }
            else if(s[i]!=q[i]) ok=false;
            vis[i]=1;
        }
        for(j=0;ok&&j<qlen&&j<slen&&s[slen-j-1]!='*'&&!vis[qlen-j-1];j++){
           // printf("%d %d\n",i,j);
            if(s[slen-j-1]=='?'){
                if(!good[q[qlen-j-1]-'a']) ok=false;
            }
            else if(s[slen-j-1]!=q[qlen-j-1]) ok=false;
        }
        if(s[i]=='*'){
            if(s[slen-j-1]!='*') ok=false;
            for(int k=i;ok&&k<=qlen-j-1;k++)
                if(good[q[k]-'a'])
                    ok=false;
        }
        if(ok&&j==qlen&&i==slen)
            puts("YES");
        else puts("NO");
    }
}
