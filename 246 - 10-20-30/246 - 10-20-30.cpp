#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
set< pair<queue<int>, vector<vector<int> > > >  condition;
int cycle, draw;
queue<int> hand;
vector<int> pile[7];
vector<vector<int> > all;
void check(int);
void process(int);
int main()
{
    int temp;
    while(~scanf("%d", &temp) && temp){
        condition.clear();
        for(int i=0 ; i<7 ; i++)
            pile[i].clear();
        while(hand.size()>0)
            hand.pop();
        hand.push(temp);
        for(int i=1 ; i<52 ; i++)
            scanf("%d", &temp), hand.push(temp);

        // Begin to deliver the first  and the second card.
        for(int i=0 ; i<2 ; i++)
            for(int j=0 ; j<7 ; j++)
                pile[j].push_back(hand.front()), hand.pop();

        // Start deliver the card.
        cycle=14, draw=0;
        for(int i=0 ; ; i++){
            if(i==7) i=0;
            process(i);
            if(hand.size()==0){
                printf("Loss: %d\n", cycle);
                break;
            }
            if(hand.size()==52){
                printf("Win : %d\n", cycle);
                break;
            }
            if(draw)
                break;
        }
    }
    return 0;
}
void check(int n)
{
    if(pile[n].size()<3)
        return;
    int last = pile[n].size()-1;
    while(pile[n].size()>2){
        if((pile[n][last]+pile[n][0]+pile[n][1])%10==0){
            hand.push(pile[n][0]), hand.push(pile[n][1]), hand.push(pile[n][last]);
            pile[n].pop_back(), pile[n].erase(pile[n].begin()), pile[n].erase(pile[n].begin());
            last = pile[n].size()-1;
            continue;
        }
        else if((pile[n][last]+pile[n][last-1]+pile[n][0])%10==0){
            hand.push(pile[n][0]), hand.push(pile[n][last-1]), hand.push(pile[n][last]);
            pile[n].pop_back(), pile[n].pop_back(), pile[n].erase(pile[n].begin());
            last = pile[n].size()-1;
            continue;
        }
        else if((pile[n][last]+pile[n][last-1]+pile[n][last-2])%10==0){
            hand.push(pile[n][last-2]), hand.push(pile[n][last-1]), hand.push(pile[n][last]);
            pile[n].pop_back(), pile[n].pop_back(), pile[n].pop_back();
            last = pile[n].size()-1;
            continue;
        }
        break;
    }
    for(int j=0 ; j<7 ; j++)
        all.push_back(pile[j]);
    if(condition.find(make_pair(hand, all))!=condition.end()){
        printf("Draw: %d\n", cycle), draw=1;
        return;
    }
    condition.insert(make_pair(hand, all));
    all.clear();
}
void process(int n)
{
    if(!pile[n].empty())
        pile[n].push_back(hand.front()), hand.pop(), cycle++, check(n);
    return;
}
