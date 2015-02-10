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

int N, row, col;
int arr[100+5][100+5];

int main()
{
    while(~scanf("%d\n", &N)){
        memset(arr, 0, sizeof(arr));
        int big=0;
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j){
                scanf("%d", &arr[i][j]);
                arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
            }
        }
        for(int i=1; i<=N ; ++i)
            for(int j=1; j<=N; ++j)
                for(int m=i; m<=N; ++m)
                    for(int n=j; n<=N; ++n)
                        big = max(big, arr[m][n] - arr[i-1][n] - arr[m][j-1] + arr[i-1][j-1]);
        printf("%d\n", big);
    }
    return 0;
}
