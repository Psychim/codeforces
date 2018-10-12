#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k;
int main(){
    cin>>k;
    n=0;
    for(int i=0;i<18&&k;i++){
        n*=10;
        if(k%2) n+=6,k--;
        else n+=8,k-=2;
    }
    if(k)
        cout<<-1;
    else cout<<n;
}
