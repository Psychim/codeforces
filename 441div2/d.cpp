#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int n;
int p;
int a[maxn];
bool c[maxn];
int point;
int main(){
    scanf("%d",&n);
    a[0]=1;
    point=n;
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++){
        scanf("%d",&p);
        c[p]=true;
        while(c[point]) point--;
        a[i]=i-(n-point)+1;
    }
    for(int i=0;i<=n;i++){
        printf("%d%c",a[i],i==n?'\n':' ');
    }
}
