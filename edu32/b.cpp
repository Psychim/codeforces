#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n;
int u,d,l,r;
char c;
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c",&c);
        switch(c){
        case 'U':
            u++;
            break;
        case 'D':
            d++;
            break;
        case 'L':
            l++;
            break;
        case 'R':
            r++;
            break;
        }
    }
    printf("%d",min(l,r)*2+2*min(u,d));
}

