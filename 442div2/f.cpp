#include<bits/stdc++.h>
#include<hash_map>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxq=1e5+10;
int n;
ll k;
ll a[maxn];
int q;
int t[maxn];
int l;
int r;
ll sum[maxn];
int sn;
struct Query{
    int l,r,i;
    ll res;
    Query(int pl=0,int pr=0,int pi=0):l(pl),r(pr),i(pi){res=0;}
    bool operator<(Query a){
        if(l/sn!=a.l/sn) return l/sn<a.l/sn;
        return r<a.r;
    }
};

Query qs[maxq];
int in;
int index[maxn],il[maxn],ir[maxn];
int cnt[4*maxn];
map<ll,int> imap;
ll cur;
ll res[maxq];
int main(){
    scanf("%d%I64d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",t+i);
    for(int i=1;i<=n;i++){
        scanf("%I64d",a+i);
        if(t[i]==2)
            a[i]=-a[i];
    }
    sum[0]=0;
    in=0;
    for(int i=0;i<=n;i++){
        if(i>0) sum[i]=sum[i-1]+a[i];
        if(!imap.count(sum[i]))
           imap[sum[i]]=in++;
        index[i]=imap[sum[i]];
        if(!imap.count(sum[i]-k))
            imap[sum[i]-k]=in++;
        il[i]=imap[sum[i]-k];
        if(!imap.count(sum[i]+k))
            imap[sum[i]+k]=in++;
        ir[i]=imap[sum[i]+k];
    }
    scanf("%d",&q);
    sn=sqrt(n);
    for(int i=0;i<q;i++){
        scanf("%d%d",&l,&r);
        qs[i]=Query(l,r,i);
    }
    sort(qs,qs+q);
    l=0;
    r=0;
    cur=0;
    cnt[index[0]]++;
    for(int i=0;i<q;i++){
        //printf("query %d %d\n",qs[i].l,qs[i].r);
        while(l!=qs[i].l-1||r!=qs[i].r){
            if(r<qs[i].r){
                //printf("r %d->%d +%d\n",r,r+1,cnt[sum[r+1]-k]);
                r++;
                cur+=cnt[il[r]];
                cnt[index[r]]++;
            }
            else if(r>qs[i].r){
               // printf("r %d->%d -%d\n",r,r-1,cnt[sum[r]-k]);
                cnt[index[r]]--;
                cur-=cnt[il[r]];
                r--;
            }
            else if(l>qs[i].l-1){
                //printf("l %d->%d +%d\n",l,l-1,cnt[sum[l-1]+k]);
                l--;
                cur+=cnt[ir[l]];
                cnt[index[l]]++;
            }
            else if(l<qs[i].l-1){
                //printf("l %d->%d -%d\n",l,l+1,cnt[sum[l]+k]);
                cnt[index[l]]--;
                cur-=cnt[ir[l]];
                l++;
            }
        }
        qs[i].res=cur;
    }
    for(int i=0;i<q;i++){
        res[qs[i].i]=qs[i].res;
    }
    for(int i=0;i<q;i++){
        printf("%I64d\n",res[i]);
    }
}
