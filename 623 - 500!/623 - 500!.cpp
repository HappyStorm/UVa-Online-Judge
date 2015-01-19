#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int big[3000];
int number[1000+5][3000+5];

int main()
{
    int n;
    memset(big, 0, sizeof(big));
    memset(number, 0, sizeof(number));
    big[2999]=1;
    int carry=0, temp=0, flag=0;
    for(int i=1 ; i<=1000 ; i++){
        carry = 0;
        flag = 0;
        for(int j=2999 ; j>=0 ; j--){
            temp = big[j] * i + carry;
            big[j] = temp % 10;
            carry = temp/10;
        }
        while(big[flag]==0)
            flag++;
        for(int j=2999 ; j>=flag ; j--)
            number[i][j] = big[j];
    }
    while(~scanf("%d", &n)){
        if(n==0)
            printf("0!\n1\n");
        else{
            flag=0;
            while(number[n][flag]==0)
                flag++;
            printf("%d!\n", n);
            for(int i=flag ; i<3000 ; i++)
                printf("%d", number[n][i]);
            putchar(10);
        }
    }
    return 0;
}
