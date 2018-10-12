#include<bits/stdc++.h>
using namespace std;
int n;
int main(){scanf("%d",&n);if(n%10<=5) n-=n%10; else n=n+10-n%10;printf("%d",n);}

