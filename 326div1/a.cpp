#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1e6+10;
const int maxw=1e6;
int w;
int n;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&w);
        q.push(w);
    }
    int res=0;
    int a,b;
    a=q.top();q.pop();
    while(q.size()){
        int b=q.top();q.pop();
        if(a==b){
            q.push(a+1);
            a=q.top();q.pop();
        }
        else{
            res++;
            a=b;
        }
    }
    res++;
    printf("%d\n",res);
}
