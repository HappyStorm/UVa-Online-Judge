#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

double calculate(int, int , int , int , int, int, double);
int main()
{
    int p, q, r, s, t, u;
    while(~scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)){
        double L=0.0, U=1.0, ans;
        if(calculate(p, q, r, s, t, u, L)*calculate(p, q, r, s, t, u, U) > 0)
            printf("No solution\n");
        else{
            while((U-L)>1e-8){
                ans = (L+U)/2;
                if(calculate(p, q, r, s, t, u, U)*calculate(p, q, r, s, t, u, ans) <= 0)
                    L = ans;
                else
                    U = ans;
            }
            printf("%.4f\n", U);
        }
    }
    return 0;
}

double calculate(int p, int q, int r, int s, int t, int u, double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
