#include <bits/stdc++.h>
using namespace std;
#define NN 205
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        int row , col;
        scanf("%d%d",&row , &col);
        long long res = 0;
        for(int i = 0;i<row;i++){
            long long sum = 0;
            for(int j=0;j<col;j++){
               long long a;
               scanf("%lld",&a);
               sum += a;
            }
            res ^= sum;
        }
 
 
        if(res > 0) printf("Case %d: Alice\n",cs++);
        else printf("Case %d: Bob\n",cs++);
    }
}
