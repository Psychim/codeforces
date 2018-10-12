#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n;
int last,now;
int state;
int main(){
    state=0;
    bool ok=true;
    scanf("%d",&n);
    last=0;
    for(int i=0;ok&&i<n;i++){
        scanf("%d",&now);
        if(now>last){
            if(state!=0)
                ok=false;
        }
        else if(now==last){
            if(state==2)
                ok=false;
            else{
                state=1;
            }
        }
        else{
            state=2;
        }
        last=now;
    }
    if(ok)
        puts("YES");
    else puts("NO");
}
