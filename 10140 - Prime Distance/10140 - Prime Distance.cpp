#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#define MAX 47000
using namespace std;
bool prime[MAX], range[1000000+10];
int L, U, prime_num, allprime[5000], ppow[5000], ans[1000000+10];
void prime_table()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false, prime[1] = false, prime_num = 0;
    int m = 46340;
    for(int i=2 ; i<=m ; i++){
        if(prime[i]){
            ppow[prime_num] = i*i, allprime[prime_num++] = i;
            for(int j=i*i ; j<=MAX ; j+=i)
                prime[j] = false;
        }
    }
}

void primepow();
void notprime();
bool isprime(int);
int main()
{
    prime_table();
    while(~scanf("%d %d", &L, &U)){
        int num = 0, close = 999999, maxdis = 0, temp, ct = 0;
        memset(range, true, sizeof(range));
        memset(ans, 0, sizeof(ans));
        if(isprime(L))
            primepow();
        else
            notprime();
        for(int i=L ; i<=U ; i++)
            if(range[i-L])
                if(isprime(i))
                    ans[ct++]=i, ++num;
                else
                    range[i-L] = false;
        int a=0, b=0, c=0, d=0;
        for(int i=0 ; i<num-1 ; i++){
            temp = ans[i+1]-ans[i];
            if(temp<close)  a = ans[i], b = ans[i+1], close = temp;
            if(temp>maxdis) c = ans[i], d = ans[i+1], maxdis = temp;
        }
        if(num>1)
            printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
        else
            printf("There are no adjacent primes.\n");
    }
}

bool isprime(int n)
{
    if(n<=46341)
        return prime[n];
    for(int i=0 ; i<prime_num && ppow[i]<=n ; i++)
        if(n % allprime[i]==0)
            return false;
    return true;
}

void primepow()
{
    int temp = L+1;
    if(L==2)
        for(int i=L+2 ; i<=U ; i+=2)
            range[i-L] = false;
    else
        for(int i=temp ; i<=U ; i+=2)
            range[i-L] = false;
}

void notprime()
{
    int temp = L+1;
    if(L%2==1)
        if(L==1)
            for(int i=L+3 ; i<=U ; i+=2)
                range[i-L] = false;
        else
            for(int i=temp ; i<=U ; i+=2)
                range[i-L] = false;
    else
        for(int i=L ; i<=U ; i+=2)
            range[i-L] = false;
}
