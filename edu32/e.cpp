#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=40;
ll m;
int n;
ll a[maxn];
ll res=0;
set<ll> left1,left2,right1,right2;
int main(){
    scanf("%d%I64d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
        //a[i]=rand()*rand()%(ll)1e9;
    }
    left1.insert(0);
    for(int i=0;i<n/2;i++){
        for(set<ll>::iterator ite=left1.begin();ite!=left1.end();ite++){
            left2.insert(*ite);
            left2.insert((*ite+a[i])%m);
        }
        left1.swap(left2);
        left2.clear();
    }
//    for(set<ll>::iterator ite=left1.begin();ite!=left1.end();ite++){
//            printf("%I64d",*ite);
//        }
//        puts("");
    right1.insert(0);
    for(int i=n/2;i<n;i++){
        for(set<ll>::iterator ite=right1.begin();ite!=right1.end();ite++){
            right2.insert(*ite);
            right2.insert((*ite+a[i])%m);
        }
        right1.swap(right2);
        right2.clear();
    }
//        for(set<ll>::iterator ite=right1.begin();ite!=right1.end();ite++){
//            printf("%I64d",*ite);
//        }
//        puts("");
    for(set<ll>::iterator ite1=left1.begin();ite1!=left1.end();ite1++){
        set<ll>::iterator ite2=right1.lower_bound(m-(*ite1)-1);
        if(ite2==right1.end()) ite2--;
//        printf("%I64d\n",*ite2);
        while(ite2!=right1.begin()&&*ite2>m-(*ite1)-1) ite2--;
//        printf("%I64d\n",*ite2);
        res=max(res,(*ite1+*ite2)%m);
    }
    printf("%I64d",res);
}
