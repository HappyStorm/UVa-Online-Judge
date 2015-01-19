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
int n, p, item, adj[130][130], Q[130], pi[130];
long long d[130];
char pre, nex, st, la;
long long cal(long long);
void initial(int);
void relax(int, int);
void Dijkstra(int);
int main()
{
    int times=1;
    while(~scanf("%d", &n)){
        if(n==-1) break;
        getchar();
        memset(adj, 0, sizeof(adj));
        for(int i=0 ; i<n ; i++){
            scanf("%c%*c%c%*c", &pre, &nex);
            adj[pre][nex] = 1, adj[nex][pre] = 1;
        }
        scanf("%d%*c%c%*c%c%*c", &item, &st, &la);

        Dijkstra(la);
        //printf("Item=%d st=%c=%d last=%c=%d\n", item, st, st, la, la);
        /*for(int i=0 ; i<=122 ; i++){
            if((isalpha(i) && pi[i]>=0) || i==la)
                printf("d[%c]=%d ",  i, d[i]), printf(" pi[%c]=%c\n", i, pi[i]);
        }*/

        printf("Case %d:\n", times++);
        printf("%lld\n", d[st]);
        int cur = st;
        putchar(st);
        while(cur!=la){
            putchar('-');
            putchar(pi[cur]);
            cur = pi[cur];
        }
        putchar(10);
    }
    return 0;
}

long long cal(long long a)
{
    long long t1 = (20*a)/19, t2 = ((20*a) + 20 )/19;
    if(t1%20==0)
        return t1;
    else if(t2%20!=0)
        return t2;
    else if(t2%20==0)
        return t2-1;
}

void initial(int s)
{
    for(int i=0 ; i<=130 ; i++)
        Q[i]=1, d[i]=-1, pi[i]=-1;
    d[s]=item;
}

void relax(int u, int v) // u = flag, v = j++
{
    long long tdu=0;
    if(isupper(u))          // town
        tdu = cal(d[u]);
    else if(islower(u))     // village
        tdu = d[u] + 1;

    if(d[v]>tdu || d[v]==-1){
        d[v] = tdu;
        pi[v] = u;
    }
    else if(d[v]==tdu)
        if(pi[v]>u)
            pi[v] = u;
}

void Dijkstra(int s)
{
    initial(s);
    for(int i=1 ; i<=130 ; i++){
        long long t=999999999999, flag=0;
                 // 1000000000
        for(int j=1 ; j<=130 ; j++)
            if(Q[j] && d[j]<t && d[j]!=-1)
                t = d[j], flag = j;
        if(!flag) break;
        Q[flag] = 0;
        for(int j=1 ; j<=130 ; j++)
            if(adj[flag][j])
                relax(flag, j);
    }
}
