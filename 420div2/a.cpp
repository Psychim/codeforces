#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int n;
int g[maxn][maxn];
int sorted[maxn*2][maxn];
bool bisearch(int x,int a[],int n){
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r)/2;
        if(a[m]==x)
            return true;
        else if(a[m]<x)
            l=m+1;
        else r=m;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            sorted[i][j]=g[i][j];
        sort(sorted[i],sorted[i]+n);
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            sorted[n+j][i]=g[i][j];
        }
        sort(sorted[n+j],sorted[n+j]+n);
    }
    bool ok=true;
    for(int i=0;i<n&&ok;i++){
        for(int j=0;j<n&&ok;j++){
            int d=g[i][j];
            if(d>1){
                ok=false;
                for(int k=0;k<n&&sorted[i][k]<d;k++){
                    if(bisearch(d-sorted[i][k],sorted[n+j],n)){
                        ok=true;
                        break;
                    }
                }
            }
        }
    }
    if(ok){
        puts("Yes");
    }
    else puts("No");
}
