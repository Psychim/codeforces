#include<bits/stdc++.h>
using namespace std;
typedef set<int>::iterator site;
typedef map<int,vector<int> >::iterator mite;
const int maxm=40;
int a[maxm];
int m;
int dp[maxm][2*maxm][maxm*maxm*4];
int res=0;
int g[2*maxm][2*maxm];
struct Node{
    int i,j,k;
    Node(int pi=0,int pj=0,int pk=0):i(pi),j(pj),k(pk){}
};
queue<Node> q;
int scores[maxm*2];
struct SetNode{
    int i,s;
    SetNode(int pi=0,int ps=0):i(pi),s(ps){}
    bool operator<(SetNode a) const{
        if(s!=a.s) return s<a.s;
        return i<a.i;
    }
};
set<SetNode> s;
stack<int> d;
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",a+i);
        //a[i]=i-1;
    }
    sort(a+1,a+1+m);
    memset(dp,-1,sizeof dp);
    dp[0][0][0]=0;
    q.push(Node(0,0,0));
    while(q.size()){
        Node u=q.front();q.pop();
        if(u.i==m) break;
        for(int j=1;u.k+j*a[u.i+1]<maxm*4*maxm&&u.k+j*a[u.i+1]>=(u.j+j)*(u.j+j-1)/2;j++){
            if(dp[u.i+1][u.j+j][u.k+j*a[u.i+1]]!=-1) continue;
//            printf("%d %d %d\n",u.i+1,u.j+j,u.k+j*a[u.i+1]);
            dp[u.i+1][u.j+j][u.k+j*a[u.i+1]]=j;
            q.push(Node(u.i+1,u.j+j,u.k+j*a[u.i+1]));
        }
    }
    bool ok=false;
    for(res=m;res<2*maxm;res++){
        if(dp[m][res][res*(res-1)/2]!=-1){
            ok=true;
            break;
        }
    }

    if(!ok)
        puts("=(");
    else{
        printf("%d\n",res);
        int j=res,k=res*(res-1)/2;
        int u=0;
        for(int i=m;i>0;i--){
            int cnt=dp[i][j][k];
            j-=cnt;
            k-=cnt*a[i];
            while(cnt){
                scores[u++]=a[i];
                cnt--;
            }
        }
        for(int i=0;i<res;i++){
            if(scores[i]) s.insert(SetNode(i,scores[i]));
//            printf("(%d %d) ",i,scores[i]);
        }
//        puts("");
        while(s.size()){
            SetNode u=*s.begin();
            s.erase(u);
            for(int i=0;i<res;i++){
                if(!scores[i])
                    s.insert(SetNode(i,scores[i]));
            }
//            printf("%d %d\n",u.i,u.s);
            for(set<SetNode>::iterator ite=s.begin();ite!=s.end();ite++){
//                printf("\t%d %d\n",ite->i,ite->s);
                if(g[u.i][ite->i]||g[ite->i][u.i]) continue;
                if(scores[u.i]>0){
                    g[u.i][ite->i]=1;
                    scores[u.i]--;
                }
                else if(ite->s>0){
                    g[ite->i][u.i]=1;
                    scores[ite->i]--;
                }
            }
            s.clear();
            for(int i=0;i<res;i++){
                if(scores[i])
                    s.insert(SetNode(i,scores[i]));
            }
        }
        for(int i=0;i<res;i++){
            for(int j=0;j<res;j++){
                printf("%d",g[i][j]);
            }
            puts("");
        }
    }
}
