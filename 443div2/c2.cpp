#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
char ope[maxn];
int x[maxn];
int n;
int k;
int rx[3];
int one=1023;
int zero=0;
void compute(int i){
    int done=(one>>i)&1;
    int dzero=(zero>>i)&1;
    for(int j=0;j<=1;j++){
        for(int k=0;k<=1;k++){
            for(int l=0;l<=1;l++){
                if(((((1^j)&k)|l)==done)&&((((0^j)&k)|l)==dzero)){
                    //printf("digit %d: 1^%d&%d|%d=%d, 0^%d&%d|%d=%d\n",i,j,k,l,done,j,k,l,dzero);
                    rx[0]+=j<<i;
                    rx[1]+=k<<i;
                    rx[2]+=l<<i;
                    return;
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c %d",ope+i,x+i);
        if(ope[i]=='^'){
            one^=x[i];
            zero^=x[i];
        }
        else if(ope[i]=='&'){
            one&=x[i];
            zero&=x[i];
        }
        else{
            one|=x[i];
            zero|=x[i];
        }
    }
    for(int i=0;1023>>i;i++){
        compute(i);
    }
    printf("%d\n",3);
    printf("^ %d\n",rx[0]);
    printf("& %d\n",rx[1]);
    printf("| %d\n",rx[2]);
}
