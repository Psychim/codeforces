#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
const int maxs=1100;
char ord1[maxn],ord2[maxn];
int table[maxn];
char text[maxs];
int main(){
    scanf("%s%s%s",ord1,ord2,text);
    for(int i=0;i<26;i++){
        table[ord1[i]-'a']=ord2[i]-'a';
    }
    for(int i=0;text[i];i++){
        if(text[i]>='A'&&text[i]<='Z'){
            text[i]='A'+table[text[i]-'A'];
        }
        else if(text[i]>='a'&&text[i]<='z')
            text[i]='a'+table[text[i]-'a'];
    }
    puts(text);
}
