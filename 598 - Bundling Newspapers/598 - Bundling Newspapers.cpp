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
#include <cctype>
#include <vector>
#include <list>
using namespace std;
int kind, a, b, c, k, temp;
bool visit[15];
char input[15], news[50];
vector<string> paper;
string ans[15];
vector<int> com;

void bundling(int, int);
int main()
{
    int test, times=0;
    scanf("%d", &test), getchar(), getchar();
    memset(input, '\0', sizeof(input));
    com.clear();
    paper.clear();
    while(test--){
        gets(input);
        if(input[0]=='*'){
            kind=0;
            memset(news, '\0', sizeof(news));
            while(gets(news)!=NULL){
                if(strlen(news)==0){
                    memset(news, '\0', sizeof(news));
                    break;
                }
                paper.push_back((string) news);
                memset(news, '\0', sizeof(news));
                kind++, com.push_back(kind);
            }
        }
        else{
            a=-1, b=-1, c=-1;
            int state=1;
            char *t;
            t = strtok(input, " ");
            while(t!=NULL){
                int len = strlen(t);
                if(len==1){
                    if(state==1)
                        a = t[0] - '0';
                    else if(state==2)
                        b = t[0] - '0';
                    else if(state==3)
                        c = t[0] - '0';
                }
                else if(len==2){
                    if(state==1)
                        a = (t[0]-'0')*10 + t[1]-'0';
                    else if(state==2)
                        b = (t[0]-'0')*10 + t[1]-'0';
                    else if(state==3)
                        c = (t[0]-'0')*10 + t[1]-'0';
                }
                t = strtok(NULL, " ");
                state++;
            }
            if(state==2)
                com.push_back(a);
            else if(state==3)
                for(int i=a ; i<=b ; i++)
                    com.push_back(i);
            else if(state==4)
                com.push_back(a), com.push_back(b), com.push_back(c);
            memset(news, '\0', sizeof(news));
            while(gets(news)!=NULL){
                if(strlen(news)==0){
                    memset(news, '\0', sizeof(news));
                    break;
                }
                paper.push_back((string) news);
                memset(news, '\0', sizeof(news));
            }
        }
        memset(visit, false, sizeof(visit));
        for(int i=0 ; i<(int) com.size() ; i++){
            printf("Size %d\n", com[i]);
            k = com[i];
            bundling(0, 0);
            putchar(10);
        }
        com.clear();
        paper.clear();
        memset(input, '\0', sizeof(input));
        if(test>0) putchar(10);
    }
    return 0;
}

void bundling(int cur, int layer)
{
    if(layer==k){
        for(int i=0 ; i<k ; i++){
            if(i==k-1)
                puts(ans[i].c_str());
            else
                printf("%s, ", ans[i].c_str());
        }
    }
    for(int i=cur ; i<(int) paper.size() ;  i++){
        if(!visit[i]){
            visit[i] = true;
            ans[layer] = paper[i];
            bundling(i+1, layer+1);
            visit[i] = false;
        }
    }
}
