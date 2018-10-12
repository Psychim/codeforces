#include<bits/stdc++.h>
using namespace std;
char graph[10][10];
int x,y;
bool ok=false;
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%c",&graph[i][j]);
            if(j%3==2)
                getchar();
        }
        if(i%3==2&&i!=8)
            getchar();
    }
    scanf("%d%d",&x,&y);
    x=(x-1)%3;
    y=(y-1)%3;
    for(int i=x*3;i<(x+1)*3;i++){
        for(int j=y*3;j<(y+1)*3;j++){
            if(graph[i][j]=='.'){
                ok=true;
                graph[i][j]='!';
            }
        }
    }
    if(!ok){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(graph[i][j]=='.')
                    graph[i][j]='!';
            }
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%c",graph[i][j]);
            if(j%3==2)
                putchar(' ');
        }
        putchar('\n');
        if(i%3==2)
            putchar('\n');
    }
}
