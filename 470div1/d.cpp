#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[maxn],t[maxn];
int sn[maxn],tn[maxn];
int ls,lt;
int q;
int a,b,c,d;
int main(){
    scanf("%s",s+1);
    scanf("%s",t+1);
    ls=strlen(s+1);
    lt=strlen(t+1);
    for(int i=1;i<=ls;i++){
        if(s[i]!='A')
            sn[i]++;
    }
    for(int i=1;i<=ls;i++)
        sn[i]+=sn[i-1];
    for(int i=1;i<=lt;i++){
        if(t[i]!='A')
            tn[i]++;
    }
    for(int i=1;i<=lt;i++)
        tn[i]+=tn[i-1];
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int ds=sn[b]-sn[a-1];
        int dt=tn[d]-tn[c-1];
        if(dt>0){
            if(dt-ds>=0&&(dt-ds)%2==0)
                printf("1");
            else printf("0");
        }
        else{
            if(b-a>=d-c&&(b-a-d+c)%3==0)
                printf("1");
            else printf("0");
        }
    }
}
