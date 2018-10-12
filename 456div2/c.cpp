#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m;
ll bo,in,da;
ll mh[maxn];
ll sh[maxn];
ll re[maxn];
struct event{
    ll t,h;
    int e;
    bool operator<(event a) const{
        if(t!=a.t)return t<a.t;
        if(e!=a.e)return e<a.e;
        return h<a.h;
    }
};
struct boundary{
    int e;
    ll t;
    bool dir;
    boundary(ll pt=0,int pe=0,bool pd=false){
        t=pt;
        e=pe;
        dir=pd;
    }
    bool operator<(boundary a) const{
        if(t!=a.t) return t<a.t;
        if(e!=a.e) return e<a.e;
        int t1=(int)dir,t2=(int)a.dir;
        return t1<t2;
    }
};
event ev[maxn];
ll ch[maxn];
ll ct[maxn];
ll bestmoney;
ll curt,curmoney;
vector<boundary> bou;
bool killable[maxn];
int cntkill;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%I64d%I64d%I64d",&bo,&in,&da);
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d%I64d",mh+i,sh+i,re+i);
        ch[i]=sh[i];
        ct[i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%I64d%d%I64d",&ev[i].t,&ev[i].e,&ev[i].h);
    }
    sort(ev,ev+m);

    for(int j=0;j<m;j++){
            int i=ev[j].e;
            if(ch[i]<=da&&re[i]){
                int dt=ct[i]+(da-ch[i])/re[i]+1;
                if(dt<ev[j].t){
                    bou.push_back(boundary(dt-1,i,true));
                    bou.push_back(boundary(dt,i,false));
                    ch[i]+=(dt-ct[i])*re[i];
                    ch[i]=min(ch[i],mh[i]);
                    ct[i]=dt;
                }
            }
            if(ev[j].h<=da){
                if(ch[i]>da){
                    bou.push_back(boundary(ev[j].t,i,true));
                }
            }
            else{
                if(ch[i]<=da){
                    bou.push_back(boundary(ev[j].t-1,i,true));
                    bou.push_back(boundary(ev[j].t,i,false));
                }
            }
            ch[i]=ev[j].h;
            ct[i]=ev[j].t;
    }
    for(int i=1;i<=n;i++){
        if(ch[i]<=da&&re[i]){
            int dt=ct[i]+(da-ch[i])/re[i]+1;
            bou.push_back(boundary(dt-1,i,true));
            bou.push_back(boundary(dt,i,false));
            ch[i]+=(dt-ct[i])*re[i];
            ct[i]=dt;
            ch[i]=min(ch[i],mh[i]);
        }
    }
    if(in){
        for(int i=1;i<=n;i++){
            if(ch[i]<=da){
                printf("-1");
                return 0;
            }
        }
    }
    sort(bou.begin(),bou.end());
    curmoney=0;
    cntkill=0;
    for(int i=1;i<=n;i++){
        if(sh[i]<=da){
            killable[i]=true;
            cntkill++;
            curmoney+=bo;
        }
    }
    bestmoney=curmoney;
    curt=0;
    for(int i=0;i<bou.size();i++){
        //printf("%I64d %d %d\n",bou[i].t,bou[i].e,bou[i].dir);
        curmoney+=(bou[i].t-curt)*in*cntkill;
        curt=bou[i].t;
        if(bou[i].dir){
            if(!killable[bou[i].e]){
                curmoney+=curt*in;
                curmoney+=bo;
                cntkill++;
                killable[bou[i].e]=true;
            }
        }
        else{
            if(killable[bou[i].e]){
                curmoney-=curt*in;
                curmoney-=bo;
                cntkill--;
                killable[bou[i].e]=false;
            }
        }
        //printf("%I64d %I64d\n",bou[i].t,curmoney);
        if((i==bou.size()-1||bou[i+1].t!=bou[i].t)&&curmoney>bestmoney){
            bestmoney=curmoney;
        }
    }
    printf("%I64d",bestmoney);
}
