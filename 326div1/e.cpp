#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=2e5;
int n,q;
int a[maxn];
struct Node{
    int bas[32];
    int lazy;
    int val;
    Node(){lazy=val=0;memset(bas,0,sizeof bas);}
};
Node t[4*maxn];
void calbas(int bas[],int val[],int len){
    for(int i=0;i<len;i++){
        int p=val[i];
        for(int bit=31;bit>=0;bit--){
            if(p&(1<<bit)){
                if(bas[bit]){
                    p=p^bas[bit];
                }
                else{
                    bas[bit]=p;
                    break;
                }
            }
        }
    }
}
void build(int l,int r,int i){
    if(l==r){
        t[i].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    int lc=2*i+1;
    int rc=2*i+2;
    build(l,mid,lc);
    build(mid+1,r,rc);
    calbas(t[i].bas,t[lc].bas,32);
    calbas(t[i].bas,t[rc].bas,32);
    int newv=t[lc].val^t[rc].val;
    calbas(t[i].bas,&newv,1);
    t[i].val=t[lc].val;
}
void pushdown(int i){
    if(t[i].lazy){
        int lc=2*i+1;
        int rc=2*i+2;
        t[lc].lazy^=t[i].lazy;
        t[rc].lazy^=t[i].lazy;
        t[lc].val^=t[i].lazy;
        t[rc].val^=t[i].lazy;
        t[i].lazy=0;
    }
}
int ans[32];
void query(int l,int r,int i,int a,int b){
    if(a<=l&&b>=r){
        calbas(ans,t[i].bas,32);
        calbas(ans,&t[i].val,1);

        return;
    }
    pushdown(i);
    int mid=(l+r)/2;
    int bas1[32],bas2[32];
    memset(bas1,0,sizeof bas1);
    memset(bas2,0,sizeof bas2);
    if(a<=mid){
        query(l,mid,2*i+1,a,b);
    }
    if(b>mid){
        query(mid+1,r,2*i+2,a,b);
    }
}
void update(int l,int r,int i,int a,int b,int k){
    if(a<=l&&b>=r){
        t[i].lazy^=k;
        t[i].val^=k;
        return;
    }
    pushdown(i);
    int mid=(l+r)/2;
    int lc=2*i+1;
    int rc=2*i+2;
    if(a<=mid)
        update(l,mid,lc,a,b,k);
    if(b>mid)
        update(mid+1,r,rc,a,b,k);
    memset(t[i].bas,0,sizeof t[i].bas);
    calbas(t[i].bas,t[lc].bas,32);
    calbas(t[i].bas,t[rc].bas,32);
    int newv=t[lc].val^t[rc].val;
    calbas(t[i].bas,&newv,1);
    t[i].val=t[lc].val;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    build(0,n-1,0);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==2){
            int l,r;
            scanf("%d%d",&l,&r);
            ll res;
            memset(ans,0,sizeof ans);
            query(0,n-1,0,l-1,r-1);
            int cnt=0;
            for(int i=0;i<32;i++){
                if(ans[i])
                    cnt++;
            }
            res=1LL<<cnt;
            cout<<res<<endl;
        }
        else{
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            update(0,n-1,0,l-1,r-1,k);
        }
    }
}
