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
int n, check, num[3000+5], jol[3000+5];


int main()
{
    while(~scanf("%d", &n)){
        check = 1;
        for(int i=0 ; i<n ; ++i)
            scanf("%d", &num[i]);
        for(int i=0 ; i<n-1 ; ++i)
            ++jol[abs(num[i+1]-num[i])];
        for(int i=1 ; i<=n-1 ; ++i)
            if(!jol[i]){ check = 0; break;}
        if(check) puts("Jolly");
        else puts("Not jolly");

        memset(num, 0, sizeof(num));
        memset(jol, 0, sizeof(jol));
    }
    return 0;
}
