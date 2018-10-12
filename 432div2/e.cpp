#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int n;
int a[maxn];
set<int> p;
bool dp[maxn][32];
int main(){
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=0;)
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++){
        for(int j=2;j<a[i];j++){
            if(a[i]%j==0){
                if(!p.count(j))
                    p.insert(j);
            }
            while(a[i]%j==0) a[i]/=j;
        }
    }
    if(p.size()%2)
        puts("Mojtaba");
    else puts("Arpa");
}
