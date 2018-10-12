#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    int l=0,r=a;
    while(l<r){
        int mid=(l+r+1)/2;
        if(mid*2<=b&&mid*4<=c)
            l=mid;
        else r=mid-1;
    }
    printf("%d\n",7*l);
}
