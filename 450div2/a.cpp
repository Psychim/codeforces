#include<bits/stdc++.h>
using namespace std;
int lft,rght;
int n;
int x,y;
int main(){
    scanf("%d",&n);
    lft=rght=0;
    while(n--){
        scanf("%d%d",&x,&y);
        if(x<0) lft++;
        if(x>0) rght++;

    }
    if(lft<=1||rght<=1){
        puts("Yes");
    }
    else puts("No");
}
