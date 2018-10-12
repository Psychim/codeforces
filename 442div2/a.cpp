#include<bits/stdc++.h>
using namespace std;
string f[5]={ "Danil", "Olya", "Slava", "Ann", "Nikita"};
char buf[110];
int main(){
    scanf("%s",buf);
    string s=buf;
    int cnt=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<s.size();j++){
            bool ok=true;
            for(int k=0;k<f[i].size();k++){
                if(j+k>=s.size()||s[j+k]!=f[i][k]){
                    ok=false;
                    break;
                }
            }
            if(ok) cnt++;
        }
    }
    //printf("%d\n",cnt);
    if(cnt==1)
        puts("YES");
    else puts("NO");
}
