#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
struct Pile{
    ll a;
    ll tosq,tonsq;
    bool operator<(Pile a) const{
        return tosq-tonsq<a.tosq-a.tonsq;
    }
};
Pile p[maxn];
bool issq(ll x){
    ll sx=sqrt(x);
    return sx*sx==x;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%I64d",&p[i].a);
        if(issq(p[i].a)){
            p[i].tosq=0;
            p[i].tonsq=(p[i].a==0?2:1);
        }
        else{
            ll sx=sqrt(p[i].a);
            p[i].tosq=min(abs(sx*sx-p[i].a),abs((sx+1)*(sx+1)-p[i].a));
            p[i].tonsq=0;
        }
    }
    sort(p,p+n);
    ll res=0;
    for(int i=0;i<n/2;i++){
        res+=p[i].tosq;
    }
    for(int i=n/2;i<n;i++){
        res+=p[i].tonsq;
    }
    printf("%I64d",res);
}
