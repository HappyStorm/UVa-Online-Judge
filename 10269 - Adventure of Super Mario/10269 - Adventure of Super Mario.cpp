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
#define DMAX 2147483646
using namespace std;
int A, B, M, L, K, xi, yi, li, ans;
int gra[100+5][100+5], dis[100+5][10+5];
bool inque[100+5][10+5];
vector<int> adj[100+5];
typedef struct node{
    int id, rk;
}Node;
Node tn, ori;
queue<Node> que;

void initial();
void Floyd_Warshall();
void preprocess();
void SPFA();
void get_ans();
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d %d %d", &A, &B, &M, &L, &K);
        initial(), preprocess();
        SPFA(), get_ans();
        printf("%d\n", ans);
    }
    return 0;
}

void initial()
{
    for(int i=0 ; i<104 ; ++i)
        for(int j=0 ; j<104 ; ++j)
            if(i==j) gra[i][j] = 0;
            else gra[i][j] = DMAX;
    for(int i=0 ; i<104 ; ++i)
        for(int j=0 ; j<14 ; ++j)
            dis[i][j] = DMAX;
    memset(inque, false, sizeof(inque));
    for(int i=0 ; i<M ; i++){
        scanf("%d %d %d", &xi, &yi, &li);
        gra[xi][yi] = gra[yi][xi] = li;
    }
}
void Floyd_Warshall()
{
    for(int k=1 ; k<=A ; ++k){  // be careful about that should use villages to refresh
        for(int i=1 ; i<=A+B ; ++i){
            for(int j=1 ; j<=A+B ; ++j){
                if(gra[i][k]!=DMAX && gra[k][j]!=DMAX){ // if exist another road
                    if(gra[i][j]==DMAX) // if origin gratance = infinite
                        gra[i][j] = gra[i][k] + gra[k][j];
                    else // if origin gratance != infinite
                        gra[i][j] = min(gra[i][j], gra[i][k] + gra[k][j]);
                }
            }
        }
    }
}
void preprocess()
{
    Floyd_Warshall();
    for(int i=1 ; i<=A+B ; ++i){
        adj[i].clear();
        for(int j=1 ; j<=A+B ; ++j)
            if(gra[i][j] && gra[i][j]!=DMAX) adj[i].push_back(j);
    }
}
void SPFA()
{
    tn.id = A+B, tn.rk = K;
    que.push(tn);
    inque[A+B][K] = true;
    dis[A+B][K] = 0;
    while(!que.empty()){
        ori = que.front(), que.pop();
        int tid = ori.id, trk = ori.rk;
        inque[tid][trk] = false;
        for(int i=0 ; i<adj[tid].size() ; ++i){
            int con = adj[tid][i];
            if(dis[con][trk] > (dis[tid][trk]+gra[tid][con])){
                dis[con][trk] = dis[tid][trk]+gra[tid][con];
                if(!inque[con][trk]){
                    inque[con][trk] = true;
                    tn.id = con, tn.rk = trk;
                    que.push(tn);
                }
            }
            if(trk>0 && gra[tid][con] <=L && dis[con][trk-1] > dis[tid][trk]){
                dis[con][trk-1] = dis[tid][trk] + max(0, gra[tid][con]-L);
                if(!inque[con][trk-1]){
                    inque[con][trk-1] = true;
                    tn.id = con, tn.rk = trk-1;
                    que.push(tn);
                }
            }
        }
    }
}
void get_ans()
{
    ans = DMAX;
    for(int i=0 ; i<=K ; ++i)
        ans = min(ans, dis[1][i]);
}
