#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,d,t;
int main(){
    cin>>k>>d>>t;
    d=((k+d-1)/d)*d;
    ll single=(2*k+d-k);
    double time=2*t/single*d;
    ll remainder=2*t%single;
    if(remainder<=2*k)
        time+=remainder*1./2;
    else time+=k+(remainder-2*k);
    printf("%lf",time);
}
