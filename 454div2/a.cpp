#include<bits/stdc++.h>
using namespace std;
int up[3];
int down[3];
int b[3];
bool ok=true;
int main(){
    int v1,v2,v3,v4;
    scanf("%d%d%d%d",&v1,&v2,&v3,&v4);
    down[0]=v1;
    up[0]=2*v1;
    down[1]=v2;
    up[1]=2*v2;
    down[2]=v3;
    up[2]=2*v3;
    down[2]=max(down[2],v4);
    up[2]=min(2*v4,up[2]);
    down[0]=max(2*v4+1,down[0]);
    down[1]=max(2*v4+1,down[1]);
    if(down[0]>up[0]) ok=false;
    b[0]=up[0];
    up[1]=min(up[0]-1,up[1]);
    if(down[1]>up[1]) ok=false;
    b[1]=up[1];
    up[2]=min(up[1]-1,up[2]);
    if(down[2]>up[2]) ok=false;
    b[2]=up[2];
    if(ok){
        printf("%d\n%d\n%d",b[0],b[1],b[2]);
    }
    else puts("-1");
}
