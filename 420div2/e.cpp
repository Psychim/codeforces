#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=110;
const ll maxk=1e18+10;
const int maxc=16;
ll a[maxn];
ll b[maxn];
int c[maxn];
int n;
ll k;
struct Matrix{
    ll value[maxc][maxc];
    int r,c;
    Matrix(int pr=0,int pc=0){
        r=pr;c=pc;
        memset(value,0,sizeof value);
    }
    Matrix operator*(Matrix op){
        Matrix res(r,op.c);
        for(int i=0;i<res.r;i++){
            for(int j=0;j<res.c;j++){
                res.value[i][j]=0;
                for(int k=0;k<c;k++){
                    res.value[i][j]+=value[i][k]*op.value[k][j]%mod;
                    res.value[i][j]%=mod;
                }
            }
        }
        return res;
    }
    Matrix pow(ll p){
        Matrix a=*this;
        Matrix res(r,c);
        for(int i=0;i<res.r;i++){
            res.value[i][i]=1;
        }
        while(p){
            if(p&1){
                res=res*a;
                //res.print();
            }
            a=a*a;
            p>>=1;
        }
        return res;
    }
    void print(){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%I64d ",value[i][j]);
            }
            puts("");
        }
    }
};
int main(){
    scanf("%d%I64d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d%d",a+i,b+i,c+i);
    Matrix m1(c[0]+1,1);
    m1.value[0][0]=1;
    for(int i=0;i<n;i++){
        //m1.print();
        Matrix trans(c[i]+1,c[i]+1);
        for(int j=0;j<trans.r;j++){
            for(int k=j-1;k<=j+1;k++){
                if(k>=0&&k<trans.r)
                    trans.value[j][k]=1;
            }
        }
        //trans.print();
        ll mov=min(b[i]-a[i],k-a[i]);
        m1=trans.pow(mov)*m1;
        if(i<n-1){
            Matrix m2(c[i+1]+1,1);
            for(int j=0;j<m2.r;j++){
                m2.value[j][0]=m1.value[j][0];
            }
            m1=m2;
        }
    }
    printf("%I64d\n",m1.value[0][0]);
}
