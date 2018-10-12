#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxq=2e5+10;
int n;
int q;
int p[maxn];
struct Node{
    Node* l=0,*r=0;
    int sz=0;
    int r=0,c=0;
};
Node root;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",p+i);
    }
}
