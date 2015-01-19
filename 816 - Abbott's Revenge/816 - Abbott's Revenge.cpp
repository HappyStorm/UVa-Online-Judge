#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int sx, sy, sd, gx, gy, px, py, ssx, ssy, fdir;
int point[15][15][5][5], visit[15][15][5], distan[15][15][5], dir[5][2]={ {0,0}, {-1,0}, {0,1}, {1,0}, {0,-1}};
char td, name[50+5], node[50+5];
typedef struct NP{
    int x, y, dir, times;
}NP;
NP tp, ori, pre[15][15][5];
queue<NP> que;
stack<pair<int,int> > ans;

int check_dir(char);
int check_go(int, char);
void enter_node(int, NP);
void getnode();
void check_start();
void bfs();
void my_clear();
int main()
{
    my_clear();
    while(gets(name)!=NULL){
        if(!strcmp(name, "END")) break;
        scanf("%d %d %c %d %d%*c", &sx, &sy, &td, &gx, &gy);
        check_start();
        point[sx][sy][0][sd] = 1;
        while(gets(node)){
            if(node[0]=='0') break;
            getnode();
            memset(node, '\0', sizeof(node));
        }
        fdir=0;
        bfs();
        printf("%s\n  ", name);
        if(!fdir)
            puts("No Solution Possible");
        else{
            ans.push(make_pair(gx,gy));
            tp = pre[gx][gy][fdir];
            while(tp.dir!=0){
                ans.push(make_pair(tp.x,tp.y));
                tp = pre[tp.x][tp.y][tp.dir];
            }
            ans.push(make_pair(sx,sy));
            int ct=0;
            while(!ans.empty()){
                if(ct<9 && ans.size()>1)
                    printf("(%d,%d) ", ans.top().first, ans.top().second), ++ct;
                else if(ct<9 && ans.size()==1)
                    printf("(%d,%d)\n", ans.top().first, ans.top().second);
                else if(ct==9 && ans.size()>1)
                    printf("(%d,%d)\n  ", ans.top().first, ans.top().second), ct=0;
                else if(ct==9 && ans.size()==1)
                    printf("(%d,%d)\n", ans.top().first, ans.top().second);
                ans.pop();
            }
        }
        my_clear();
        memset(point, 0, sizeof(point));
        memset(pre, 0, sizeof(pre));
        memset(name, '\0', sizeof(name));
    }
    return 0;
}
void my_clear()
{
    for(int i=0 ; i<10 ; i++)
        for(int j=0 ; j<10 ; j++)
            for(int k=0 ; k<5 ; k++)
                visit[i][j][k]=0, distan[i][j][k]=1e9;
}
void check_start()
{
    sd = check_dir(td);
    if(sd==1)      ssx = sx-1, ssy = sy;
    else if(sd==2) ssx = sx,   ssy = sy+1;
    else if(sd==3) ssx = sx+1, ssy = sy;
    else           ssx = sx,   ssy = sy-1;
}
int check_dir(char ch)
{
    if(ch=='N') return 1;
    else if(ch=='E') return 2;
    else if(ch=='S') return 3;
    else if(ch=='W') return 4;
    else return 0;
}
int check_go(int di, char ch)
{
    if(ch=='L'){
        if(di==1) return 4;
        else return (di-1);
    }
    else if(ch=='R'){
        if(di==4) return 1;
        else return (di+1);
    }
    else
        return di;
}
void getnode()
{
    int len = strlen(node), r=-1, c=-1, d=0;
    for(int i=0 ; i<len ; i++, d=0){
        if(isdigit(node[i]) && r==-1)
            r = node[i]-'0';
        else if(isdigit(node[i]) && c==-1)
            c = node[i]-'0';
        else if(d = check_dir(node[i]))
            while(node[++i]!=' ')
                point[r][c][d][check_go(d,node[i])] = 1;
        node[i] = '\0';
    }
    memset(node, '\0', sizeof(node));
}
void bfs()
{
    distan[sx][sy][0] = 0;
    tp.x = sx, tp.y = sy, tp.times = 0, tp.dir = 0;
    pre[ssx][ssy][sd] = tp;
    que.push(tp);
    while(!que.empty()){
        ori = que.front();
        que.pop();
        if(ori.x==gx && ori.y==gy && ori.times>0){
            fdir = ori.dir;
            while(!que.empty()) que.pop();
            break;
        }
        visit[ori.x][ori.y][ori.dir] = 0, ori.times = distan[ori.x][ori.y][ori.dir];
        for(int i=0 ; i<=4 ; i++){
            if(point[ori.x][ori.y][ori.dir][i]){
                tp.x = ori.x + dir[i][0], tp.y = ori.y + dir[i][1];
                tp.times = ori.times+1, tp.dir = i;
                if(tp.x<=9 && tp.x>=1 && tp.y<=9 && tp.y>=1){
                    if(tp.times < distan[tp.x][tp.y][i]){
                        distan[tp.x][tp.y][i] = tp.times;
                        pre[tp.x][tp.y][i] = ori;
                        if(!visit[tp.x][tp.y][i])
                            visit[tp.x][tp.y][i] = 1, que.push(tp);
                    }
                }
            }
        }
    }
}
