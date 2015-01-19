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
int n, m, id;
int adj[25+5][25+5], flag[25+5];
char pre[25+5], lat[25+5];
set<string> name;
map<string, int> peo_to_id;
map<int, string> id_to_peo;
map<string, int>::iterator ptoi;
map<int, string>::iterator itop;

void initial();
void preprocess();
void connect();
void Floyd_Warshall();
void build_closure();
int main()
{
    int sets=0;
    while(scanf("%d %d", &n, &m)){
        if(!n && !m) break;
        initial();
        for(int i=0 ; i<m ; i++){
            scanf("%s %s", pre, lat);
            preprocess();
            connect();
            memset(pre, '\0', sizeof(pre));
            memset(lat, '\0', sizeof(lat));
        }
        build_closure();
        if(sets) putchar(10);
        printf("Calling circles for data set %d:\n", ++sets);
        for(int i=1 ; i<=n ; i++) flag[i] = 1;
        for(int i=1 ; i<=n ; i++){
            if(flag[i]==1){
                flag[i] = 0;
                itop = id_to_peo.find(i);
                printf("%s", (itop->second).c_str());
                for(int j=i+1 ; j<=n ; j++){
                    if(adj[i][j]==1 && adj[j][i]==1){
                        flag[j] = 0;
                        itop = id_to_peo.find(j);
                        printf(", %s", (itop->second).c_str());
                    }
                }
                putchar(10);
            }
        }
    }
    return 0;
}

void initial()
{
    name.clear();
    peo_to_id.clear();
    id_to_peo.clear();
    memset(adj, -1, sizeof(adj));
    memset(pre, '\0', sizeof(pre));
    memset(lat, '\0', sizeof(lat));
    id = 1;
}
void preprocess()
{
    if(name.find((string)pre)==name.end()){
        peo_to_id.insert(pair<string, int>((string)pre, id++));
        id_to_peo.insert(pair<int, string>(id-1, (string)pre));
        name.insert((string)pre);
    }
    if(name.find((string)lat)==name.end()){
        peo_to_id.insert(pair<string, int>((string)lat, id++));
        id_to_peo.insert(pair<int, string>(id-1, (string)lat));
        name.insert((string)lat);
    }
}
void connect()
{
    int pr, la;
    ptoi = peo_to_id.find((string) pre), pr = ptoi->second;
    ptoi = peo_to_id.find((string) lat), la = ptoi->second;
    adj[pr][la] = 1;
}
void Floyd_Warshall()
{
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(adj[i][j]==-1)
                    if(adj[i][k]==1 && adj[k][j]==1)
                        adj[i][j] = 1;
            }
        }
    }
}
void build_closure()
{
    for(int i=0 ; i<=n ; i++)
        for(int j=0 ; j<=n ; j++)
            if(i==j) adj[i][j] = adj[j][i] = 0;
    Floyd_Warshall();
}
