#include<bits/stdc++.h>
using namespace std;
int n;
int len;
int tmp;
vector<int> res;
int main(){
    scanf("%d",&n);
    len=0;
    tmp=n;
    while(tmp){
        len++;
        tmp/=10;
    }
    for(int i=9*len;i>=0;i--){
        tmp=n-i;
        int x=0;
        while(tmp){
            x+=tmp%10;
            tmp/=10;
        }
        if(i==x) res.push_back(n-i);
    }
    printf("%d\n",res.size());
    for(int i=0;i<res.size();i++){
        printf("%d%c",res[i],i==res.size()-1?'\n':' ');
    }
}
