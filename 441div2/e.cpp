#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int maxm=1e6+10;
int n,m;
int l,x;
vector<int> w[maxn];
vector<int> restrict[maxm];
bool cap[maxm];
bool allow[maxm];
bool ok;
int res=0;
void capitalize(int x){
    if(cap[x]) return;
    cap[x]=true;
    res++;
    for(int k=0;k<restrict[x].size()&&ok;k++){
        if(!allow[restrict[x][k]]){
            ok=false;
        }
        else capitalize(restrict[x][k]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(allow,1,sizeof allow);
    memset(cap,0,sizeof cap);
    ok=true;
    for(int i=0;i<n;i++){
        scanf("%d",&l);
        while(l--){
            scanf("%d",&x);
            w[i].push_back(x);
        }
    }
    for(int i=1;i<n&&ok;i++){
        int j=0;
        while(j<w[i].size()&&j<w[i-1].size()&&w[i][j]==w[i-1][j]) j++;
        if(j==w[i].size()||j==w[i-1].size()){       //prefix
            if(w[i].size()<w[i-1].size()){
                ok=false;
            }
        }
        else if(cap[w[i][j]]!=cap[w[i-1][j]]){
            if(cap[w[i][j]]){
                if(w[i-1][j]<w[i][j]&&allow[w[i-1][j]]){
                    capitalize(w[i-1][j]);
                }
                else{
                    ok=false;
                }
            }
            else{
                if(w[i-1][j]>w[i][j]){
                    allow[w[i][j]]=false;
                }
            }
        }
        else{
            if(cap[w[i][j]]){
                if(w[i][j]<w[i-1][j])
                    ok=false;
            }
            else{
                if(w[i][j]<w[i-1][j]){
                    if(allow[w[i-1][j]]){
                        allow[w[i][j]]=false;
                        capitalize(w[i-1][j]);
                    }
                    else{
                        ok=false;
                    }
                }
                else{
                    restrict[w[i][j]].push_back(w[i-1][j]);
                }
            }
        }
    }
    if(ok){
        puts("Yes");
        printf("%d\n",res);
        for(int i=1;i<=m;i++){
            if(cap[i]){
                printf("%d ",i);
            }
        }
        puts("");
    }
    else puts("No");
}
