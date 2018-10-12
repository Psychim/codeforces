#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point;
typedef Point Vector;
struct Point{
    ll x,y;
    Point(ll a=0,ll b=0){x=a;y=b;};
    Vector operator-(Point a){
        return Vector(x-a.x,y-a.y);
    }
    ll lenpow(){
        return x*x+y*y;
    }

};
Point p[3];
ll cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}
int main(){
    for(int i=0;i<3;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=Point(x,y);
    }
    Vector ab=p[1]-p[0];
    Vector bc=p[2]-p[1];
    if(cross(ab,bc)==0||ab.lenpow()!=bc.lenpow())
        puts("No");
    else puts("Yes");
}
