#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int m,n;
struct Node{
    int pos;
    int v;
    int chg;
};
int comp1(const void*a,const void*b){
    Node*pa=(Node*)a;
    Node*pb=(Node*)b;
    return pa->v-pb->v;
}
int comp2(const void*a,const void*b){
    Node*pa=(Node*)a;
    Node*pb=(Node*)b;
    return pa->pos-pb->pos;
}
Node a[maxn];
int b[maxn],bn;
int odn,evn,odchgn,evchgn,chg;
bool bisearch(int s[],int sn,int x){
    if(sn==0) return false;
    static int od=0,ev=0;
    int l=x%2?od:ev,r=sn-1;
    while(l<r){
        int mid=(l+r)/2;
        if(s[mid]<x)
            l=mid+1;
        else r=mid;
    }
    if(x%2)
        od=l;
    else ev=l;
    if(s[l]==x)
        return true;
    else return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].v);
        a[i].pos=i;
        a[i].chg=0;
        if(a[i].v%2)
            odn++;
        else evn++;
    }
    qsort(a,n,sizeof(Node),comp1);
    if(odn>evn)
        odchgn=odn-evn,evchgn=0;
    else evchgn=evn-odn,odchgn=0;
    for(int i=1;i<n;i++){
        if(a[i].v==a[i-1].v){
            if(a[i].v%2){
                if(odchgn>0){
                    odchgn-=2;
                    a[i].chg=2;
                }
                else a[i].chg=1;
            }
            else{
                if(evchgn>0){
                    evchgn-=2;
                    a[i].chg=1;
                }
                else a[i].chg=2;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[i].v%2==0&&evchgn&&!a[i].chg){
            evchgn-=2;
            a[i].chg=1;
        }
        else if(a[i].v%2&&odchgn&&!a[i].chg){
            odchgn-=2;
            a[i].chg=2;
        }
    }
    if(evchgn||odchgn){
        chg=-1;
    }
    else{
        bn=chg=0;
        for(int i=0;i<n;i++){
            if(!a[i].chg){
                b[bn++]=a[i].v;
            }
        }
        sort(b,b+bn);
        int odlast=-1,evlast=0;
        for(int i=0;chg!=-1&&i<n;i++){
            if(a[i].chg==1){
                int j=odlast+2;
                while(j<=m&&bisearch(b,bn,j)) j+=2;
                if(j>m)
                    chg=-1;
                else{
                    a[i].v=j;
                    chg++;
                    odlast=j;
                }
            }
            else if(a[i].chg==2){
                int j=evlast+2;
                while(j<=m&&bisearch(b,bn,j)) j+=2;
                if(j>m)
                    chg=-1;
                else{
                    chg++;
                    a[i].v=j;
                    evlast=j;
                }
            }
        }
    }
    printf("%d\n",chg);
    if(chg!=-1){
        qsort(a,n,sizeof(Node),comp2);
        for(int i=0;i<n;i++)
            printf("%d%c",a[i].v,i==n-1?'\n':' ');
    }
}
