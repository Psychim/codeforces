#include<bits/stdc++.h>
using namespace std;
struct mystr{
    string s;
    bool operator<(mystr a) const{
        if(s.size()!=a.s.size())return s.size()>a.s.size();
        return s<a.s;
    }
    mystr(string ps=""){
        s=ps;
    }
};
struct Record{
    set<mystr> numbers;
    Record(){}
    void add(string newnum){
        numbers.insert(mystr(newnum));
    }
};
typedef map<string,Record>::iterator mite;
typedef set<mystr>::iterator site;
map<string,Record> recs;
int n,m,x;
string tmp1,tmp2;
struct Node{
    bool flag;
    map<char,Node*> ch;
    Node(){flag=false;}
};
Node* root;
void add(string s){
    Node* p;
    for(int i=0;i<s.size();i++){
        p=root;
        for(int j=i;j<s.size();j++){
            if(!p->ch.count(s[j])){
                p->ch[s[j]]=new Node();
            }
            p=p->ch[s[j]];
        }
        p->flag=true;
    }
}
bool findsuf(string s){
    Node* p=root;
    for(int i=0;i<s.size();i++){
        if(p->ch.count(s[i])){
            p=p->ch[s[i]];
        }
        else return false;
    }
    if(p->flag) return true;
    return false;
}
int main(){
    scanf("%d",&n);
    m=0;
    for(int i=0;i<n;i++){
        cin>>tmp1;
        if(!recs.count(tmp1))
            m++;
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>tmp2;
            recs[tmp1].add(tmp2);
        }
    }
    for(mite ite=recs.begin();ite!=recs.end();ite++){
        Record &r=ite->second;
        root=new Node();
        for(site ite2=r.numbers.begin();ite2!=r.numbers.end();){
            //cout<<ite2->s<<endl;
            if(findsuf(ite2->s)){
                r.numbers.erase((ite2++)->s);
            }
            else add((ite2++)->s);
        }
    }
    printf("%d\n",recs.size());
    for(mite ite=recs.begin();ite!=recs.end();ite++){
        cout<<ite->first<<' ';
        Record &r=ite->second;
        cout<<r.numbers.size();
        for(site ite2=r.numbers.begin();ite2!=r.numbers.end();ite2++){
            cout<<' '<<ite2->s;
        }
        cout<<endl;
    }
}
