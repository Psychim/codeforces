#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
string s[27];
int scnt;
int n;
char buf[maxn];
bool ok;
int scsor[27];
int pre[27];
bool vis[27];
bool has[27];
bool chosen[27];
int id(char a){
    return a-'a'+1;
}
char cid(int i){
    return char('a'+i-1);
}
bool check(char x[]){
    memset(has,0,sizeof has);
    for(int i=0;x[i];i++){
        if(has[id(x[i])]) return false;
        has[id(x[i])]=1;
    }
    return true;
}
int main(){
    srand(time(0));
    scanf("%d",&n);
    ok=true;
    for(int i=0;i<n;i++){
        scanf("%s",buf);
        vis[id(buf[0])]=1;
        ok&=check(buf);
        for(int j=1;buf[j];j++){
            vis[id(buf[j])]=1;
            if(scsor[id(buf[j-1])]&&scsor[id(buf[j-1])]!=id(buf[j])||pre[id(buf[j])]&&id(buf[j-1])!=pre[id(buf[j])]){
                //printf("%c has scsor %c or %c has pre %c\n",buf[j-1],cid(scsor[id(buf[j-1])]),buf[j],cid(pre[id(buf[j])]));
                ok=false;
            }
            else if(!scsor[id(buf[j-1])]||!pre[id(buf[j])]){
                scsor[id(buf[j-1])]=id(buf[j]);
                pre[id(buf[j])]=id(buf[j-1]);
            }
        }
    }
    if(!ok){
        puts("NO");
    }
    else{
        for(int i=1;i<=26;i++){
            if(!pre[i]&&vis[i]){
                int u=i;
                while(u){
                    chosen[u]=1;
                    s[scnt]+=cid(u);
                    u=scsor[u];
                }
                scnt++;
            }
        }
        if(scnt==0)
            ok=false;
        for(int i=1;i<=26;i++){
            if(vis[i]&&!chosen[i])
                ok=false;
        }
        if(!ok){
            puts("NO");
            return 0;
        }
        sort(s,s+scnt);
        for(int i=0;i<scnt;i++){
            cout<<s[i];
        }
    }
}
