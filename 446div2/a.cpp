#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
int a[maxn],b[maxn];
ll sum=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",b+i);
    }
    sort(b,b+n);
    ll bsum=b[n-1]+b[n-2];
    if(sum<=bsum){
        puts("YES");
    }
    else puts("NO");
}
