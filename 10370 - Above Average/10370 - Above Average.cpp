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

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        int people;
        scanf("%d", &people);

        double grades[1005];
        for(int i=0 ; i<people ; i++){
            scanf("%lf", &grades[i]);
        }

        double total=0.0;
        for(int i=0 ; i<people ; i++)
            total+=grades[i];

        double average = total/people;

        double pass=0.0;
        for(int i=0 ; i<people ; i++){
            if(grades[i]>average)
                pass++;
        }

        double pass_rate = pass/people*100;
        printf("%.3lf%%\n", pass_rate);
    }
    return 0;
}
