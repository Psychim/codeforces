#include<bits/stdc++.h>
using namespace std;
int n;
string com;
int number;
int res;
vector<int> s;
int cnt;
bool compare(int a,int b){
    return a>b;
}
int main(){
    scanf("%d",&n);
    res=0,cnt=1;
    while(cnt<=n){
        cin>>com;
        if(!com.compare("add")){
            cin>>number;
            s.push_back(number);
        }
        else{
            if(s.size()){
                if(s[s.size()-1]!=cnt){
                    //printf("%d %d\n",s.size(),s[s.size()-1]);
                    res++;
                    s.clear();
                }
                else s.pop_back();
            }
            cnt++;
        }
    }
    printf("%d\n",res);
}
