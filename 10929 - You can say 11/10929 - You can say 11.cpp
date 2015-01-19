#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char input[1000];
    while(gets(input)!=NULL){
        int length = strlen(input);
        if(input[0]=='0' && length==1)
            break;
        int sum[2] = {0};
        for(int i=0 ; i<length ; i++)
            sum[i%2]+=input[i]-'0';
        if((sum[0]-sum[1])%11==0)
            printf("%s is a multiple of 11.\n", input);
        else
            printf("%s is not a multiple of 11.\n", input);
        /*if(input[0]=='0' && length==1)
            break;

        int odd=0, even=0, sum;
        for(int i=0 ; i<length ; i+=2)
            odd = odd + (input[i] - '0');
        for(int i=1 ; i<length ; i+=2)
            even = even + (input[i] - '0');
        sum = abs(odd-even);
        if(sum%11==0)
            printf("%s is a multiple of 11.\n", input);
        else
            printf("%s is not a multiple of 11.\n", input);*/
    }
    return 0;
}
