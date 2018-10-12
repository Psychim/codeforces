#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int k,n;
int a[maxn];
int b[maxn];
int score[maxn];
set<int> s;
set<int> scores;
set<int>::iterator ite;
int main(){
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
    for(int i=1;i<=k;i++){
        scores.clear();
        score[i]=b[0];
        for(int j=i-1;j>=0;j--){
            score[j]=score[j+1]-a[j];
            if(j>0) scores.insert(score[j]);
        }
        for(int j=i+1;j<=k;j++){
            score[j]=score[j-1]+a[j-1];
            scores.insert(score[j]);
        }
        bool ok=true;
        for(int j=1;ok&&j<n;j++){
            ite=scores.find(b[j]);
            if(ite==scores.end())
                ok=false;
        }
        if(ok)
            s.insert(score[0]);
    }
    printf("%d\n",s.size());
}
