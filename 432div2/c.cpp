#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dim=5;
const int maxn=1e3+10;
const double eps=1e-7;
struct Point;
typedef Point Vector;
struct Point{
    int x[dim];
    Point(){}
    Vector operator-(Point a){
        Vector res;
        for(int i=0;i<dim;i++)
            res.x[i]=x[i]-a.x[i];
        return res;
    }
    ll operator*(Point a){
        ll res=0;
        for(int i=0;i<dim;i++)
            res+=x[i]*a.x[i];
        return res;
    }
    double len(){
        double res=0;
        for(int i=0;i<dim;i++)
            res+=x[i]*x[i];
        return sqrt(res);
    }
};
int n,k;
Point p[maxn];
bool good[maxn];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<dim;j++){
            scanf("%d",&p[i].x[j]);
        }
    }
    memset(good,1,sizeof good);
    for(int i=0;i<n;i++){
        if(!good[i]) continue;
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                Vector ij=p[j]-p[i],jk=p[k]-p[j],ki=p[i]-p[k];
                double cosjik=-(ij*ki)/ij.len()/jk.len(),
                        cosijk=-(jk*ij)/jk.len()/ij.len(),
                        cosikj=-(jk*ki)/jk.len()/ki.len();
                if(cosjik<eps){
                    good[j]=good[k]=0;
                }
                else if(cosijk<eps){
                    good[i]=good[k]=0;
                }
                else if(cosikj<eps){
                    good[i]=good[j]=0;
                }
                else good[i]=good[j]=good[k]=0;
            }
        }
    }
    k=0;
    for(int i=0;i<n;i++)
        if(good[i]) k++;
    printf("%d\n",k);
    for(int i=0;i<n;i++)
        if(good[i]) printf("%d\n",i+1);
}
