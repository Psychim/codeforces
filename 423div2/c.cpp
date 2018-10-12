#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxtkx=1e6+10;
struct Node{
    int t, x;
    Node(int pt=0,int px=0){
        t=pt;
        x=px;
    }
    bool operator<(Node a)const{
        return x<a.x;
    }
};
set<Node> s;
set<Node>::iterator ite;
int n,k,x;
string t[maxn];
int l[maxn];
int main(){
    scanf("%d",&n);
    t[0]="";
    for(int i=1;i<=n;i++){
        cin>>t[i]>>k;
        l[i]=t[i].size();
        //printf("%d\n",l[i]);
        while(k--){
            scanf("%d",&x);
            ite=s.find(Node(0,x));
            if(ite==s.end()||l[ite->t]<l[i]){
                if(ite!=s.end())s.erase(ite);
                s.insert(Node(i,x));
            }
        }
    }
    int i;
    for(i=1,ite=s.begin();ite!=s.end();ite++){
        //printf("%d %d\n",ite->t,ite->x);
        while(ite->x>i){
            putchar('a');
            i++;
        }
        for(int j=i-ite->x;j<l[ite->t];j++,i++){
            putchar(t[ite->t][j]);
        }
    }
    puts("");
}
