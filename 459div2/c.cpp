#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
string s;
int dp[maxn][maxn];
int cnt=0;
bool check(int i,int j){
    if(s[i]=='('){
        if(s[j]!='(')
            return true;
    }
    else if(s[i]=='?'){
        if(s[i]!='(')
            return true;
    }
    return false;
}
int main(){
    cin>>s;
    memset(dp,0,sizeof dp);
    for(int i=0;i<s.size()-1;i++){
        if(check(i,i+1)){
            dp[i][i+1]=1;
            cnt++;
        }
    }
    for(int len=4;len<s.size();len+=2){
        for(int i=0;i+len-1<s.size();i++){
            if(check(i,i+len-1)&&dp[i+1][i+len-2]){
                dp[i][i+len-1]=1;
                cnt++;
                continue;
            }
            for(int j=i+1;j<i+len-1;j+=2){
                if(dp[i][j]&&dp[j+1][i+len-1]){
                    dp[i][i+len-1]=1;
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n",cnt);
}
