#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int N, X;
int num[10000+5];

int main()
{
    N=0;
    while(~scanf("%d", &num[N++])){
        sort(num, num+N);
        if(N%2)
            printf("%d\n", num[N/2]);
        else
            printf("%d\n", (num[N/2]+num[N/2-1])/2);
    }
    return 0;
}
