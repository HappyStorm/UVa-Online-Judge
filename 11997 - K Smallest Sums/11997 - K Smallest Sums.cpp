#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define K 777
using namespace std;

struct Number{
    int value, index;
    Number(int v, int i){
        value = v, index = i;
    }
    bool operator < (const struct Number &a) const{
        return value > a.value;
    }
};

void Merge(int[], int[], int);

int num[K][K];
priority_queue<Number> ans;
int main()
{
    int k;
    while(~scanf("%d", &k)){
        memset(num, 0, sizeof(num));
        for(int i=0 ; i<k ; i++){
            for(int j=0 ; j<k ; j++)
                scanf("%d", &num[i][j]);
            sort(num[i], num[i]+k);
        }
        for(int i=1 ; i<k ; i++)
            Merge(num[0], num[i], k);
        for(int i=0 ; i<k ; i++)
            if(i!=k-1)
                printf("%d ", num[0][i]);
            else
                printf("%d\n", num[0][i]);
    }
    return 0;
}

void Merge(int* A, int* B, int n)
{
    while(!ans.empty())
        ans.pop();
    for(int i=0 ; i<n ; i++)
        ans.push(Number(A[i]+B[0],0));
    int index;
    for(int i=0 ; i<n ; i++){
        Number n = ans.top();
        ans.pop();
        A[i] = n.value, index = n.index;
        ans.push(Number(n.value-B[index]+B[index+1], index+1));
    }
}
