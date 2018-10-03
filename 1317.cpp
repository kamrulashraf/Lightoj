#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
         int n , m , k;
         double p;
         scanf("%d%d%d%lf",&n,&m,&k,&p);
         double res = (n*k*p);
         // think for 1 basket probabilty of sucessful thorow
         // p*(1/m)
         // number of thorow = n*k
         // for 1 busket sucessful thorow = n*k*p/m
         // for m busket sucessful thorow = n*k*p
         printf("Case %d: %.8lf\n",cs++ ,res);
    }
}
