#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int t;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    t=0;
    if(a>b)
        swap(a,b);
    while(!(a%2&&b==a+1)){
        a-=a/2;
        b-=b/2;
        t++;
    }
    t++;
    if((1<<t)==n)
        puts("Final!");
    else printf("%d",t);
}
