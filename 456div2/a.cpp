#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll x,y,z;
ll na,nb;
int main(){
    scanf("%I64d%I74d",&a,&b);
    scanf("%I64d%I64d%I64d",&x,&y,&z);
    na=2*x+y;
    nb=y+3*z;
    printf("%I64d",max(0LL,na-a)+max(0LL,nb-b));
}
