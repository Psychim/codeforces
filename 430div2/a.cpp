#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,x,y,k;
bool ok;
int main(){
    scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k);
    ll bl=x,br=y;
    ok=false;
    for(ll i=x;!ok&&i<=y;i++){
        if(k*i>=l&&k*i<=r)
            ok=true;
        else if(k*i>r)
            break;
    }
    if(ok)
        puts("YES");
    else puts("NO");
}
