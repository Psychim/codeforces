#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p,y;
int main(){
    cin>>p>>y;
    for(int i=y;i>p;i--){
        bool ok=true;
        for(int j=2;ok&&j<=i/j&&j<=p;j++){
            if(i%j==0) ok=false;
        }
        if(ok) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}
