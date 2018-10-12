#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int v[maxn];
int t[maxn];
int node[maxn];
int lc[maxn];
int rc[maxn];
int sum[maxn];
int minv[maxn];
int maxv[maxn];
int sz;
void add(int key,int i){
    if(!~node[i]){
        node[i]=key;
        sum[i]=minv[i]=maxv[i]=node[i];
        sz++;
        return;
    }
    else{
        if(key<=node[i]){
            if(!~lc[i]){
                lc[i]=sz;
            }
            add(key,lc[i]);
        }
        else{
            if(!~rc[i]){
                rc[i]=sz;
            }
            add(key,rc[i]);
        }
        sum[i]=sum[lc[i]]+sum[rc[i]]+node[i];
        minv[i]=min(minv[lc[i]],minv[rc[i]]);
        maxv[i]=max(maxv[lc[i]],maxv[rc[i]]);
        minv[i]=min(minv[i],node[i]);
        maxv[i]=max(maxv[i],node[i]);
    }
}
void update(int val,int i){
    if(!~node[i]) return;
    if(val<node[i]){
        if(!~lc[i])
            update(val,lc[i]);

    }
    else if(val>=node[i]){
        if(!~lc[i])
            update(val,lc[i]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",t+i);
    }
    memset(node,-1,sizeof(node));
    memset(lc,-1,sizeof(lc));
    memset(rc,-1,sizeof(rc));
    sz=0;
    for(int i=0;i<n;i++){
        add(v[i],0);
        ll before=sum[0];
        update(t[i],0);
        ll after=sum[0];
        printf("%I64d ",before-after);
    }
}
