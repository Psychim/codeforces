#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
int n,x;
struct Node{
    int l,r,cost;
    Node(int pl=0,int pr=0,int pc=0){
        l=pl;r=pr;cost=pc;
    }
    int d(){
        return r-l+1;
    }
    bool operator<(Node a){
        if(d()<a.d())
            return true;
        if(d()==a.d()&&cost<a.cost)
            return true;
        return false;
    }

};
Node p[maxn];
int bisearch(int start,Node& a){
    int l=start+1,r=n-1;
    while(l<r){
        int mid=(l+r)/2;
        if(p[mid].d()<x-a.d())
            l=mid+1;
        else r=mid;
    }
    if(p[l].d()!=x-a.d()) return -1;
    while(l<n&&p[l].d()==x-a.d()){
        if(p[l].r<a.l||p[l].l>a.r){
            return l;
        }
        l++;
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].cost);
    }
    sort(p,p+n);
    int res=inf;
    for(int i=0;i<n-1;i++){
        int tmp=p[i].cost;
        int j=bisearch(i,p[i]);
        if(j==-1) continue;
        tmp+=p[j].cost;
        res=min(res,tmp);
    }
    if(res==inf)
        puts("-1");
    else printf("%d\n",res);
}
