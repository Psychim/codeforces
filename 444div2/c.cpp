#include<bits/stdc++.h>
using namespace std;
const int maxn=24;
int a[maxn];
bool judgef(int x[],int s){
    bool ok=1;
    for(int i=1;i<=3;i++){
        ok&=x[s]==x[s+i];
    }
    return ok;
}
bool judge(int x[] ){
    bool ok=true;
    ok&=judgef(x,0);
    ok&=judgef(x,4);
    ok&=judgef(x,8);
    ok&=judgef(x,12);
    ok&=judgef(x,16);
    ok&=judgef(x,20);
    return ok;
}
void rotatef1(int x[] ){
    int tmp=x[0];
    x[0]=x[2];
    x[2]=x[3];
    x[3]=x[1];
    x[1]=tmp;
    tmp=x[12];
    int tmp2=x[13];
    x[12]=x[4];
    x[13]=x[5];
    x[4]=x[16];
    x[5]=x[17];
    x[16]=x[20];
    x[17]=x[21];
    x[20]=tmp;
    x[21]=tmp2;
}
void rotatef2(int x[]){
    int tmp=x[4];
    x[4]=x[6];
    x[6]=x[7];
    x[7]=x[5];
    x[5]=tmp;
    tmp=x[13];
    int tmp2=x[15];
    x[13]=x[8];
    x[15]=x[9];
    x[8]=x[18];
    x[9]=x[16];
    x[18]=x[3];
    x[16]=x[2];
    x[3]=tmp;
    x[2]=tmp2;
}
void rotatef3(int x[]){
    int tmp=x[8];
    x[8]=x[10];
    x[10]=x[11];
    x[11]=x[9];
    x[9]=tmp;
    tmp=x[23];
    int tmp2=x[22];
    x[23]=x[19];
    x[22]=x[18];
    x[19]=x[7];
    x[18]=x[6];
    x[7]=x[15];
    x[6]=x[14];
    x[15]=tmp;
    x[14]=tmp2;
}
void rotatef4(int x[]){
    int tmp=x[12];
    x[12]=x[14];
    x[14]=x[15];
    x[15]=x[13];
    x[13]=tmp;
    tmp=x[21];
    int tmp2=x[23];
    x[21]=x[10];
    x[23]=x[8];
    x[10]=x[6];
    x[8]=x[4];
    x[6]=x[2];
    x[4]=x[0];
    x[2]=tmp;
    x[0]=tmp2;
}
void rotatef5(int x[]){
    int tmp=x[16];
    x[16]=x[18];
    x[18]=x[19];
    x[19]=x[17];
    x[17]=tmp;
    tmp=x[5];
    int tmp2=x[7];
    x[5]=x[9];
    x[7]=x[11];
    x[9]=x[22];
    x[11]=x[20];
    x[22]=x[1];
    x[20]=x[3];
    x[1]=tmp;
    x[3]=tmp2;
}
void rotatef6(int x[]){
    int tmp=x[20];
    x[20]=x[22];
    x[22]=x[23];
    x[23]=x[21];
    x[21]=tmp;
    tmp=x[17];
    int tmp2=x[19];
    x[17]=x[11];
    x[19]=x[10];
    x[11]=x[14];
    x[10]=x[12];
    x[14]=x[0];
    x[12]=x[1];
    x[0]=tmp;
    x[1]=tmp2;
}
int main(){
    for(int i=0;i<maxn;i++){
        scanf("%d",a+i);
    }
    bool ok=false;
    if(judgef(a,0)){
        rotatef1(a);
        ok|=judge(a);
        rotatef1(a);
        rotatef1(a);
        ok|=judge(a);
        rotatef1(a);
    }
    if(judgef(a,4)){
        rotatef2(a);
        ok|=judge(a);
        rotatef2(a);
        rotatef2(a);
        ok|=judge(a);
        rotatef2(a);
    }
        if(judgef(a,8)){
        rotatef3(a);
        ok|=judge(a);
        rotatef3(a);
        rotatef3(a);
        ok|=judge(a);
        rotatef3(a);
    }
        if(judgef(a,12)){
        rotatef4(a);
        ok|=judge(a);
        rotatef4(a);
        rotatef4(a);
        ok|=judge(a);
        rotatef4(a);
    }
        if(judgef(a,16)){
        rotatef5(a);
        ok|=judge(a);
        rotatef5(a);
        rotatef5(a);
        ok|=judge(a);
        rotatef5(a);
    }
        if(judgef(a,20)){
        rotatef6(a);
        ok|=judge(a);
        rotatef6(a);
        rotatef6(a);
        ok|=judge(a);
        rotatef6(a);
    }
    if(ok)
        puts("YES");
    else puts("NO");
}
