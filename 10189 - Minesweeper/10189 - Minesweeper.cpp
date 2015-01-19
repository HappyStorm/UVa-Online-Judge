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
int m, n, gra[100+10][100+10];
char in[100+10][100+10], ans[100+10][100+10];

int mine(int, int);

int main()
{
    int times = 0;
    while(~scanf("%d %d", &n, &m)){
        if(n==0 && m==0) break;
        getchar();
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=m ; ++j)
                 in[i][j] = getchar();
            getchar();
        }
        for(int i=1 ; i<=n ; ++i)
            for(int j=1 ; j<=m ; ++j)
                gra[i][j] = mine(i,j);

        if(times) putchar(10);
        printf("Field #%d:\n", ++times);
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=m ; ++j)
                if(in[i][j]=='*') putchar('*');
                else putchar(gra[i][j]+'0');
            putchar(10);
        }

        memset(in, '\0', sizeof(in));
        memset(ans, '\0', sizeof(ans));
        memset(gra, 0, sizeof(gra));
    }
    return 0;
}

int mine(int x, int y)
{
    int bomb = 0;
    for(int i=-1 ; i<=1 ; ++i)
        for(int j=-1 ; j<=1 ; ++j)
            if(in[x+i][y+j]=='*') ++bomb;
    return bomb;
}
