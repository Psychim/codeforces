#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n;
int a[maxn];
int spec;
bool ok;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    spec=3;
    ok=true;
    for(int i=0;ok&&i<n;i++){
        if(a[i]==spec) ok=false;
        spec=6-spec-a[i];
    }
    if(ok)
        puts("YES");
    else puts("NO");
}
