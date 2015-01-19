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
typedef int state[3];
state st[2000],a;
int pour[2000];
int record[205];
int target;
int vis[205][205],vispour[205][205];
int try_to_insert(int x,int tpour)
{
    state &k = st[x];
    if(vis[k[0]][k[1]] != 1 || vispour[k[0]][k[1]] > tpour)
    {
        vis[k[0]][k[1]] = 1;
        vispour[k[0]][k[1]] = tpour;
        return 1;
    }
    return 0;
}
int main()
{
    int i,j,t,ans;
    scanf("%d",&t);
    while(t--)
    {
        memset(record,0,sizeof(record));
        memset(vis,0,sizeof(vis));
        memset(vispour,0,sizeof(vis));
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&target);
        st[1][0] = st[1][1] = 0;
        st[1][2] = a[2];
        memset(pour,0,sizeof(pour));
        record[a[2]] = 1;
        int front = 1,rear = 2;
        vis[0][0] = 1;
        bool flag = false;
        while(front < rear)
        {
            for(i = 0; i < 3; i++)
                if(record[st[front][i]] == 0 || pour[record[st[front][i]]] > pour[front])
                    record[st[front][i]] = front;
            for(i = 0; i < 3; i++)
                if(st[front][i] == target)
                {
                    if(flag)
                        ans = pour[ans] > pour[front]?front:ans;
                    else
                            ans = front;
                    flag = true;
                    break;
                }
            for(i = 0; i < 3; i++)
            {
                state &w = st[front];
                if(w[i] != 0)
                {
                    for(j = 0; j < 3; j++)
                    {
                        if(i == j || (i != j && w[j] == a[j])) continue;
                        state &temp = st[rear];
                        memcpy(temp,w,sizeof(w));
                        int pp;
                        if(w[i] + w[j] > a[j])
                        {
                            pp = a[j] - w[j];
                            temp[i] = w[i] - pp;
                            temp[j] = a[j];
                        }
                        else
                        {
                            pp = w[i];
                            temp[i] = 0;
                            temp[j] = w[j] + pp;
                        }
                        int tpour;
                            tpour = pour[front] + pp;
                        if(try_to_insert(rear,tpour))
                        {
                            pour[rear] = tpour;
                            rear++;
                        }
                    }
                }
            }
            front++;
        }
        if(record[target] == 0)
        {
            for(i = target; record[i] == 0; i--);
            printf("%d %d\n",pour[record[i]],i);
        }
        else printf("%d %d\n",pour[ans],target);
    }
    return 0;
}
