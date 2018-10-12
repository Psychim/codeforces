#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int l[maxn];
int seg[maxn*4];
int flag[maxn*4];
void pushdown(int i,int l,int r){
    int li=2*i+1,ri=2*i+2;
    if(flag[i]){
        flag[li]=flag[ri]=1;
        seg[li]=seg[ri]=0;
        flag[i]=0;
    }
}
void kill(int i,int l,int r,int a,int b){
    pushdown(i,l,r);
    if(b<l||a>r) return;
    if(a<=l&&b>=r){
        flag[i]=1;
        seg[i]=0;
        return;
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    kill(li,l,mid,a,b);
    kill(ri,mid+1,r,a,b);
    seg[i]=seg[li]+seg[ri];
}
void build(int i,int l,int r){
    if(l>r) return;
    if(l==r){
        seg[i]=1;
        return;
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    build(li,l,mid);
    build(ri,mid+1,r);
    seg[i]=seg[li]+seg[ri];
    return;
}
int query(int i,int l,int r,int a,int b){
    pushdown(i,l,r);
    if(b<l||a>r) return 0;
    if(a<=l&&b>=r){
        return seg[i];
    }
    int mid=(l+r)/2;
    return query(2*i+1,l,mid,a,b)+query(2*i+2,mid+1,r,a,b);
}
int main(){
    scanf("%d",&n);
    build(0,0,n-1);
    for(int i=0;i<n;i++){
        scanf("%d",l+i);
        kill(0,0,n-1,max(0,i-l[i]),i-1);
    }
    printf("%d",query(0,0,n-1,0,n-1));
}
