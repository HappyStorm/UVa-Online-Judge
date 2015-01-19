#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

//Check if the assignment is suitable.
bool cutok(int, int, long long);

bool ifcut[500+10];
long long nums[500+10], sum, allmax;
int main()
{
    int test, m, k;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &m, &k);
        sum=0, allmax=0;

        //Load data & find the total & sort.
        for(int i=0 ; i<m ; i++){
            scanf("%lld", &nums[i]);
            sum = sum + nums[i];
            allmax = max(nums[i], allmax);
        }
        //sort(nums, nums+m);
        for(int i=0 ; i<m ; i++)
            ifcut[i] = false;
        //Binary search for the k segments.
        long long low=allmax, high=sum;
        while(low<high){
            long long mid = (low+high)/2;
            if(cutok(m, k, mid))
                high = mid;
            else
                low = mid+1;
        }

        //Cutting segments.
        int cut=k-1;    //If k segments, exists k-1 '/'(= k-1 cuts).
        long long segsum = low, tempsum=0;
        printf("Segsum= %lld\n", segsum);
        for(int i=m-1 ; i>=0 ; i--){
//  m objects have m-1 spaces to set '/'(cut).
//   0                                           m-1
//  [0]   [1]   [2]   [3]  [4]   [5]  [6]   [7]  [8]
//  100   200   300   400  500 / 600  700 / 800  900    m=9, k=3, cut=k-1=2, (sum=1700)
//  100 / 100 / 100 / 100  100                          m=5, k=4, cut=k-1=3, (sum= 200)
//   0                           m-1
/*
    number = i, means there are (i+1) objects left.
    so if the cut>=objects, then the spaces all left behind need to be put '/' in it.
    else if objects are more than the cuts, then we can sum it continuously.
*/
            if(i+1>cut && (tempsum+nums[i])<=segsum)
                tempsum = tempsum + nums[i];
            else    //i=6
                ifcut[i] = true, tempsum = nums[i], cut--; //printf("%d:%lld--", i, nums[i]);
        }
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
    int ct=1;   //No cut, but still one segment.
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
