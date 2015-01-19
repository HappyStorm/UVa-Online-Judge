#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Xsum{
    int a, b, sum;
};

int cmp(const void *a, const void *b)
{
    int c = *(int*)a, d = *(int*)b;
    return (d-c);
}
bool xcmp(Xsum a, Xsum b)
{
    return a.sum<b.sum;
}

int bisearch(int, vector<Xsum>);

int nums[1000+10];
int main()
{
    int n;
    while(~scanf("%d", &n)){
        if(n==0)
            break;
        memset(nums, 0, sizeof(nums));
        for(int i=0 ; i<n ; i++)
            scanf("%d", &nums[i]);
        //Sort from big to small.
        qsort(nums, n, sizeof(nums[0]), cmp);
        vector<Xsum> X;
        Xsum x;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                x.sum = nums[i] + nums[j];
                x.a = nums[i], x.b = nums[j];
                X.push_back(x);
            }
        }
        //Sort by sum & from small to big.
        sort(X.begin(), X.end(), xcmp);

        int ans=0, flag=0, ok=0;
        for(int i=0 ; i<n ; i++){
            for(int j=n-1 ; j>0 ; j--){
                if(j!=i){
                    int temp = nums[i] - nums[j];
                    flag = bisearch(temp, X);
                    if(flag){
                        if(nums[i]==X[flag].a || nums[i]==X[flag].b ||
                           nums[j]==X[flag].a || nums[j]==X[flag].b){
                            while(nums[i]==X[flag].a || nums[i]==X[flag].b ||
                                  nums[j]==X[flag].a || nums[j]==X[flag].b)
                                    flag++;
                            if(X[flag].sum==temp){
                                ans = nums[i], ok=1;
                                break;
                            }
                        }
                        else{
                            ans = nums[i], ok=1;
                            break;
                        }
                    }
                }
            }
            if(ok)
                break;
        }
        if(ok)
            printf("%d\n", ans);
        else
            printf("no solution\n");
    }
    return 0;
}

int bisearch(int dif, vector<Xsum> X)
{
    int low = 0, high = X.size()-1, mid;
    while(low<high){
        mid = (low+high)/2;
        if(X[mid].sum==dif){
            while(X[mid].sum==dif)
                mid--;
            return mid+1;
        }
        else if(X[mid].sum<dif)
            low = mid+1;
        else
            high = mid;
    }
    return 0;
}
