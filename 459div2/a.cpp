#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n;
int main(){
    scanf("%d",&n);
    int a1=0,a2=1;
    for(int i=1;i<=n;i++){
        if(i==a2){
            putchar('O');
            while(a2<=i){
                a2=a1+a2;
                a1=a2-a1;
            }
        }
        else putchar('o');
    }
}
