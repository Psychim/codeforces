#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,k;
struct Node{
    int id,ch;
    Node(int pid=0,int pch=0){id=pid;ch=pch;}
};
int cnt;
int main(){
    scanf("%d%d",&n,&k);
    if((n-1)%k==1){
        printf("%d\n",(n-1)/k*2+1);
    }
    else if((n-1)%k==0){
        printf("%d\n",(n-1)/k*2);
    }
    else printf("%d\n",(n-1)/k*2+2);
    queue<Node> q;
    cnt=2;
    q.push(Node(1,k));
    while(cnt<=n&&q.size()){
        Node u=q.front();q.pop();
        for(int i=0;cnt<=n&&i<u.ch;i++,cnt++){
            printf("%d %d\n",u.id,cnt);
            q.push(Node(cnt,1));
        }
    }
}
