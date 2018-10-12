#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int n;
int cnt[26];
bool is[26];
bool work(int k){
    memset(cnt,0,sizeof cnt);
    memset(is,0,sizeof is);
    int l=0,r=0;
    cnt[s[l]-'a']++;
    is[s[l]-'a']=1;
    while(r<l+k-1){
        r++;
        cnt[s[r]-'a']++;
        is[s[r]-'a']=1;
    }
    while(r<n-1){
        cnt[s[l]-'a']--;
        cnt[s[r+1]-'a']++;
        if(cnt[s[l]-'a']==0)
            is[s[l]-'a']=0;
        l++;
        r++;
    }
    for(int i=0;i<26;i++)
        if(is[i]) return true;
    return false;
}
int main(){
    scanf("%s",s);
    n=strlen(s);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(work(mid))
            r=mid;
        else l=mid+1;
    }
    printf("%d",l);
}
