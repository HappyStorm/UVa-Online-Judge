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
int a, b, test, sum;



int main()
{
    int times = 0;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &a, &b);
        sum = 0;
        for(int i=a ; i<=b ; ++i)
            if(i%2) sum += i;
        printf("Case %d: %d\n", ++times, sum);
    }
    return 0;
}
