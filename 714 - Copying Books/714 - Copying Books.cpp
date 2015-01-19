#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool ifcut[500+10];
long long nums[500+10], sum, allmax;

bool cutok(int, int, long long);
int main()
{
    int test, m, k;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &m, &k);
        sum=0, allmax=0;
        for(int i=0 ; i<m ; i++){
            scanf("%lld", &nums[i]);
            sum = sum + nums[i];
            allmax = max(nums[i], allmax);
        }
        memset(ifcut, false, sizeof(ifcut));
        long long low=allmax, high=sum;
        while(low<high){
            long long mid = (low+high)/2;
            if(cutok(m, k, mid))
                high = mid;
            else
                low = mid+1;
        }
        int cut=k-1;
        long long segsum = low, tempsum=0;
        printf("Segsum= %lld\n", segsum);
        for(int i=m-1 ; i>=0 ; i--)
            if(i+1>cut && (tempsum+nums[i])<=segsum)
                tempsum = tempsum + nums[i];
            else
                ifcut[i] = true, tempsum = nums[i], cut--;
        for(int i=0 ; i<m ; i++){
            if(i==m-1)
                printf("%lld\n", nums[i]);
            else
                printf("%lld ", nums[i]);
            if(ifcut[i])
                printf("/ ");
        }
    }
    return 0;
}

bool cutok(int books, int segment, long long bounder)
{
    long long tempsum=0;
    int ct=1;
    for(int i=0 ; i<books ; i++){
        if(tempsum+nums[i]>bounder)
            tempsum=0, ct++;
        tempsum = tempsum + nums[i];
    }
    if(ct>segment)
        return false;
    else
        return true;
}
