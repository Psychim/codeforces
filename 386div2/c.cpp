#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int s,x1,x2;
int t1,t2;
int p,d;
int res;
int main(){
    scanf("%d%d%d%d%d%d%d",&s,&x1,&x2,&t1,&t2,&p,&d);
    res=abs(x1-x2)*t2;
    if(x1<x2){
        if(d==-1){
            res=min(res,abs(p+x2)*t1);
        }
        else if(p>x1){
            res=min(res,abs(s-p+s+x2)*t1);
        }
        else res=min(res,abs(x2-p)*t1);
    }
    else {
        if(d==1)
            res=min(res,abs(s-p+s-x2)*t1);
        else if(p<x1)
            res=min(res,abs(p+s+s-x2)*t1);
        else res=min(res,abs(p-x2)*t1);
    }
    printf("%d\n",res);
}
