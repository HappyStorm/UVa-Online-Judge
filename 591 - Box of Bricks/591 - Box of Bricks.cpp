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

int n, ct;
int h[50+5];


int main()
{
    while(~scanf("%d", &n) && n){
        int sum=0, avg=0, m=0;
        for(int i=0; i<n; ++i)
            scanf("%d", &h[i]), sum+=h[i];
        avg = sum/n;
        for(int i=0; i<n; ++i)
            m+=abs(h[i]-avg);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++ct, m/2);
    }
    return 0;
}
