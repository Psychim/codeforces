#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll mod=1e9+7;
char s[maxn];
ll hashval[maxn];
ll rev10;
ll a,b,c;
ll fp(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
class BigInteger{
    private:
        int *d;
        int n;
    public:
        BigInteger(){
            d=new int[maxn];
            memset(d,0,sizeof d);
        }
        ~BigInteger(){
            delete[]d;
        }
        BigInteger(char *s,int len):BigInteger(){
            n=len;
            int i=0;
            for(int j=n-1;j>=0;j--,i++){
                d[i]=s[j]-'0';
            }
        }
        BigInteger operator+(const BigInteger& a) const{
            BigInteger c;
            int maxn=max(n,a.n);
            for(int i=0;i<maxn;i++){
                c.d[i]=a.d[i]+d[i];
            }
            for(int i=0;i<maxn;i++){
                if(c.d[i]/10){
                    c.d[i+1]+=c.d[i]/10;
                    c.d[i]%=10;
                    if(i==maxn-1)
                        maxn++;
                }
            }
            c.n=maxn;
            return c;
        }
        bool operator==(const BigInteger& a)const{
            if(a.n!=n)return false;
            for(int i=0;i<n;i++){
                if(d[i]!=a.d[i])return false;
            }
            return true;
        }
};
void print(int l1,int l2,int l3){
    for(int i=0;i<l1;i++)
        printf("%c",s[i]);
    printf("+");
    for(int i=l1;i<l1+l2;i++)
        printf("%c",s[i]);
    printf("=");
    for(int i=l1+l2;s[i];i++){
        printf("%c",s[i]);
    }
}
bool devide(int l1,int l2,int l3){
    if(l1>0&&l2>0&&l3>0){
        if(l1>1&&s[0]=='0') return false;
        if(l2>1&&s[l1]=='0') return false;
        if(l3>1&&s[l1+l2]=='0') return false;
       // printf("%d %d %d\n",l1,l2,l3);
        a=(hashval[0]-hashval[l1]+mod)%mod*fp(rev10,l2+l3)%mod;
        b=(hashval[l1]-hashval[l1+l2]+mod)%mod*fp(rev10,l3)%mod;
        c=hashval[l1+l2];
        //printf("%I64d %I64d %I64d %I64d\n",a,b,(a+b)%mod,c);
        if((a+b)%mod==c%mod){
            //BigInteger ba(s,l1),bb(s+l1,l2),bc(s+l1+l2,l3);
            //if(bb+ba==bc){
            print(l1,l2,l3);
            return true;
            //}
        }
    }
    return false;
}
int main(){
    scanf("%s",s);
    int n=strlen(s);
    ll j=1;
    hashval[n]=0;
    rev10=fp(10,mod-2);
    //printf("%I64d\n",rev10);
    for(int i=n-1;i>=0;i--,j=j*10%mod){
        hashval[i]=(hashval[i+1]+(ll)(s[i]-'0')*j%mod)%mod;
       // printf("%I64d\n",hashval[i]);
    }
    int l1,l2,l3;
    for(l3=n/3;l3<=n/2;l3++){
        l1=l3;
        l2=n-l3-l1;
        if(devide(l1,l2,l3))
            return 0;
        l1=l3-1;
        l2=n-l1-l3;
        if(devide(l1,l2,l3))
            return 0;
        l2=l3;
        l1=n-l3-l2;
        if(devide(l1,l2,l3))
            return 0;
        l2=l3-1;
        l1=n-l3-l2;
        if(devide(l1,l2,l3))
            return 0;
    }
}
