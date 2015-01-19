#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    long long a, b;
    while(EOF!=scanf("%lld %lld", &a, &b)){
        long long ans = abs(a-b);
        printf("%lld\n", ans);
    }
    return 0;
}
