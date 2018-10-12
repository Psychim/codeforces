#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxk=2010;
int n;
int k;
ll p;
ll a[maxk];
ll b[maxk];
ll res;
ll tmp;
int main(){
    scanf("%d%d%I64d",&n,&k,&p);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
    }
    for(int i=0;i<k;i++){
        scanf("%I64d",b+i);
    }
    sort(a,a+n);
    sort(b,b+k);
    res=1e10;
    for(int i=0;i<=k-n;i++){
        tmp=abs(b[i]-a[0])+abs(p-b[i]);
        for(int j=1;j<n;j++){
            tmp=max(tmp,abs(b[i+j]-a[j])+abs(p-b[i+j]));
        }
        res=min(tmp,res);
    }
    printf("%I64d",res);
}
