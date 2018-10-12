#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
char s[maxn];
int d=7;
bool ok=false;
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0') continue;
        if(n-i<d){
            d++;
        }
        else{
            ok=true;
            break;
        }
    }
    if(ok) puts("yes");
    else puts("no");
}
