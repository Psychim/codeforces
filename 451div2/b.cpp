#include<bits/stdc++.h>
using namespace std;
int n;
int a;
int b;
int x,y;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    bool ok=false;
    for(x=0;x*a<=n;x++){
        if((n-x*a)%b==0){
            y=(n-x*a)/b;
            ok=true;
            break;
        }
    }
    if(ok){
        puts("YES");
        printf("%d %d",x,y);
    }
    else puts("NO");
}
