#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
const int maxn=2e5;
const int maxk=1e9+10;
int w,n,k;

struct Music{
    int a,t,p;
    bool operator<(const Music &b)const{
        return t<b.t||t==b.t&&(a<b.a||a==b.a&&p<b.p);
    }
};
typedef set<Music>::iterator sit;
set<Music> h1,h2;
Music m[maxn];
bool where[maxn];
int ans,nowa,nowt,da,dt;

int main(){
    scanf("%d%d%d",&n,&w,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&m[i].a);
    for(int i=0;i<n;i++)
        scanf("%d",&m[i].t);
    for(int i=0;i<n;i++)
        m[i].p=i;
    int r=0;
    ans=nowa=nowt=0;
    for(int l=0;l<n;l++){
        while(r<n){
            if(h2.size()<w){
                da=m[r].a;
                dt=(m[r].t+1)/2;
                if(nowt+dt>k) break;
                h2.insert(m[r]);
                where[r]=1;
            }
            else if(h2.begin()->t<m[r].t){
                Music out=*h2.begin();
                dt=out.t-(out.t+1)/2+(m[r].t+1)/2;
                da=m[r].a;
                if(nowt+dt>k) break;
                h1.insert(out);
                h2.erase(out);
                h2.insert(m[r]);
                where[out.p]=0;
                where[r]=1;
            }
            else{
                dt=m[r].t;
                da=m[r].a;
                if(nowt+dt>k) break;
                h1.insert(m[r]);
                where[r]=0;
            }
            nowa+=da;
            nowt+=dt;
            ans=max(nowa,ans);
            r++;
        }
        if(r==l) continue;
        if(where[l]){
            h2.erase(m[l]);
            nowt-=(m[l].t+1)/2;
            nowa-=m[l].a;
            if(h1.size()){
                Music out=*h1.rbegin();
                h1.erase(out);
                h2.insert(out);
                where[out.p]=1;
                nowt-=out.t/2;
            }
        }
        else{
            h1.erase(m[l]);
            nowt-=m[l].t;
            nowa-=m[l].a;
        }
    }
    printf("%d\n",ans);
}
