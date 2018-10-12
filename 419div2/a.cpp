#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int res;
int main(){
    int hh,mm;
    scanf("%d:%d",&hh,&mm);
    if(hh<5||hh>=10&&hh<15||hh>=20&&hh<23){
        if(mm<=hh/10+hh%10*10){
            res=hh/10+hh%10*10-mm;
        }
        else{
            res=(hh+1)/10+(hh+1)%10*10+60-mm;
        }
    }
    else if(hh==5||hh==15){
        if(mm<=hh/10+hh%10*10){
            res=hh/10+hh%10*10-mm;
        }
        else{
            res=60-mm+240+(hh+5)/10;
        }
    }
    else if(hh>5&&hh<10||hh>15&&hh<20){
        if(hh/10==0)
            res=60-mm+(10-hh-1)*60+1;
        else res=60-mm+(20-hh-1)*60+2;
    }
    else{
        if(mm<=32)
            res=32-mm;
        else res=60-mm;
    }
    printf("%d\n",res);
}
