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
int n, a, b;

int main()
{
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        if(a>b) puts(">");
        else if(a<b) puts("<");
        else    puts("=");
    }
    return 0;
}
