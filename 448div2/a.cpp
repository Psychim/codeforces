#include<bits/stdc++.h>
using namespace std;
const int maxn=400;
int n;
int a[maxn];
int res;
int tmp;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    res=360;
    for(int l=0;l<n;l++){
        tmp=a[l];
        int r=l;
        while(tmp+a[(r+1)%n]<=180){
            tmp+=a[(r+1)%n];
            r=(r+1)%n;
        }
        res=min(res,abs(360-2*tmp));
    }
    printf("%d",res);
}
