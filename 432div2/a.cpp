#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int main(){
    scanf("%d%d%d",&n,&k,&t);
    if(t<=k)
        printf("%d\n",t);
    else if(t>=n)
        printf("%d\n",n+k-t);
    else printf("%d\n",k);
}
