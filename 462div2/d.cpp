#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-7;
ll p;
int k;
vector<double> up,down;
vector<double> b;
vector<int> a;
int d=1;
int main(){
    cin>>p>>k;
    up.push_back((k-1.-p)/k);
    down.push_back(-p*1./k);
    b.push_back(0);
    a.push_back(0);
    cout<<down[d-1]<<'\t'<<up[d-1]<<endl;
    while(up[d-1]<-eps||down[d-1]>eps){
        up.push_back((k-1.-down[d-1])/k);
        down.push_back(-up[d-1]/k);
        b.push_back(0);
        a.push_back(0);
        d++;
        cout<<down[d-1]<<'\t'<<up[d-1]<<endl;
    }
    b[d-1]=0;
    cout<<"b["<<d-1<<"]="<<0<<endl;
    for(--d;d;--d){
        up[d-1]=min(k-1-b[d]*k,up[d-1]);
        down[d-1]=max(-b[d]*k,down[d-1]);
        double upa=b[d]*k+up[d-1];
        double downa=b[d]*k+down[d-1];
        a[d]=ceil(downa);
        b[d-1]=a[d]-b[d]*k;
        cout<<downa<<'\t'<<upa<<endl;
        cout<<"a["<<d<<"]="<<a[d]<<"\tb["<<d-1<<"]="<<b[d-1]<<endl;
    }
    a[0]=b[0]*k+p;
    cout<<"a[0]="<<a[0]<<endl;
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<(i==a.size()-1?'\n':' ');
}
