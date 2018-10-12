#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxt=200010;
int a[maxt];
int b[maxt];
int main(){
    memset(a,0,sizeof(a));
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        a[l]++;
        a[r+1]--;
    }
    memset(b,0,sizeof b);
    for(int i=1;i<maxt;i++){
        a[i]+=a[i-1];
        b[i]=b[i-1];
        if(a[i]>=k)
            b[i]++;
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",b[r]-b[l-1]);
    }
}
