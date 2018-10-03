#include <bits/stdc++.h>
using namespace std;
#define NN 205
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d", &n);
        int a[NN] , b[NN];
        for(int i = 0 ; i< n ; i++)
            scanf("%d",&a[i]);
        for(int i = 0 ; i< n ; i++)
            scanf("%d",&b[i]);
        for(int i = 0 ; i< n ; i++)
            a[i] = abs(b[i]-a[i]-1);
        int res = 0;
        for(int i=0;i<n;i++)
            res ^= a[i];
 
        if(res > 0) printf("Case %d: white wins\n",cs++);
        else printf("Case %d: black wins\n",cs++);
    }
}
