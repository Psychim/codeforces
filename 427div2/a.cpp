#include<bits/stdc++.h>
using namespace std;
int s,v1,v2,t1,t2;
int main(){
    scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    int r1=t1*2+v1*s,r2=t2*2+v2*s;
    //printf("%d %d\n",r1,r2);
    if(r1<r2)
        puts("First");
    else if(r1==r2)
        puts("Friendship");
    else puts("Second");
}
