#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n;
int a[maxn];
int cnt[maxn];
set<int> s;
set<int>::iterator ite;
int main(){
    scanf("%d",&n);
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        s.insert(a[i]);
        cnt[a[i]]++;
    }
    if(s.size()==2){
        ite=s.begin();
        int first=*ite++;
        int second=*ite;
        if(cnt[first]==n/2){
            printf("YES\n%d %d\n",first,second);
        }
        else puts("NO");
    }
    else puts("NO");
}
