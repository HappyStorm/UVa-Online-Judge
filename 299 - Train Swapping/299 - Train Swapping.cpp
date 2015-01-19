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
int N, L, tra[50+10], S, temp;


int main()
{
    scanf("%d", &N);
    while(N--){
        memset(tra, 0, sizeof(tra));
        scanf("%d", &L);
        S = 0;
        for(int i=0 ; i<L ; ++i)
            scanf("%d", &tra[i]);
        for(int i=0 ; i<L ; ++i){
            for(int j=0 ; j<L-1 ; ++j){
                if(tra[j]>tra[j+1]){
                    temp = tra[j];
                    tra[j] = tra[j+1];
                    tra[j+1] = temp;
                    ++S;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", S);
    }
    return 0;
}
