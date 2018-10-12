#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
int k;
bool perfect(ll a){
    int sum=0;
    while(a&&sum<=10){
        sum+=a%10;
        a/=10;
    }
    if(sum==10&&!a)
        return true;
    return false;
}
int main(){
    scanf("%d",&k);
    a=0;
    while(k){
        ++a;
        if(perfect(a))
            --k;
    }
    printf("%I64d",a);
}
