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
int N, center, later, critical, start=1, deep[100+5], con[100+5][100+5], temp[100+5];
bool visit[100+5], ans[100+5];
char t;

void trace(int, int, int);
int main()
{
    while(~scanf("%d", &N) && N){
        memset(con, 0, sizeof(con));
        memset(deep, 0, sizeof(deep));
        memset(temp, 0, sizeof(temp));
        memset(visit, false, sizeof(visit));
        memset(ans, false, sizeof(ans));
        while(~scanf("%d", &center) && center){
            while(~scanf("%d%c", &later, &t)){
                con[center][later] = 1;
                con[later][center] = 1;
                if(t=='\n') break;
            }
        }
        critical = 0;
        trace(1,0,1);
        for(int i=1 ; i<=100 ; i++)
            if(ans[i])
                ++critical;
        printf("%d\n", critical);
    }
    return 0;
}

void trace(int cur, int parent, int step)
{
    int child=0;
    deep[cur] = step, temp[cur] = step;
    visit[cur] = true;
    for(int i=1 ; i<=100 ; i++){
        if(con[cur][i] && i!=parent && visit[i])
            temp[cur] = min(temp[cur], deep[i]);
        if(con[cur][i] && !visit[i]){
            trace(i, cur, step+1);
            ++child;
            temp[cur] = min(temp[cur], temp[i]);
            if((cur==start && child>1) || (cur!=start && temp[i]>=deep[cur]))
                ans[cur] = true;
        }
    }
}
