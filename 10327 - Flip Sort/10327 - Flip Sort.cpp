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
    int num, times=0;
    while(scanf("%d", &num)!=EOF){
        int* nums = (int*) malloc(num * sizeof(int));

        int t=0;
        while(t<num)
            scanf("%d", &nums[t]), t++;

        for(int i=0 ; i<num ; i++){
            for(int j=0 ; j<num-1 ; j++){
                int temp;
                if(*(nums+j) > *(nums+j+1)){
                    temp = *(nums+j);
                    nums[j] = *(nums+j+1);
                    nums[j+1] = temp;
                    times++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", times);
        times=0;
        free(nums);
    }
    return 0;
}

