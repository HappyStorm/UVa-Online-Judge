#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int solve(int);

int main()
{
    int k, people[14];
    for(int i=1 ; i<14 ; i++)
        people[i] = solve(i);
    while(~scanf("%d", &k) && k)
        printf("%d\n", people[k]);
    return 0;
}

int solve(int k){
    int pre, index = k, n = 2*k;
    while(index>0){
        if(index%n >= k){
            pre = index%n;
            int i;
            for(i=2 ; i<=k ; i++){
               int x = (pre+index)%(n-i+1);
               if(x < k || x >= 2*k)
                   break;
               else
                   pre = x;
            }
            if(i == k+1)
                return index+1;
        }
        index++;
    }
}
