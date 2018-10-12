#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int v[maxn];
int t[maxn];
int n;
int sum[maxn*4];
int minv[maxn*4],maxv[maxn*4];
bool setv[maxn*4];
int subv[maxn*4];
void build(int i,int l,int r){
    if(l>r) return;
    if(l==r){
        sum[i]=minv[i]=maxv[i]=v[l];
        setv[i]=subv[i]=0;
        return;
    }
    int mid=(l+r)/2,li=2*i+1,ri=2*i+2;
    build(li,l,mid);
    build(ri,mid+1,r);
    sum[i]=sum[li]+sum[ri];
    minv[i]=min(minv[li],minv[ri]);
    maxv[i]=max(maxv[li],maxv[ri]);
    setv[i]=subv[i]=0;
}
void pushdown(int i,int l,int r){
    if(l>r) return;
    int li=2*i+1,ri=2*i+2;
    if(setv[i]){
        sum[i]=0;
        minv[i]=maxv[i]=0;
        setv[li]=setv[ri]=setv[i];
        subv[li]=subv[ri]=0;
        setv[i]=0;
    }
    else if(subv[i]){
        sum[i]-=(r-l+1)*subv[i];
        minv[i]-=subv[i];
        maxv[i]-=subv[i];
        subv[li]+=subv[i];
        subv[ri]+=subv[i];
        subv[i]=0;
    }
}
void update(int i,int l,int r,int ll,int rr,int v){
    int mid=(l+r)/2,li=2*i+1,ri=2*i+2;
    if(r<ll||l>rr||l>r) return;
    pushdown(i,l,r);
    if(l>=ll&&r<=rr){
        if(minv[i]>=v){
            subv[i]+=v;
            pushdown(i,l,r);
            return;
        }
        else if(maxv[i]<=v){
            setv[i]=true;
            subv[i]=0;
            pushdown(i,l,r);
            return;
        }
    }
    if(ll<=mid)
        update(li,l,mid,ll,rr,v);
    if(rr>mid)
        update(ri,mid+1,r,ll,rr,v);
    sum[i]=sum[li]+sum[ri];
    minv[i]=min(minv[li],minv[ri]);
    maxv[i]=max(maxv[li],maxv[ri]);
    setv[i]=subv[i]=0;
}
long long query(int i,int l,int r,int ll,int rr){
    if(l>r) return 0;
    pushdown(i,l,r);
    int mid=(l+r)/2,li=2*i+1,ri=2*i+2;
    if(r<ll||l>rr) return 0;
    if(l>=ll&&r<=rr){
        return sum[i];
    }
    long long res=0;
    if(ll<=mid)
        res+=query(li,l,mid,ll,rr);
    if(r>mid)
        res+=query(ri,mid+1,r,ll,rr);
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
    }
    build(0,0,n-1);
    for(int i=0;i<n;i++){
        scanf("%d",t+i);
        ll before=query(0,0,n-1,0,i);
        update(0,0,n-1,0,i,t[i]);
        ll after=query(0,0,n-1,0,i);
        printf("%I64d ",before-after);
    }
}
