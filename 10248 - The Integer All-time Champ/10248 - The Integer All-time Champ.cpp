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
int m, n, gra[10][10], in[10], out[10], app[10];

void find_path(int);
int main()
{
    while(~scanf("%d %d", &m, &n)){
        memset(gra, 0, sizeof(gra));
        for(int i=0 ; i<10 ; i++)
            in[i]=0, out[i]=0, app[i]=0;
        for(int i=m ; i<=n ; i++)
            if(i>=10)
                gra[i/10][i%10]=1, out[i/10]++, in[i%10]++;
            else app[i]=1;
        for(int i=1 ; i<10 ; i++)
            if(out[i] > in[i])
                find_path(i), i=0;
        for(int i=1 ; i<10 ; i++)
            if(out[i] || in[i])
                find_path(i);
        for(int i=1 ; i<10 ; i++)
            if(app[i])
                putchar(i+'0');
        putchar(10);
    }
    return 0;
}

void find_path(int cur)
{
    putchar(cur+'0');
    app[cur]=0;
    if(gra[cur][cur]){
         out[cur]--, in[cur]--;
         gra[cur][cur]--;
         find_path(cur);
         return;
    }
    for(int i=1 ; i<10 ; i++){
        if(i==cur) continue;
        if(gra[cur][i]){
            out[cur]--, in[i]--;
            gra[cur][i]--;
            find_path(i);
            return;
        }
    }
    if(gra[cur][0]){
        out[cur]--, in[0]--;
        gra[cur][0]--;
        find_path(0);
    }
}
