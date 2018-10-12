#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,b;
ll ans;
ll tmp;
int main(){
    scanf("%d%d",&m,&b);
    ans=b*(b+1LL)/2LL;
    for(int x=m;b-x/m>=0;x+=m){
        int y=b-x/m;
        tmp=y*(y+1LL)/2LL*(x+1)+(y+1LL)*x*(x+1LL)/2LL;
        ans=max(tmp,ans);
    }
    printf("%I64d\n",ans);
}
