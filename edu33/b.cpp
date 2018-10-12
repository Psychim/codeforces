#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int beau(int x){
    return ((1<<x)-1)*(1<<(x-1));
}
int main(){
    scanf("%d",&n);
    int res=1;
    for(int i=1;beau(i)<=n;i++){
        if(n%beau(i)==0) res=i;
    }
    printf("%d",beau(res));
}
