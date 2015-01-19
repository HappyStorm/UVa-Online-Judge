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
char in[1000+10];
map<char, char> qwerty;
map<char, char>::iterator iter;

int main()
{
    qwerty['1'] = '`', qwerty['2'] = '1', qwerty['3'] = '2';
    qwerty['4'] = '3', qwerty['5'] = '4', qwerty['6'] = '5';
    qwerty['7'] = '6', qwerty['8'] = '7', qwerty['9'] = '8';
    qwerty['0'] = '9', qwerty['-'] = '0', qwerty['='] = '-';
    qwerty['W'] = 'Q', qwerty['S'] = 'A', qwerty['X'] = 'Z';
    qwerty['E'] = 'W', qwerty['D'] = 'S', qwerty['C'] = 'X';
    qwerty['R'] = 'E', qwerty['F'] = 'D', qwerty['V'] = 'C';
    qwerty['T'] = 'R', qwerty['G'] = 'F', qwerty['B'] = 'V';
    qwerty['Y'] = 'T', qwerty['H'] = 'G', qwerty['N'] = 'B';
    qwerty['U'] = 'Y', qwerty['J'] = 'H', qwerty['M'] = 'N';
    qwerty['I'] = 'U', qwerty['K'] = 'J', qwerty[','] = 'M';
    qwerty['O'] = 'I', qwerty['L'] = 'K', qwerty['.'] = ',';
    qwerty['P'] = 'O', qwerty[';'] = 'L', qwerty['/'] = '.';
    qwerty['['] = 'P', qwerty['\''] = ';',qwerty[']'] = '[';
    qwerty['\\'] = ']',qwerty[' '] = ' ';
    while(gets(in)!=NULL){
        int len = strlen(in);
        for(int i=0 ; i<len ; ++i)
            iter = qwerty.find(in[i]), printf("%c", iter->second);
        putchar(10);
        memset(in, '\0', sizeof(in));
    }
    return 0;
}
