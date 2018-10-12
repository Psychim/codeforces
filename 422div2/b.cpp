#include<bits/stdc++.h>
using namespace std;
const int maxm=5010;
int n,m;
char s[maxm],t[maxm];
vector<int> p;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    scanf("%s",t);
    int res=maxm;
    for(int i=0;i<=m-n;i++){
        int cnt=0;
        vector<int> tmp;
        for(int j=0;j<n;j++){
            if(s[j]!=t[i+j]){
                tmp.push_back(j+1);
                cnt++;
            }
        }
        if(cnt<res){
            swap(p,tmp);
            res=cnt;
        }
    }
    printf("%d\n",res);
    for(int i=0;i<p.size();i++){
        printf("%d ",p[i]);
    }
    puts("");
}
