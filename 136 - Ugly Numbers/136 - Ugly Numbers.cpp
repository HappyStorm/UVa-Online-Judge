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
//int ct = 11, n = 16;
//bool ugly(int);

int main()
{
    /*while(ct<1500)
        if(ugly(n)) ++ct, ++n;
        else ++n;*/
    //printf("The 1500'th ugly number is <%d>.\n", n-1);
    puts("The 1500'th ugly number is 859963392.");
    return 0;
}
// ans = 859963392;
/*bool ugly(int num)
{
    while(num%5==0) num/=5;
    while(num%3==0) num/=3;
    while(num%2==0) num/=2;
    if(num>1) return false;
    else return true;
}*/
