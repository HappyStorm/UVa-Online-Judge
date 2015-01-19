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
set<char> small;
char all[100], con[100], ans[30], tem[30], a, b;
int deg[30], len, tot, ct;
bool adj[30][30], vis[30];

void topodfs(int);
int main()
{
    int times=0;
    memset(all, '\0', sizeof(all));
    memset(con, '\0', sizeof(con));
    memset(ans, '\0', sizeof(ans));
    memset(tem, '\0', sizeof(tem));
    while(gets(all)!=NULL){
        gets(con);
        memset(deg, 0, sizeof(deg));
        memset(adj, false, sizeof(adj));
        memset(vis, false, sizeof(vis));
        len = strlen(all), tot=0;
        for(int i=0 ; i<len ; i++)
            if(isalpha(all[i]))
                deg[all[i]-'a'] = 1, tot++;
        int flag=0;
        len = strlen(con);
        for(int i=0 ; i<len ; i++){
            if(isalpha(con[i]) && flag==0)
                a = con[i], flag=1;
            else if(isalpha(con[i]) && flag==1){
                b = con[i], flag=0;
                if(!adj[a-'a'][b-'a']) deg[b-'a']++;
                    adj[a-'a'][b-'a'] = true;
            }
        }
        if(times++) putchar(10);
        topodfs(0);
        memset(all, '\0', sizeof(all));
        memset(con, '\0', sizeof(con));
        memset(ans, '\0', sizeof(ans));
        memset(tem, '\0', sizeof(tem));
    }
    return 0;
}

void topodfs(int lay)
{
    if(lay==tot){
        for(int i=0 ; i<tot ; i++)
            putchar(ans[i]);
        putchar(10);
        return;
    }
    for(int i=0 ; i<27 ; i++){
        if(!vis[i] && deg[i]==1){
            for(int j=0 ; j<27 ; j++)
                if(adj[i][j])
                    deg[j]--;
            vis[i] = true;
            ans[lay] = i+'a';
            topodfs(lay+1);
            for(int j=0 ; j<27 ; j++)
                if(adj[i][j])
                    deg[j]++;
            vis[i] = false;
        }
    }
}
