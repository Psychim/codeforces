#include<bits/stdc++.h>
using namespace std;
int a,b,d;
int tire;
int main(){
    scanf("%d%d",&a,&b);
    d=abs(a-b);
    tire=(1+d/2)*(d/2);
    if(d%2){
        tire+=d/2+1;
    }
    printf("%d",tire);
}
