
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int q;
int BIT[maxn];
int p[maxn];
struct Query{
    int l,d,r,u;
    int i;
};
bool complft(Query a,Query b){
    return a.l<b.l;
}
bool compr(Query a,Query b){
    return a.r>b.r;
}
Query que[maxn];
long long  res[maxn];
void add(int x){for(;x<=n;x+=x&-x)BIT[x]++;}
int query(int x){int s=0;for(;x;x-=x&-x)s+=BIT[x];return s;}
long long c2(long long  x){
    return x*(x-1)/2;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",p+i);
    }
    for(int i=0;i<q;i++){
        scanf("%d%d%d%d",&que[i].l,&que[i].d,&que[i].r,&que[i].u);
        que[i].i=i;
        res[i]=c2(n)-c2(que[i].l-1)-c2(que[i].d-1)-c2(n-que[i].r)-c2(n-que[i].u);
    }
    sort(que,que+q,complft);
    memset(BIT,0,sizeof BIT);
    int r=1;
    for(int i=0;i<q;i++){
        while(r<que[i].l){
            add(p[r++]);
        }
        res[que[i].i]+=c2(query(que[i].d-1))+c2(query(n)-query(que[i].u));
    }
    memset(BIT,0,sizeof BIT);
    r=n;
    sort(que,que+q,compr);
    for(int i=0;i<q;i++){
        while(r>que[i].r){
            add(p[r--]);
        }
        res[que[i].i]+=c2(query(que[i].d-1))+c2(query(n)-query(que[i].u));
    }
    for(int i=0;i<q;i++){
        printf("%I64d\n",res[i]);
    }
}
