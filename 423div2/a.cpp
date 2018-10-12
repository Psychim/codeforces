#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    c=0;
    int res=0;
    while(n--){
        int x;
        scanf("%d",&x);
        if(x==1){
            if(a)
                --a;
            else if(b)
                --b,++c;
            else if(c)
                --c;
            else ++res;
        }
        else{
            if(b)
                --b;
            else res+=2;
        }
    }
    printf("%d\n",res);
}
