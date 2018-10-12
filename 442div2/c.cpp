#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
vector<int> pos;
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i+=2){
        pos.push_back(i);
    }
    for(int i=1;i<=n;i+=2){
        pos.push_back(i);
    }
    for(int i=2;i<=n;i+=2){
        pos.push_back(i);
    }
    printf("%d\n",pos.size());
    for(int i=0;i<pos.size();i++){
        printf("%d ",pos[i]);
    }
}
