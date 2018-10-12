#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 100100
#define llg int
#define yyj(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
llg n,m,Q;

inline int getint()
{
       int w=0,q=0; char c=getchar();
       while((c<'0' || c>'9') && c!='-') c=getchar(); if(c=='-') q=1,c=getchar();
       while (c>='0' && c<='9') w=w*10+c-'0', c=getchar(); return q ? -w : w;
}

struct XOR
{
    llg bas[31],lazy,val;

    void init() {memset(bas,0,sizeof(bas)); lazy=val=0;}

    llg count()
    {
        llg ans=0;
        for (llg i=0;i<=30;i++) if (bas[i]) ans++;
        return ans;
    }

    void add(llg x)
    {
        for (llg i=30;i>=0;i--)
            if ((x>>i)&1)
            {
                if (bas[i]) x^=bas[i];
                else {bas[i]=x; break;}
            }
    }

    XOR operator +(const XOR&a) const
    {
        XOR ans; ans.init();
        for (llg i=0;i<=30;i++) ans.add(bas[i]),ans.add(a.bas[i]);
        ans.add(a.val^val);
        ans.val=val;
        return ans;
    }
}po[maxn*10],ans;

void pushdown(llg o,llg l,llg r)
{
    llg lc=o<<1,rc=o<<1|1;
    if (po[o].lazy)
    {
        po[lc].lazy^=po[o].lazy;
        po[rc].lazy^=po[o].lazy;
        po[lc].val^=po[o].lazy;
        po[rc].val^=po[o].lazy;
        po[o].lazy=0;
    }
}

void build(llg o,llg l,llg r)
{
    po[o].init();
    if (l==r)
    {
        po[o].val=getint();
        return ;
    }
    llg lc=o<<1,rc=o<<1|1,mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    po[o]=po[lc]+po[rc];
}

void modify(llg o,llg l,llg r,llg L,llg R,llg d)
{
    if (l>=L && r<=R)
    {
        po[o].lazy^=d;
        po[o].val^=d;
        return ;
    }
    pushdown(o,l,r);
    llg lc=o<<1,rc=o<<1|1,mid=(l+r)>>1;
    if (L<=mid) modify(lc,l,mid,L,R,d);
    if (R>mid) modify(rc,mid+1,r,L,R,d);
    po[o]=po[lc]+po[rc];
}

void query(llg o,llg l,llg r,llg L,llg R)
{
    if (l>=L && r<=R)
    {
        ans=ans+po[o];
        return ;
    }
    pushdown(o,l,r);
    llg lc=o<<1,rc=o<<1|1,mid=(l+r)>>1;
    if (L<=mid) query(lc,l,mid,L,R);
    if (R>mid) query(rc,mid+1,r,L,R);
    po[o]=po[lc]+po[rc];
}

int main()
{
    //yyj("xor");
    cin>>n>>Q;
    build(1,1,n);
    while (Q--)
    {
        llg ty=getint(),l=getint(),r=getint();
        if (ty==1)
        {
            llg d=getint();
            modify(1,1,n,l,r,d);
        }
        else
        {
            ans.init();
            query(1,1,n,l,r);
            printf("%d\n",(1<<ans.count()));
        }
    }
    return 0;
}
