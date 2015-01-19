#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <cstring>
#include <cctype>
#include <set>
using namespace std;
int v, e, f, t, guard, ori, ok, w, b, gra[200+5];
bool adj[200+5][200+5], vis[200+5];
queue<int> que;

int bfs(int);
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &v, &e);
        memset(adj, false, sizeof(adj));
        memset(vis, false, sizeof(vis));
        memset(gra, 0, sizeof(gra));
        for(int i=0 ; i<e ; i++){
            scanf("%d %d", &f, &t);
            adj[f][t] = true, adj[t][f] = true;
        }
        ok=1;
        int ans=0;
        for(int i=0 ; i<v ; i++){
            if(!vis[i])
               ans+=bfs(i);
            if(!ok)
                break;
        }
        if(ok)
            printf("%d\n", ans);
        else
            puts("-1");
        while(!que.empty()) que.pop();
    }
    return 0;
}

int bfs(int head)
{
    que.push(head);
    gra[head] = 1;
    int alone=1;
    w=1, b=0;
    while(!que.empty()){
        ori = que.front();
        que.pop();
        vis[ori] = true;
        for(int i=0 ; i<v ; i++){
            if(adj[ori][i]){
                if(vis[i]){
                    if(gra[ori]==gra[i])
                        ok=0;
                }
                else{
                    gra[i] = !gra[ori];
                    if(gra[i]) w++;
                    else b++;
                    vis[i] = true;
                    que.push(i);
                }
                alone=0;
            }
            if(!ok)
                break;
        }
        if(!ok)
            break;
    }
    while(!que.empty()) que.pop();
    if(alone)
        return 1;
    else
        return min(w,b);
}
