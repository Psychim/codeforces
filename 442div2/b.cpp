#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
char buf[maxn];
int a[maxn],b[maxn];
int n;
int main(){
    scanf("%s",buf+1);
    n=strlen(buf+1);
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++){
        a[i]=a[i-1];
        b[i]=b[i-1];
        if(buf[i]=='a')
            a[i]++;
        else b[i]++;
    }
    int res=0;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            int one=a[i]-a[0];
            int two=b[j]-b[i];
            int three=a[n]-a[j];
            res=max(res,one+two+three);
        }
    }
    printf("%d",res);
}
