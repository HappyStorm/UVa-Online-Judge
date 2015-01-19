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
int N, ans, dir[8][2]={{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}};
char gra[5+5][5+5], tc, target[5+5][5+5]={"11111", "01111", "00 11", "00001", "00000"};
typedef struct point{
    int x, y, time;
    char pgra[5+5][5+5];
}P;
queue<P> que;
P tp, ori;
map<string, int> plane_head;
map<string, int> plane_tail;
map<string, int>::iterator iter_head;
map<string, int>::iterator iter_tail;
string ts;

void initial_head();
void initial_tail();
void BFS_head();
void BFS_tail();
string build(char[][10]);
P build_point(P, int);
int solve();

int main()
{
    initial_tail();
    BFS_tail();
    scanf("%d", &N), getchar();
    while(N--){
        initial_head();
        //BFS_head();
        iter_tail = plane_tail.find(build(gra));
        //ans = solve();
        if(iter_tail==plane_tail.end())
            puts("Unsolvable in less than 11 move(s).");
        else
            printf("Solvable in %d move(s).\n", iter_tail->second);
    }
    return 0;
}

void initial_head()
{
    ans = -1;
    memset(gra, '\0', sizeof(gra));
    plane_head.clear();
    for(int i=0 ; i<5 ; ++i){c
        for(int j=0 ; j<5 ; ++j)
            gra[i][j] = getchar();
        getchar();
    }
}
void initial_tail()
{
    memset(tp.pgra, '\0', sizeof(tp.pgra));
    plane_tail.clear();
    while(!que.empty()) que.pop();
    for(int i=0 ; i<5 ; ++i)
        for(int j=0 ; j<5 ; ++j)
            tp.pgra[i][j] = target[i][j];
    tp.x = 2, tp.y = 2, tp.time = 0;
    que.push(tp);
    plane_tail.insert(pair<string, int>(build(tp.pgra), 0));
}
void BFS_head()
{
    int ct=0;
    while(!que.empty()){
        ori = que.front(), que.pop();
        if(ori.time>8) break;
        for(int i=0 ; i<8 ; ++i){
            tp = build_point(ori, i);
            if(tp.x<0 || tp.x>=5 || tp.y<0 || tp.y>=5) continue;
            tc = ori.pgra[tp.x][tp.y];
            tp.pgra[tp.x][tp.y] = ' ', tp.pgra[ori.x][ori.y] = tc;
            iter_head = plane_head.find(build(tp.pgra));
            if(iter_head==plane_head.end()){
                plane_head.insert(pair<string, int>(build(tp.pgra), tp.time));
                que.push(tp);
            }
            else{
                if((iter_head->second)>tp.time){
                    plane_head.insert(pair<string, int>(build(tp.pgra), tp.time));
                    que.push(tp);
                }
            }
        }
    }
    while(!que.empty()) que.pop();
}
void BFS_tail()
{
    int ct=0;
    while(!que.empty()){
        ori = que.front(), que.pop();
        if(ori.time>9) break;
        for(int i=0 ; i<8 ; ++i){
            memset(tp.pgra, '\0', sizeof(tp.pgra));
            tp = build_point(ori, i);
            if(tp.x<0 || tp.x>=5 || tp.y<0 || tp.y>=5) continue;
            tc = ori.pgra[tp.x][tp.y];
            tp.pgra[tp.x][tp.y] = ' ', tp.pgra[ori.x][ori.y] = tc;
            iter_tail = plane_tail.find(build(tp.pgra));
            if(iter_tail==plane_tail.end()){
                plane_tail.insert(pair<string, int>(build(tp.pgra), tp.time));
                que.push(tp);
            }
            else{
                if((iter_tail->second)>tp.time){
                    plane_tail.insert(pair<string, int>(build(tp.pgra), tp.time));
                    que.push(tp);
                }
            }
        }
    }
    while(!que.empty()) que.pop();
}
string build(char arr[][10])
{
    ts.clear();
    for(int i=0 ; i<5 ; ++i)
        ts.append(arr[i]);
    return ts;
}
P build_point(P a, int d)
{
    P np;
    memset(np.pgra, '\0', sizeof(np.pgra));
    np.x = a.x + dir[d][0];
    np.y = a.y + dir[d][1];
    np.time = a.time+1;
    for(int i=0 ; i<5 ; ++i)
        for(int j=0 ; j<5 ; ++j)
            np.pgra[i][j] = a.pgra[i][j];
    return np;
}
int solve()
{
    iter_tail = plane_tail.begin();
    for( ; iter_tail!=plane_tail.end() ; ++iter_tail){
        iter_head = plane_head.find(iter_tail->first);
        if(iter_head!=plane_head.end())
            return (iter_tail->second + iter_head->second);
    }
    return -1;
}
