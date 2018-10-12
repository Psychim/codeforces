#include<bits/stdc++.h>
using namespace std;
int a[6];
int sum=0;
bool ok;
int main(){
    for(int i=0;i<6;i++){
        scanf("%d",a+i);
        sum+=a[i];
    }
    ok=false;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                int tmp=a[i]+a[j]+a[k];
                if(tmp==sum-tmp) ok=true;
            }
        }
    }
    if(ok)
        puts("YES");
    else puts("NO");
}
