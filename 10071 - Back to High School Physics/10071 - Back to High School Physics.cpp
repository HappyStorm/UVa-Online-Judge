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
int v, t;
double a;

int main()
{
    while(~scanf("%d %d", &v, &t)){
        if(v==0 || t==0) printf("0\n");
        else{
            a = (double)v / (double) t;
            printf("%.0f\n", 0.5*a*pow(2*t,2));
        }
    }
    return 0;
}
