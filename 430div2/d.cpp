#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,m,x,tmpx;
int a[maxn];
int res;
int getbit(int num,int pos){
    return (num>>pos)&1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    x=0;
    while(m--){
        scanf("%d",&tmpx);
        x^=tmpx;
        res=0;
        int l=0,r=n-1;
        for(int bit=31;bit>=0;bit--){
            int tmp=getbit(x,bit);
            if(getbit(a[l],bit)==getbit(a[r],bit)){
                if(getbit(a[l],bit)!=tmp)
                    res+=tmp<<bit;
            }
            else{
                int tl=l,tr=r;
                while(tl<tr){
                    int mid=(tl+tr)/2;
                    if(getbit(a[mid],bit))
                        tr=mid;
                    else tl=mid+1;
                }
                if(tmp)
                    l=tl;
                else r=tl-1;
            }
        }
        printf("%d\n",res);
    }
}
