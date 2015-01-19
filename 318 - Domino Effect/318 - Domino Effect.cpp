#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int n, m, a, b, l, W[500+10][500+10], Q[500+10], d[500+10], pi[500+10];
struct edge{
    int pre, nex;
    double time;
};
edge te;
vector<edge> e;
void initial(int);
void relax(int, int);
void Dijkstra(int);
int main()
{
    int times=1;
    while(~scanf("%d %d", &n, &m)){
        if(n==0 && m==0) break;
        memset(W, -1, sizeof(W)), e.clear();
        for(int i=0 ; i<m ; i++)
            scanf("%d %d %d", &a, &b, &l), W[a][b] = l, W[b][a] = l;
        Dijkstra(1);
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(W[i][j]!=-1){
                    double mint = min(d[i], d[j]), maxt = max(d[i], d[j]);
                    te.pre = i, te.nex = j, te.time = (mint+W[i][j]-maxt)/2 + maxt;
                    W[i][j] = -1, W[j][i] = -1, e.push_back(te);
                }
            }
        }
        double far=0;
        int key=1, key1=0, key2=0;
        for(int i=1 ; i<=n ; i++)
            if(d[i]>far)
                far = d[i], key = i;
        for(int i=0 ; i<e.size() ; i++)
            if(e[i].time>far)
                key1 = e[i].pre, key2 = e[i].nex, far = e[i].time;
        if(key1==0 && key2==0)
            printf("System #%d\nThe last domino falls after %.1f seconds, at key domino %d.\n", times++, far, key);
        else
            printf("System #%d\nThe last domino falls after %.1f seconds, between key dominoes %d and %d.\n", times++, far, key1, key2);
        putchar(10);
    }
    return 0;
}

void initial(int s)
{
    for(int i=0 ; i<=n ; i++)
        Q[i]=1, d[i]=-1, pi[i]=-1;
    d[s]=0;
}

void relax(int u, int v)
{
    if(d[v]>d[u] + W[u][v] || d[v]==-1)
        d[v] = d[u] + W[u][v], pi[v] = u;
}

void Dijkstra(int s)
{
    initial(1);
    for(int i=1 ; i<=n ; i++){
        int t=1e9, flag=0;
        for(int j=1 ; j<=n ; j++)
            if(Q[j] && d[j]<t && d[j]!=-1)
                t = d[j], flag = j;
        Q[flag] = 0;
        for(int j=1 ; j<=n ; j++){
            if(W[flag][j]!=-1)
                relax(flag,j);
        }
    }
}
