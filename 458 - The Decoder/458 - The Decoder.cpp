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
char in[2000];


int main()
{
    while(gets(in)!=NULL){
        int len = strlen(in);
        for(int i=0 ; i<len ; ++i)
            putchar(in[i]-7);
        putchar(10);
    }
    return 0;
}
