#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,k;
int a[maxn];
int open[maxn];
int cnt;
int res;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        open[i]=1;
    }
    sort(a,a+n);
    cnt=1;
    res=0;
    int al=0,ar=0;
    for(int l=1;l+m-1<=1e6;l++){
        while(true){
            if(al<n&&a[al]<l){
                cnt-=open[al];
                al++;
            }
            else if(ar+1<n&&a[ar+1]<=l+m-1){
                cnt+=open[ar+1];
                ar++;
            }
            else break;
        }
        int i=ar;
        while(cnt>=k){
            while(!open[i]){
                i--;
            }
            open[i]=0;
            cnt--;
            res++;
        }
    }
    printf("%d",res);
}
