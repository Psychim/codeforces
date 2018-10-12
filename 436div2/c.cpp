#include<bits/stdc++.h>
using namespace std;
int a,b,f,k,cur,res;
int main(){
    scanf("%d%d%d%d",&a,&b,&f,&k);
    cur=b;
    res=0;
    bool ok=true;
    for(int i=0;ok&&i<k;i++){
        if(i%2){
            cur-=a-f;
        }
        else{
            cur-=f;
        }
        if(cur<0){
            ok=false;
            break;
        }
        if(i==k-1){
            if(i%2){
                if(cur<f){
                    cur=b;
                    res++;
                }
                cur-=f;
            }
            else{
                if(cur<a-f){
                    cur=b;
                    res++;
                }
                cur-=a-f;
            }
        }
        else if(i%2){
            if(cur<f*2){
                cur=b;
                res++;
            }
            cur-=f;
        }
        else{
            if(cur<2*(a-f)){
                cur=b;
                res++;
            }
            cur-=a-f;
        }
        if(cur<0){
            ok=false;
            break;
        }
    }
    if(ok){
        printf("%d\n",res);
    }
    else puts("-1");
}
