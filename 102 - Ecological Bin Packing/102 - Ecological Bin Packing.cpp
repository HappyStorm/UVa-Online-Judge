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
int b1, g1, c1, b2, g2, c2, b3, g3, c3, step[6];

int main()
{
    while(~scanf("%d %d %d %d %d %d %d %d %d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3)){
        /*BCG*/ step[0] = b2 + b3 + c1 + c3 + g1 + g2;
        /*BGC*/ step[1] = b2 + b3 + c1 + c2 + g1 + g3;
        /*CBG*/ step[2] = b1 + b3 + c2 + c3 + g1 + g2;
        /*CGB*/ step[3] = b1 + b2 + c2 + c3 + g1 + g3;
        /*GBC*/ step[4] = b1 + b3 + c1 + c2 + g2 + g3;
        /*GCB*/ step[5] = b1 + b2 + c1 + c3 + g2 + g3;

        int flag = 0, least = step[0];
        for(int i=0 ; i<6 ; ++i)
            if(step[i]<least) flag = i, least = step[i];
        switch(flag){
            case 0: {printf("BCG %d\n", least); break;}
            case 1: {printf("BGC %d\n", least); break;}
            case 2: {printf("CBG %d\n", least); break;}
            case 3: {printf("CGB %d\n", least); break;}
            case 4: {printf("GBC %d\n", least); break;}
            case 5: {printf("GCB %d\n", least); break;}
        }
    }
    return 0;
}
