#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5e4+10;
int n,a,b;
bool ok;
int gcd(int a,int b){
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        ok=1;
        int g=gcd(a,b);
        ll tmp1=a*1LL*b;
        ll tmp2=pow(tmp1*1.,1./3)+1e-6;
        //printf("%I64d %I64d\n",tmp1,tmp2);
        if(tmp2*tmp2*tmp2!=tmp1)
            ok=0;
        for(int i=2;ok&&i<=g;i++){
            int c=0,d=0,e,f;
            if(g%i) continue;
            while(g%i==0)g/=i;
            while(a%i==0){
                c++;
                a/=i;
            }
            while(b%i==0){
                d++;
                b/=i;
            }
            if(c>d) swap(c,d);
            if((2*d-c)%3==0){
                f=(2*d-c)/3;
                e=d-2*f;
                if(e<0)
                    ok=0;
            }
            else ok=0;
        }
        if(a!=b)
            ok=0;
        if(ok)
            puts("YES");
        else puts("NO");
    }
}
