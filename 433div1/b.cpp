#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxk=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n;
int m;
int k;
struct Flight{
    int d;
    int f;
    int t;
    ll c;
    bool operator<(Flight a){
        if(d!=a.d) return d<a.d;
        if(f!=a.f) return f<a.f;
        if(t!=a.t) return t<a.t;
        return c<a.c;
    }
};
Flight f[maxn];
ll arr[maxk];
ll dep[maxk];
ll sum;
int vcnt;
ll minc[maxn];
bool vis[maxn];
int p;
ll res;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%I64d",&f[i].d,&f[i].f,&f[i].t,&f[i].c);
    }
    sort(f,f+m);
    memset(vis,0,sizeof vis);
    sum=0;
    vcnt=0;
    p=0;
    for(int i=1;i<=1e6;i++){
        for(;p<m&&f[p].d<=i;p++){
            if(f[p].f==0) continue;
            if(!vis[f[p].f]){
                vis[f[p].f]=1;
                minc[f[p].f]=f[p].c;
                sum+=f[p].c;
                vcnt++;
            }
            else{
                if(f[p].c<minc[f[p].f]){
                    sum+=f[p].c-minc[f[p].f];
                    minc[f[p].f]=f[p].c;
                }
            }
        }
        if(vcnt==n){
            arr[i]=sum;
        }
        else arr[i]=-1;
    }
    sum=0;
    vcnt=0;
    memset(vis,0,sizeof vis);
    p=m-1;
    for(int i=1e6;i>0;i--){
        for(;p>=0&&f[p].d>=i;p--){
            if(f[p].t==0) continue;
            if(!vis[f[p].t]){
                vis[f[p].t]=1;
                minc[f[p].t]=f[p].c;
                sum+=f[p].c;
                vcnt++;
            }
            else{
                if(f[p].c<minc[f[p].t]){
                    sum+=f[p].c-minc[f[p].t];
                    minc[f[p].t]=f[p].c;
                }
            }
        }
        if(vcnt==n){
            dep[i]=sum;
        }
        else dep[i]=-1;
    }
    res=inf;
    for(int i=1;i<=1e6;i++){
        if(arr[i]==-1) continue;
        if(i+k+1>1e6||dep[i+k+1]==-1) break;
        res=min(res,arr[i]+dep[i+k+1]);
    }
    printf("%I64d",res==inf?-1:res);
}
