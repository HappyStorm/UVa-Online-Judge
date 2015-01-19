#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#define MAX 100000
using namespace std;
bool prime[MAX];
int prime_num=0;
void prime_table()
{
    memset(prime, true, sizeof(prime));
    long long m = 100000;
    for(long long i=2 ; i<=m ; i++){
        if(prime[i]){
            prime_num++;
            for(long long j=i*i ; j<=MAX ; j=j+i)
                prime[j] = false;
        }
    }
}
long long factor(long long);

int main()
{
    prime_table();
    int N;
    scanf("%d", &N);
    while(N--){
        long long L, U;
        long long range[100000];
        memset(range, 0, sizeof(range));
        scanf("%lld %lld", &L, &U);
        long long flag, div=0;
        long long temp;
        for(int i=0 ; i<=U-L ; i++){
            temp = factor(i+L);
            if(temp>div)
                flag = i, div = temp;
            range[i] = temp;
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, U, flag+L, range[flag]);
    }
}

long long factor(long long n)
{
    int m = (int) (sqrt(n)+0.001), num=0;
    long long x = n, div=1;
    long long ppow[100000];
    memset(ppow, 0, sizeof(ppow));
    for(int i=2 ; i<=m ; i++){
        if(prime[i] && (x%i==0)){
            ppow[num] = 0;
            while(x%i==0)
                x = x/i, ppow[num]++;
            div = div * (ppow[num]+1);
            num++;
        }
        m = (int) (sqrt(x)+0.001);
    }
    if(x>1)
        ppow[num] = 1, div = div * (ppow[num]+1), num++;
    return div;
}
