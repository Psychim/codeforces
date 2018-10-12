#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
char s[maxn];
int n;
int cnt[26][maxn][26];
double prob[26];
double res=0;
int main(){
    memset(cnt,0,sizeof cnt);
    scanf("%s",s);
    n=strlen(s);
    for(int l=0;l<n;l++){
        int start=s[l]-'a';
        for(int i=0;i<n;i++){
            cnt[start][i][s[(l+i)%n]-'a']++;
        }
    }
//    for(int c=0;c<26;c++){
//        for(int i=0;i<n;i++){
//            for(int d=0;d<26;d++)
//                if(cnt[c][i][d]>0)
//                printf("cnt[%c][%d][%c]=%d\n",'a'+c,i,'a'+d,cnt[c][i][d]);
//        }
//    }
    for(int c=0;c<26;c++){
        if(!cnt[c][0][c])continue;
        if(cnt[c][0][c]==1){
            prob[c]=1./n;
            continue;
        }
        int base=cnt[c][0][c];
        for(int i=1;i<n;i++){
            int win=0,sum=0;
            for(int d=0;d<26;d++){
                sum+=cnt[c][i][d];
                if(cnt[c][i][d]==1)
                    win++;
            }
            prob[c]=max(prob[c],base*1./n*win/sum);
        }
    }
    for(int c=0;c<26;c++)
        res+=prob[c];
    printf("%.15lf",res);
}
