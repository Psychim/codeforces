#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    if(a[0]==a[n-1]-1||a[0]==a[n-1]){
        printf("%d\n",n);
    }
    else{
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[n-1-i]-2)
                cnt1++;
            else break;
        }
        for(int i=0;i<n;i++){
            if(a[i]==a[0]+1) cnt2++;
        }
        cnt2=cnt2/2*2;
        if(cnt1*2>cnt2){
            int tmp=a[0]+1;
            for(int i=0;i<cnt1;i++){
                a[i]=a[n-1-i]=tmp;
            }
            printf("%d\n",n-cnt1*2);
        }
        else{
            int tmp=1;
            int j=0;
            for(int i=0;i<n&&j<cnt2;i++){
                if(a[i]==a[0]+1){
                    a[i]+=tmp;
                    tmp=-tmp;
                    j++;
                }
            }
            printf("%d\n",n-cnt2);
        }
    }
    for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
}
