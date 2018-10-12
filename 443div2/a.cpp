#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1010;
int n;
int s[maxn];
int d[maxn];
int cur;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",s+i,d+i);
    }
    cur=0;
    for(int i=1;i<=n;i++){
        int j=0;
        while(s[i]+j*d[i]<=cur) j++;
        cur=s[i]+j*d[i];
    }
    printf("%d",cur);
}
