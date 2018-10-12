#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a,b,c;
int fa,fb;
bool vis[maxn];
int main(){
    scanf("%d%d%d",&a,&b,&c);
    a=a%b;
    int res=0;
    bool ok=false;
    while(!vis[a]){
        res++;
        if(c==a*10/b){
            ok=true;
            break;
        }
        vis[a]=true;
        a=a*10%b;
    }
    printf("%d",ok?res:-1);
}
