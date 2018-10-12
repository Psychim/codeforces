#include<bits/stdc++.h>
using namespace std;
map<char,int> mp,cmp;
int main(){
    mp['^']=cmp['^']=0;
    mp['>']=cmp['<']=1;
    mp['v']=cmp['v']=2;
    mp['<']=cmp['>']=3;
    char a,b;
    int n;
    scanf("%c %c%d",&a,&b,&n);
    bool cw=0,ccw=0;
    if((mp[a]+n)%4==mp[b])
        cw=1;
    if((cmp[a]+n)%4==cmp[b])
        ccw=1;
    if(ccw^cw){
        if(cw)
            puts("cw");
        else puts("ccw");
    }
    else puts("undefined");
}
