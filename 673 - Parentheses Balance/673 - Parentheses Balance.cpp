#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;


int main()
{
    int test;
    scanf("%d", &test), getchar();
    while(test--){
        char input[128+10];
        gets(input);
        int len = strlen(input);
        if(len==0)
            printf("Yes\n");
        else{
            int check=1;
            stack<char> paren;
            for(int i=0 ; i<len ; i++){
                if(input[i]=='(' || input[i]=='[')
                   paren.push(input[i]);
                else if(input[i]==')'){
                    if(paren.size()<1 || paren.top()!='('){
                        check=0;
                        break;
                    }
                    else if(paren.top()=='(')
                        paren.pop();
                }
                else if(input[i]==']'){
                    if(paren.size()<1 || paren.top()!='['){
                        check=0;
                        break;
                    }
                    else if(paren.top()=='[')
                        paren.pop();
                }
            }
            if(paren.size()>0)
                check=0;
            if(check)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
