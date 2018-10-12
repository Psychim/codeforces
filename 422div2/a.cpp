#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c=min(a,b);
    int res=1;
    for(int i=1;i<=c;i++) res*=i;
    printf("%d\n",res);
}
