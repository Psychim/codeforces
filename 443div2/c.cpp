#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n;
char ope[maxn];
int x[maxn];
vector<char> ope1;
vector<int> x1;
queue<char> ope2;
queue<int> x2;
void movexor(int i){
    ope1.push_back(ope[i]);
    x1.push_back(x[i]);
    ope2.push(0);
    x2.push(0);
    char curope=ope2.front();ope2.pop();
    int curx=x2.front();x2.pop();
    while(curope){
        if(curope=='&'){
            ope2.push('|');
            int y=0;
            for(int d=0;d<10;d++){
                if(x[i]&(1<<d)){
                    y+=(curx&(1<<d))^(1<<d);
                }
            }
            x2.push(y);
            ope2.push('&');
            x2.push(curx|x[i]);
        }
        else{
            ope2.push('&');
            int y=0;
            for(int d=0;d<10;d++){
                if(x[i]&(1<<d)){
                    y+=(curx&(1<<d))^(1<<d);
                }
                else y+=1<<d;
            }
            x2.push(y);
            ope2.push('|');
            x2.push(curx&~x[i]);
        }
        curope=ope2.front();ope2.pop();
        curx=x2.front();x2.pop();
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c %d",ope+i,x+i);
    }
    for(int i=0;i<n;i++){
        if(ope[i]=='^'){
            movexor(i);
        }
        else{
            ope2.push(ope[i]);
            x2.push(x[i]);
        }
    }
    bool hasand=false;
    int andnum=0;
    while(ope2.size()&&!hasand){
        char curope=ope2.front();ope2.pop();
        int curx=x2.front();x2.pop();
        if(curope=='|'){
            ope1.push_back(curope);
            x1.push_back(curx);
        }
        else{
            hasand=true;
            andnum=curx;
        }
    }
    while(ope2.size()){
        char curope=ope2.front();ope2.pop();
        int curx=x2.front();x2.pop();
        if(curope=='&'){
            andnum&=curx;
        }
        else{
            ope1.push_back(curope);
            x1.push_back(curx);
            andnum|=curx;
        }
    }
    int xornum=0,ornum=0;
    for(int i=0;i<ope1.size();i++){
        if(ope1[i]=='^') xornum^=x1[i];
        else if(ope1[i]=='|') ornum|=x1[i];
    }
    int k=0;
    if(xornum) k++;
    if(ornum) k++;
    if(hasand)  k++;
    printf("%d\n",k);
    if(xornum) printf("^ %d\n",xornum);
    if(ornum) printf("| %d\n",ornum);
    if(hasand) printf("& %d\n",andnum);
}
