#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int p;
int d[maxn];
int dn[maxn];
int res;
int main(){
    scanf("%d",&n);
    d[1]=1;
    dn[1]=1;
    for(int i=2;i<=n;i++){
        scanf("%d",&p);
        d[i]=d[p]+1;
        dn[d[i]]++;
    }
    for(int i=1;i<=n;i++){
        res+=dn[i]%2;
    }
    printf("%d",res);
}
