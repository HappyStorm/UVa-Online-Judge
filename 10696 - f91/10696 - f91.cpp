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

int f91(int);

int N;
int fnum[1000000+5];

int main()
{
    while(~scanf("%d", &N) && N)
        printf("f91(%d) = %d\n", N, f91(N));
    return 0;
}

int f91(int n)
{
    if(n<=100)
        return fnum[n] ? fnum[n] : f91(f91(n+11));
    else
        return fnum[n] = n-10;
}
