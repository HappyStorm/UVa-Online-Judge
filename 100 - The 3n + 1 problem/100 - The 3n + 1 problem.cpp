#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b;
    while(EOF!=scanf("%d %d", &a, &b)){
        int low = min(a,b), high = max(a, b), ans=0;

        for(int i=low ; i<=high ; i++){
            int ct=1, temp=i;
            while(temp!=1){
                if(temp%2==1)
                    temp=3*temp+1;
                else
                    temp/=2;
                ct++;
            }
            if(ct>ans)
                ans = ct;
        }
        printf("%d %d %d\n", a, b, ans);
    }
    return 0;
}
