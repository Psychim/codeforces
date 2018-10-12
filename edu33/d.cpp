#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll maxd=1e9+10;
int a[maxn];
int n;
ll d;
ll cur;
bool ok;
ll mx[maxn];
ll saved;
int res;
int main(){
    scanf("%d%I64d",&n,&d);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    cur=0;
    ok=true;
    for(int i=0;i<n;i++){
        cur+=a[i];
        mx[i]=d-cur;
    }
    for(int i=n-2;i>=0;i--){
        mx[i]=min(mx[i],mx[i+1]);
    }
//    for(int i=0;i<n;i++){
//        printf("%I64d ",mx[i]);
//    }
//    puts("");
    saved=0;
    res=0;
    cur=0;
    for(int i=0;ok&&i<n;i++){
        cur+=a[i];
        if(cur>d) ok=false;
        if(a[i]==0&&cur<0){
            cur+=mx[i]-saved;
            saved=mx[i];
            res++;
            if(cur<0){
                ok=false;
            }
        }

        //printf("%I64d %I64d\n",cur,saved);
    }
    if(ok){
        printf("%d",res);
    }
    else puts("-1");
}
