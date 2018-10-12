#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b;
double best;
int main(){
    scanf("%d%d",&n,&m);
    best=1000;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        best=min(best,a*1./b);
    }
    printf("%.8lf",best*m);
}
