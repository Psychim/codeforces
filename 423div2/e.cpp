#include<bits/stdc++.h>
using namespace std;
const int maxs=1e5+1;
const int maxe=11;
int t[4][maxe][maxe][(1<<18)-1];
char s[maxs];
int q,ns;
map<char,int> mp;
void update(int l,int r,int si,int p,int v,int i,int j,int k){
    if(l==r&&l==p){
        t[i][j][k][si]=v;
        return;
    }
    int mid=(l+r)/2;
    int li=2*si+1,ri=2*si+2;
    if(p<=mid)
        update(l,mid,li,p,v,i,j,k);
    else update(mid+1,r,ri,p,v,i,j,k);
    t[i][j][k][si]=t[i][j][k][li]+t[i][j][k][ri];
    //printf("%d\n",t[i][j][k][si]);
}
int query(int l,int r,int si,int a,int b,int i,int j,int k){
    if(a<=l&&b>=r){
        return t[i][j][k][si];
    }
    int mid=(l+r)/2;
    int li=2*si+1,ri=2*si+2;
    int res=0;
    if(a<=mid)
        res+=query(l,mid,li,a,b,i,j,k);
    if(b>mid)
        res+=query(mid+1,r,ri,a,b,i,j,k);
    return res;
}
int main(){
    mp['A']=0;
    mp['G']=1;
    mp['T']=2;
    mp['C']=3;
    memset(t,0,sizeof t);
    scanf("%s",s+1);
    ns=strlen(s+1);
    for(int j=1;j<maxe;j++){
        for(int i=1;i<=ns;i++){
            update(1,ns,0,i,1,mp[s[i]],j,i%j);
        }
    }
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            char c;
            scanf("%d %c",&x,&c);
            for(int j=1;j<maxe;j++){
                update(1,ns,0,x,0,mp[s[x]],j,x%j);
                update(1,ns,0,x,1,mp[c],j,x%j);
            }
            s[x]=c;
        }
        else{
            int l,r;
            char e[maxe];
            scanf("%d %d %s",&l,&r,e);
            int res=0;
            int j=strlen(e);
            for(int m=0;m<j;m++){
                res+=query(1,ns,0,l,r,mp[e[m]],j,(l+m)%j);
            }
            printf("%d\n",res);
        }
    }
}
