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
int N, step;
char in[10+10], a[10+10], b[10+10], c[10+10];
string re, ori;

bool palin(string);
void add();
int main()
{
    scanf("%d", &N), getchar();
    while(N--){
        gets(in), ori = (string) in;
        while(!palin(ori))
            add(), ++step;
        printf("%d %s\n", step, ori.c_str());
        for(int i=0 ; i<19 ; ++i)
            in[i] = a[i] = b[i] = c[i] = '\0';
        step = 0;
    }
    return 0;
}

bool palin(string str)
{
    string t = str;
    reverse(t.begin(), t.end());
    if(t.compare(str)!=0) return false;
    else return true;
}

void add()
{
    int carry = 0, sum = 0, len = 0;
    re = ori, reverse(re.begin(), re.end());
    for(int i=0 ; i<re.length() ; ++i)
        a[19-i] = re[i], b[19-i] = ori[i];
    for(int i=19 ; a[i]!='\0' ; --i){
        sum = a[i]-'0' + b[i]-'0' + carry;
        if(sum>=10) carry = 1, c[len++] = (sum%10) + '0';
        else carry = 0, c[len++] = sum + '0';
    }
    if(carry>0) c[len++] = carry + '0';
    ori = string(c);
}
