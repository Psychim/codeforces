#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int pos;
int res;
int dis[3];
int nxt[3];
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&c);
    pos=0;
    res=0;
    if(a<b){
        dis[0]=a;
        nxt[0]=1;
    }
    else{
        dis[0]=b;
        nxt[0]=2;
    }
    if(a<c){
        dis[1]=a;
        nxt[1]=0;
    }
    else{
        dis[1]=c;
        nxt[1]=2;
    }
    if(b<c){
        dis[2]=b;
        nxt[2]=0;
    }
    else{
        dis[2]=c;
        nxt[2]=1;
    }
    for(int i=1;i<n;i++){
        res+=dis[pos];
        pos=nxt[pos];
    }
    printf("%d\n",res);
}
