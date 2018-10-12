#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,m,k;
char s[maxn][maxn];
int ans;
int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        int l=0,r=-1;
        while(l<m&&r+1<m){
            if(s[i][l]=='*'){
                l++;
                r=l-1;
            }
            else{
                if(s[i][r+1]=='.'){
                    r++;
                }
                else l=r+1;
                if(r-l+1==k){
                    ans++;
                    l++;
                }
            }
        }
    }
    if(k>1){
        for(int i=0;i<m;i++){
            int l=0,r=-1;
            while(l<n&&r+1<n){
                if(s[l][i]=='*'){
                    l++;
                    r=l-1;
                }
                else{
                    if(s[r+1][i]=='.'){
                        r++;
                    }
                    else l=r+1;
                    if(r-l+1==k){
                        ans++;
                        l++;
                    }
                }
            }
        }
    }
    printf("%d",ans);
}
