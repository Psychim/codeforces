#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n;
int a[maxn];
int res;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<n-1;i++){
        if(a[i]<a[i-1]&&a[i]<a[i+1]) res++;
        if(a[i]>a[i-1]&&a[i]>a[i+1]) res++;
    }
    printf("%d",res);
}
