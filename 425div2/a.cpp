#include<bits/stdc++.h>
using namespace std;
int main(){
    long long  n,k;
    scanf("%I64d%I64d",&n,&k);
    if(n/k%2)
        printf("YES");
    else puts("NO");
}
