#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
vector<int> pos;
bool first[maxn];
int cnt[maxn];
int main(){
    scanf("%d",&n);
    memset(first,1,sizeof first);
    for(int i=1;i<=n;i++){
        cnt[i]=1;
    }
    queue<int> q;
    q.push(max(1,n-1));
    while(q.size()){
        int i=q.front();q.pop();
        if(!cnt[i]) continue;
        pos.push_back(i);
        cnt[i]=0;
        if(first[i]){
            first[i]=0;
            if(i>1){
                q.push(i-1);
                cnt[i-1]++;
            }
            if(i<n){
                q.push(i+1);
                cnt[i+1]++;
            }
        }
    }
    printf("%d\n",pos.size());
    for(int i=0;i<pos.size();i++){
        printf("%d ",pos[i]);
    }
}

