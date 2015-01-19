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
#define MAX 2147483647
using namespace std;
int r, c, curstep, minstep, light, swit[3+5][3+5], gra[5+5][5+5], pre[25+5], ans[25+5];
int dir[9][2]={{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {0,0}, {1,0}, {-1,1}, {0,1}, {1,1}};
char in[5+5][5+5];

void intitial();
bool valid(int);
bool oper(int, int, int, int);
void press(int, int);
void DFS(int, int);
int main()
{
    int times=0;
    while(scanf("%d %d", &r, &c)){
        if(r==0 && c==0) break;
        intitial();
        printf("Case #%d\n", ++times);
        DFS(0,0);
        if(minstep==MAX)
            puts("Impossible.");
        else{
            for(int i=0 ; i<minstep ; ++i)
                if(i==minstep-1)
                    printf("%d\n", ans[i]);
                else
                    printf("%d ", ans[i]);
        }
    }
    return 0;
}

void intitial()
{
    getchar();
    memset(swit, 0, sizeof(swit));
    memset(gra, 0, sizeof(gra));
    memset(pre, 0, sizeof(pre));
    memset(ans, 0, sizeof(ans));
    memset(in, '\0', sizeof(in));
    for(int i=0 ; i<3 ; ++i)
        gets(in[i]);
    for(int i=0 ; i<3 ; ++i)
        for(int j=0 ; j<3 ; ++j)
            if(in[i][j]=='*')
                swit[i][j] = 1;
    minstep = MAX, light = 0, curstep = 0;
}

bool valid(int row)
{
    if(row<2) return true;
    for(int i=row-2 ; i>=0 ; --i){
        for(int j=0 ; j<c ; ++j)
            if(!gra[i][j]) return false;
    }
    return true;
}
bool oper(int tr, int tc, int tsr, int tsc)
{
    if(tr>=0 && tr<r && tc>=0 && tc<c && swit[tsr][tsc])
        return true;
    else return false;
}
void press(int row, int col)
{
    int gr, gc, sr, sc;
    for(int i=0 ; i<9 ; i++){
        gr = row + dir[i][0], gc = col + dir[i][1];
        sr = 1 + dir[i][0], sc = 1 + dir[i][1];
        if(oper(gr,gc,sr,sc)){
            if(gra[gr][gc])
                gra[gr][gc] = 0, --light;
            else
                gra[gr][gc] = 1, ++light;
        }
    }
}
void DFS(int row, int col)
{
    if(light==r*c){
        if(curstep<minstep){
            minstep = curstep;
            for(int i=0 ; i<minstep ; ++i)
                ans[i] = pre[i];
        }
        return;
    }
    if(row>=r) return;  // out of row range, then return.
    if(col==c){         // if col == c, check if next row is a valid row.
        if(!valid(row)) return;
        DFS(row+1,0);
        return;
    }
    // first(press) now location pressed.
    press(row, col);
    pre[curstep++] = row * c + col + 1;
    DFS(row, col+1);
    // now location not pressed.
    --curstep;
    press(row,col); // second press to recover the graph.
    DFS(row,col+1);
}