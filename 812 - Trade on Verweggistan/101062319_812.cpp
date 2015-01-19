#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct PrulsCon{
    int id, price;
    long long untilSum;
};

bool cmpSum(PrulsCon a, PrulsCon b)
{
    if(a.untilSum!=b.untilSum)
        return a.untilSum>b.untilSum;
    else
        return a.id<b.id;
}

int main()
{
    int W, workyard=0;
    while(~scanf("%d", &W)){
        if(W==0)
            break;
        vector<PrulsCon> pruList[W+10];
        long long piles;
        PrulsCon prul;
        for(int i=0 ; i<W ; i++){
            scanf("%lld", &piles);
            long long tempprice, tempsum=0;
            for(int j=0 ; j<piles ; j++){
                scanf("%lld", &tempprice);
                prul.id = j+1, prul.price = tempprice;
                tempsum+=(10-tempprice), prul.untilSum = tempsum;
                pruList[i].push_back(prul);
            }
            if(piles!=0)
                sort(pruList[i].begin(), pruList[i].end(), cmpSum);

            long long bigprofit = pruList[i].front().untilSum;
            for(int j=0 ; j<piles ; j++){
                if(pruList[i][j].untilSum<bigprofit){
                    pruList[i].erase(pruList[i].begin()+j, pruList[i].end());
                    break;
                }
            }
        }

        long long profit=0;
        for(int i=0 ; i<W ; i++)
            if(pruList[i].size() && pruList[i].front().untilSum>=0)
                profit+=(pruList[i].front().untilSum);
            else
                pruList[i].clear();

        set<long long> tempstore;
        tempstore.insert(0);
        for(int i=0 ; i<W ; i++){
            //printf("Now WorkShop<%d>:\n \t\t\tProfit: %lld\n", i+1, pruList[i][0].untilSum);
            //for(int j=0 ; j<pruList[i].size() ; j++)
                //printf("pruList[%d][%d]= %d \t UntilSum= %lld\n", i, j, pruList[i][j].price, pruList[i][j].untilSum);

            vector<long long> tempnow;
            if(pruList[i].size()>0 && pruList[i][0].untilSum==0)
                tempnow.push_back(0);
            for(int j=0 ; /*j<10 && */j<pruList[i].size() ; j++){
                if(pruList[i][j].untilSum==pruList[i][0].untilSum)
                    tempnow.push_back(pruList[i][j].id);
                else if(pruList[i][j].untilSum<pruList[i][0].untilSum)
                    break;
            }
            if(tempnow.size()==0)
                tempnow.push_back(0);
            //for(int j=0 ; j<10 && j<tempnow.size() ; j++)
               // printf("TempNow[%d]= %lld\n", j, tempnow[j]);

            set<long long>::iterator it = tempstore.begin();
            vector<long long> store;
            int capacity = tempstore.size();
            for(int ct=0 ; ct<capacity /*&& ct<10*/ ; ct++, it++)
                for(int j=0 ; /*j<10 &&*/ j<tempnow.size() ; j++)
                    store.push_back(tempnow[j] + *it);

            sort(store.begin(), store.end());
            //for(int j=0 ; j<store.size() ; j++)
                //printf("Add= %lld\n", store[j]);

            tempstore.clear();
            for(int j=0 ; j<store.size() ; j++)
                tempstore.insert(store[j]);

            it = tempstore.begin();
            //for(int i=0 ; it!=tempstore.end() && i<10 ; i++, it++)
                //printf("TempStore[%d]= %lld\n", i, *it);
            //putchar(10);
        }


        if(workyard!=0)
            putchar(10);
        workyard++;

        printf("Workyards %d\n", workyard);
        printf("Maximum profit is %lld.\n", profit);
        printf("Number of pruls to buy: ");

        set<long long>::iterator ansiter = tempstore.begin();
        for(int i=0 ; i<10 && ansiter!=tempstore.end() ; i++, ansiter++){
            if(i!=tempstore.size()-1 && i<9)
                printf("%lld ", *ansiter);
            else if(i==tempstore.size()-1 || i==9)
                printf("%lld\n", *ansiter);
        }
    }
    return 0;
}
