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
int flag;
char in[100+10];

int main()
{
    while(gets(in)!=NULL){
        int len = strlen(in);
        for(int i=0 ; i<len ; ++i){
            if(flag==0 && in[i]=='"') putchar('`'), putchar('`'), flag = 1;
            else if(flag==1 && in[i]=='"') putchar('\''), putchar('\''), flag = 0;
            else putchar(in[i]);
        }
        putchar(10);
    }
    return 0;
}
