#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    if(m>=5){
        puts("YES");
        for(int i=1;i<=n;i++){
            int l=(i-1)*m+1;
            int r=i*m;
            if(i%2){
                for(int j=l;j<=r;j+=2){
                    printf("%d ",j);
                }
                for(int j=l+1;j<=r;j+=2){
                    printf("%d ",j);
                }
            }
            else{
                for(int j=l+1;j<=r;j+=2){
                    printf("%d ",j);
                }
                for(int j=l;j<=r;j+=2){
                    printf("%d ",j);
                }
            }
            puts("");
        }
    }
    else if(m==4){
        puts("YES");
        int l=1,r=n%2?n-1:n;
        int lp=1,rp=-1;
        for(int i=1;i<=n;i++){
            printf("%d %d \n",1+(l-1)*m,2+(r-1)*m);
            l+=2*lp;
            r+=2*rp;
            if(l>n||l<1){
                l=n%2?n-1:n;
                lp=-1;
            }
            if(r>n||r<1){
                r=1;
                rp=1;
            }
        }
    }
    else puts("NO");
}
