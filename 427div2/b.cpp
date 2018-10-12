#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char d[maxn];
int k;
int dif[10];
int main(){
    scanf("%d",&k);
    scanf("%s",d);
    memset(dif,0,sizeof dif);
    int sum=0;
    for(int i=0;d[i];i++){
        sum+=d[i]-'0';
        dif['9'-d[i]]++;
    }
    int res=0;
    for(int i=9;i&&sum<k;i--){
        int need=(k-sum)/i+1;
        need=min(need,dif[i]);
        k-=need*i;
        res+=need;
    }
    printf("%d\n",res);
}
