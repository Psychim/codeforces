#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int a[maxn];
int n;
bool vis[1000];
int cnt=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]&&!vis[a[i]]){
            cnt++;
            vis[a[i]]=true;
        }
    }
    cout<<cnt;
}
