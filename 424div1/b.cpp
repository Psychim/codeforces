#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int a[maxn];
int n;
int last;
struct Card{
    int a,i;
    Card(int pa=0,int pi=0):a(pa),i(pi){}
    int dis(int cur){
        if(i<cur)return n-cur+i;
        else return i-cur;
    }
    bool operator<(Card c){
        if(a!=c.a)
            return a<c.a;
        else return dis(last)<c.dis(last);
    }
};
Card c[maxn];

int v[maxn*4];
int bn;
Card buf[maxn];
void update(int i,int l,int r,int p,int k){
    if(p==l&&p==r){
        v[i]+=k;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid)
        update(2*i+1,l,mid,p,k);
    else update(2*i+2,mid+1,r,p,k);
    v[i]=v[2*i+1]+v[2*i+2];
}
int query(int i,int l,int r,int ll,int rr){
    //printf("%d %d %d %d\n",l,r,ll,rr);
    if(rr<l||ll>r) return 0;
    if(ll<=l&&rr>=r){
        return v[i];
    }
    int mid=(l+r)/2;
    return query(2*i+1,l,mid,ll,rr)+query(2*i+2,mid+1,r,ll,rr);
}
ll res;
int main(){
    scanf("%d",&n);
    memset(v,0,sizeof v);
    last=0;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        c[i]=Card(a[i],i);
        update(0,0,n-1,i,1);
    }
    sort(c,c+n);

    for(int i=0;i<n;){
        //printf("%d %d\n",last,c[i].i);
        buf[0]=c[i++];
        bn=1;
        while(i<n&&c[i].a==buf[0].a){
            buf[bn++]=c[i++];
        }
        sort(buf,buf+bn);
        for(int j=0;j<bn;j++){
            //printf("%d %d\n",buf[j].a,buf[j].i);
            if(buf[j].i<last){
                res+=query(0,0,n-1,last,n-1);
                res+=query(0,0,n-1,0,buf[j].i);
            }
            else{
                res+=query(0,0,n-1,last,buf[j].i);
            }
            last=buf[j].i;
            update(0,0,n-1,buf[j].i,-1);
        }
    }
    printf("%I64d",res);
}
