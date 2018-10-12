#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=510;
int n;
ll k;
int a[maxn];
int win[maxn];
queue<int> q;
int winner=0;
int main(){
    scanf("%d%I64d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        q.push(a[i]);
    }
    int a1=q.front();q.pop();
    while(!winner){
        if(a1==n){
            winner=n;
        }
        else{
            int a2=q.front();q.pop();
            while(a1>a2){
                win[a1]++;
                a2=q.front();q.pop();
                q.push(a2);
            }
            if(win[a1]>=k) winner=a1;
            else{
                q.push(a1);
                a1=a2;
                win[a1]++;
            }
        }
    }
    printf("%d",winner);
}
