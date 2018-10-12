#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];
int pos[maxn];
int seg[maxn*4];
int rev[maxn];
int domi[maxn];
void add(int i,int l,int r,int p){
    if(l>r||p<l||p>r)return;
    if(l==r&&l==p){
        seg[i]++;
        return;
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    add(li,l,mid,p);
    add(ri,mid+1,r,p);
    seg[i]=seg[li]+seg[ri];
}
int query(int i,int l,int r,int a,int b){
    if(b<l||a>r||l>r) return 0;
    if(a<=l&&b>=r){
        return seg[i];
    }
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    return query(li,l,mid,a,b)+query(ri,mid+1,r,a,b);
}
int finde(int i,int l,int r,int a,int b){
    if(b<l||a>r||l>r||seg[i]==0)return 0;
    if(l==r) return l;
    int mid=(l+r)/2;
    int li=2*i+1,ri=2*i+2;
    int le=finde(li,l,mid,a,b);
    int re=finde(ri,mid+1,r,a,b);
    return max(le,re);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==n){
            rev[a[i]]=0;
        }
        else rev[a[i]]=query(0,1,n,a[i]+1,n);
        if(rev[a[i]]==1){
            int e=finde(0,1,n,a[i]+1,n);
            domi[e]++;
        }
        add(0,1,n,a[i]);
    }
    int who=1;
    int contri=domi[1]-(rev[1]==0);
    for(int i=1;i<=n;i++){
        int tmp=domi[i]-(rev[i]==0);
        if(tmp>contri){
            contri=tmp;
            who=i;
        }
    }
    printf("%d",who);
}
