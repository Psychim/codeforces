#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=60;
int n,m;
ll a[maxn],b[maxn];
ll c[maxn];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i);
    for(int i=0;i<m;i++)
        scanf("%I64d",b+i);
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<n;i++){
        if(a[i]<0){
            c[i]=a[i]*b[0];
        }
        else c[i]=a[i]*b[m-1];
    }
    sort(c,c+n);
    cout<<c[n-2];
}
