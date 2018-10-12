#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1<<17)+10;
int k;
int n,q;
int t;
int a[maxn];
int _min[maxn<<2];
int _max[maxn<<2];
void build(int l,int r,int i){
    if(l==r){
        _min[i]=a[l];
        _max[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*i+1);
    build(mid+1,r,2*i+2);
    _min[i]=min(_min[2*i+1],_min[2*i+2]);
    _max[i]=max(_max[2*i+1],_max[2*i+2]);
}
void update(int l,int r,int i,int p,int key){
    if(p==l&&p==r){
        _min[i]=key;
        _max[i]=key;
        return;
    }
    int mid=(l+r)>>1;
    int li=2*i+1,ri=2*i+2;
    if(p<=mid){
        update(l,mid,li,p,key);
    }
    else if(p>mid){
        update(mid+1,r,ri,p,key);
    }
    _min[i]=min(_min[li],_min[ri]);
    _max[i]=max(_max[li],_max[ri]);
}
int querymin(int l,int r,int i,int a,int b){
    if(a<=l&&b>=r){
        return _min[i];
    }
    int mid=(l+r)>>1;
    int li=2*i+1,ri=2*i+2;
    int res=(1<<k);
    if(a<=mid){
        res=min(res,querymin(l,mid,li,a,b));
    }
    if(b>mid){
        res=min(res,querymin(mid+1,r,ri,a,b));
    }
    return res;
}
int querymax(int l,int r,int i,int a,int b){
    if(a<=l&&b>=r){
        return _max[i];
    }
    int mid=(l+r)>>1;
    int li=2*i+1,ri=2*i+2;
    int res=-(1<<k);
    if(a<=mid){
        res=max(res,querymax(l,mid,li,a,b));
    }
    if(b>mid){
        res=max(res,querymax(mid+1,r,ri,a,b));
    }
    return res;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        n=1<<k;
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }
        scanf("%d",&q);
        build(0,n-1,0);
        int com,x,y;
        while(q--){
            scanf("%d%d%d",&com,&x,&y);
            if(com==1){
                ll res;
                ll tmp1=querymin(0,n-1,0,x,y);
                ll tmp2=querymax(0,n-1,0,x,y);
                if(tmp1>=0){
                    res=tmp1*tmp1;
                }
                else if(tmp1<0){
                    if(tmp2<=0){
                        res=tmp2*tmp2;
                    }
                    else{
                        res=tmp2*tmp1;
                    }
                }
                printf("%lld\n",res);
            }
            else if(com==2){
                update(0,n-1,0,x,y);
            }
        }
    }
}
