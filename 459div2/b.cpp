#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
map<string,string> ipname;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        s2+=";";
        ipname[s2]=s1;
    }
    for(int i=0;i<m;i++){
        string s1,s2;
        cin>>s1>>s2;
        cout<<s1<<' '<<s2<<" #"<<ipname[s2]<<endl;
    }
}
