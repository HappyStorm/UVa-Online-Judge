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
int n, f, area, animal, eco, premium;

int main()
{
    scanf("%d", &n);
    while(n--){
        premium = 0;
        scanf("%d", &f);
        for(int i=0 ; i<f ; ++i){
            scanf("%d %d %d", &area, &animal, &eco);
            premium +=  area * eco;
        }
        printf("%d\n", premium);
    }
    return 0;
}
