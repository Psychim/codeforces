#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=5e5+10;
int a[maxn];
int v[maxn<<4];
int q,com,x,y,z,n;
int gcd(int a,int b){
    if(b)return gcd(b,a%b);
    return a;
}
void build(int i,int l,int r){
    if(l>r) return;
    if(l==r){
        v[i]=a[l];
        return;
    }
    int mid=(l+r)>>1,li=2*i+1,ri=2*i+2;
    build(li,l,mid);
    build(ri,mid+1,r);
    v[i]=gcd(v[li],v[ri]);
}
void modify(int i,int l,int r,int p,int x){
    if(l>r||r<p||l>p)return;
    if(l==p&&p==r){
        v[i]=a[l]=x;
        return;
    }
    int mid=(l+r)>>1,li=2*i+1,ri=2*i+2;
    modify(li,l,mid,p,x);
    modify(ri,mid+1,r,p,x);
    v[i]=gcd(v[li],v[ri]);
}
pii query(int i,int l,int r,int ll,int rr,int x){
    int mid=(l+r)>>1,li=2*i+1,ri=2*i+2;
    if(l>=ll&&r<=rr){
        if(v[i]%x){
            if(l==r){
                return make_pair(1,x);
            }
            else{
                pii tmp1=query(li,l,mid,ll,rr,x);
                if(tmp1.first>1)
                    return tmp1;
                pii tmp2=query(ri,mid+1,r,ll,rr,x);
                return make_pair(tmp1.first+tmp2.first,gcd(tmp1.second,tmp2.second));
            }
        }
        else{
            return make_pair(0,v[i]);
        }
    }
    else{
        pii tmp1(0,0),tmp2(0,0);
        if(ll<=mid)
            tmp1=query(li,l,mid,ll,rr,x);
        if(tmp1.first>1)
            return tmp1;
        if(rr>mid)
            tmp2=query(ri,mid+1,r,ll,rr,x);
        return make_pair(tmp1.first+tmp2.first,gcd(tmp1.second,tmp2.second));
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    scanf("%d",&q);
    build(0,0,n-1);
    while(q--){
        scanf("%d",&com);
        if(com==1){
            scanf("%d%d%d",&x,&y,&z);
            pii res=query(0,0,n-1,x-1,y-1,z);
            if(res.second%z==0&&res.second!=z){
                res.second=z;
                ++res.first;
            }
            if(res.first<=1&&res.second==z){
                puts("YES");
            }
            else puts("NO");
        }
        else{
            scanf("%d%d",&x,&y);
            modify(0,0,n-1,x-1,y);
        }
    }
}
