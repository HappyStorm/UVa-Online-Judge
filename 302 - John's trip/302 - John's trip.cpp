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
vector<int> trip;
int x, y, z, start, degree[50], con[50][2000], visit[2000], last=1;

void travel(int);
int main()
{
    memset(con, 0, sizeof(con));
    memset(degree, 0, sizeof(degree));
    memset(visit, 0, sizeof(visit));
    int first=0;
    while(~scanf("%d %d", &x, &y)){
        if(x!=0 && y!=0){
            if(first==0)
                start = min(x,y);
            first++;
            scanf("%d", &z);
            con[x][z] = y, con[y][z] = x;
            ++degree[x], ++degree[y];
            last=0;
        }
        else{
            if(!last){
                int oddnode=0, check=1;
                for(int i=1 ; i<50 ; i++)
                    if(degree[i]%2){
                        oddnode++; break;}
                if(oddnode>0)
                    puts("Round trip does not exist.");
                else{
                    for(int i=start ; i<50 ; i++)
                        travel(i);
                    for(int i=trip.size()-1 ; i>=0 ; --i)
                        if(i==0)
                            printf("%d\n", trip[i]);
                        else
                            printf("%d ", trip[i]);
                }
                last=1;
                memset(con, 0, sizeof(con));
                memset(degree, 0, sizeof(degree));
                memset(visit, 0, sizeof(visit));
                trip.clear();
                first=0;
                putchar(10);
            }
            else
                break;
        }
    }
    return 0;
}

void travel(int cur)
{
    for(int i=0 ; i<2000 ; i++){
        if(con[cur][i] && !visit[i]){
            visit[i] = 1;
            travel(con[cur][i]);
            trip.push_back(i);
        }
    }
}
